	.include "MPlayDef.s"

	.section .rodata

	@********************** Track  1 **********************@

	.align 2
	.global song_0270_1
song_0270_1:	@ 0x087E781C
	.byte	KEYSH	, 0
	.byte	TEMPO	, 60
	.byte	VOICE	, 55
	.byte	VOL	, v120
	.byte		N44	, Cn3, v120
	.byte	W48
	.byte	FINE

	.align 2
	.global song_0270
song_0270:	@ 0x087E782C
	.byte	1		@ trackCount
	.byte	0		@ blockCount
	.byte	255		@ priority
	.byte	0		@ reverb

	.word	voicegroup004		@ voicegroup/tone

	.word	song_0270_1		@ track
