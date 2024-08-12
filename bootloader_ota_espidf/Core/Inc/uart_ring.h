#ifndef UART_RING_H
#define UART_RING_H

#include "stdint.h"

void uart_receive(uint8_t data_rx);//trong hàm callback uart gọi hàm này để lấy dữ liệu rồi push vào buffer
void uart_init(void);// hàm khởi tạo buffer
uint16_t uart_available();//hàm check data có trong buffer hay không
uint8_t uart_read();//hàm lấy data trong buffer

#endif