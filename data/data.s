	.include "asm/macros.inc"
	.include "constants/gba_constants.inc"

	.section .rodata

	.equiv MPLAY_SIZE, 12
	.equiv SONG_SIZE, 8

@ gUnk_08057854: @ 08057854
@	.incbin "baserom.gba", 0x57854, 0x6AF214 - 0x57854

gUnk_0805881C: @ 0805881C
	.incbin "baserom.gba", 0x5881C, 0x6AF214 - 0x5881C

@gUnk_0805882C:
@	.incbin "baserom.gba", 0x5882C, 0x6AF214 - 0x5882C

@gUnk_0805881C: @ 0805881C
@	.incbin "baserom.gba", 0x5881C, gUnk_0805882C - gUnk_0805881C
@	
@gUnk_0805882C:
@	.incbin "baserom.gba", 0x5882C, gUnk_08058834 - gUnk_0805882C
@
@gUnk_08058834:
@	.incbin "baserom.gba", 0x58834, gUnk_08058864 - gUnk_08058834
@
@gUnk_08058864:
@	.incbin "baserom.gba", 0x58864, gUnk_0805887C - gUnk_08058864
@
@gUnk_0805887C:
@	.incbin "baserom.gba", 0x5887C, gUnk_0805888C - gUnk_0805887C
@
@gUnk_0805888C:
@	.incbin "baserom.gba", 0x5888C, gUnk_08059794 - gUnk_0805888C
@
@gUnk_08059794:
@	.incbin "baserom.gba", 0x59794, gUnk_080597D8 - gUnk_08059794
@
@gUnk_080597D8:
@	.incbin "baserom.gba", 0x597D8, 0x59D48 - 0x597D8
@
@gUnk_08059D48:
@	.incbin "baserom.gba", 0x59D48, 0x6AF214 - 0x59D48
