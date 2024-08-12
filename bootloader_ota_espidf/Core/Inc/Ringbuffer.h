#ifndef RINGBUFFER_H
#define RINGBUFFER_H

#include "stdint.h"

typedef struct // struct lưu bộ đệm buffer...
{
    uint8_t *buffer;
    uint16_t head;
    uint16_t tail;
    uint16_t maxlen;
}Ringbuffer; 

void     ring_buff_init(Ringbuffer *ring_buff,uint8_t *buff, uint16_t len); // hàm khởi tạo bộ đệm ban đầu
uint8_t  ring_buff_push(Ringbuffer *ring_buff, uint8_t data);// hàm đẩy dữ liệu vào bộ đệm
uint8_t  ring_buff_pop(Ringbuffer *ring_buff, uint8_t *data);//hàm lấy dữ liệu từ bộ đệm
uint16_t ring_buff_available(Ringbuffer *ring_buff);// hàm check dữ liệu trong bộ đệm
#endif