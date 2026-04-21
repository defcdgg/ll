	.include "MPlayDef.s"

	.section .rodata

	@********************** Track  1 **********************@

	.align 2
	.global song_0194_1
song_0194_1:	@ 0x087E6F9C
	.byte	KEYSH	, 0
	.byte	TEMPO	, 60
	.byte	VOICE	, 107
	.byte	VOL	, v120
	.byte		N68	, Cn3, v120
	.byte	W72
	.byte	FINE

	.align 2
	.global song_0194
song_0194:	@ 0x087E6FAC
	.byte	1		@ trackCount
	.byte	0		@ blockCount
	.byte	255		@ priority
	.byte	0		@ reverb

	.word	voicegroup003		@ voicegroup/tone

	.word	song_0194_1		@ track
