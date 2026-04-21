	.include "MPlayDef.s"

	.section .rodata

	@********************** Track  1 **********************@

	.align 2
	.global song_0146_1
song_0146_1:	@ 0x087E6A40
	.byte	KEYSH	, 0
	.byte	TEMPO	, 60
	.byte	VOICE	, 59
	.byte	VOL	, v120
	.byte		N24	, Cn3, v120
	.byte	W24
	.byte	W01
	.byte	FINE

	.align 2
	.global song_0146
song_0146:	@ 0x087E6A50
	.byte	1		@ trackCount
	.byte	0		@ blockCount
	.byte	255		@ priority
	.byte	0		@ reverb

	.word	voicegroup003		@ voicegroup/tone

	.word	song_0146_1		@ track
