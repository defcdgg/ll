#ifndef _SAVE_H
#define _SAVE_H

#include "gba/types.h"

s32 Save_Fsm(u8);
void Save_FillSlot0(u8);
void Save_FillSlot1();
void Save_FillSlot2();
void Save_FillSlot3(u8);

#endif