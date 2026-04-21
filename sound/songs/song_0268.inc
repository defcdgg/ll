	.include "MPlayDef.s"

	.section .rodata

	@********************** Track  1 **********************@

	.align 2
	.global song_0268_1
song_0268_1:	@ 0x087E77E4
	.byte	KEYSH	, 0
	.byte	TEMPO	, 60
	.byte	VOICE	, 53
	.byte	VOL	, v120
	.byte		N36	, Cn3, v120
	.byte	W36
	.byte	FINE

	.align 2
	.global song_0268
song_0268:	@ 0x087E77F4
	.byte	1		@ trackCount
	.byte	0		@ blockCount
	.byte	255		@ priority
	.byte	0		@ reverb

	.word	voicegroup004		@ voicegroup/tone

	.word	song_0268_1		@ track
