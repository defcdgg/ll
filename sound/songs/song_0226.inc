	.include "MPlayDef.s"

	.section .rodata

	@********************** Track  1 **********************@

	.align 2
	.global song_0226_1
song_0226_1:	@ 0x087E7340
	.byte	KEYSH	, 0
	.byte	TEMPO	, 60
	.byte	VOICE	, 11
	.byte	VOL	, v120
	.byte		N80	, Cn3, v120
	.byte	W80
	.byte	W01
	.byte	FINE

	.align 2
	.global song_0226
song_0226:	@ 0x087E7350
	.byte	1		@ trackCount
	.byte	0		@ blockCount
	.byte	255		@ priority
	.byte	0		@ reverb

	.word	voicegroup004		@ voicegroup/tone

	.word	song_0226_1		@ track
