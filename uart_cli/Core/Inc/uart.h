/*
 * uart.h
 *
 *  Created on: May 14, 2023
 *      Author: kien
 *      *** xử lí dữ liệu uart: nhận, tách dữ liệu
 */

#ifndef INC_UART_H_
#define INC_UART_H_

#include "stdint.h"
#include "stm32f1xx_hal.h"
#include "string.h"

void uart_receive(uint8_t c);
void uart_init(void);
void uart_handle(void);
#endif /* INC_UART_H_ */
