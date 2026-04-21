	.include "MPlayDef.s"

	.section .rodata

	@********************** Track  1 **********************@

	.align 2
	.global song_0147_1
song_0147_1:	@ 0x087E6A5C
	.byte	KEYSH	, 0
	.byte	TEMPO	, 60
	.byte	VOICE	, 60
	.byte	VOL	, v120
	.byte		N44	, Cn3, v120
	.byte	W44
	.byte	W01
	.byte	FINE

	.align 2
	.global song_0147
song_0147:	@ 0x087E6A6C
	.byte	1		@ trackCount
	.byte	0		@ blockCount
	.byte	255		@ priority
	.byte	0		@ reverb

	.word	voicegroup003		@ voicegroup/tone

	.word	song_0147_1		@ track
