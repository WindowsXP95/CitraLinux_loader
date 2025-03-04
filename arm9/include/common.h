#pragma once

#include <inttypes.h>
#include <stddef.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>

#define u8 uint8_t
#define u16 uint16_t
#define u32 uint32_t
#define u64 uint64_t

#define vu8 volatile u8
#define vu16 volatile u16
#define vu32 volatile u32
#define vu64 volatile u64

#define max(a,b) \
    (((a) > (b)) ? (a) : (b))
#define min(a,b) \
    (((a) < (b)) ? (a) : (b))
#define getbe16(d) \
    (((d)[0]<<8) | (d)[1])
#define getbe32(d) \
    ((((u32) getbe16(d))<<16) | ((u32) getbe16(d+2)))
#define getbe64(d) \
    ((((u64) getbe32(d))<<32) | ((u64) getbe32(d+4)))
#define getle16(d) (*((u16*) (d)))
#define getle32(d) (*((u32*) (d)))
#define getle64(d) (*((u64*) (d)))
#define align(v,a) \
    (((v) % (a)) ? ((v) + (a) - ((v) % (a))) : (v))

// standard work area, size must be a multiple of 0x200 (512)
#define BUFFER_ADDRESS  ((u8*) 0x21000000)
#define BUFFER_MAX_SIZE ((u32) (1 * 1024 * 1024))

// log file name
#define LOG_FILE "citralinux_loader.log"

static inline u32 strchrcount(const char* str, char symbol) {
    u32 count = 0;
    for (u32 i = 0; str[i] != '\0'; i++) {
        if (str[i] == symbol)
            count++;
    }
    return count;
}
