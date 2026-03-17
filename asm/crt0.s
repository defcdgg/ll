	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

	arm_func_start __start
__start: @ 0x08000000
	b _080000C0

    .include "asm/rom_header.inc"

_080000C0:
	mov r0, #0x12
	msr cpsr_fc, r0
	ldr sp, _080000F8 @ =0x03007FA0
	mov r0, #0x1f
	msr cpsr_fc, r0
	ldr sp, _080000F4 @ =0x03007F00
	ldr r1, _08000250 @ =0x03007FFC
	add r0, pc, #0x18 @ =sub_80000FC
	str r0, [r1]
	ldr r1, _08000254 @ =sub_800128C
	mov lr, pc
	bx r1

	arm_func_start j_init_vector
j_init_vector: @ 0x080000F0
	b _080000C0
	.align 2, 0
_080000F4: .4byte 0x03007F00
_080000F8: .4byte 0x03007FA0

	arm_func_start sub_80000FC
sub_80000FC: @ 0x080000FC
	mov r3, #0x4000000
	add r3, r3, #0x200
	ldr r2, [r3]
	and r1, r2, r2, lsr #16
	ands r0, r1, #0x2000
	strbne r0, [r3, #-0x17c]
_08000114:
	bne _08000114
	mov r2, #0
	ands r0, r1, #0x80
	bne _0800015C
	add r2, r2, #4
	ands r0, r1, #1
	bne _0800015C
	add r2, r2, #4
	ands r0, r1, #2
	bne _0800015C
	add r2, r2, #4
	ands r0, r1, #4
	bne _0800015C
	add r2, r2, #4
	ands r0, r1, #0x100
	bne _0800015C
	add r2, r2, #4
	ands r0, r1, #0x1000
_0800015C:
	strh r0, [r3, #2]
	ldr r1, _08000258 @ =0x0805769C
	add r1, r1, r2
	ldr r0, [r1]
	bx r0

	arm_func_start sub_8000170
sub_8000170: @ 0x08000170
	mov r3, #0x4000000
	add r3, r3, #0x200
	ldr r2, [r3]
	ldrh r1, [r3, #8]
	mrs r0, spsr
	push {r0, r1, r2, r3, lr}
	mov r0, #1
	strh r0, [r3, #8]
	and r1, r2, r2, lsr #16
	mov ip, #0
	ands r0, r1, #0xc0
	bne _080001EC
	add ip, ip, #4
	ands r0, r1, #1
	bne _080001EC
	add ip, ip, #4
	ands r0, r1, #2
	bne _080001EC
	add ip, ip, #4
	ands r0, r1, #4
	bne _080001EC
	add ip, ip, #4
	ands r0, r1, #0x100
	bne _080001EC
	add ip, ip, #4
	ands r0, r1, #0x1000
	bne _080001EC
	add ip, ip, #4
	ands r0, r1, #0x2000
	strbne r0, [r3, #-0x17c]
_080001E8:
	bne _080001E8
_080001EC:
	strh r0, [r3, #2]
	mov r1, #0x20c0
	bic r2, r2, r0
	and r1, r1, r2
	strh r1, [r3]
	mrs r3, apsr
	bic r3, r3, #0xdf
	orr r3, r3, #0x1f
	msr cpsr_fc, r3
	ldr r1, _0800025C @ =0x0805769C
	add r1, r1, ip
	ldr r0, [r1]
	stmdb sp!, {lr}
	add lr, pc, #0x0 @ =0x08000228
	bx r0
	ldm sp!, {lr}
	mrs r3, apsr
	bic r3, r3, #0xdf
	orr r3, r3, #0x92
	msr cpsr_fc, r3
	pop {r0, r1, r2, r3, lr}
	strh r2, [r3]
	strh r1, [r3, #8]
	msr spsr_fc, r0
	bx lr
	.align 2, 0
_08000250: .4byte 0x03007FFC
_08000254: .4byte sub_800128C
_08000258: .4byte 0x0805769C
_0800025C: .4byte 0x0805769C


	arm_func_start sub_8000260
sub_8000260: @ 0x08000260
	push {r8, sb, sl, fp}
	mov ip, #0x4000000
	ldr fp, _0800029C @ =0x03004DF0
	add sl, fp, #0x28
	mov sb, #1
	mov r8, #0
	strb r8, [ip, #0x208]
	ldm sl, {r0, r1}
	stm sl!, {r1}
	stm sl!, {r0}
	ldrb r0, [fp, #5]
	strb r8, [fp, #5]
	strb sb, [ip, #0x208]
	pop {r8, sb, sl, fp}
	bx lr
	.align 2, 0
_0800029C: .4byte 0x03004DF0

