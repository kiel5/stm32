//dk bat tat led

#ifndef  LED_DRIVE_H
#define LED_DRIVE_H

#include "stm32f1xx_hal.h"
void set_led(uint8_t index,uint8_t status);
void toggle_led(uint8_t index);
void set_all_led(uint8_t sta);
void led_drive_init(void);

#endif