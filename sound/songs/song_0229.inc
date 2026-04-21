	.include "MPlayDef.s"

	.section .rodata

	@********************** Track  1 **********************@

	.align 2
	.global song_0229_1
song_0229_1:	@ 0x087E7394
	.byte	VOL	, v127
	.byte	KEYSH	, 0
	.byte	TEMPO	, 60
	.byte	VOICE	, 14
	.byte		N23	, Cn3, v100
	.byte	W24
	.byte	FINE

	.align 2
	.global song_0229
song_0229:	@ 0x087E73A4
	.byte	1		@ trackCount
	.byte	0		@ blockCount
	.byte	255		@ priority
	.byte	0		@ reverb

	.word	voicegroup004		@ voicegroup/tone

	.word	song_0229_1		@ track
