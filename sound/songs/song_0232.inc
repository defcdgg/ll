	.include "MPlayDef.s"

	.section .rodata

	@********************** Track  1 **********************@

	.align 2
	.global song_0232_1
song_0232_1:	@ 0x087E73E8
	.byte	KEYSH	, 0
	.byte	TEMPO	, 60
	.byte	VOICE	, 17
	.byte	VOL	, v120
	.byte		N20	, Cn3, v120
	.byte	W21
	.byte	FINE

	.align 2
	.global song_0232
song_0232:	@ 0x087E73F8
	.byte	1		@ trackCount
	.byte	0		@ blockCount
	.byte	255		@ priority
	.byte	0		@ reverb

	.word	voicegroup004		@ voicegroup/tone

	.word	song_0232_1		@ track
