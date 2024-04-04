#include "setEffect_led_ci.h"
#include "response.h"
#include "stdlib.h"
#include "app_led.h"
void setEffect_led(char **arg_v, uint8_t arg_num)// dùng char** cho mảng chuỗi
{
    uint8_t index_effect = atoi(arg_v[1]);
    if(index_effect == 1)
    {
        uint16_t freq = atoi(arg_v[2]);
        app_led_blink_all(freq);
        response_print("ok man");
    }
    if(index_effect == 2)
    {
        uint16_t freq = atoi(arg_v[2]);
        app_led_light_up(freq);
        response_print("ok man");
    }
    
} 