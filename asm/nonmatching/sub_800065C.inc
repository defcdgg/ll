	.syntax unified

	push {r4, r5, lr}
	ldr r0, _08000674 @ =0x0300259C
	ldrb r0, [r0]
	subs r0, #1
	cmp r0, #5
	bls _0800066A
	b _08000870
_0800066A:
	lsls r0, r0, #2
	ldr r1, _08000678 @ =_0800067C
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08000674: .4byte gUnk_0300259C
_08000678: .4byte _0800067C
_0800067C: @ jump table
	.4byte _08000694 @ case 0
	.4byte _0800069E @ case 1
	.4byte _080006A8 @ case 2
	.4byte _080006B2 @ case 3
	.4byte _08000754 @ case 4
	.4byte _080007E8 @ case 5
_08000694:
	bl m4aSoundVSync
	bl sub_80002A0
	b _08000874
_0800069E:
	bl m4aSoundVSync
	bl sub_8018070
	b _08000874
_080006A8:
	bl m4aSoundVSync
	bl sub_80004F8
	b _08000874
_080006B2:
	bl m4aSoundVSync
	bl sub_8004ADC
	ldr r0, _08000724 @ =0x04000014
	movs r2, #0
	strh r2, [r0]
	adds r0, #2
	strh r2, [r0]
	adds r0, #2
	movs r1, #4
	strh r1, [r0]
	adds r0, #2
	strh r2, [r0]
	adds r0, #2
	strh r1, [r0]
	adds r0, #2
	strh r2, [r0]
	ldr r1, _08000728 @ =0x04000050
	ldr r0, _0800072C @ =0x03004658
	ldrh r0, [r0]
	strh r0, [r1]
	adds r1, #2
	ldr r0, _08000730 @ =0x03004550
	ldrh r0, [r0]
	strh r0, [r1]
	adds r1, #0x82
	ldr r0, _08000734 @ =0x030035C0
	str r0, [r1]
	movs r0, #0xe0
	lsls r0, r0, #0x13
	str r0, [r1, #4]
	ldr r0, _08000738 @ =0x80000200
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	ldr r0, _0800073C @ =0x02005800
	str r0, [r1]
	ldr r0, _08000740 @ =0x0600F800
	str r0, [r1, #4]
	ldr r4, _08000744 @ =0x80000400
	str r4, [r1, #8]
	ldr r0, [r1, #8]
	ldr r3, _08000748 @ =0x03004DC0
	ldrb r0, [r3]
	cmp r0, #0
	beq _0800071C
	ldr r0, _0800074C @ =0x02005000
	str r0, [r1]
	ldr r0, _08000750 @ =0x0600F000
	str r0, [r1, #4]
	str r4, [r1, #8]
	ldr r0, [r1, #8]
	strb r2, [r3]
_0800071C:
	bl sub_8005020
	b _08000874
	.align 2, 0
_08000724: .4byte 0x04000014
_08000728: .4byte 0x04000050
_0800072C: .4byte gUnk_03004658
_08000730: .4byte gUnk_03004550
_08000734: .4byte gUnk_030035C0
_08000738: .4byte 0x80000200
_0800073C: .4byte gUnk_02005800
_08000740: .4byte 0x0600F800
_08000744: .4byte 0x80000400
_08000748: .4byte gUnk_03004DC0
_0800074C: .4byte gUnk_02005000
_08000750: .4byte 0x0600F000
_08000754:
	bl sub_8016F30
	bl m4aSoundVSync
	bl sub_8004ADC
	bl sub_8003264
	ldr r0, _080007C0 @ =0x030035C0
	movs r1, #0xe0
	lsls r1, r1, #0x13
	movs r2, #0x80
	lsls r2, r2, #1
	bl CpuFastSet
	ldr r0, _080007C4 @ =0x04000014
	movs r4, #0
	strh r4, [r0]
	adds r0, #2
	strh r4, [r0]
	adds r0, #2
	strh r4, [r0]
	adds r0, #2
	strh r4, [r0]
	adds r0, #2
	strh r4, [r0]
	adds r0, #2
	strh r4, [r0]
	ldr r1, _080007C8 @ =0x04000050
	ldr r0, _080007CC @ =0x03004658
	ldrh r0, [r0]
	strh r0, [r1]
	adds r1, #2
	ldr r0, _080007D0 @ =0x03004550
	ldrh r0, [r0]
	strh r0, [r1]
	ldr r0, _080007D4 @ =0x02005800
	ldr r1, _080007D8 @ =0x0600F800
	movs r2, #0x80
	lsls r2, r2, #2
	bl CpuFastSet
	ldr r5, _080007DC @ =0x03004DC0
	ldrb r0, [r5]
	cmp r0, #0
	beq _08000874
	ldr r0, _080007E0 @ =0x02005000
	ldr r1, _080007E4 @ =0x0600F000
	movs r2, #0x80
	lsls r2, r2, #2
	bl CpuFastSet
	strb r4, [r5]
	b _08000874
	.align 2, 0
_080007C0: .4byte gUnk_030035C0
_080007C4: .4byte 0x04000014
_080007C8: .4byte 0x04000050
_080007CC: .4byte gUnk_03004658
_080007D0: .4byte gUnk_03004550
_080007D4: .4byte gUnk_02005800
_080007D8: .4byte 0x0600F800
_080007DC: .4byte gUnk_03004DC0
_080007E0: .4byte gUnk_02005000
_080007E4: .4byte 0x0600F000
_080007E8:
	bl m4aSoundVSync
	ldr r0, _08000838 @ =0x04000014
	movs r1, #0
	strh r1, [r0]
	adds r0, #2
	strh r1, [r0]
	adds r0, #2
	strh r1, [r0]
	adds r0, #2
	strh r1, [r0]
	adds r0, #2
	strh r1, [r0]
	adds r0, #2
	strh r1, [r0]
	bl sub_8004ADC
	ldr r1, _0800083C @ =0x040000D4
	ldr r0, _08000840 @ =0x030035C0
	str r0, [r1]
	movs r0, #0xe0
	lsls r0, r0, #0x13
	str r0, [r1, #4]
	ldr r0, _08000844 @ =0x80000200
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	bl sub_8008E94
	bl sub_805008C
	ldr r2, _08000848 @ =0x04000050
	ldr r0, _0800084C @ =0x03004658
	ldrh r1, [r0]
	strh r1, [r2]
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq _08000854
	ldr r0, _08000850 @ =0x04000054
	b _08000856
	.align 2, 0
_08000838: .4byte 0x04000014
_0800083C: .4byte 0x040000D4
_08000840: .4byte gUnk_030035C0
_08000844: .4byte 0x80000200
_08000848: .4byte 0x04000050
_0800084C: .4byte gUnk_03004658
_08000850: .4byte 0x04000054
_08000854:
	ldr r0, _08000868 @ =0x04000052
_08000856:
	ldr r1, _0800086C @ =0x03004550
	ldrh r1, [r1]
	strh r1, [r0]
	bl sub_8005020
	bl sub_80038CC
	b _08000874
	.align 2, 0
_08000868: .4byte 0x04000052
_0800086C: .4byte gUnk_03004550
_08000870:
	bl m4aSoundVSync
_08000874:
	ldr r0, _0800088C @ =0x030025A4
	ldrb r1, [r0]
	adds r1, #1
	strb r1, [r0]
	ldr r2, _08000890 @ =0x03001948
	ldr r1, [r2]
	ldr r0, _08000894 @ =0x0CDFD7EE
	cmp r1, r0
	bhi _08000898
	adds r0, r1, #1
	b _0800089A
	.align 2, 0
_0800088C: .4byte gUnk_030025A4
_08000890: .4byte gUnk_03001948
_08000894: .4byte 0x0CDFD7EE
_08000898:
	ldr r0, _080008BC @ =0x0CDFD7F0
_0800089A:
	str r0, [r2]
	ldr r1, _080008C0 @ =0x030025A0
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r3, _080008C4 @ =0x04000208
	movs r0, #0
	strh r0, [r3]
	ldr r2, _080008C8 @ =0x03007FF8
	ldrh r0, [r2]
	movs r1, #1
	orrs r0, r1
	strh r0, [r2]
	strh r1, [r3]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080008BC: .4byte 0x0CDFD7F0
_080008C0: .4byte gUnk_030025A0
_080008C4: .4byte 0x04000208
_080008C8: .4byte gUnk_03007FF8
	.syntax divided
	