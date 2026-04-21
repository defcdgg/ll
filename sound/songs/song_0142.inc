	.include "MPlayDef.s"

	.section .rodata

	@********************** Track  1 **********************@

	.align 2
	.global song_0142_1
song_0142_1:	@ 0x087E69CC
	.byte	KEYSH	, 0
	.byte	TEMPO	, 60
	.byte	VOICE	, 55
	.byte	VOL	, v120
	.byte		N72	, Cn3, v120
	.byte	W72
	.byte	W03
	.byte	FINE

	.align 2
	.global song_0142
song_0142:	@ 0x087E69DC
	.byte	1		@ trackCount
	.byte	0		@ blockCount
	.byte	255		@ priority
	.byte	0		@ reverb

	.word	voicegroup003		@ voicegroup/tone

	.word	song_0142_1		@ track
