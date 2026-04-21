	.include "MPlayDef.s"

	.section .rodata

	@********************** Track  1 **********************@

	.align 2
	.global song_0105_1
song_0105_1:	@ 0x087E65AC
	.byte	VOL	, v127
	.byte	KEYSH	, 0
song_0105_1_1:
	.byte	TEMPO	, 60
	.byte	VOICE	, 18
	.byte		N22	, Cn3, v100
	.byte	W22
	.byte	GOTO	
		.word	song_0105_1_1
	.byte	FINE

	.align 2
	.global song_0105
song_0105:	@ 0x087E65C0
	.byte	1		@ trackCount
	.byte	0		@ blockCount
	.byte	255		@ priority
	.byte	0		@ reverb

	.word	voicegroup003		@ voicegroup/tone

	.word	song_0105_1		@ track
