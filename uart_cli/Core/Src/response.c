/*
 * response.c
 *
 *  Created on: May 16, 2023
 *      Author: kien
 */
#include <response.h>
#include "string.h"
static UART_HandleTypeDef *huart_print;

void response_print(const char* str,...){
		char stringArray[100];
		va_list args;
		va_start(args,str);
		vsprintf(stringArray, str, args);
		va_end(args);

		HAL_UART_Transmit(huart_print, (uint8_t*)stringArray, strlen(stringArray), 200);
}
void response_init(UART_HandleTypeDef* _huart_print)
{
	huart_print =_huart_print;
}

