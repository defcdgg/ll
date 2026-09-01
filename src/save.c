
#include "save.h"
#include "code_0.h"
#include "gba/defines.h"
#include "gba/gba.h"
#include "globals.h"
#include "include_asm.h"
#include "m4a.h"

s32 Save_Fsm(u8 arg0)
{

    switch (gUnk_03004D44)
    {

        case 0x1:
            ReadSram((u8 *)SRAM + (gUnk_03004DD0 << 0xB), (u8 *)0x02021000 + (gUnk_03004DD0 << 0xB), 0x800);
            gUnk_03004D44++;
            return 1;

        case 0x2:
            if (VerifySram((u8 *)(gUnk_03004DD0 << 0xB) + 0x02021000, (u8 *)SRAM + (gUnk_03004DD0 << 0xB), 0x800) != 0)
            {
                gUnk_03004D44 = 0xFD;
            }
            else
            {
                if (gUnk_03004DD0 <= 0xE)
                {
                    gUnk_03004D44--;
                }
                else
                {
                    gUnk_03004D44 = 0xF9;
                }
                gUnk_03004DD0++;
            }
            return 1;

        case 0x3:
            WriteSram((u8 *)(gUnk_03004DD0 << 0xB) + 0x02021000, (u8 *)SRAM + (gUnk_03004DD0 << 0xB), 0x800);
            gUnk_03004D44++;
            return 1;

        case 0x4:
            if (VerifySram((u8 *)(gUnk_03004DD0 << 0xB) + 0x02021000, (u8 *)SRAM + (gUnk_03004DD0 << 0xB), 0x800) != 0)
            {
                gUnk_03004D44 = 0xFD;
                Msg_ShowById(0x27, 0xB);
                if (gMenuCursorSel > 5U)
                {
                    gMenuCursorSel = gSaveCurSlot + 3;
                    sub_800E668(0xFF);
                }
            }
            else
            {
                if (gUnk_03004DD0 <= 0xE)
                {
                    gUnk_03004D44--;
                }
                else
                {
                    gUnk_03004D44 = 0xFF;
                    Msg_ShowById(0x19, 0xB);
                    if (gMenuCursorSel > 5)
                    {
                        gMenuCursorSel = gSaveCurSlot + 3;
                        sub_800E668(0xFF);
                    }
                }
                gUnk_03004DD0++;
            }
            return 1;

        case 0xF9:
            Save_FillSlot0(0);
            gUnk_03004D44 = 0xFA;
            return 1;

        case 0xFA:
            Save_FillSlot0(1);
            gUnk_03004D44 = 0xFB;
            return 1;

        case 0xFB:
            Save_FillSlot0(2);
            gUnk_03004D44 = 0xFC;
            return 1;

        case 0xFC:
            Save_FillSlot0(3);
            gUnk_03004D44 = 0xFF;
            return 1;

        case 0xFD:
            *(u8 *)0x02021000 = 0xFF;
            *(u8 *)0x02023000 = 0xFF;
            *(u8 *)0x02025000 = 0xFF;
            *(u8 *)0x02027000 = 0xFF;
            gUnk_03004D44 = 0xFF;
            return 1;

        case 0xFF:
            if (arg0 == 0)
            {
                SaveUi_DrawSlots();
            }
            gUnk_03004D44 = 0xFE;
            return 1;

        default:
            return 0;
    }
}

INCLUDE_ASM("asm/matchings", Save_FillSlot0);
INCLUDE_ASM("asm/matchings", Save_FillSlot1);
INCLUDE_ASM("asm/matchings", Save_FillSlot2);
INCLUDE_ASM("asm/matchings", Save_FillSlot3);