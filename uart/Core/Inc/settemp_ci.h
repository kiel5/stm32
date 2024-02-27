#ifndef SETTEMP_CI_H
#define SETTEMP_CI_H

#include "stdint.h"
#include "stm32f1xx_hal.h"
#include "string.h"

void settempMax(char **arg_v, uint8_t arg_num);
void settempMix(char **arg_v, uint8_t arg_num);
#endif