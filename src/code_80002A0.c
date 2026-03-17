#include "main.h"




IntrFunc const gIntrTable[] = {
    sub_8016FC0,
    sub_800065C,
    sub_800124C,
    DummyIntr4,
    DummyIntr3,
    DummyIntr3,
    DummyIntr3,
    DummyIntr3,
    DummyIntr3,
    DummyIntr3,
    DummyIntr3,
    DummyIntr3,
    DummyIntr3,
};


u8 const gUnk_080576D0[] = {
  0x00, 0x04, 0x09, 0x0e, 0x13, 0x18, 0x1d, 0x21, 0x26, 0x2a, 0x2f, 0x33,
  0x37, 0x3b, 0x3f, 0x43, 0x46, 0x4a, 0x4d, 0x50, 0x53, 0x55, 0x58, 0x5a,
  0x5c, 0x5e, 0x5f, 0x61, 0x62, 0x62, 0x63, 0x63, 0x64, 0x63, 0x63, 0x62,
  0x62, 0x61, 0x5f, 0x5e, 0x5c, 0x5a, 0x58, 0x55, 0x53, 0x50, 0x4d, 0x4a,
  0x46, 0x43, 0x3f, 0x3b, 0x37, 0x33, 0x2f, 0x2a, 0x26, 0x21, 0x1d, 0x18,
  0x13, 0x0e, 0x09, 0x04, 0x00, 0xfc, 0xf7, 0xf2, 0xed, 0xe8, 0xe3, 0xdf,
  0xda, 0xd6, 0xd1, 0xcd, 0xc9, 0xc5, 0xc1, 0xbd, 0xba, 0xb6, 0xb3, 0xb0,
  0xad, 0xab, 0xa8, 0xa6, 0xa4, 0xa2, 0xa1, 0x9f, 0x9e, 0x9e, 0x9d, 0x9d,
  0x9c, 0x9d, 0x9d, 0x9e, 0x9e, 0x9f, 0xa1, 0xa2, 0xa4, 0xa6, 0xa8, 0xab,
  0xad, 0xb0, 0xb3, 0xb6, 0xba, 0xbd, 0xc1, 0xc5, 0xc9, 0xcd, 0xd1, 0xd6,
  0xda, 0xdf, 0xe3, 0xe8, 0xed, 0xf2, 0xf7, 0xfc
};


void sub_80002A0(void) {
    u16 val;

    sub_8004ADC();
    
    switch (gUnk_03004698) 
    {
        case 1: 
            REG_BG1HOFS = 0;
            REG_BG1VOFS = 0;
            break;
        case 2: 
            gUnk_03002C40++;
            REG_BG1HOFS = (gUnk_03002C40 >> 1) & 0xFF;
            REG_BG1VOFS = 0;
            break;
        case 3: 
            gUnk_03002C40++;
            REG_BG1HOFS = (gUnk_03002C40 >> 2) & 0xFF;
            REG_BG1VOFS = 0x10;
            break;
        case 4: 
            REG_BG1HOFS = 0x40;
            REG_BG1VOFS = 0;
            break;
        case 5: 
            REG_BG1HOFS = (s16) ((u8) gUnk_030025B4 >> 3);
            REG_BG1VOFS = 0;
            break;
        case 6: 
            REG_BG1HOFS = 0;
            REG_BG1VOFS = 0x1E;
            break;
        default:
            REG_BG1HOFS =(0x1F &  gUnk_030025B4);
            REG_BG1VOFS = (0x1F & gUnk_030025FC);
            break;
    }
    
    REG_BG2HOFS = gUnk_03004848;
    REG_BG2VOFS = gUnk_03004828;
    REG_BG3HOFS = gUnk_0300484C;
    REG_BG3VOFS = gUnk_03004648;


    DmaCopy16(3, &gUnk_030035C0, 0x07000000, 0x400);

    sub_8002F6C();
    sub_8008D18();
    
    if (gUnk_03002604 == 0) {
        sub_805008C();
    }
    
    sub_800B14C();
    
    if (gUnk_03004800[13] != 0) {
        DmaCopy16(3, gUnk_02005380, 0x0600F380, 0x100);
        gUnk_03004800[13] = 0U;
    }

    REG_BLDCNT = gUnk_03004658;
    if(gUnk_03004658 & 0x80)
    {
        REG_BLDY = gUnk_03004550;
    }
    else
    {
        REG_BLDALPHA = gUnk_03004550;
    }

    sub_8005020();
    sub_80038CC();
    
    switch (gUnk_03004610) 
    {
        case 0:
        default:
            break;
        case 1:  
        case 3:  
            val = (gUnk_03001988 - 1) & 0x3FF;
            gUnk_03001988 = val;
            gUnk_03001B54 = (val >> 2) + gUnk_030025FC;
            break;
        case 2:  
        case 4:  
            val = (gUnk_03001988 - 1) & 0x7FF;
            gUnk_03001988 = val;
            gUnk_03001B54 = (val >> 3) + gUnk_030025FC;
    }
}


