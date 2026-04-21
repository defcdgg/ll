	.include "MPlayDef.s"

	.section .rodata

	@********************** Track  1 **********************@

	.align 2
	.global song_0272_1
song_0272_1:	@ 0x087E7854
	.byte	KEYSH	, 0
	.byte	TEMPO	, 60
	.byte	VOICE	, 57
	.byte	VOL	, v120
	.byte		N56	, Cn3, v120
	.byte	W60
	.byte	FINE

	.align 2
	.global song_0272
song_0272:	@ 0x087E7864
	.byte	1		@ trackCount
	.byte	0		@ blockCount
	.byte	255		@ priority
	.byte	0		@ reverb

	.word	voicegroup004		@ voicegroup/tone

	.word	song_0272_1		@ track
