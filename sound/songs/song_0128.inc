	.include "MPlayDef.s"

	.section .rodata

	@********************** Track  1 **********************@

	.align 2
	.global song_0128_1
song_0128_1:	@ 0x087E6844
	.byte	KEYSH	, 0
	.byte	TEMPO	, 60
	.byte	VOICE	, 41
	.byte	VOL	, v120
	.byte		N17	, Cn3, v120
	.byte	W18
	.byte	FINE

	.align 2
	.global song_0128
song_0128:	@ 0x087E6854
	.byte	1		@ trackCount
	.byte	0		@ blockCount
	.byte	255		@ priority
	.byte	0		@ reverb

	.word	voicegroup003		@ voicegroup/tone

	.word	song_0128_1		@ track
