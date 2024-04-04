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
    if(data_rx == '\n')  // nhan xong du lieu
    {
        uart_buff[uart_len++] = '\0'; // them ki tu \0 de tao chuoi   
        uart_flag = 1;
    }
    else // van dang nhan du lieu
    {
        uart_buff[uart_len++] = data_rx;
    }
}
void uart_init();   
void uart_handle()
{
    if(uart_flag)
    {
        cli_command_excutive(uart_buff,uart_len);// day du lieu sang file cli_command.c de thuc hien task khac
        uart_flag = 0;
        uart_len  = 0;
    }
}
