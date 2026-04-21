	.include "MPlayDef.s"

	.section .rodata

	@********************** Track  1 **********************@

	.align 2
	.global song_0172_1
song_0172_1:	@ 0x087E6D24
	.byte	KEYSH	, 0
	.byte	TEMPO	, 60
	.byte	VOICE	, 85
	.byte	VOL	, v120
	.byte		N88	, Cn3, v120
	.byte	W90
	.byte	FINE

	.align 2
	.global song_0172
song_0172:	@ 0x087E6D34
	.byte	1		@ trackCount
	.byte	0		@ blockCount
	.byte	255		@ priority
	.byte	0		@ reverb

	.word	voicegroup003		@ voicegroup/tone

	.word	song_0172_1		@ track
