	.include "MPlayDef.s"

	.section .rodata

	@********************** Track  1 **********************@

	.align 2
	.global song_0260_1
song_0260_1:	@ 0x087E76FC
	.byte	KEYSH	, 0
	.byte	TEMPO	, 60
	.byte	VOICE	, 45
	.byte	VOL	, v120
	.byte		N44	, Cn3, v120
	.byte	W44
	.byte	W01
	.byte	FINE

	.align 2
	.global song_0260
song_0260:	@ 0x087E770C
	.byte	1		@ trackCount
	.byte	0		@ blockCount
	.byte	255		@ priority
	.byte	0		@ reverb

	.word	voicegroup004		@ voicegroup/tone

	.word	song_0260_1		@ track
