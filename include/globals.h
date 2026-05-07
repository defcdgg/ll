#ifndef GUARD_GLOBALS_H
#define GUARD_GLOBALS_H

#include "ewram.h"
#include "gba/types.h"
#include "iwram.h"

#define A_BUTTON      0x0001
#define B_BUTTON      0x0002
#define SELECT_BUTTON 0x0004
#define START_BUTTON  0x0008
#define DPAD_RIGHT    0x0010
#define DPAD_LEFT     0x0020
#define DPAD_UP       0x0040
#define DPAD_DOWN     0x0080
#define R_BUTTON      0x0100
#define L_BUTTON      0x0200
#define RESET_GAME    0x000F

#define KEYS_MASK     0x03FF
#define KEY_OR_INTR   0x0000
#define KEY_AND_INTR  0x8000
#define JOY_EXCL_DPAD 0x030F

typedef void (*IntrFunc)(void);
typedef void (*GameFunc)(void);

// GameFunc gGameFuncTable[] = {
//     sub_08003088
// };

// GameFunc gUnk_087E83F8[] = {
//     sub_8001538
// };

static inline void inl_cpufastset(void *src, void *dst, u32 sz)
{
    CpuFastCopy(src, dst, sz);
}

extern void IntrMain();

#endif /* GUARD_GLOBALS_H */
