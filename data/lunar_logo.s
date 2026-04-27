	.include "asm/macros.inc"
	.include "constants/gba_constants.inc"

	.section .rodata

lunar_logo:

.global pltt_08057854
pltt_08057854: @ 0x08057854
	.incbin "data/lunar_logo/pltt.gbapal"

.global tilemap_08057874
tilemap_08057874: @ 0x08057874
	.incbin "data/lunar_logo/tilemap.bin.lz"

.global tileset_1_08057A80
tileset_1_08057A80: @ 0x08057A80
	.incbin "data/lunar_logo/tileset_1.4bpp.lz"

.global tileset_2_08057EEC
tileset_2_08057EEC: @ 0x08057EEC
	.incbin "data/lunar_logo/tileset_2.4bpp.lz"

.global tileset_3_080583C4
tileset_3_080583C4: @ 0x080583C4
	.incbin "data/lunar_logo/tileset_3.4bpp.lz"

