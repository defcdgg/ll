	.include "MPlayDef.s"

	.section .rodata

	@********************** Track  1 **********************@

	.align 2
	.global song_0249_1
song_0249_1:	@ 0x087E75C8
	.byte	KEYSH	, 0
	.byte	TEMPO	, 60
	.byte	VOICE	, 34
	.byte	VOL	, v120
	.byte		N92	, Cn3, v120
	.byte	W92
	.byte	W01
	.byte	FINE

	.align 2
	.global song_0249
song_0249:	@ 0x087E75D8
	.byte	1		@ trackCount
	.byte	0		@ blockCount
	.byte	255		@ priority
	.byte	0		@ reverb

	.word	voicegroup004		@ voicegroup/tone

	.word	song_0249_1		@ track
