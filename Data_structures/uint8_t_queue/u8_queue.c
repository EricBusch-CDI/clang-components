/*
 * u8_queue.c
 *
 * Created: 10/22/2021 1:39:15 PM
 *  Author: EricB
 */
#include "u8_queue.h"


bool u8_queue_enqueue (u8_queue_t *queue, uint8_t byte)
{
    bool did_queue = false;

    if (!u8_queue_is_full (queue))
    {
        queue->rear = (queue->rear + 1) % U8_QUEUE_CAPACITY;
        queue->data[queue->rear] = byte;
        queue->size += 1;
    }

    return did_queue;
}
bool u8_queue_dequeue (u8_queue_t *queue, uint8_t *byte)
{
    bool did_dequeue = false;
    if (!u8_queue_is_empty (queue))
    {
        *byte = queue->data[queue->front];
        queue->front = (queue->front + 1) % U8_QUEUE_CAPACITY;
        queue->size -= 1;
        did_dequeue = true;
    }



    return did_dequeue;
}
bool u8_queue_front (u8_queue_t *queue, uint8_t *byte);
bool u8_queue_rear (u8_queue_t *queue, uint8_t *byte);
