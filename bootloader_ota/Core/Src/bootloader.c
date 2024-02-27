#include "bootloader.h"
#include "min.h"
#include "uart_ring.h"
#include "stm32f103xb.h"
#include "bootloader_command.h"
#define MIN_PORT 0
#define MIN_ID   1

struct min_context min_cxt;
typedef enum
{
    OTA_IDLE_STATE,
    OTA_START_STATE,
    OTA_SEND_INFOR_STATE,
    OTA_SEND_DATA_STATE,
    OTA_END_STATE
}OTA_State_Typedef;
OTA_State_Typedef ota_state;
void min_application_handler(uint8_t min_id, uint8_t const*min_payload, 
                              uint8_t len_payload, uint8_t port)
{
  // HAL_GPIO_WritePin(GPIOC,GPIO_PIN_13,min_payload[0]);
  // min_send_frame(&min_cxt,MIN_ID,&min_payload[0],1);
    switch (ota_state)
    //min_payload có dạng 0x00, 0x01, 0x02 
    {
    case OTA_IDLE_STATE:
        OTACode* ota_code = (OTACode *)min_payload;
        if(ota_code->command_id == OTA_CODE && ota_code->ota_cmd == START_CODE)
        {
            ota_state = OTA_START_STATE;
            ota_send_response(ACK);
        }
        break;
    case OTA_START_STATE:
        OTAInfor *infor = (OTAInfor *)min_payload;
        if(infor->command_id = OTA_Infor)
        {
            // lưu tên và version vào flash
            ota_send_response(ACK);
            ota_state = OTA_SEND_INFOR_STATE;
        }

        break;  
    case OTA_SEND_INFOR_STATE:
        OTAData* ota_data = (OTAData *) min_payload;
        if(ota_data->command_id == OTA_DATA)
        {
            // dòng đầu tiên 
            //lấy data lưu vào vùng app
            ota_send_response(ACK);
        }
        break;
    case OTA_SEND_DATA_STATE:
        //nhận dòng thứ 2 trở đi
        OTAData* ota_data = (OTAData *) min_payload;
        if(ota_data->command_id == OTA_DATA)
        {
            // dòng thứ 2  
            //lấy data lưu vào vùng app
            ota_send_response(ACK);
        }
        else if(ota_data->command_id == OTA_CODE)
        {
            OTACode * code = (OTACode *)min_payload;
            if(code->ota_cmd == END_CODE)
            {
                ota_state = OTA_END_STATE;
                ota_send_response(ACK);
            }
        }
        break;
    case OTA_END_STATE:
        break;  
    default:
        break;
    }
}

void bootloader_send_data(void *data, uint8_t len)
{
    min_send_frame(&min_cxt,MIN_ID,(uint8_t*) data,len);
}
void ota_send_code(OTA_CODE_NAME ota_code)
{
    //uint8_t buff_ota_start[] = {0x00,1, 0x00};
    OTACode cmd;
    cmd.command_id = OTA_CODE;
    cmd.len  = 1;
    cmd.ota_cmd = ota_code;
    bootloader_send_data(&cmd,sizeof(cmd));
}
void ota_send_response(OTA_Response_name ack)
{
    OTAResponse response;
    response.command_id = OTA_RESPONSE;
    response.len = 1;
    response.ack = ack; 
    bootloader_send_data(&response,sizeof(response));
}
void bootloader_request_update()
{
  uint8_t cmd[] = {0x00,1,2};
  min_send_frame(&min_cxt,MIN_ID,cmd,3);
}
void bootloader_handlde()
{
    uint8_t len = 0;
    uint8_t data;
    if(uart_available() > 0)
    {
      data = uart_read();
      len = 1;
    }
    min_poll(&min_cxt,&data, len);
}
void bootloader_init()
{
    min_init_context(&min_cxt,MIN_PORT);
    ota_state = OTA_IDLE_STATE;
}
