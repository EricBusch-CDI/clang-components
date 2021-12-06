/*
 * u8_queue.h
 *
 * Created: 10/22/2021 1:38:58 PM
 *  Author: EricB
 */


#ifndef U8_QUEUE_H_
#define U8_QUEUE_H_

#include <stdbool.h>
#include <stdint.h>

#define U8_QUEUE_CAPACITY 512

typedef struct
{
    uint16_t front, rear, size;
    uint8_t data[U8_QUEUE_CAPACITY];
} u8_queue_t;

#define U8_QUEUE_INIT() \
{\
	.front = 0,\
	.size = 0,\
	.rear = U8_QUEUE_CAPACITY - 1,\
	.data = {0}\
}

static inline bool u8_queue_is_full (u8_queue_t *queue)
{
    return (queue->size == U8_QUEUE_CAPACITY);
}
static inline bool u8_queue_is_empty (u8_queue_t *queue)
{
    return (queue->size == 0);
}
/**
 * \brief Function to add a byte to a queue
 *
 * \param queue containing data
 *
 * \return true if data successfully queued false otherwise
 */
bool u8_queue_enqueue (u8_queue_t *queue, uint8_t byte);

/**
 * \brief queue to retrieve byte from queue
 *
 * \param queue containing data
 * \param byte to place the data in
 *
 * \return true if successfully dequeued false otherwise
 */
bool u8_queue_dequeue (u8_queue_t *queue, uint8_t *byte);
/**
 * \brief queue to get first byte from queue. Does not dequeue
 *
 * \param queue containing data
 * \param byte to place the data in
 *
 * \return true if byte retrieved, false otherwise
 */
bool u8_queue_front (u8_queue_t *queue, uint8_t *byte);
/**
 * \brief queue to get last byte from queue. Does not dequeue
 *
 * \param queue containing data
 * \param byte to place the data in
 *
 * \return true if byte retrieved, false otherwise
 */
bool u8_queue_rear (u8_queue_t *queue, uint8_t *byte);



#endif /* U8_QUEUE_H_ */