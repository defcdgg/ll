	.include "MPlayDef.s"

	.section .rodata

	@********************** Track  1 **********************@

	.align 2
	.global song_0104_1
song_0104_1:	@ 0x087E658C
	.byte	VOL	, v127
	.byte	KEYSH	, 0
song_0104_1_1:
	.byte	TEMPO	, 60
	.byte	VOICE	, 17
	.byte		N54	, Cn3, v100
	.byte	W52
	.byte	W01
	.byte	GOTO	
		.word	song_0104_1_1
	.byte	W02
	.byte	FINE

	.align 2
	.global song_0104
song_0104:	@ 0x087E65A0
	.byte	1		@ trackCount
	.byte	0		@ blockCount
	.byte	255		@ priority
	.byte	0		@ reverb

	.word	voicegroup003		@ voicegroup/tone

	.word	song_0104_1		@ track
