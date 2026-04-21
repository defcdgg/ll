	.include "MPlayDef.s"

	.section .rodata

	@********************** Track  1 **********************@

	.align 2
	.global song_0160_1
song_0160_1:	@ 0x087E6BD0
	.byte	KEYSH	, 0
	.byte	TEMPO	, 60
	.byte	VOICE	, 73
	.byte	VOL	, v120
	.byte		N32	, Cn3, v120
	.byte	W32
	.byte	W02
	.byte	FINE

	.align 2
	.global song_0160
song_0160:	@ 0x087E6BE0
	.byte	1		@ trackCount
	.byte	0		@ blockCount
	.byte	255		@ priority
	.byte	0		@ reverb

	.word	voicegroup003		@ voicegroup/tone

	.word	song_0160_1		@ track
