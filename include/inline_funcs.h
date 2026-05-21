#ifndef INLINE_FUNCS_H
#define INLINE_FUNCS_H

#include "gba/types.h"
#include "gba/gba.h"

static inline void ClearBuffer(u16 *buf, u8 w, u8 h)
{
    u16 x, y;
    u16 *temp_buf;
    for (y = 0; y < h; y++)
    {
        temp_buf = buf;

        for (x = 0; x < w; x++)
        {
            *buf++ = 0xB001;
        }
        buf = temp_buf + 0x20;
    }
}

static inline void SetBgUnknown1(u16 *buf, u16 val)
{
    *buf = val;
}

static inline void SetBgUnknown(u16 *buf, u16 val)
{
    *buf = val + 0xb240;
}


static inline void CpuCopy(void *src, void *dst, u32 size)
{
    CpuFastCopy(src, dst, size);
}

#endif // INLINE_FUNCS_H


