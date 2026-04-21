	.include "MPlayDef.s"

	.section .rodata

	@********************** Track  1 **********************@

	.align 2
	.global song_0233_1
song_0233_1:	@ 0x087E7404
	.byte	VOL	, v127
	.byte	KEYSH	, 0
	.byte	TEMPO	, 60
	.byte	VOICE	, 18
	.byte		N56	, Cn3, v100
	.byte	W56
	.byte	W02
	.byte	FINE

	.align 2
	.global song_0233
song_0233:	@ 0x087E7414
	.byte	1		@ trackCount
	.byte	0		@ blockCount
	.byte	255		@ priority
	.byte	0		@ reverb

	.word	voicegroup004		@ voicegroup/tone

	.word	song_0233_1		@ track
