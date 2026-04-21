	.include "asm/macros.inc"
	.include "constants/gba_constants.inc"

	.section .rodata

	.equiv MPLAY_SIZE, 12
	.equiv SONG_SIZE, 8

gUnk_08057854: @ 08057854
	.incbin "baserom.gba", 0x57854, 0x6AF214 - 0x57854

@ gUnk_08057854: @ 08057854
@	.incbin "baserom.gba", 0x57854, 32 + 524

@ gUnk_08057A80: @ 08057A80
@	.incbin "baserom.gba", 0x57A80, 1132

@ gUnk_08057EEC: @ 08057EEC
@	.incbin "baserom.gba", 0x57EEC, 1240

@ gUnk_080583C4: @ 080583C4
@	.incbin "baserom.gba", 0x583C4, 1112
	