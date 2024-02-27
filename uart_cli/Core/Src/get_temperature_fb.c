/*
 * gettempure_fb.c
 *
 *  Created on: May 15, 2023
 *      Author: kien
 */
#include "get_temperature_fb.h"
#include "response.h"
#include "sensor.h"
#include "stdlib.h"
extern UART_HandleTypeDef huart1;
void gettemp(char **arg_value, uint8_t arg_num){
	if(arg_num <2 || arg_num >2){
		response_print("don't enough");
	    return;
	}
	else response_print("ok\n");
	uint8_t channal= atoi(arg_value[1]);
	response_print("temp = %f",get_sensor(channal));
}


