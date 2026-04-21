	.include "MPlayDef.s"

	.section .rodata

	@********************** Track  1 **********************@

	.align 2
	.global song_0277_1
song_0277_1:	@ 0x087E78E0
	.byte	KEYSH	, 0
	.byte	TEMPO	, 60
	.byte	VOICE	, 62
	.byte	VOL	, v120
	.byte		N40	, Cn3, v120
	.byte	W40
	.byte	W01
	.byte	FINE

	.align 2
	.global song_0277
song_0277:	@ 0x087E78F0
	.byte	1		@ trackCount
	.byte	0		@ blockCount
	.byte	255		@ priority
	.byte	0		@ reverb

	.word	voicegroup004		@ voicegroup/tone

	.word	song_0277_1		@ track
