	.include "MPlayDef.s"

	.section .rodata

	@********************** Track  1 **********************@

	.align 2
	.global song_0077_1
song_0077_1:	@ 0x087E6284
	.byte	KEYSH	, 0
	.byte	TEMPO	, 60
	.byte	VOICE	, 14
	.byte	VOL	, v120
	.byte		N08	, Cn3, v120
	.byte	W09
	.byte	FINE

	.align 2
	.global song_0077
song_0077:	@ 0x087E6294
	.byte	1		@ trackCount
	.byte	0		@ blockCount
	.byte	255		@ priority
	.byte	0		@ reverb

	.word	voicegroup002		@ voicegroup/tone

	.word	song_0077_1		@ track
