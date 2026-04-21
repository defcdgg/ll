	.include "MPlayDef.s"

	.section .rodata

	@********************** Track  1 **********************@

	.align 2
	.global song_0210_1
song_0210_1:	@ 0x087E7168
	.byte	KEYSH	, 0
	.byte	TEMPO	, 60
	.byte	VOICE	, 16
	.byte	VOL	, v120
	.byte		N60	, Cn3, v120
	.byte	W60
	.byte	W02
	.byte	FINE

	.align 2
	.global song_0210
song_0210:	@ 0x087E7178
	.byte	1		@ trackCount
	.byte	0		@ blockCount
	.byte	255		@ priority
	.byte	0		@ reverb

	.word	voicegroup003		@ voicegroup/tone

	.word	song_0210_1		@ track
