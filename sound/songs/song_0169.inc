	.include "MPlayDef.s"

	.section .rodata

	@********************** Track  1 **********************@

	.align 2
	.global song_0169_1
song_0169_1:	@ 0x087E6CCC
	.byte	VOL	, v127
	.byte	KEYSH	, 0
song_0169_1_1:
	.byte	TEMPO	, 60
	.byte	VOICE	, 61
	.byte		N72	, Cn3, v100
	.byte	W68
	.byte	W03
	.byte	GOTO	
		.word	song_0169_1_1
	.byte	W04
	.byte	FINE

	.align 2
	.global song_0169
song_0169:	@ 0x087E6CE0
	.byte	1		@ trackCount
	.byte	0		@ blockCount
	.byte	255		@ priority
	.byte	0		@ reverb

	.word	voicegroup003		@ voicegroup/tone

	.word	song_0169_1		@ track
