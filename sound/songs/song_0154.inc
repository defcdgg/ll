	.include "MPlayDef.s"

	.section .rodata

	@********************** Track  1 **********************@

	.align 2
	.global song_0154_1
song_0154_1:	@ 0x087E6B28
	.byte	KEYSH	, 0
	.byte	TEMPO	, 60
	.byte	VOICE	, 67
	.byte	VOL	, v120
	.byte		N30	, Cn3, v120
	.byte	W30
	.byte	W01
	.byte	FINE

	.align 2
	.global song_0154
song_0154:	@ 0x087E6B38
	.byte	1		@ trackCount
	.byte	0		@ blockCount
	.byte	255		@ priority
	.byte	0		@ reverb

	.word	voicegroup003		@ voicegroup/tone

	.word	song_0154_1		@ track
