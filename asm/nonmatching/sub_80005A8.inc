	.include "asm/macros.inc"
	.include "constants/constants.inc"
	
	.syntax unified
	.text

	push {r4, r5, r6, r7, lr}
	lsls r0, r0, #0x10
	lsrs r7, r0, #0x10
	ldr r0, _080005C0 @ =0x03004610
	ldrh r0, [r0]
	cmp r0, #3
	beq _08000620
	cmp r0, #3
	ble _080005C4
	cmp r0, #4
	beq _08000620
	b _08000644
	.align 2, 0
_080005C0: .4byte gUnk_03004610
_080005C4:
	cmp r0, #1
	blt _08000644
	ldr r6, _08000604 @ =0x04000014
	ldr r0, _08000608 @ =0x03001B60
	ldr r5, _0800060C @ =0x03001B54
	ldrb r1, [r5]
	adds r1, r1, r7
	movs r4, #0xff
	ands r1, r4
	adds r1, r1, r0
	ldr r0, _08000610 @ =0x030025B4
	ldrh r3, [r0]
	movs r2, #0x1f
	adds r0, r2, #0
	ands r0, r3
	ldrb r1, [r1]
	adds r0, r0, r1
	strh r0, [r6]
	ldr r3, _08000614 @ =0x04000016
	ldr r1, _08000618 @ =0x030019C0
	ldrb r0, [r5]
	adds r0, r0, r7
	ands r0, r4
	adds r0, r0, r1
	ldr r1, _0800061C @ =0x030025FC
	ldrh r1, [r1]
	ands r2, r1
	ldrb r0, [r0]
	adds r2, r2, r0
	strh r2, [r3]
	b _08000644
	.align 2, 0
_08000604: .4byte 0x04000014
_08000608: .4byte gUnk_03001B60
_0800060C: .4byte gUnk_03001B54
_08000610: .4byte gUnk_030025B4
_08000614: .4byte 0x04000016
_08000618: .4byte gUnk_030019C0
_0800061C: .4byte gUnk_030025FC
_08000620:
	ldr r4, _0800064C @ =0x04000014
	ldr r1, _08000650 @ =0x03001B60
	ldr r3, _08000654 @ =0x03001B54
	ldrb r0, [r3]
	adds r0, r0, r7
	movs r2, #0xff
	ands r0, r2
	adds r0, r0, r1
	ldrb r0, [r0]
	strh r0, [r4]
	adds r4, #2
	ldr r1, _08000658 @ =0x030019C0
	ldrb r0, [r3]
	adds r0, r0, r7
	ands r0, r2
	adds r0, r0, r1
	ldrb r0, [r0]
	strh r0, [r4]
_08000644:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0800064C: .4byte 0x04000014
_08000650: .4byte gUnk_03001B60
_08000654: .4byte gUnk_03001B54
_08000658: .4byte gUnk_030019C0

	.syntax divided
	