	.include "MPlayDef.s"

	.section .rodata

	@********************** Track  1 **********************@

	.align 2
	.global song_0259_1
song_0259_1:	@ 0x087E76E0
	.byte	KEYSH	, 0
	.byte	TEMPO	, 60
	.byte	VOICE	, 44
	.byte	VOL	, v120
	.byte		N92	, Cn3, v120
	.byte	W96
	.byte	FINE

	.align 2
	.global song_0259
song_0259:	@ 0x087E76F0
	.byte	1		@ trackCount
	.byte	0		@ blockCount
	.byte	255		@ priority
	.byte	0		@ reverb

	.word	voicegroup004		@ voicegroup/tone

	.word	song_0259_1		@ track
