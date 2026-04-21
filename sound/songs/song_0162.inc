	.include "MPlayDef.s"

	.section .rodata

	@********************** Track  1 **********************@

	.align 2
	.global song_0162_1
song_0162_1:	@ 0x087E6C08
	.byte	KEYSH	, 0
	.byte	TEMPO	, 60
	.byte	VOICE	, 75
	.byte	VOL	, v120
	.byte		N44	, Cn3, v120
	.byte	W44
	.byte	W01
	.byte	FINE

	.align 2
	.global song_0162
song_0162:	@ 0x087E6C18
	.byte	1		@ trackCount
	.byte	0		@ blockCount
	.byte	255		@ priority
	.byte	0		@ reverb

	.word	voicegroup003		@ voicegroup/tone

	.word	song_0162_1		@ track
