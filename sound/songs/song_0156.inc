	.include "MPlayDef.s"

	.section .rodata

	@********************** Track  1 **********************@

	.align 2
	.global song_0156_1
song_0156_1:	@ 0x087E6B60
	.byte	KEYSH	, 0
	.byte	TEMPO	, 60
	.byte	VOICE	, 69
	.byte	VOL	, v120
	.byte		N08	, Cn3, v120
	.byte	W09
	.byte	FINE

	.align 2
	.global song_0156
song_0156:	@ 0x087E6B70
	.byte	1		@ trackCount
	.byte	0		@ blockCount
	.byte	255		@ priority
	.byte	0		@ reverb

	.word	voicegroup003		@ voicegroup/tone

	.word	song_0156_1		@ track
