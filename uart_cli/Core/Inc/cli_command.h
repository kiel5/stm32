/*
 * cli_command.h
 *
 *  Created on: May 16, 2023
 *      Author: kien
 */

#ifndef INC_CLI_COMMAND_H_
#define INC_CLI_COMMAND_H_
#include "stm32f1xx_hal.h"
#include "string.h"
void cli_command_executive(char* uart_buff, uint8_t len);

#endif /* INC_CLI_COMMAND_H_ */
