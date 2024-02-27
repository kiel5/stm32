#ifndef BOOTLOADER_H
#define BOOTLOADER_H
#include "bootloader_command.h"
void ota_send_response(OTA_Response_name ack);
void bootloader_send_data(void *data, uint8_t len);
void ota_send_code(OTA_CODE_NAME ota_code);
void bootloader_init();
void bootloader_handlde();
void min_application_handler(uint8_t min_id, uint8_t const*min_payload, 
                              uint8_t len_payload, uint8_t port);



#endif