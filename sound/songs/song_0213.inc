	.include "MPlayDef.s"

	.section .rodata

	@********************** Track  1 **********************@

	.align 2
	.global song_0213_1
song_0213_1:	@ 0x087E71C0
	.byte	KEYSH	, 0
	.byte	TEMPO	, 60
	.byte	VOICE	, 126
	.byte	VOL	, v120
	.byte		N44	, Cn3, v120
	.byte	W44
	.byte	W02
	.byte	FINE

	.align 2
	.global song_0213
song_0213:	@ 0x087E71D0
	.byte	1		@ trackCount
	.byte	0		@ blockCount
	.byte	255		@ priority
	.byte	0		@ reverb

	.word	voicegroup003		@ voicegroup/tone

	.word	song_0213_1		@ track
