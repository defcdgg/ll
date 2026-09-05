typedef unsigned char u8;
typedef unsigned short u16;
typedef signed int s32;
typedef unsigned int u32;
extern u16 gUnk_02016000[];
extern u8 gUnk_02016200[];
u8 EventFlags_Test(u16);
u8 SwitchFlags_Test(u16);
u32 sub_804FA04(u32 *ptr)
{
    u8 *data;
    u8 t;
    u8 n;
    u32 off;
    u16 i;
    u16 v;
    u16 *tbl;
    u8 res;

    data = (u8 *) (*ptr);
    t = data[1];
    n = t >> 1;
    for (i = 0; n > i; i++)
    {
        v = data[(i * 2) + 3] | (data[(i * 2) + 4] << 8);
        if (v > 0x1FF)
        {
            res = SwitchFlags_Test(v - 0x200);
        }
        else
        {
            res = EventFlags_Test(v);
        }
        if (res != 0)
        {
            break;
        }
    }

    tbl = (u16 *) 0x02016000;
    if (res == 0)
    {
        *ptr = 0x02016200 + tbl[data[2]];
    }
    else
    {
        off = t + 3;
        *ptr = (*ptr) + off;
    }
    return 1;
}
