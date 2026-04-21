	.include "MPlayDef.s"

	.section .rodata

	@********************** Track  1 **********************@

	.align 2
	.global song_0239_1
song_0239_1:	@ 0x087E74AC
	.byte	VOL	, v127
	.byte	KEYSH	, 0
	.byte	TEMPO	, 60
	.byte	VOICE	, 24
	.byte		N40	, Cn3, v100
	.byte	W42
	.byte	FINE

	.align 2
	.global song_0239
song_0239:	@ 0x087E74BC
	.byte	1		@ trackCount
	.byte	0		@ blockCount
	.byte	255		@ priority
	.byte	0		@ reverb

	.word	voicegroup004		@ voicegroup/tone

	.word	song_0239_1		@ track
