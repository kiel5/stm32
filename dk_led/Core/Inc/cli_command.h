#ifndef CLI_COMMAND_H
#define CLI_COMMAND_H
 
#include "string.h"
#include "stdint.h"
#include "response.h"
#include "gettemp_ci.h"

void cli_command_excutive(char *uart_buff,uint8_t len);


#endif