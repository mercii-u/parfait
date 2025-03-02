#ifndef PARFAIT_COMMON_H
#define PARFAIT_COMMON_H

#include <stdio.h>

#define true    1
#define false   -1

typedef unsigned char   u8_t;
typedef unsigned short  u16_t;
typedef unsigned int    u32_t;
typedef unsigned long   u64_t;

typedef signed char     s8_t;
typedef signed short    s16_t;
typedef signed int      s32_t;
typedef signed long     s64_t;

typedef signed char     bool;

struct program
{
    struct
    {
        char    *filename;
        bool    readonly;
    } args;
};




#endif
