#include "cli_command_table.h"
#include "cli_type.h"
#include "gettemp_ci.h"
#include "settemp_ci.h"
#include "setEffect_led_ci.h"

const cli_command_info_t command_info_gettemp =
{
    gettemp_ci,              // con trỏ hàm
    "gettemp from lm35"      // text help
};
const cli_command_info_t command_info_settempMax =
{
    settempMax,
    "settempMax from lm35"
};
const cli_command_info_t command_info_settempMin =
{
    settempMix,
    "settempMin from lm35"
};
const cli_command_info_t command_info_setEfectLed =
{
    setEffect_led,
    "setEfectLed"
};
const cli_command_entry_t command_entry_table[]=   // khởi tạo mảng table( với kiểu dữ liệu cm_entry) chứa tên lệnh và infor
{
   {"gettemp"   ,&command_info_gettemp},              //phần tử thứ 0
   {"settempMax",&command_info_settempMax},
   {"settempMin",&command_info_settempMin},
   {"setEffect", &command_info_setEfectLed},
   {NULL,NULL}
};