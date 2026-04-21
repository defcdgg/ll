	.include "MPlayDef.s"

	.section .rodata

	@********************** Track  1 **********************@

	.align 2
	.global song_0119_1
song_0119_1:	@ 0x087E6740
	.byte	KEYSH	, 0
	.byte	TEMPO	, 60
	.byte	VOICE	, 32
	.byte	VOL	, v120
	.byte		N19	, Cn3, v120
	.byte	W19
	.byte	FINE

	.align 2
	.global song_0119
song_0119:	@ 0x087E6750
	.byte	1		@ trackCount
	.byte	0		@ blockCount
	.byte	255		@ priority
	.byte	0		@ reverb

	.word	voicegroup003		@ voicegroup/tone

	.word	song_0119_1		@ track
