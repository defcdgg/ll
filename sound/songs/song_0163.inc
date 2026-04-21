	.include "MPlayDef.s"

	.section .rodata

	@********************** Track  1 **********************@

	.align 2
	.global song_0163_1
song_0163_1:	@ 0x087E6C24
	.byte	KEYSH	, 0
	.byte	TEMPO	, 60
	.byte	VOICE	, 76
	.byte	VOL	, v120
	.byte		N44	, Cn3, v120
	.byte	W44
	.byte	W01
	.byte	FINE

	.align 2
	.global song_0163
song_0163:	@ 0x087E6C34
	.byte	1		@ trackCount
	.byte	0		@ blockCount
	.byte	255		@ priority
	.byte	0		@ reverb

	.word	voicegroup003		@ voicegroup/tone

	.word	song_0163_1		@ track
