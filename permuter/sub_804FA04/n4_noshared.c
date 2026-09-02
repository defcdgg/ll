typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;

extern u8 EventFlags_Test(u16);
extern u8 SwitchFlags_Test(u16);
extern u16 gUnk_02016000[];
extern u8 gUnk_02016200[];

u32 sub_804FA04(u32 *ptr)
{
    u8 *data;
    u8 b;
    u16 i;
    u16 id;
    u8 result;

    data = (u8 *)*ptr;
    b = data[1];
    for (i = 0; b >> 1 > i; i++)
    {
        id = data[3 + i * 2] | (data[4 + i * 2] << 8);
        if (id > 0x1FF)
            result = SwitchFlags_Test(id - 0x200);
        else
            result = EventFlags_Test(id);
        if (result != 0)
            break;
    }
    if (result == 0)
    {
        u32 value = *(u16 *)((u32)gUnk_02016000 + data[2] * 2);
        *ptr = value + (u32)gUnk_02016200;    }
    else
    {
        u32 t = b + 3;
        *ptr += t;    }
    return 1;
}
