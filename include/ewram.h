#ifndef _EWRAM_H
#define _EWRAM_H

#include "gba/types.h"

extern u8 gUnk_02004000[];
extern u8 gUnk_02005380[];

#define VRAM_BUF_2005000 (u16*)0x2005000
#define VRAM_BUF_2005800 (u16*)0x2005800

#endif