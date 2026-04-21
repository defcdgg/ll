	.include "MPlayDef.s"

	.section .rodata

	@********************** Track  1 **********************@

	.align 2
	.global song_0225_1
song_0225_1:	@ 0x087E7324
	.byte	KEYSH	, 0
	.byte	TEMPO	, 60
	.byte	VOICE	, 10
	.byte	VOL	, v120
	.byte		N40	, Cn3, v120
	.byte	W40
	.byte	FINE

	.align 2
	.global song_0225
song_0225:	@ 0x087E7334
	.byte	1		@ trackCount
	.byte	0		@ blockCount
	.byte	255		@ priority
	.byte	0		@ reverb

	.word	voicegroup004		@ voicegroup/tone

	.word	song_0225_1		@ track
