#include "Ringbuffer.h"

void ring_buff_init(Ringbuffer *ring_buff,uint8_t *buff, uint16_t len)
{
    ring_buff->buffer = buff;
    ring_buff->head = 0;
    ring_buff->tail = 0;
    ring_buff->maxlen = len; 
}
uint8_t ring_buff_push(Ringbuffer *ring_buff, uint8_t data)
{
    uint16_t next;
    next = ring_buff->head +1;
    if(next >= ring_buff->maxlen)
    {
        next = 0;
    }
    if(next == ring_buff->tail)
    {
        return -1;
    }
    ring_buff->buffer[ring_buff->head] = data;
    ring_buff->head = next;
    return 0; 
}
uint8_t ring_buff_pop(Ringbuffer *ring_buff, uint8_t *data)
{
    uint8_t next;
    if(ring_buff->head == ring_buff->tail) return -1;
    next = ring_buff->tail +1;
    if(next >=ring_buff->maxlen)           next = 0;
    *data = ring_buff->buffer[ring_buff->tail];
    ring_buff->tail = next;
    return 0;
}

uint16_t ring_buff_available(Ringbuffer *ring_buff)
{
    if(ring_buff->head < ring_buff->tail){
        return ring_buff->maxlen - (ring_buff->tail - ring_buff->head);
    }
    return (ring_buff->head - ring_buff->tail); 
}