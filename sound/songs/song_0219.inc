	.include "MPlayDef.s"

	.section .rodata

	@********************** Track  1 **********************@

	.align 2
	.global song_0219_1
song_0219_1:	@ 0x087E7278
	.byte	KEYSH	, 0
	.byte	TEMPO	, 60
	.byte	VOICE	, 4
	.byte	VOL	, v120
	.byte		N28	, Cn3, v120
	.byte	W28
	.byte	FINE

	.align 2
	.global song_0219
song_0219:	@ 0x087E7288
	.byte	1		@ trackCount
	.byte	0		@ blockCount
	.byte	255		@ priority
	.byte	0		@ reverb

	.word	voicegroup004		@ voicegroup/tone

	.word	song_0219_1		@ track
