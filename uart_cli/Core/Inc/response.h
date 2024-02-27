/*
 * response.h
 *
 *  Created on: May 16, 2023
 *      Author: kien
 */

#ifndef INC_RESPONSE_H_
#define INC_RESPONSE_H_
#include "stdio.h"
#include "stm32f1xx_hal.h"
#include <stdarg.h>

void response_print(const char* str,...);
void response_init(UART_HandleTypeDef* _huart_print);
#endif /* INC_RESPONSE_H_ */
