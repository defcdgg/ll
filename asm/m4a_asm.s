	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

	thumb_func_start umul3232H32
umul3232H32: @ 0x0805389C
	add r2, pc, #0x0 @ =__umul3232H32
	bx r2

	arm_func_start __umul3232H32
__umul3232H32: @ 0x080538A0
	umull r2, r3, r0, r1
	add r0, r3, #0
	bx lr

	thumb_func_start SoundMain
SoundMain: @ 0x080538AC
	ldr r0, _08053918 @ =0x03007FF0
	ldr r0, [r0]
	ldr r2, _0805391C @ =0x68736D53
	ldr r3, [r0]
	cmp r2, r3
	beq _080538BA
	bx lr
_080538BA:
	adds r3, #1
	str r3, [r0]
	push {r4, r5, r6, r7, lr}
	mov r1, r8
	mov r2, sb
	mov r3, sl
	mov r4, fp
	push {r0, r1, r2, r3, r4}
	sub sp, #0x18
	ldrb r1, [r0, #0xc]
	cmp r1, #0
	beq _080538DE
	ldr r2, _08053924 @ =0x04000006
	ldrb r2, [r2]
	cmp r2, #0xa0
	bhs _080538DC
	adds r2, #0xe4
_080538DC:
	adds r1, r1, r2
_080538DE:
	str r1, [sp, #0x14]
	ldr r3, [r0, #0x20]
	cmp r3, #0
	beq _080538EE
	ldr r0, [r0, #0x24]
	bl sub_08053C5A
	ldr r0, [sp, #0x18]
_080538EE:
	ldr r3, [r0, #0x28]
	bl sub_08053C5A
	ldr r0, [sp, #0x18]
	ldr r3, [r0, #0x10]
	mov r8, r3
	ldr r5, _08053928 @ =0x00000350
	adds r5, r5, r0
	ldrb r4, [r0, #4]
	subs r7, r4, #1
	bls _0805390E
	ldrb r1, [r0, #0xb]
	subs r1, r1, r7
	mov r2, r8
	muls r2, r1, r2
	adds r5, r5, r2
_0805390E:
	str r5, [sp, #8]
	ldr r6, _0805392C @ =0x00000630
	ldr r3, _08053920 @ =SoundMainRAM_Buffer + 1
	bx r3
	.align 2, 0
_08053918: .4byte 0x03007FF0
_0805391C: .4byte 0x68736D53
_08053920: .4byte SoundMainRAM_Buffer + 1
_08053924: .4byte 0x04000006
_08053928: .4byte 0x00000350
_0805392C: .4byte 0x00000630

	thumb_func_start SoundMainRAM
SoundMainRAM: @ 0x08053930
	ldrb r3, [r0, #5]
	cmp r3, #0
	beq SoundMainRAM_NoReverb
	add r1, pc, #0x4 @ =SoundMainRAM_Reverb
	bx r1
	.align 2, 0

	arm_func_start SoundMainRAM_Reverb
SoundMainRAM_Reverb: @ 0x0805393C
	cmp r4, #2
	addeq r7, r0, #0x350
	addne r7, r5, r8
	mov r4, r8
_0805394C:
	ldrsb r0, [r5]
	ldrsb r1, [r7], #1
	add r0, r0, r1
	mul r1, r0, r3
	asr r0, r1, #8
	tst r0, #0x80
	addne r0, r0, #1
	strb r0, [r5], #1
	subs r4, r4, #1
	bgt _0805394C
	add r0, pc, #0x1F @ =SoundMainRAM_ChanLoop
	bx r0

	thumb_func_start SoundMainRAM_NoReverb
SoundMainRAM_NoReverb: @ 0x0805397C
	movs r0, #0
	mov r1, r8
	lsrs r1, r1, #3
	blo _08053986
	stm r5!, {r0}
_08053986:
	lsrs r1, r1, #1
	blo _0805398E
	stm r5!, {r0}
	stm r5!, {r0}
_0805398E:
	stm r5!, {r0}
	stm r5!, {r0}
	stm r5!, {r0}
	stm r5!, {r0}
	subs r1, #1
	bgt _0805398E

	non_word_aligned_thumb_func_start SoundMainRAM_ChanLoop
SoundMainRAM_ChanLoop: @ 0x0805399A
	ldr r4, [sp, #0x18]
	ldr r0, [r4, #0x18]
	mov ip, r0
	ldrb r0, [r4, #6]
	adds r4, #0x50
_080539A4:
	str r0, [sp, #4]
	ldr r3, [r4, #0x24]
	ldr r0, [sp, #0x14]
	cmp r0, #0
	beq _080539C4
	ldr r1, _080539C0 @ =0x04000006
	ldrb r1, [r1]
	cmp r1, #0xa0
	bhs _080539B8
	adds r1, #0xe4
_080539B8:
	cmp r1, r0
	blo _080539C4
	b _08053C46
	.align 2, 0
_080539C0: .4byte 0x04000006
_080539C4:
	ldrb r6, [r4]
	movs r0, #0xc7
	tst r0, r6
	bne _080539CE
	b sub_08053C3C
_080539CE:
	movs r0, #0x80
	tst r0, r6
	beq _080539FE
	movs r0, #0x40
	tst r0, r6
	bne _08053A0E
	movs r6, #3
	strb r6, [r4]
	adds r0, r3, #0
	adds r0, #0x10
	str r0, [r4, #0x28]
	ldr r0, [r3, #0xc]
	str r0, [r4, #0x18]
	movs r5, #0
	strb r5, [r4, #9]
	str r5, [r4, #0x1c]
	ldrb r2, [r3, #3]
	movs r0, #0xc0
	tst r0, r2
	beq _08053A56
	movs r0, #0x10
	orrs r6, r0
	strb r6, [r4]
	b _08053A56
_080539FE:
	ldrb r5, [r4, #9]
	movs r0, #4
	tst r0, r6
	beq _08053A14
	ldrb r0, [r4, #0xd]
	subs r0, #1
	strb r0, [r4, #0xd]
	bhi _08053A64
_08053A0E:
	movs r0, #0
	strb r0, [r4]
	b sub_08053C3C
_08053A14:
	movs r0, #0x40
	tst r0, r6
	beq _08053A34
	ldrb r0, [r4, #7]
	muls r5, r0, r5
	lsrs r5, r5, #8
	ldrb r0, [r4, #0xc]
	cmp r5, r0
	bhi _08053A64
_08053A26:
	ldrb r5, [r4, #0xc]
	cmp r5, #0
	beq _08053A0E
	movs r0, #4
	orrs r6, r0
	strb r6, [r4]
	b _08053A64
_08053A34:
	movs r2, #3
	ands r2, r6
	cmp r2, #2
	bne _08053A52
	ldrb r0, [r4, #5]
	muls r5, r0, r5
	lsrs r5, r5, #8
	ldrb r0, [r4, #6]
	cmp r5, r0
	bhi _08053A64
	adds r5, r0, #0
	beq _08053A26
	subs r6, #1
	strb r6, [r4]
	b _08053A64
_08053A52:
	cmp r2, #3
	bne _08053A64
_08053A56:
	ldrb r0, [r4, #4]
	adds r5, r5, r0
	cmp r5, #0xff
	blo _08053A64
	movs r5, #0xff
	subs r6, #1
	strb r6, [r4]
_08053A64:
	strb r5, [r4, #9]
	ldr r0, [sp, #0x18]
	ldrb r0, [r0, #7]
	adds r0, #1
	muls r0, r5, r0
	lsrs r5, r0, #4
	ldrb r0, [r4, #2]
	ldrb r1, [r4, #3]
	adds r0, r0, r1
	muls r0, r5, r0
	lsrs r0, r0, #9
	strb r0, [r4, #0xa]
	movs r0, #0x10
	ands r0, r6
	str r0, [sp, #0x10]
	beq _08053A94
	adds r0, r3, #0
	adds r0, #0x10
	ldr r1, [r3, #8]
	adds r0, r0, r1
	str r0, [sp, #0xc]
	ldr r0, [r3, #0xc]
	subs r0, r0, r1
	str r0, [sp, #0x10]
_08053A94:
	ldr r5, [sp, #8]
	ldr r2, [r4, #0x18]
	ldr r3, [r4, #0x28]
	add r0, pc, #0x4 @ =sub_8053AA0
	bx r0
	.align 2, 0

	arm_func_start sub_8053AA0
sub_8053AA0: @ 0x08053AA0
	str r8, [sp]
	ldrb sl, [r4, #0xa]
	lsl sl, sl, #0x10
	ldrb r0, [r4, #1]
	tst r0, #8
	beq _08053BA8
_08053AB8:
	cmp r2, #4
	ble _08053B14
	subs r2, r2, r8
	movgt lr, #0
	bgt _08053AE4
	mov lr, r8
	add r2, r2, r8
	sub r8, r2, #4
	sub lr, lr, r8
	ands r2, r2, #3
	moveq r2, #4
_08053AE4:
	ldr r6, [r5]
_08053AE8:
	ldrsb r0, [r3], #1
	mul r1, sl, r0
	bic r1, r1, #0xff0000
	add r6, r1, r6, ror #8
	adds r5, r5, #0x40000000
	blo _08053AE8
	str r6, [r5], #4
	subs r8, r8, #4
	bgt _08053AE4
	adds r8, r8, lr
	beq _08053C28
_08053B14:
	ldr r6, [r5]
_08053B18:
	ldrsb r0, [r3], #1
	mul r1, sl, r0
	bic r1, r1, #0xff0000
	add r6, r1, r6, ror #8
	subs r2, r2, #1
	beq _08053B78
_08053B30:
	adds r5, r5, #0x40000000
	blo _08053B18
	str r6, [r5], #4
	subs r8, r8, #4
	bgt _08053AB8
	b _08053C28
_08053B48:
	ldr r0, [sp, #0x18]
	cmp r0, #0
	beq _08053B6C
	ldr r3, [sp, #0x14]
	rsb sb, r2, #0
_08053B5C:
	adds r2, r0, r2
	bgt _08053BFC
	sub sb, sb, r0
	b _08053B5C
_08053B6C:
	pop {r4, ip}
	mov r2, #0
	b _08053B88
_08053B78:
	ldr r2, [sp, #0x10]
	cmp r2, #0
	ldrne r3, [sp, #0xc]
	bne _08053B30
_08053B88:
	strb r2, [r4]
	lsr r0, r5, #0x1e
	bic r5, r5, #0xc0000000
	rsb r0, r0, #3
	lsl r0, r0, #3
	ror r6, r6, r0
	str r6, [r5], #4
	b _08053C30
_08053BA8:
	push {r4, ip}
	ldr lr, [r4, #0x1c]
	ldr r1, [r4, #0x20]
	mul r4, ip, r1
	ldrsb r0, [r3]
	ldrsb r1, [r3, #1]!
	sub r1, r1, r0
_08053BC4:
	ldr r6, [r5]
_08053BC8:
	mul sb, lr, r1
	add sb, r0, sb, asr #23
	mul ip, sl, sb
	bic ip, ip, #0xff0000
	add r6, ip, r6, ror #8
	add lr, lr, r4
	lsrs sb, lr, #0x17
	beq _08053C08
	bic lr, lr, #0x3f800000
	subs r2, r2, sb
	ble _08053B48
	subs sb, sb, #1
	addeq r0, r0, r1
_08053BFC:
	ldrsbne r0, [r3, sb]!
	ldrsb r1, [r3, #1]!
	sub r1, r1, r0
_08053C08:
	adds r5, r5, #0x40000000
	blo _08053BC8
	str r6, [r5], #4
	subs r8, r8, #4
	bgt _08053BC4
	sub r3, r3, #1
	pop {r4, ip}
	str lr, [r4, #0x1c]
_08053C28:
	str r2, [r4, #0x18]
	str r3, [r4, #0x28]
_08053C30:
	ldr r8, [sp]
	add r0, pc, #0x1 @ =sub_08053C3C
	bx r0

	thumb_func_start sub_08053C3C
sub_08053C3C: @ 0x08053C3C
	ldr r0, [sp, #4]
	subs r0, #1
	ble _08053C46
	adds r4, #0x40
	b _080539A4
_08053C46:
	ldr r0, [sp, #0x18]
	ldr r3, _08053C5C @ =0x68736D53
	str r3, [r0]
	add sp, #0x1c
	pop {r0, r1, r2, r3, r4, r5, r6, r7}
	mov r8, r0
	mov sb, r1
	mov sl, r2
	mov fp, r3
	pop {r3}

	non_word_aligned_thumb_func_start sub_08053C5A
sub_08053C5A: @ 0x08053C5A
	bx r3
	.align 2, 0
_08053C5C: .4byte 0x68736D53

	thumb_func_start SoundMainBTM
SoundMainBTM: @ 0x08053C60
	mov ip, r4
	movs r1, #0
	movs r2, #0
	movs r3, #0
	movs r4, #0
	stm r0!, {r1, r2, r3, r4}
	stm r0!, {r1, r2, r3, r4}
	stm r0!, {r1, r2, r3, r4}
	stm r0!, {r1, r2, r3, r4}
	mov r4, ip
	bx lr
	.align 2, 0

	thumb_func_start RealClearChain
RealClearChain: @ 0x08053C78
	ldr r3, [r0, #0x2c]
	cmp r3, #0
	beq _08053C96
	ldr r1, [r0, #0x34]
	ldr r2, [r0, #0x30]
	cmp r2, #0
	beq _08053C8A
	str r1, [r2, #0x34]
	b _08053C8C
_08053C8A:
	str r1, [r3, #0x20]
_08053C8C:
	cmp r1, #0
	beq _08053C92
	str r2, [r1, #0x30]
_08053C92:
	movs r1, #0
	str r1, [r0, #0x2c]
_08053C96:
	bx lr

	thumb_func_start ply_fine
ply_fine:
	push {r4, r5, lr}
	adds r5, r1, #0
	ldr r4, [r5, #0x20]
	cmp r4, #0
	beq _08053CBC
_08053CA2:
	ldrb r1, [r4]
	movs r0, #0xc7
	tst r0, r1
	beq _08053CB0
	movs r0, #0x40
	orrs r1, r0
	strb r1, [r4]
_08053CB0:
	adds r0, r4, #0
	bl RealClearChain
	ldr r4, [r4, #0x34]
	cmp r4, #0
	bne _08053CA2
_08053CBC:
	movs r0, #0
	strb r0, [r5]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start MPlayJumpTableCopy
MPlayJumpTableCopy: @ 0x08053CC8
	mov ip, lr
	movs r1, #0x24
	ldr r2, _08053CF8 @ =0x086AF214
_08053CCE:
	ldr r3, [r2]
	bl _08053CE2
	stm r0!, {r3}
	adds r2, #4
	subs r1, #1
	bgt _08053CCE
	bx ip
	.align 2, 0

	thumb_func_start ldrb_r3_r2
ldrb_r3_r2: @ 0x08053CE0
	ldrb r3, [r2]
_08053CE2:
	push {r0}
	lsrs r0, r2, #0x19
	bne _08053CF4
	ldr r0, _08053CF8 @ =0x086AF214
	cmp r2, r0
	blo _08053CF2
	lsrs r0, r2, #0xe
	beq _08053CF4
_08053CF2:
	movs r3, #0
_08053CF4:
	pop {r0}
	bx lr
	.align 2, 0
_08053CF8: .4byte 0x086AF214

	thumb_func_start ld_r3_tp_adr_i
ld_r3_tp_adr_i: @ 0x08053CFC
	ldr r2, [r1, #0x40]

	non_word_aligned_thumb_func_start sub_08053CFE
sub_08053CFE: @ 0x08053CFE
	adds r3, r2, #1
	str r3, [r1, #0x40]
	ldrb r3, [r2]
	b _08053CE2
	.align 2, 0

	thumb_func_start ply_goto
ply_goto:
	push {lr}
_08053D0A:
	ldr r2, [r1, #0x40]
	ldrb r0, [r2, #3]
	lsls r0, r0, #8
	ldrb r3, [r2, #2]
	orrs r0, r3
	lsls r0, r0, #8
	ldrb r3, [r2, #1]
	orrs r0, r3
	lsls r0, r0, #8
	bl ldrb_r3_r2
	orrs r0, r3
	str r0, [r1, #0x40]
	pop {r0}
	bx r0

	thumb_func_start ply_patt
ply_patt: @ 0x08053D28
	ldrb r2, [r1, #2]
	cmp r2, #3
	bhs _08053D40
	lsls r2, r2, #2
	adds r3, r1, r2
	ldr r2, [r1, #0x40]
	adds r2, #4
	str r2, [r3, #0x44]
	ldrb r2, [r1, #2]
	adds r2, #1
	strb r2, [r1, #2]
	b ply_goto
_08053D40:
	b ply_fine
	.align 2, 0

	thumb_func_start ply_pend
ply_pend: @ 0x08053D44
	ldrb r2, [r1, #2]
	cmp r2, #0
	beq _08053D56
	subs r2, #1
	strb r2, [r1, #2]
	lsls r2, r2, #2
	adds r3, r1, r2
	ldr r2, [r3, #0x44]
	str r2, [r1, #0x40]
_08053D56:
	bx lr

	thumb_func_start ply_rept
ply_rept: @ 0x08053D58
	push {lr}
	ldr r2, [r1, #0x40]
	ldrb r3, [r2]
	cmp r3, #0
	bne _08053D68
	adds r2, #1
	str r2, [r1, #0x40]
	b _08053D0A
_08053D68:
	ldrb r3, [r1, #3]
	adds r3, #1
	strb r3, [r1, #3]
	mov ip, r3
	bl ld_r3_tp_adr_i
	cmp ip, r3
	bhs _08053D7A
	b _08053D0A
_08053D7A:
	movs r3, #0
	strb r3, [r1, #3]
	adds r2, #5
	str r2, [r1, #0x40]
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start ply_prio
ply_prio: @ 0x08053D88
	mov ip, lr
	bl ld_r3_tp_adr_i
	strb r3, [r1, #0x1d]
	bx ip
	.align 2, 0

	thumb_func_start ply_tempo
ply_tempo: @ 0x08053D94
	mov ip, lr
	bl ld_r3_tp_adr_i
	lsls r3, r3, #1
	strh r3, [r0, #0x1c]
	ldrh r2, [r0, #0x1e]
	muls r3, r2, r3
	lsrs r3, r3, #8
	strh r3, [r0, #0x20]
	bx ip

	thumb_func_start ply_keysh
ply_keysh: @ 0x08053DA8
	mov ip, lr
	bl ld_r3_tp_adr_i
	strb r3, [r1, #0xa]
	ldrb r3, [r1]
	movs r2, #0xc
	orrs r3, r2
	strb r3, [r1]
	bx ip
	.align 2, 0

	thumb_func_start ply_voice
ply_voice: @ 0x08053DBC
	mov ip, lr
	ldr r2, [r1, #0x40]
	ldrb r3, [r2]
	adds r2, #1
	str r2, [r1, #0x40]
	lsls r2, r3, #1
	adds r2, r2, r3
	lsls r2, r2, #2
	ldr r3, [r0, #0x30]
	adds r2, r2, r3
	ldr r3, [r2]
	bl _08053CE2
	str r3, [r1, #0x24]
	ldr r3, [r2, #4]
	bl _08053CE2
	str r3, [r1, #0x28]
	ldr r3, [r2, #8]
	bl _08053CE2
	str r3, [r1, #0x2c]
	bx ip
	.align 2, 0

	thumb_func_start ply_vol
ply_vol: @ 0x08053DEC
	mov ip, lr
	bl ld_r3_tp_adr_i
	strb r3, [r1, #0x12]
	ldrb r3, [r1]
	movs r2, #3
	orrs r3, r2
	strb r3, [r1]
	bx ip
	.align 2, 0

	thumb_func_start ply_pan
ply_pan: @ 0x08053E00
	mov ip, lr
	bl ld_r3_tp_adr_i
	subs r3, #0x40
	strb r3, [r1, #0x14]
	ldrb r3, [r1]
	movs r2, #3
	orrs r3, r2
	strb r3, [r1]
	bx ip

	thumb_func_start ply_bend
ply_bend: @ 0x08053E14
	mov ip, lr
	bl ld_r3_tp_adr_i
	subs r3, #0x40
	strb r3, [r1, #0xe]
	ldrb r3, [r1]
	movs r2, #0xc
	orrs r3, r2
	strb r3, [r1]
	bx ip

	thumb_func_start ply_bendr
ply_bendr: @ 0x08053E28
	mov ip, lr
	bl ld_r3_tp_adr_i
	strb r3, [r1, #0xf]
	ldrb r3, [r1]
	movs r2, #0xc
	orrs r3, r2
	strb r3, [r1]
	bx ip
	.align 2, 0

	thumb_func_start ply_lfodl
ply_lfodl: @ 0x08053E3C
	mov ip, lr
	bl ld_r3_tp_adr_i
	strb r3, [r1, #0x1b]
	bx ip
	.align 2, 0

	thumb_func_start ply_modt
ply_modt: @ 0x08053E48
	mov ip, lr
	bl ld_r3_tp_adr_i
	ldrb r0, [r1, #0x18]
	cmp r0, r3
	beq _08053E5E
	strb r3, [r1, #0x18]
	ldrb r3, [r1]
	movs r2, #0xf
	orrs r3, r2
	strb r3, [r1]
_08053E5E:
	bx ip

	thumb_func_start ply_tune
ply_tune: @ 0x08053E60
	mov ip, lr
	bl ld_r3_tp_adr_i
	subs r3, #0x40
	strb r3, [r1, #0xc]
	ldrb r3, [r1]
	movs r2, #0xc
	orrs r3, r2
	strb r3, [r1]
	bx ip

	thumb_func_start ply_port
ply_port: @ 0x08053E74
	mov ip, lr
	ldr r2, [r1, #0x40]
	ldrb r3, [r2]
	adds r2, #1
	ldr r0, _08053E88 @ =0x04000060
	adds r0, r0, r3
	bl sub_08053CFE
	strb r3, [r0]
	bx ip
	.align 2, 0
_08053E88: .4byte 0x04000060

	thumb_func_start m4aSoundVSync
m4aSoundVSync: @ 0x08053E8C
	ldr r0, _08054128 @ =0x03007FF0
	ldr r0, [r0]
	ldr r2, _0805412C @ =0x68736D53
	ldr r3, [r0]
	subs r3, r3, r2
	cmp r3, #1
	bhi _08053EBE
	ldrb r1, [r0, #4]
	subs r1, #1
	strb r1, [r0, #4]
	bgt _08053EBE
	ldrb r1, [r0, #0xb]
	strb r1, [r0, #4]
	ldr r2, _08053EC0 @ =0x040000BC
	ldr r1, [r2, #8]
	lsls r1, r1, #7
	blo _08053EB2
	ldr r1, _08053EC4 @ =0x84400004
	str r1, [r2, #8]
_08053EB2:
	movs r1, #4
	lsls r1, r1, #8
	strh r1, [r2, #0xa]
	movs r1, #0xb6
	lsls r1, r1, #8
	strh r1, [r2, #0xa]
_08053EBE:
	bx lr
	.align 2, 0
_08053EC0: .4byte 0x040000BC
_08053EC4: .4byte 0x84400004

	thumb_func_start MPlayMain
MPlayMain: @ 0x08053EC8
	ldr r2, _0805412C @ =0x68736D53
	ldr r3, [r0, #0x34]
	cmp r2, r3
	beq _08053ED2
	bx lr
_08053ED2:
	adds r3, #1
	str r3, [r0, #0x34]
	push {r0, lr}
	ldr r3, [r0, #0x38]
	cmp r3, #0
	beq _08053EE4
	ldr r0, [r0, #0x3c]
	bl sub_8054120
_08053EE4:
	pop {r0}
	push {r4, r5, r6, r7}
	mov r4, r8
	mov r5, sb
	mov r6, sl
	mov r7, fp
	push {r4, r5, r6, r7}
	adds r7, r0, #0
	ldr r0, [r7, #4]
	cmp r0, #0
	bge _08053EFC
	b _08054110
_08053EFC:
	ldr r0, _08054128 @ =0x03007FF0
	ldr r0, [r0]
	mov r8, r0
	adds r0, r7, #0
	bl FadeOutBody
	ldr r0, [r7, #4]
	cmp r0, #0
	bge _08053F10
	b _08054110
_08053F10:
	ldrh r0, [r7, #0x22]
	ldrh r1, [r7, #0x20]
	adds r0, r0, r1
	b _08054060
_08053F18:
	ldrb r6, [r7, #8]
	ldr r5, [r7, #0x2c]
	movs r3, #1
	movs r4, #0
_08053F20:
	ldrb r0, [r5]
	movs r1, #0x80
	tst r1, r0
	bne _08053F2A
	b _0805403C
_08053F2A:
	mov sl, r3
	orrs r4, r3
	mov fp, r4
	ldr r4, [r5, #0x20]
	cmp r4, #0
	beq _08053F5E
_08053F36:
	ldrb r1, [r4]
	movs r0, #0xc7
	tst r0, r1
	beq _08053F52
	ldrb r0, [r4, #0x10]
	cmp r0, #0
	beq _08053F58
	subs r0, #1
	strb r0, [r4, #0x10]
	bne _08053F58
	movs r0, #0x40
	orrs r1, r0
	strb r1, [r4]
	b _08053F58
_08053F52:
	adds r0, r4, #0
	bl ClearChain
_08053F58:
	ldr r4, [r4, #0x34]
	cmp r4, #0
	bne _08053F36
_08053F5E:
	ldrb r3, [r5]
	movs r0, #0x40
	tst r0, r3
	beq _08053FDC
	adds r0, r5, #0
	bl Clear64byte
	movs r0, #0x80
	strb r0, [r5]
	movs r0, #2
	strb r0, [r5, #0xf]
	movs r0, #0x40
	strb r0, [r5, #0x13]
	movs r0, #0x16
	strb r0, [r5, #0x19]
	movs r0, #1
	adds r1, r5, #6
	strb r0, [r1, #0x1e]
	b _08053FDC
_08053F84:
	ldr r2, [r5, #0x40]
	ldrb r1, [r2]
	cmp r1, #0x80
	bhs _08053F90
	ldrb r1, [r5, #7]
	b _08053F9A
_08053F90:
	adds r2, #1
	str r2, [r5, #0x40]
	cmp r1, #0xbd
	blo _08053F9A
	strb r1, [r5, #7]
_08053F9A:
	cmp r1, #0xcf
	blo _08053FB0
	mov r0, r8
	ldr r3, [r0, #0x38]
	adds r0, r1, #0
	subs r0, #0xcf
	adds r1, r7, #0
	adds r2, r5, #0
	bl sub_8054120
	b _08053FDC
_08053FB0:
	cmp r1, #0xb0
	bls _08053FD2
	adds r0, r1, #0
	subs r0, #0xb1
	strb r0, [r7, #0xa]
	mov r3, r8
	ldr r3, [r3, #0x34]
	lsls r0, r0, #2
	ldr r3, [r3, r0]
	adds r0, r7, #0
	adds r1, r5, #0
	bl sub_8054120
	ldrb r0, [r5]
	cmp r0, #0
	beq _08054038
	b _08053FDC
_08053FD2:
	ldr r0, _08054124 @ =0x086AF488
	subs r1, #0x80
	adds r1, r1, r0
	ldrb r0, [r1]
	strb r0, [r5, #1]
_08053FDC:
	ldrb r0, [r5, #1]
	cmp r0, #0
	beq _08053F84
	subs r0, #1
	strb r0, [r5, #1]
	ldrb r1, [r5, #0x19]
	cmp r1, #0
	beq _08054038
	ldrb r0, [r5, #0x17]
	cmp r0, #0
	beq _08054038
	ldrb r0, [r5, #0x1c]
	cmp r0, #0
	beq _08053FFE
	subs r0, #1
	strb r0, [r5, #0x1c]
	b _08054038
_08053FFE:
	ldrb r0, [r5, #0x1a]
	adds r0, r0, r1
	strb r0, [r5, #0x1a]
	adds r1, r0, #0
	subs r0, #0x40
	lsls r0, r0, #0x18
	bpl _08054012
	lsls r2, r1, #0x18
	asrs r2, r2, #0x18
	b _08054016
_08054012:
	movs r0, #0x80
	subs r2, r0, r1
_08054016:
	ldrb r0, [r5, #0x17]
	muls r0, r2, r0
	asrs r2, r0, #6
	ldrb r0, [r5, #0x16]
	eors r0, r2
	lsls r0, r0, #0x18
	beq _08054038
	strb r2, [r5, #0x16]
	ldrb r0, [r5]
	ldrb r1, [r5, #0x18]
	cmp r1, #0
	bne _08054032
	movs r1, #0xc
	b _08054034
_08054032:
	movs r1, #3
_08054034:
	orrs r0, r1
	strb r0, [r5]
_08054038:
	mov r3, sl
	mov r4, fp
_0805403C:
	subs r6, #1
	ble _08054048
	movs r0, #0x50
	adds r5, r5, r0
	lsls r3, r3, #1
	b _08053F20
_08054048:
	ldr r0, [r7, #0xc]
	adds r0, #1
	str r0, [r7, #0xc]
	cmp r4, #0
	bne _0805405A
	movs r0, #0x80
	lsls r0, r0, #0x18
	str r0, [r7, #4]
	b _08054110
_0805405A:
	str r4, [r7, #4]
	ldrh r0, [r7, #0x22]
	subs r0, #0x96
_08054060:
	strh r0, [r7, #0x22]
	cmp r0, #0x96
	blo _08054068
	b _08053F18
_08054068:
	ldrb r2, [r7, #8]
	ldr r5, [r7, #0x2c]
_0805406C:
	ldrb r0, [r5]
	movs r1, #0x80
	tst r1, r0
	beq _08054106
	movs r1, #0xf
	tst r1, r0
	beq _08054106
	mov sb, r2
	adds r0, r7, #0
	adds r1, r5, #0
	bl TrkVolPitSet
	ldr r4, [r5, #0x20]
	cmp r4, #0
	beq _080540FC
_0805408A:
	ldrb r1, [r4]
	movs r0, #0xc7
	tst r0, r1
	bne _0805409A
	adds r0, r4, #0
	bl ClearChain
	b _080540F6
_0805409A:
	ldrb r0, [r4, #1]
	movs r6, #7
	ands r6, r0
	ldrb r3, [r5]
	movs r0, #3
	tst r0, r3
	beq _080540B8
	bl ChnVolSetAsm
	cmp r6, #0
	beq _080540B8
	ldrb r0, [r4, #0x1d]
	movs r1, #1
	orrs r0, r1
	strb r0, [r4, #0x1d]
_080540B8:
	ldrb r3, [r5]
	movs r0, #0xc
	tst r0, r3
	beq _080540F6
	ldrb r1, [r4, #8]
	movs r0, #8
	ldrsb r0, [r5, r0]
	adds r2, r1, r0
	bpl _080540CC
	movs r2, #0
_080540CC:
	cmp r6, #0
	beq _080540EA
	mov r0, r8
	ldr r3, [r0, #0x30]
	adds r1, r2, #0
	ldrb r2, [r5, #9]
	adds r0, r6, #0
	bl sub_8054120
	str r0, [r4, #0x20]
	ldrb r0, [r4, #0x1d]
	movs r1, #2
	orrs r0, r1
	strb r0, [r4, #0x1d]
	b _080540F6
_080540EA:
	adds r1, r2, #0
	ldrb r2, [r5, #9]
	ldr r0, [r4, #0x24]
	bl MidiKeyToFreq
	str r0, [r4, #0x20]
_080540F6:
	ldr r4, [r4, #0x34]
	cmp r4, #0
	bne _0805408A
_080540FC:
	ldrb r0, [r5]
	movs r1, #0xf0
	ands r0, r1
	strb r0, [r5]
	mov r2, sb
_08054106:
	subs r2, #1
	ble _08054110
	movs r0, #0x50
	adds r5, r5, r0
	bgt _0805406C
_08054110:
	ldr r0, _0805412C @ =0x68736D53
	str r0, [r7, #0x34]
	pop {r0, r1, r2, r3, r4, r5, r6, r7}
	mov r8, r0
	mov sb, r1
	mov sl, r2
	mov fp, r3
	pop {r3}

	thumb_func_start sub_8054120
sub_8054120: @ 0x08054120
	bx r3
	.align 2, 0
_08054124: .4byte 0x086AF488
_08054128: .4byte 0x03007FF0
_0805412C: .4byte 0x68736D53

	thumb_func_start TrackStop
TrackStop: @ 0x08054130
	push {r4, r5, r6, lr}
	adds r5, r1, #0
	ldrb r1, [r5]
	movs r0, #0x80
	tst r0, r1
	beq _08054168
	ldr r4, [r5, #0x20]
	cmp r4, #0
	beq _08054166
	movs r6, #0
_08054144:
	ldrb r0, [r4]
	cmp r0, #0
	beq _0805415E
	ldrb r0, [r4, #1]
	movs r3, #7
	ands r0, r3
	beq _0805415C
	ldr r3, _08054170 @ =0x03007FF0
	ldr r3, [r3]
	ldr r3, [r3, #0x2c]
	bl sub_8054120
_0805415C:
	strb r6, [r4]
_0805415E:
	str r6, [r4, #0x2c]
	ldr r4, [r4, #0x34]
	cmp r4, #0
	bne _08054144
_08054166:
	str r4, [r5, #0x20]
_08054168:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08054170: .4byte 0x03007FF0

	thumb_func_start ChnVolSetAsm
ChnVolSetAsm: @ 0x08054174
	ldrb r1, [r4, #0x12]
	movs r0, #0x14
	ldrsb r2, [r4, r0]
	movs r3, #0x80
	adds r3, r3, r2
	muls r3, r1, r3
	ldrb r0, [r5, #0x10]
	muls r0, r3, r0
	asrs r0, r0, #0xe
	cmp r0, #0xff
	bls _0805418C
	movs r0, #0xff
_0805418C:
	strb r0, [r4, #2]
	movs r3, #0x7f
	subs r3, r3, r2
	muls r3, r1, r3
	ldrb r0, [r5, #0x11]
	muls r0, r3, r0
	asrs r0, r0, #0xe
	cmp r0, #0xff
	bls _080541A0
	movs r0, #0xff
_080541A0:
	strb r0, [r4, #3]
	bx lr

	thumb_func_start ply_note
ply_note: @ 0x080541A4
	push {r4, r5, r6, r7, lr}
	mov r4, r8
	mov r5, sb
	mov r6, sl
	mov r7, fp
	push {r4, r5, r6, r7}
	sub sp, #0x18
	str r1, [sp]
	adds r5, r2, #0
	ldr r1, _0805439C @ =0x03007FF0
	ldr r1, [r1]
	str r1, [sp, #4]
	ldr r1, _080543A0 @ =0x086AF488
	adds r0, r0, r1
	ldrb r0, [r0]
	strb r0, [r5, #4]
	ldr r3, [r5, #0x40]
	ldrb r0, [r3]
	cmp r0, #0x80
	bhs _080541EA
	strb r0, [r5, #5]
	adds r3, #1
	ldrb r0, [r3]
	cmp r0, #0x80
	bhs _080541E8
	strb r0, [r5, #6]
	adds r3, #1
	ldrb r0, [r3]
	cmp r0, #0x80
	bhs _080541E8
	ldrb r1, [r5, #4]
	adds r1, r1, r0
	strb r1, [r5, #4]
	adds r3, #1
_080541E8:
	str r3, [r5, #0x40]
_080541EA:
	movs r0, #0
	str r0, [sp, #0x14]
	adds r4, r5, #0
	adds r4, #0x24
	ldrb r2, [r4]
	movs r0, #0xc0
	tst r0, r2
	beq _0805423C
	ldrb r3, [r5, #5]
	movs r0, #0x40
	tst r0, r2
	beq _0805420A
	ldr r1, [r5, #0x2c]
	adds r1, r1, r3
	ldrb r0, [r1]
	b _0805420C
_0805420A:
	adds r0, r3, #0
_0805420C:
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #2
	ldr r0, [r5, #0x28]
	adds r1, r1, r0
	mov sb, r1
	mov r6, sb
	ldrb r1, [r6]
	movs r0, #0xc0
	tst r0, r1
	beq _08054224
	b _0805438A
_08054224:
	movs r0, #0x80
	tst r0, r2
	beq _08054240
	ldrb r1, [r6, #3]
	movs r0, #0x80
	tst r0, r1
	beq _08054238
	subs r1, #0xc0
	lsls r1, r1, #1
	str r1, [sp, #0x14]
_08054238:
	ldrb r3, [r6, #1]
	b _08054240
_0805423C:
	mov sb, r4
	ldrb r3, [r5, #5]
_08054240:
	str r3, [sp, #8]
	ldr r6, [sp]
	ldrb r1, [r6, #9]
	ldrb r0, [r5, #0x1d]
	adds r0, r0, r1
	cmp r0, #0xff
	bls _08054250
	movs r0, #0xff
_08054250:
	str r0, [sp, #0x10]
	mov r6, sb
	ldrb r0, [r6]
	movs r6, #7
	ands r6, r0
	str r6, [sp, #0xc]
	beq _08054290
	ldr r0, [sp, #4]
	ldr r4, [r0, #0x1c]
	cmp r4, #0
	bne _08054268
	b _0805438A
_08054268:
	subs r6, #1
	lsls r0, r6, #6
	adds r4, r4, r0
	ldrb r1, [r4]
	movs r0, #0xc7
	tst r0, r1
	beq _080542E4
	movs r0, #0x40
	tst r0, r1
	bne _080542E4
	ldrb r1, [r4, #0x13]
	ldr r0, [sp, #0x10]
	cmp r1, r0
	blo _080542E4
	beq _08054288
	b _0805438A
_08054288:
	ldr r0, [r4, #0x2c]
	cmp r0, r5
	bhs _080542E4
	b _0805438A
_08054290:
	ldr r6, [sp, #0x10]
	adds r7, r5, #0
	movs r2, #0
	mov r8, r2
	ldr r4, [sp, #4]
	ldrb r3, [r4, #6]
	adds r4, #0x50
_0805429E:
	ldrb r1, [r4]
	movs r0, #0xc7
	tst r0, r1
	beq _080542E4
	movs r0, #0x40
	tst r0, r1
	beq _080542B8
	cmp r2, #0
	bne _080542BC
	adds r2, #1
	ldrb r6, [r4, #0x13]
	ldr r7, [r4, #0x2c]
	b _080542D6
_080542B8:
	cmp r2, #0
	bne _080542D8
_080542BC:
	ldrb r0, [r4, #0x13]
	cmp r0, r6
	bhs _080542C8
	adds r6, r0, #0
	ldr r7, [r4, #0x2c]
	b _080542D6
_080542C8:
	bhi _080542D8
	ldr r0, [r4, #0x2c]
	cmp r0, r7
	bls _080542D4
	adds r7, r0, #0
	b _080542D6
_080542D4:
	blo _080542D8
_080542D6:
	mov r8, r4
_080542D8:
	adds r4, #0x40
	subs r3, #1
	bgt _0805429E
	mov r4, r8
	cmp r4, #0
	beq _0805438A
_080542E4:
	adds r0, r4, #0
	bl ClearChain
	movs r1, #0
	str r1, [r4, #0x30]
	ldr r3, [r5, #0x20]
	str r3, [r4, #0x34]
	cmp r3, #0
	beq _080542F8
	str r4, [r3, #0x30]
_080542F8:
	str r4, [r5, #0x20]
	str r5, [r4, #0x2c]
	ldrb r0, [r5, #0x1b]
	strb r0, [r5, #0x1c]
	cmp r0, r1
	beq _0805430A
	adds r1, r5, #0
	bl clear_modM
_0805430A:
	ldr r0, [sp]
	adds r1, r5, #0
	bl TrkVolPitSet
	ldr r0, [r5, #4]
	str r0, [r4, #0x10]
	ldr r0, [sp, #0x10]
	strb r0, [r4, #0x13]
	ldr r0, [sp, #8]
	strb r0, [r4, #8]
	ldr r0, [sp, #0x14]
	strb r0, [r4, #0x14]
	mov r6, sb
	ldrb r0, [r6]
	strb r0, [r4, #1]
	ldr r7, [r6, #4]
	str r7, [r4, #0x24]
	ldr r0, [r6, #8]
	str r0, [r4, #4]
	ldrh r0, [r5, #0x1e]
	strh r0, [r4, #0xc]
	bl ChnVolSetAsm
	ldrb r1, [r4, #8]
	movs r0, #8
	ldrsb r0, [r5, r0]
	adds r3, r1, r0
	bpl _08054344
	movs r3, #0
_08054344:
	ldr r6, [sp, #0xc]
	cmp r6, #0
	beq _08054372
	mov r6, sb
	ldrb r0, [r6, #2]
	strb r0, [r4, #0x1e]
	ldrb r1, [r6, #3]
	movs r0, #0x80
	tst r0, r1
	bne _0805435E
	movs r0, #0x70
	tst r0, r1
	bne _08054360
_0805435E:
	movs r1, #8
_08054360:
	strb r1, [r4, #0x1f]
	ldrb r2, [r5, #9]
	adds r1, r3, #0
	ldr r0, [sp, #0xc]
	ldr r3, [sp, #4]
	ldr r3, [r3, #0x30]
	bl sub_8054120
	b _0805437C
_08054372:
	ldrb r2, [r5, #9]
	adds r1, r3, #0
	adds r0, r7, #0
	bl MidiKeyToFreq
_0805437C:
	str r0, [r4, #0x20]
	movs r0, #0x80
	strb r0, [r4]
	ldrb r1, [r5]
	movs r0, #0xf0
	ands r0, r1
	strb r0, [r5]
_0805438A:
	add sp, #0x18
	pop {r0, r1, r2, r3, r4, r5, r6, r7}
	mov r8, r0
	mov sb, r1
	mov sl, r2
	mov fp, r3
	pop {r0}
	bx r0
	.align 2, 0
_0805439C: .4byte 0x03007FF0
_080543A0: .4byte 0x086AF488

	thumb_func_start ply_endtie
ply_endtie: @ 0x080543A4
	push {r4, r5}
	ldr r2, [r1, #0x40]
	ldrb r3, [r2]
	cmp r3, #0x80
	bhs _080543B6
	strb r3, [r1, #5]
	adds r2, #1
	str r2, [r1, #0x40]
	b _080543B8
_080543B6:
	ldrb r3, [r1, #5]
_080543B8:
	ldr r1, [r1, #0x20]
	cmp r1, #0
	beq _080543E0
	movs r4, #0x83
	movs r5, #0x40
_080543C2:
	ldrb r2, [r1]
	tst r2, r4
	beq _080543DA
	tst r2, r5
	bne _080543DA
	ldrb r0, [r1, #0x11]
	cmp r0, r3
	bne _080543DA
	movs r0, #0x40
	orrs r2, r0
	strb r2, [r1]
	b _080543E0
_080543DA:
	ldr r1, [r1, #0x34]
	cmp r1, #0
	bne _080543C2
_080543E0:
	pop {r4, r5}
	bx lr

	thumb_func_start clear_modM
clear_modM: @ 0x080543E4
	movs r2, #0
	strb r2, [r1, #0x16]
	strb r2, [r1, #0x1a]
	ldrb r2, [r1, #0x18]
	cmp r2, #0
	bne _080543F4
	movs r2, #0xc
	b _080543F6
_080543F4:
	movs r2, #3
_080543F6:
	ldrb r3, [r1]
	orrs r3, r2
	strb r3, [r1]
	bx lr
	.align 2, 0

	thumb_func_start ld_r3_tp_adr_i_rev
ld_r3_tp_adr_i_rev: @ 0x08054400
	ldr r2, [r1, #0x40]
	adds r3, r2, #1
	str r3, [r1, #0x40]
	ldrb r3, [r2]
	bx lr
	.align 2, 0

	thumb_func_start ply_lfos
ply_lfos: @ 0x0805440C
	mov ip, lr
	bl ld_r3_tp_adr_i_rev
	strb r3, [r1, #0x19]
	cmp r3, #0
	bne _0805441C
	bl clear_modM
_0805441C:
	bx ip
	.align 2, 0

	thumb_func_start ply_mod
ply_mod: @ 0x08054420
	mov ip, lr
	bl ld_r3_tp_adr_i_rev
	strb r3, [r1, #0x17]
	cmp r3, #0
	bne _08054430
	bl clear_modM
_08054430:
	bx ip
	.align 2, 0

    