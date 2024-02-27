#include "app_led.h"
#include "led_drive.h"
#include "stdint.h"
typedef enum {
    LED_IDLE_STATUS,
    LED_OFF_ALL_STATUS,
    LED_ON_ALL_STATUS,
    LED_BLINK_STATUS,
    LED_LIGHT_UP_STATUS
}LED_STATE_NAME;
typedef struct 
{
    LED_STATE_NAME led_state_name;
    uint16_t time;
    uint16_t tick;
    union 
    {
        struct
        {
            uint8_t sta;
        }blink;
        struct 
        {
            uint8_t index;
            uint8_t direct;
            uint8_t sta;
        }light_up;   
    }effect;
}AppLedState;

static AppLedState  app_led_state;
void app_led_init(void )
{
    app_led_state.led_state_name = LED_IDLE_STATUS;
}
void app_led_excute()
{
    switch (app_led_state.led_state_name)
    {
    case LED_BLINK_STATUS:
        app_led_state.effect.blink.sta != app_led_state.effect.blink.sta;
        set_all_led(app_led_state.effect.blink.sta);
        break;
    case LED_LIGHT_UP_STATUS:
        set_led(app_led_state.effect.light_up.index,app_led_state.effect.light_up.direct);  // bật led thứ index, ban đầu =0;
        app_led_state.effect.light_up.index += app_led_state.effect.light_up.direct;        //tăng index
        if(app_led_state.effect.light_up.index > 7)    //bật xog 8 led thì đổi chiều ngc lại
        {
            app_led_state.effect.light_up.sta = 0;
            app_led_state.effect.light_up.direct = -1;
        }
        if(app_led_state.effect.light_up.index < 0)    // tắt xog 8 led thì lại bật                         
        {
            app_led_state.effect.light_up.sta = 1;
            app_led_state.effect.light_up.direct = 1;
        }
    default:
        break;
    }
}
void app_led_handle(){
    if(app_led_state.led_state_name != LED_IDLE_STATUS)
    {
        if(HAL_GetTick() - app_led_state.tick >= app_led_state.time)
        {
            app_led_excute();
            app_led_state.tick = HAL_GetTick();
        }

    }
}

void app_led_blink_all(uint16_t freq)
{
    app_led_state.led_state_name = LED_BLINK_STATUS;
    app_led_state.time = freq;
}
void app_led_blink_led(uint16_t freq)
{

}
void app_led_light_up(uint16_t freq)
{
    app_led_state.led_state_name = LED_LIGHT_UP_STATUS;
    app_led_state.time= freq;                           //time
    app_led_state.effect.light_up.index = 0;            // chỉ số
    app_led_state.effect.light_up.direct = 1;           //chiều tăng
    app_led_state.effect.light_up.sta = 1;              //trạng thái bật
}

