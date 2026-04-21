	.include "MPlayDef.s"

	.section .rodata

	@********************** Track  1 **********************@

	.align 2
	.global song_0103_1
song_0103_1:	@ 0x087E656C
	.byte	VOL	, v127
	.byte	KEYSH	, 0
song_0103_1_1:
	.byte	TEMPO	, 60
	.byte	VOICE	, 16
	.byte		N40	, Cn3, v100
	.byte	W40
	.byte	GOTO	
		.word	song_0103_1_1
	.byte	W02
	.byte	FINE

	.align 2
	.global song_0103
song_0103:	@ 0x087E6580
	.byte	1		@ trackCount
	.byte	0		@ blockCount
	.byte	255		@ priority
	.byte	0		@ reverb

	.word	voicegroup003		@ voicegroup/tone

	.word	song_0103_1		@ track
