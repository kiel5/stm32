#include "uart_ring.h"
#include "Ringbuffer.h"
#define UART_RING_LEN 128

uint8_t buff_uart[UART_RING_LEN];
Ringbuffer ringbuff;
 
void uart_receive(uint8_t data_rx)
{
    ring_buff_push(&ringbuff,data_rx);
}
uint16_t uart_available()
{
    return ring_buff_available(&ringbuff);
}
uint8_t uart_read()
{
    uint8_t data;
    ring_buff_pop(&ringbuff,&data);
    return data;
}
void uart_init(void)
{
    ring_buff_init(&ringbuff,buff_uart,UART_RING_LEN);
}