void sub_80004F8(void) {
    u16 val;

    REG_BG0HOFS = 0;
    REG_BG0VOFS = 0;
    REG_BG1HOFS = 0;
    REG_BG1VOFS = 0;
    REG_BG2HOFS = 0;
    REG_BG2VOFS = 0;
    REG_BG3HOFS = 0;
    REG_BG3VOFS = 0;

    DmaCopy16(3, &gUnk_030035C0, OAM, 0x400);

    REG_BLDCNT = gUnk_03004658;
    REG_BLDALPHA = gUnk_03004550;
    
    DmaCopy16(3, VRAM_BUF_2005800, 0x0600F800, 0x800);

    sub_8005020();
    val = (gUnk_03001988 - 1) & 0x3FF;
    gUnk_03001988 = val;
    gUnk_03001B54 = (val >> 2) + gUnk_030025FC;
}

INCLUDE_ASM(sub_80005A8)

void sub_800065C(void) {

    switch (gUnk_0300259C) 
    {
        case 1:
            m4aSoundVSync();
            sub_80002A0();
            break;
        case 2:
            m4aSoundVSync();
            sub_8018070();
            break;
        case 3:
            m4aSoundVSync();
            sub_80004F8();
            break;
        case 4:
            m4aSoundVSync();
            sub_8004ADC();
            
            REG_BG1HOFS = 0;
            REG_BG1VOFS = 0;
            REG_BG2HOFS = 4;
            REG_BG2VOFS = 0;
            REG_BG3HOFS = 4;
            REG_BG3VOFS = 0;
    
            REG_BLDCNT = gUnk_03004658;
            REG_BLDALPHA = gUnk_03004550;
    
            DmaCopy16(3, gUnk_030035C0, OAM, 0x400);
            DmaCopy16(3, VRAM_BUF_2005800, 0x0600F800, 0x800);
    
            if (gUnk_03004DC0 != 0)
            {
                DmaCopy16(3, VRAM_BUF_2005000, 0x0600F000, 0x800);
                gUnk_03004DC0 = 0;
            }
            
            sub_8005020();
            break;
        case 5:
            sub_8016F30();
            m4aSoundVSync();
            sub_8004ADC();
            sub_8003264();
            
            // CpuFastCopy(gUnk_030035C0, (u32*)0x07000000, 0x400);
            inl_cpufastset(gUnk_030035C0, (void*)0x07000000, 0x400);
    
            REG_BG1HOFS = 0;
            REG_BG1VOFS = 0;
            REG_BG2HOFS = 0;
            REG_BG2VOFS = 0;
            REG_BG3HOFS = 0;
            REG_BG3VOFS = 0;
            REG_BLDCNT = gUnk_03004658;
            REG_BLDALPHA = gUnk_03004550;
            
            // CpuFastCopy(gUnk_02005800, 0x0600F800, 0x800);
            inl_cpufastset(VRAM_BUF_2005800, (void*)0x0600F800, 0x800);
    
            if (gUnk_03004DC0 != 0) 
            {
                // CpuFastCopy(gUnk_02005000, 0x0600F000, 0x800);
                inl_cpufastset(VRAM_BUF_2005000, (void*)0x0600F000,  0x800);
                gUnk_03004DC0 = 0;
            }
    
            break;
        case 6:
            m4aSoundVSync();
            
            REG_BG1HOFS = 0;
            REG_BG1VOFS = 0;
            REG_BG2HOFS = 0;
            REG_BG2VOFS = 0;
            REG_BG3HOFS = 0;
            REG_BG3VOFS = 0;
            
            sub_8004ADC();
            DmaCopy16(3, gUnk_030035C0, OAM, 0x400);
    
            sub_8008E94();
            sub_805008C();
            
            REG_BLDCNT = gUnk_03004658;
            if(gUnk_03004658 & 0x80)
            {
                REG_BLDY = gUnk_03004550;
            }
            else
            {
                REG_BLDALPHA = gUnk_03004550;
            }
            
            sub_8005020();
            sub_80038CC();
            break;
        default:
            m4aSoundVSync();
            break;
    }
        
    gUnk_030025A4++;
    
    if (gUnk_03001948 <= 0x0CDFD7EE) 
    {
        gUnk_03001948++;
    } 
    else 
    {
        gUnk_03001948 = 0x0CDFD7F0;
    }

    gUnk_030025A0++;
    REG_IME = 0;
    gUnk_03007FF8 |= 1;
    REG_IME = 1;

}

void sub_80008CC(void) {

    sub_8053838(0);
    sub_8053838(1);
    sub_8053838(2);
    sub_8053838(3);
    sub_805369C(0);
    VBlankIntrWait();

    while ( REG_DISPSTAT & 1 );
 
    sub_80533F0();
    sub_8053688();
    VBlankIntrWait();

    while ( REG_DISPSTAT & 1 );

    sub_80533F0();
    sub_80535F4();
    VBlankIntrWait();
    while ( REG_DISPSTAT & 1 );

    sub_80533F0();
    VBlankIntrWait();
    REG_DISPCNT |= 0x80;
}


