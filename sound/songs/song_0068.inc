	.include "MPlayDef.s"

	.section .rodata

	@********************** Track  1 **********************@

	.align 2
	.global song_0068_1
song_0068_1:	@ 0x087E6188
	.byte	KEYSH	, 0
	.byte	TEMPO	, 60
	.byte	VOICE	, 5
	.byte	VOL	, v120
	.byte		N10	, Cn3, v120
	.byte	W10
	.byte	FINE

	.align 2
	.global song_0068
song_0068:	@ 0x087E6198
	.byte	1		@ trackCount
	.byte	0		@ blockCount
	.byte	255		@ priority
	.byte	0		@ reverb

	.word	voicegroup002		@ voicegroup/tone

	.word	song_0068_1		@ track
