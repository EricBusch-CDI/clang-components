/*
 * crc.c
 *
 * Created: 9/10/2021 10:25:39 AM
 *  Author: eric.busch
 */

#include "crc16.h"


uint16_t crc16 (uint8_t dataLength, uint8_t command, uint8_t *data)
{
    uint16_t polynomial = 0x8005;	/* As per datasheet */
    uint16_t crc = 0xFFFF;			/* Initial value */
    uint8_t i, j;

    crc ^= ( (uint16_t) dataLength << 8);
    for (j = 0; j < 8; j++)
    {
        if ( (crc & 0x8000) != 0)
        {
            crc = (crc << 1) ^ polynomial;
        }
        else
        {
            crc <<= 1;
        }
    }

    crc ^= ( (uint16_t) command << 8);
    for (j = 0; j < 8; j++)
    {
        if ( (crc & 0x8000) != 0)
        {
            crc = (crc << 1) ^ polynomial;
        }
        else
        {
            crc <<= 1;
        }
    }

    for (i = 0; i < dataLength; i++)
    {
        crc ^= ( (uint16_t) (data[i]) << 8);
        for (j = 0; j < 8; j++)
        {
            if ( (crc & 0x8000) != 0)
            {
                crc = (crc << 1) ^ polynomial;
            }
            else
            {
                crc <<= 1;
            }
        }
    }

    return crc;
}

