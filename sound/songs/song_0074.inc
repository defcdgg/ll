	.include "MPlayDef.s"

	.section .rodata

	@********************** Track  1 **********************@

	.align 2
	.global song_0074_1
song_0074_1:	@ 0x087E6230
	.byte	KEYSH	, 0
	.byte	TEMPO	, 60
	.byte	VOICE	, 11
	.byte	VOL	, v120
	.byte		N14	, Cn3, v120
	.byte	W15
	.byte	FINE

	.align 2
	.global song_0074
song_0074:	@ 0x087E6240
	.byte	1		@ trackCount
	.byte	0		@ blockCount
	.byte	255		@ priority
	.byte	0		@ reverb

	.word	voicegroup002		@ voicegroup/tone

	.word	song_0074_1		@ track
