#include "cli_command.h"
#include "cli_command_table.h"
#include "cli_type.h"

extern const cli_command_entry_t command_entry_table[];
cli_command_info_t *find_command_info(char *cmd)//khai báo hàm trả về con trỏ 
{
   const cli_command_entry_t *command_entry = command_entry_table; // con trỏ kiểu dữ liệu cm_infor, trỏ tới table
   if(strcmp(cmd,"help")==0)//in lần lượt các text
   {
    while(command_entry->command_info!= NULL)
    {
        response_print(command_entry->command_info->help);
        response_print("\n");
        command_entry++;
    }
  
   }
   else if(strcmp(cmd,"help") != 0)
   {
   while(command_entry->command_info != NULL)           
   {
    if(strcmp(command_entry->name,cmd) == 0)
    {
        return command_entry->command_info; // thực hiện lệnh
    }
    command_entry++;
   }
   response_print("find not found command");
   }
   return NULL; // 
}

void cli_command_excutive(char *uart_buff,uint8_t len){
        char* argv[10];
        uint8_t arg_num=0;
        char* pch; //tach chuoi
        pch = strtok((char*)uart_buff," ");
        while(pch != NULL)
        {   
            argv[arg_num] = pch;
            pch = strtok(NULL, " ");
            arg_num++; 
        }
        const cli_command_info_t *command_infor = find_command_info(argv[0]); // khai báo con trỏ cm_infor = con trỏ hàm 
        if(command_infor != NULL)
        {
            command_infor->function(argv,arg_num);
        }    

}   