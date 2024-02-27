#ifndef BOOTLOADER_COMMAND_H
#define BOOTLOADER_COMMAND_H

#include "stdint.h"
#include "stdint.h"
enum 
{
    OTA_CODE    = 0x00,
    OTA_Infor   = 0x01,
    OTA_DATA    = 0x02,
    OTA_RESPONSE= 0x03
};

typedef enum
{
    START_CODE,
    END_CODE,
    REQUEST_CODE
}OTA_CODE_NAME;

typedef enum
{
    ACK,
    NACK
}OTA_Response_name;

typedef struct 
{
    uint8_t command_id;
    uint8_t len;
    uint8_t ota_cmd;
}__attribute__((packed)) OTACode;

typedef struct 
{
  uint8_t command_id;
  uint8_t len;
  uint8_t ack;  
}__attribute__((packed)) OTAResponse;

typedef struct 
{
  uint8_t command_id;
  uint8_t len;
  uint8_t name[50];
  uint8_t version[5];  
}__attribute__((packed)) OTAInfor;

typedef struct 
{
  uint8_t command_id;
  uint8_t len;
  uint8_t data[16];  
}__attribute__((packed)) OTAData;

#endif