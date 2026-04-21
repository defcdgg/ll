	.include "MPlayDef.s"

	.section .rodata

	@********************** Track  1 **********************@

	.align 2
	.global song_0145_1
song_0145_1:	@ 0x087E6A20
	.byte	VOL	, v127
	.byte	KEYSH	, 0
song_0145_1_1:
	.byte	TEMPO	, 60
	.byte	VOICE	, 58
	.byte		N11	, Cn3, v100
	.byte	W08
	.byte	GOTO	
		.word	song_0145_1_1
	.byte	W04
	.byte	FINE

	.align 2
	.global song_0145
song_0145:	@ 0x087E6A34
	.byte	1		@ trackCount
	.byte	0		@ blockCount
	.byte	255		@ priority
	.byte	0		@ reverb

	.word	voicegroup003		@ voicegroup/tone

	.word	song_0145_1		@ track
