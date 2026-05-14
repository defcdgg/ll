	.include "asm/macros.inc"
	.include "constants/gba_constants.inc"

	.section .rodata


gUnk_087E83F0: @ 087E83F0
	.incbin "baserom.gba", 0x7E8430, 0x800000 - 0x7E8430
