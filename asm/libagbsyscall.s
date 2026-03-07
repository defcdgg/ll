	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

	thumb_func_start CpuFastSet
CpuFastSet: @ 0x08055984
	svc #0xc
	bx lr

	thumb_func_start CpuSet
CpuSet: @ 0x08055988
	svc #0xb
	bx lr

	thumb_func_start HuffUnComp
HuffUnComp: @ 0x0805598C
	svc #0x13
	bx lr

	thumb_func_start IntrWait
IntrWait: @ 0x08055990
	movs r2, #0
	svc #4
	bx lr
	.align 2, 0

	thumb_func_start LZ77UnCompVram
LZ77UnCompVram: @ 0x08055998
	svc #0x12
	bx lr

	thumb_func_start LZ77UnCompWram
LZ77UnCompWram: @ 0x0805599C
	svc #0x11
	bx lr

	thumb_func_start ObjAffineSet
ObjAffineSet: @ 0x080559A0
	svc #0xf
	bx lr

	thumb_func_start RegisterRamReset
RegisterRamReset: @ 0x080559A4
	svc #1
	bx lr

	thumb_func_start VBlankIntrWait
VBlankIntrWait: @ 0x080559A8
	movs r2, #0
	svc #5
	bx lr
	.align 2, 0
	