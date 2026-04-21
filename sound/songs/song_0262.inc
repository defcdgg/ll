	.include "MPlayDef.s"

	.section .rodata

	@********************** Track  1 **********************@

	.align 2
	.global song_0262_1
song_0262_1:	@ 0x087E7734
	.byte	KEYSH	, 0
	.byte	TEMPO	, 60
	.byte	VOICE	, 47
	.byte	VOL	, v120
	.byte		N30	, Cn3, v120
	.byte	W30
	.byte	W01
	.byte	FINE

	.align 2
	.global song_0262
song_0262:	@ 0x087E7744
	.byte	1		@ trackCount
	.byte	0		@ blockCount
	.byte	255		@ priority
	.byte	0		@ reverb

	.word	voicegroup004		@ voicegroup/tone

	.word	song_0262_1		@ track
