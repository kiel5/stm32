#include "gettemp_ci.h"
#include "response.h"
#include "lm35.h"

void gettemp_ci(char **arg_v, uint8_t arg_num)
{
    if(arg_num < 2)
    {
        response_print("dont enough, arg = %d",arg_num);
        return;
    }
    if(arg_num > 2)
    {
        response_print("too much, arg = %d",arg_num);
        return;
    }
    
    uint8_t channal = atoi(arg_v[1]);
    response_print("temp = %d\n",(uint8_t)gettemp_lm35(channal));
}
