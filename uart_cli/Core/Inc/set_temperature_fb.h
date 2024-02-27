/*
 * set_temperature_fb.h
 *
 *  Created on: May 16, 2023
 *      Author: kien
 */

#ifndef INC_SET_TEMPERATURE_FB_H_
#define INC_SET_TEMPERATURE_FB_H_

#include "stm32f1xx_hal.h"

void settempMax(char **arg_value, uint8_t arg_num);
void settempMin(char **arg_value, uint8_t arg_num);
#endif /* INC_SET_TEMPERATURE_FB_H_ */
