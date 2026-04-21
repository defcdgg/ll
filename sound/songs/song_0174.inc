	.include "MPlayDef.s"

	.section .rodata

	@********************** Track  1 **********************@

	.align 2
	.global song_0174_1
song_0174_1:	@ 0x087E6D5C
	.byte	VOL	, v127
	.byte	KEYSH	, 0
	.byte	TEMPO	, 60
	.byte	VOICE	, 87
	.byte		N30	, Cn3, v100
	.byte	W30
	.byte	W01
	.byte	FINE

	.align 2
	.global song_0174
song_0174:	@ 0x087E6D6C
	.byte	1		@ trackCount
	.byte	0		@ blockCount
	.byte	255		@ priority
	.byte	0		@ reverb

	.word	voicegroup003		@ voicegroup/tone

	.word	song_0174_1		@ track
