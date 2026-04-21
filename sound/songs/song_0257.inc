	.include "MPlayDef.s"

	.section .rodata

	@********************** Track  1 **********************@

	.align 2
	.global song_0257_1
song_0257_1:	@ 0x087E76A8
	.byte	KEYSH	, 0
	.byte	TEMPO	, 60
	.byte	VOICE	, 42
	.byte	VOL	, v120
	.byte		N54	, Cn3, v120
	.byte	W54
	.byte	W01
	.byte	FINE

	.align 2
	.global song_0257
song_0257:	@ 0x087E76B8
	.byte	1		@ trackCount
	.byte	0		@ blockCount
	.byte	255		@ priority
	.byte	0		@ reverb

	.word	voicegroup004		@ voicegroup/tone

	.word	song_0257_1		@ track
