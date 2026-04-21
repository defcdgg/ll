	.include "MPlayDef.s"

	.section .rodata

	@********************** Track  1 **********************@

	.align 2
	.global song_0138_1
song_0138_1:	@ 0x087E695C
	.byte	KEYSH	, 0
	.byte	TEMPO	, 60
	.byte	VOICE	, 51
	.byte	VOL	, v120
	.byte		N42	, Cn3, v120
	.byte	W42
	.byte	W01
	.byte	FINE

	.align 2
	.global song_0138
song_0138:	@ 0x087E696C
	.byte	1		@ trackCount
	.byte	0		@ blockCount
	.byte	255		@ priority
	.byte	0		@ reverb

	.word	voicegroup003		@ voicegroup/tone

	.word	song_0138_1		@ track
