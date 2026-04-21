	.include "MPlayDef.s"

	.section .rodata

	@********************** Track  1 **********************@

	.align 2
	.global song_0117_1
song_0117_1:	@ 0x087E6708
	.byte	KEYSH	, 0
	.byte	TEMPO	, 60
	.byte	VOICE	, 30
	.byte	VOL	, v120
	.byte		N19	, Cn3, v120
	.byte	W19
	.byte	FINE

	.align 2
	.global song_0117
song_0117:	@ 0x087E6718
	.byte	1		@ trackCount
	.byte	0		@ blockCount
	.byte	255		@ priority
	.byte	0		@ reverb

	.word	voicegroup003		@ voicegroup/tone

	.word	song_0117_1		@ track
