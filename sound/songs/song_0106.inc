	.include "MPlayDef.s"

	.section .rodata

	@********************** Track  1 **********************@

	.align 2
	.global song_0106_1
song_0106_1:	@ 0x087E65CC
	.byte	VOL	, v127
	.byte	KEYSH	, 0
song_0106_1_1:
	.byte	TEMPO	, 60
	.byte	VOICE	, 19
	.byte		N36	, Cn3, v100
	.byte	W36
	.byte	W01
	.byte	GOTO	
		.word	song_0106_1_1
	.byte	W01
	.byte	FINE

	.align 2
	.global song_0106
song_0106:	@ 0x087E65E0
	.byte	1		@ trackCount
	.byte	0		@ blockCount
	.byte	255		@ priority
	.byte	0		@ reverb

	.word	voicegroup003		@ voicegroup/tone

	.word	song_0106_1		@ track
