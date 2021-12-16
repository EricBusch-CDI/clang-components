#include "uart_frame.h"

bool uart_frame_init(uart_frame_t *frame, uint32_t data_size)
{
    frame->data = (uint8_t *) malloc(data_size);

    if(frame->data == NULL)
    {
    	return false;
    }
    else
    {
    	return true;
    }
}
