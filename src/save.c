
#include "save.h"
#include "code_0.h"
#include "gba/defines.h"
#include "gba/gba.h"
#include "globals.h"
#include "include_asm.h"
#include "m4a.h"

s32 sub_80109F8(u8 arg0)
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
                sub_8016508(0x27, 0xB);
                if (gUnk_03000187 > 5U)
                {
                    gUnk_03000187 = gUnk_03000220 + 3;
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
                    sub_8016508(0x19, 0xB);
                    if (gUnk_03000187 > 5)
                    {
                        gUnk_03000187 = gUnk_03000220 + 3;
                        sub_800E668(0xFF);
                    }
                }
                gUnk_03004DD0++;
            }
            return 1;

        case 0xF9:
            sub_8010BEC(0);
            gUnk_03004D44 = 0xFA;
            return 1;

        case 0xFA:
            sub_8010BEC(1);
            gUnk_03004D44 = 0xFB;
            return 1;

        case 0xFB:
            sub_8010BEC(2);
            gUnk_03004D44 = 0xFC;
            return 1;

        case 0xFC:
            sub_8010BEC(3);
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
                sub_8015F14();
            }
            gUnk_03004D44 = 0xFE;
            return 1;

        default:
            return 0;
    }
}

INCLUDE_ASM("asm/nonmatchings", sub_8010BEC); // Matched
INCLUDE_ASM("asm/nonmatchings", sub_8010CCC); // Matched
INCLUDE_ASM("asm/nonmatchings", sub_8010D80); // Matched
INCLUDE_ASM("asm/nonmatchings", sub_8010E58); // Matched