#ifndef GENERIC_UTILS_H
#define GENERIC_UTILS_H
#include <stdlib.h>
#include <stdio.h>
#include "string.h"
#include "math.h"

//make string all nulls
#ifndef nullStr
#define nullStr(str, size) memset(str, '\0', size)
#endif


#ifndef GET_HIGH_NIBBLE
#define GET_HIGH_NIBBLE(_UINT8) (((_UINT8) & 0xf0) >> 4)
#endif

#ifndef GET_LOW_NIBBLE
#define GET_LOW_NIBBLE(_UINT8) ((_UINT8)  & 0x0fu)
#endif

#ifndef GET_HIGH_BYTE
#define GET_HIGH_BYTE(_UINT16) (((_UINT16)&0xff00u) >> 8u)

#endif
#ifndef GET_LOW_BYTE
#define GET_LOW_BYTE(_UINT16) (((_UINT16)&0x00FF))
#endif

#ifndef GET_N_BYTE
#define GET_N_BYTE(num, byte) (((num) >> (8*(byte))) & 0xFF)
#endif

//zero an array
#ifndef zeroArr
#define zeroArr(arr, size) memset(arr, 0, size)
#endif

//get fractional value as percenage
#ifndef asPercentageInt
#define asPercentageInt(num, den) (int)round((100 * (((double)num) / den)))
#endif

#ifndef asPercentageFloat
#define asPercentageFloat(num, den) (float)(100 * (((double)num) / den))
#endif

// get array length
#ifndef ARRAY_SIZE
#define ARRAY_SIZE(arr) (sizeof(arr) / (sizeof(arr[0])))
#endif

//check to see if a number is hard within the limits
#ifndef inBounds
#define inBounds(x, lower, upper) ((lower <= x) && (x <= upper))
#endif

//macro to check if a number is in a number within bounds plus some tolerance
#ifndef inTolerance
#define inTolerance(x, nominal, tolerance) inBounds(x, nominal - tolerance, nominal + tolerance)
#endif

//get average of two values
#ifndef average2
#define average2(x, y) ((double)((x) + (y)) / 2.0)
#endif

//macro to get decimal value of a float up to the given place
#ifndef getDecimalPlace
#define getDecimalPlace(f, place) ((int)(((f) - (int)(f)) * pow(10, (place))))
#endif

#ifndef CHECKFLAG
#define CHECKFLAG(condition) ( \
    {                          \
        if (condition)         \
        {                      \
            condition = false; \
            return true;       \
        }                      \
        else                   \
        {                      \
            return false;      \
        }                      \
    })
#endif

//get boolean true or false to check if year is leap year
#ifndef IS_LEAP_YEAR
#define IS_LEAP_YEAR(year) ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0)
#endif

//get max between two numbers
#ifndef max
#define max(a, b) (a > b ? a : b)
#endif

//get min between two numbers
#ifndef min
#define min(a, b) (a < b ? a : b)
#endif

// return 1 if little endian
#ifndef isLittleEndian
#define isLittleEndian() (((*(short *)"21") & 0xFF) == '2')
#endif

// return 1 if big endian
#ifndef IsBigEndian
#define IsBigEndian() (((*(short *)"21") & 0xFF) == '1')
#endif

#ifndef AS_STRING
#define AS_STRING(x) #x
#endif

#ifndef MAKE_U16
#define MAKE_U16(high_byte, low_byte) (high_byte << 8 | low_byte)
#endif

#ifndef GENERIC_MAP
#define GENERIC_MAP(in, out_low, out_high, in_low, in_high)\
    (((out_high) - (out_low)) / ((in_high) - (in_low)) * ((in) - (in_low)) + (out_low))
#endif

#ifndef IS_EVEN
#define IS_EVEN(x) (~((x) & 0b1))
#endif

#ifndef IS_ODD
#define IS_ODD(x) ((x) & 0b1)
#endif




#endif