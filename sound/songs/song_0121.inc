	.include "MPlayDef.s"

	.section .rodata

	@********************** Track  1 **********************@

	.align 2
	.global song_0121_1
song_0121_1:	@ 0x087E6778
	.byte	KEYSH	, 0
	.byte	TEMPO	, 60
	.byte	VOICE	, 34
	.byte	VOL	, v120
	.byte		N13	, Cn3, v120
	.byte	W13
	.byte	FINE

	.align 2
	.global song_0121
song_0121:	@ 0x087E6788
	.byte	1		@ trackCount
	.byte	0		@ blockCount
	.byte	255		@ priority
	.byte	0		@ reverb

	.word	voicegroup003		@ voicegroup/tone

	.word	song_0121_1		@ track