s32 sub_800096C(void) {

    switch (gUnk_03001B50) 
    {
        case 0:
            REG_RCNT = 0xC000;
            VBlankIntrWait();
            sub_8017600(&gUnk_03001AD0, &gUnk_03001CB0, 0x10, 0);
            gUnk_03004F20.unk5E = 1;
            gUnk_03004F20.unk2 = 1;
            gUnk_03001B50++;
        case 1:
            gUnk_03001940 = sub_80171E4();
            
            if (gUnk_03001940 == -1) 
            {
                gUnk_030025A8 = 5;
                gUnk_03001B50 = 6;
                break;
            }
            
            if ((sub_8017588() == 0) && ( gUnk_03001940 <= 0xFF))
            {
                if (gUnk_03001D30 == 0) {
                    sub_801761C();
                    gUnk_03001B50 = 4;
                    gUnk_030025A8 = 2;
                }
                gUnk_03001D30--;
                break;
            }

            switch (gUnk_03001940)
            {
                case 0:
                case 1:
                    if (gUnk_03001D30 == 0) 
                    {
                        sub_801761C();
                        gUnk_03001B50 = 4;
                        gUnk_030025A8 = 2;
                    }
                    else 
                    {
                        gUnk_03001D30--;
                    }
                    break;
                
                case 2:
                    if (sub_8017588() == 0) 
                    {
                        sub_801761C();
                        gUnk_03001B50 = 5;
                        gUnk_030025A8 = 3;
                    }
                    else if (gUnk_030025A8 == 0) 
                    {
                        gUnk_03004F20.unk5E = 1;
                        gUnk_03004F20.unk2 = 1;
                        gUnk_030025A8 = 1;
                    }
                    break;
                
                case 0x101:
                case 0x102:
                case 0x103:
                case 0x104:
                    gUnk_030025A8 = 3;
                    gUnk_03001B50 = 5;
                    break;
                
                default:
                break;
            }

            break;
        case 2:
        case 3:
        case 4:
            sub_801761C();
            gUnk_03001B50 = 9;
            break;
        case 5:
            sub_801761C();
            gUnk_03001B50 = 9;
            break;
        case 6:
            gUnk_03001B50 = 0;
            break;
        case 7:
            sub_801761C();
            break;
        case 8:
            if (gUnk_030025A8 == 0) 
            {
                sub_801761C();
                gUnk_03001B50 = 0;
            }
            break;
        case 9:
            sub_801761C();
            gUnk_03001B50 = 8;
            break;
    }
    
    return sub_8017588();
}


void sub_8000B58(void) {
    u16 i;

    DmaFill16(3, 0, (void*)VRAM, VRAM_SIZE);
    DmaFill32(3, 0, (void*)OAM, OAM_SIZE);
    DmaFill16(3, 0, (void*)PLTT, PLTT_SIZE);
    DmaFill16(3, 0, &gUnk_02004000, 0x2000);
    
    sub_8004B8C();
    sub_8004BBC();

    gUnk_03001948 = 0;
    gUnk_030032D0 = 0;
    gUnk_03002604 = 0;
    gUnk_03004910 = 0;
    gUnk_03004840 = 0;
    gUnk_0300465C = 0;
    gUnk_030025F4 = 0xFF;


    for (i = 0; i < 16; i++)
    {
        gUnk_03004800[i] = 0;
    }
    
    for (i = 0; i < 128; i++)
    {
        gUnk_030035C0[i].all.unk0 = 0;
        gUnk_030035C0[i].all.unk4 = 0;
    }

    sub_8004AC0();
    sub_8004B60();
    sub_8009A5C();
    sub_8001090();
    sub_8001014();
    sub_8009168();
    
    gUnk_0300259C = 0;
    gUnk_03004D4C = 0;
    gUnk_03004D40 = 0;
    gUnk_03004854 = 0;
    gUnk_030025D8 = 0;
    gUnk_0300483C = 0;
    gUnk_03002C48 = 0;
}

void sub_8000C98(u16 arg0) {

    u16 i;
    u8 mask;
    s8 mul1, mul2;
    s8 div1, div2;
    
    mask = 0x7F;
    switch (arg0)
    {
        case 1:
            div1 = 12;
            mul1 = 32;
            div2 = 12;
            mul2 = 16;
            break;
        case 2:
            div1 = 16;
            mul1 = 8;
            div2 = 4;
            mul2 = 16;
            mask = 0x3F;
            break;
        case 3:
            div1 = 16;
            mul1 = 32;
            div2 = 32;
            mul2 = 4;
            break;
        case 4:
            div1 = 4;
            mul1 = 1;
            div2 = 16;  
            mul2 = 1;
            mask = 0x3F;
            break;
        default:
            return;
    }
    
    for (i = 0; i < 255; i++)
    {
        gUnk_03001B60[i] = gUnk_080576D0[ (i * mul1) & mask] / div1;
        gUnk_030019C0[i] = gUnk_080576D0[ (i * mul2) & mask] / div2;
    }

}



