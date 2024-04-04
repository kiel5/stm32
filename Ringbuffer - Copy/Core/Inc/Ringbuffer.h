#ifndef RINGBUFFER_H
#define RINGBUFFER_H

#include "stdint.h"

typedef struct 
{
    uint8_t * const buffer;
    uint16_t head;
    uint16_t tail;
    uint16_t maxlen;
}Ringbuffer;

void ring_buff_init(Ringbuffer *ring_buff,uint8_t *buff, uint16_t len);
uint8_t ring_buff_push(Ringbuffer *ring_buff, uint8_t data);
uint8_t ring_buff_pop(Ringbuffer *ring_buff, uint8_t *data);
uint16_t ring_buff_available(Ringbuffer *ring_buff);
#endif