//mỗi lần thay k phải sửa 
#include "led_drive.h"
#include "string.h"
#include "stdint.h"

void set_led(uint8_t index,uint8_t status)
{
    HAL_GPIO_WritePin(GPIOA,GPIO_PIN_0 << index,(GPIO_PinState)status);
}
void toggle_led(uint8_t index)
{
    HAL_GPIO_TogglePin(GPIOA,GPIO_PIN_0<< index);
}
void set_all_led(uint8_t sta)
{
    for(uint8_t i=0;i<8;i++)
    {
        set_led(i,sta);
    }
}
