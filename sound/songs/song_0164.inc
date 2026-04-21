	.include "MPlayDef.s"

	.section .rodata

	@********************** Track  1 **********************@

	.align 2
	.global song_0164_1
song_0164_1:	@ 0x087E6C40
	.byte	KEYSH	, 0
	.byte	TEMPO	, 60
	.byte	VOICE	, 77
	.byte	VOL	, v120
	.byte		N56	, Cn3, v120
	.byte	W60
	.byte	FINE

	.align 2
	.global song_0164
song_0164:	@ 0x087E6C50
	.byte	1		@ trackCount
	.byte	0		@ blockCount
	.byte	255		@ priority
	.byte	0		@ reverb

	.word	voicegroup003		@ voicegroup/tone

	.word	song_0164_1		@ track
