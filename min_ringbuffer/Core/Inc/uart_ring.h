#ifndef UART_RING_H
#define UART_RING_H

#include "stdint.h"
void uart_receive(uint8_t data_rx);
void uart_init(void);
uint16_t uart_available();
uint8_t uart_read();

#endif