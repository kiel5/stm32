#include "min.h"
#include "stm32f1xx.h"
#include "stm32f1xx_hal.h"

void min_tx_start(uint8_t port){}
void min_tx_finished(uint8_t port){}

void min_tx_byte(uint8_t port, uint8_t byte) // hàm tự định nghĩa mỗi chip
{
  USART1->DR = byte;
  while (!(USART1->SR & USART_SR_TC));
}
uint16_t min_tx_space(uint8_t port)
{
  return 512;
}
uint32_t min_time_ms(void)
{
    return HAL_GetTick();
}
