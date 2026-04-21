	.include "MPlayDef.s"

	.section .rodata

	@********************** Track  1 **********************@

	.align 2
	.global song_0200_1
song_0200_1:	@ 0x087E7044
	.byte	KEYSH	, 0
	.byte	TEMPO	, 60
	.byte	VOICE	, 113
	.byte	VOL	, v120
	.byte		N68	, Cn3, v120
	.byte	W72
	.byte	FINE

	.align 2
	.global song_0200
song_0200:	@ 0x087E7054
	.byte	1		@ trackCount
	.byte	0		@ blockCount
	.byte	255		@ priority
	.byte	0		@ reverb

	.word	voicegroup003		@ voicegroup/tone

	.word	song_0200_1		@ track
