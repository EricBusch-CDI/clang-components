/*
 * crc.h
 *
 * Created: 9/10/2021 10:25:28 AM
 *  Author: eric.busch
 */


#ifndef CRC16_H_
#define CRC16_H_

#include <stdint.h>

uint16_t crc16 (uint8_t dataLength, uint8_t command, uint8_t *data);


#endif /* CRC_H_ */