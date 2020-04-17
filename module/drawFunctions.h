#ifndef DRAWFUCNTIONS_H
#define DRAWFUCNTIONS_H

#ifndef __KERNEL__
#include <stdint.h>
#include <stdbool.h>
#endif

#include "epd1in54.h"
#include "epdif.h"
#include "Lucida_Console_8pts.h"

// uint8_t imageBuf[5000] = {0};
extern uint8_t imageBuffer[200][25];

#define DISP_WHITE 0
#define DISP_BLACK 1

#define BYTE_TO_BINARY_PATTERN "%c%c%c%c%c%c%c%c"
#define BYTE_TO_BINARY(byte)  \
  (byte & 0x80 ? '1' : '0'), \
  (byte & 0x40 ? '1' : '0'), \
  (byte & 0x20 ? '1' : '0'), \
  (byte & 0x10 ? '1' : '0'), \
  (byte & 0x08 ? '1' : '0'), \
  (byte & 0x04 ? '1' : '0'), \
  (byte & 0x02 ? '1' : '0'), \
  (byte & 0x01 ? '1' : '0') 

#endif