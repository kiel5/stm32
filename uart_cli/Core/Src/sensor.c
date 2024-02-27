/*
 * sensor.c
 *
 *  Created on: May 16, 2023
 *      Author: kien
 */

#include "sensor.h"

float get_sensor(uint8_t channal)
{
	float temp = 0;
	if(channal == 0)     temp =20.5;
	else if(channal ==1) temp =50.7;
	return temp;
}
