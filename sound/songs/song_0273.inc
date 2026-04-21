	.include "MPlayDef.s"

	.section .rodata

	@********************** Track  1 **********************@

	.align 2
	.global song_0273_1
song_0273_1:	@ 0x087E7870
	.byte	KEYSH	, 0
	.byte	TEMPO	, 60
	.byte	VOICE	, 58
	.byte	VOL	, v120
	.byte		N42	, Cn3, v120
	.byte	W44
	.byte	FINE

	.align 2
	.global song_0273
song_0273:	@ 0x087E7880
	.byte	1		@ trackCount
	.byte	0		@ blockCount
	.byte	255		@ priority
	.byte	0		@ reverb

	.word	voicegroup004		@ voicegroup/tone

	.word	song_0273_1		@ track
