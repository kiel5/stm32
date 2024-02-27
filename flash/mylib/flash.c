#include "flash.h"

void flash_unlock()
{
    HAL_FLASH_Unlock();
}
void flash_lock()
{
    HAL_FLASH_Lock();
}
void flash_erease(uint32_t add_page)// địa chỉ thuộc page là dc 
{
    FLASH_EraseInitTypeDef eraseInit;
    eraseInit.PageAddress =add_page;
    eraseInit.NbPages = 1;
    eraseInit.TypeErase = FLASH_TYPEERASE_PAGES;
    uint32_t PageError;
    HAL_FLASHEx_Erase(&eraseInit,&PageError); 
}
// ví dụ uin8_t a[]={1,2,3,4,5,6,7,8}
void flash_write_arr(uint32_t addr,uint8_t *data,uint16_t len)
{
    for(uint8_t i = 0; i<len ;i+=2)
    {
        HAL_FLASH_Program(FLASH_TYPEPROGRAM_HALFWORD,addr+i, data[i] | (uint16_t)data[i+1]<<8);
    }
}
void flash_read_arr(uint32_t addr,uint8_t *data,uint16_t len){
    for(uint16_t i = 0; i < len; i+=2)
    {
        uint16_t data_buff = *(volatile uint32_t *)(addr + i);// ép kiểu add thành con trỏ địa chỉ
        data[i]= data_buff;
        data[i+1] = data_buff>>8; 
    }
}
 
