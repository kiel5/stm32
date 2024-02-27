#ifndef RESPONSE_H
#define RESPONSE_H

#include "stdint.h"
#include "stm32f1xx_hal.h"
#include "string.h"
#include "stdarg.h"
#include "stdio.h"
void response_init(UART_HandleTypeDef *_huart_printf);
void response_print(const char* str, ...);
#endif