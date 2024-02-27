#include "uart.h"
#include "gettemp_ci.h"
#include "cli_command.h"
#include "response.h"
#define MAX_DATA_UART 100


static char uart_buff[MAX_DATA_UART];
static uint8_t uart_len=0;
uint8_t uart_flag =0;
void receive_data(uint8_t data_rx)
{
    if(data_rx == '\n')
    {
        uart_buff[uart_len++]='\0';
        uart_flag = 1;
    }
    else 
    {
        uart_buff[uart_len++] = data_rx;
    }
}
void uart_init();   
void uart_handle()
{
    if(uart_flag)
    {
        cli_command_excutive(uart_buff,uart_len);
        uart_flag = 0;
        uart_len = 0;
    }
}
