#include "lm35.h"

float gettemp_lm35(uint8_t channal)
{
    float temp = 40.5;
    if      (channal==0)      temp =10.5;
    else if (channal==1)temp =20.5;
    else temp=0;
    return temp;
}