	.include "MPlayDef.s"

	.section .rodata

	@********************** Track  1 **********************@

	.align 2
	.global song_0275_1
song_0275_1:	@ 0x087E78A8
	.byte	KEYSH	, 0
	.byte	TEMPO	, 60
	.byte	VOICE	, 60
	.byte	VOL	, v120
	.byte		N16	, Cn3, v120
	.byte	W16
	.byte	FINE

	.align 2
	.global song_0275
song_0275:	@ 0x087E78B8
	.byte	1		@ trackCount
	.byte	0		@ blockCount
	.byte	255		@ priority
	.byte	0		@ reverb

	.word	voicegroup004		@ voicegroup/tone

	.word	song_0275_1		@ track
