#ifndef UART_FRAME_H
#define UART_FRAME_H

#ifndef UART_FRAME_LENGTH
#define __UART__FRAME_LENGTH__ 64
#else
#define __UART__FRAME_LENGTH__ UART_FRAME_LENGTH
#endif

#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
typedef struct
{
    uint16_t preamble;
    uint8_t len;
    uint8_t command;
    uint8_t	*data;
    uint16_t crc;

} uart_frame_t;

bool uart_frame_init(uart_frame_t *frame, uint32_t data_size);
static inline void uart_frame_free(uart_frame_t *frame)
{
    free(&frame->data);
}


#endif
