	.include "MPlayDef.s"

	.section .rodata

	@********************** Track  1 **********************@

	.align 2
	.global song_0084_1
song_0084_1:	@ 0x087E6348
	.byte	KEYSH	, 0
	.byte	TEMPO	, 60
	.byte	VOICE	, 21
	.byte	VOL	, v120
	.byte		N52	, Cn3, v120
	.byte	W54
	.byte	FINE

	.align 2
	.global song_0084
song_0084:	@ 0x087E6358
	.byte	1		@ trackCount
	.byte	0		@ blockCount
	.byte	255		@ priority
	.byte	0		@ reverb

	.word	voicegroup002		@ voicegroup/tone

	.word	song_0084_1		@ track
