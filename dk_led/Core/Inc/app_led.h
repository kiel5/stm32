// dk hieu ung led
#ifndef  APP_LED_H
#define APP_LED_H
#include "stdint.h"

void app_led_blink_led(uint16_t freq);
void app_led_init(void);
void app_led_handle(void);
void app_led_blink_all(uint16_t freq);
void app_led_light_up(uint16_t freq);
#endif