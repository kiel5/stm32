/*
 * cli_command.c
 *
 *  Created on: May 16, 2023
 *      Author: kien
 */
#include "cli_command.h"
#include "response.h"
#include <get_temperature_fb.h>
void cli_command_executive(char* uart_buff, uint8_t len){
			char* arg_value[10];
			uint8_t arg_num = 0;
	// tách dữ liệu
			char* pch;
			pch = strtok(uart_buff," ");
			while(pch != NULL){

				arg_value[arg_num++] = pch;
				pch = strtok(NULL, " ");
			}
			if(strcmp(arg_value[0],"gettemp")== 0){
				gettemp(arg_value,arg_num);
			}
			else if(strcmp(arg_value[0],"gettempMax")== 0){
			//	settempMax(arg_value,arg_num);
			}
			else if(strcmp(arg_value[0],"gettempMin")== 0){
				//settempMin(arg_value,arg_num);
					}
}

