#include "response.h"
static UART_HandleTypeDef *huart_printf;

void response_print(const char* str, ...)    
{
    char stringArray[100];

    va_list args; // khai báo danh sách đối số biến đổi(args sẽ gồm str,...)
    va_start(args, str);  // khởi tạo args và trỏ đến vị trí của đối số đầu tiên trong danh sách args
    vsprintf(stringArray,str,args); // định dạng chuỗi kí tự
    va_end(args);   //dọn dẹp  
    HAL_UART_Transmit(huart_printf,(uint8_t*)stringArray,strlen(stringArray),100);
}
void response_init(UART_HandleTypeDef *_huart_printf)
{
    huart_printf = _huart_printf;
}
