#ifndef CLI_TYPE_H
#define CLI_TYPE_H
#include"stdint.h"
#include "string.h"
#include "cli_command_table.h"


typedef void (*cli_command_func_t)(char **arg,uint8_t arg_num);// định nghĩa kiểu dữ liệu con trỏ hàm
typedef struct 
{
    cli_command_func_t function;
    char               *help_description;
}cli_command_info_t;                            //infor chứa con trỏ hàm và mô tả lệnh khi response
typedef struct 
{
    const char                 *name;
    const cli_command_info_t   *command_info;
}cli_command_entry_t;                           // entry chứa tên lệnh và infor


#endif