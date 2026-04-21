	.include "MPlayDef.s"

	.section .rodata

	@********************** Track  1 **********************@

	.align 2
	.global song_0144_1
song_0144_1:	@ 0x087E6A04
	.byte	KEYSH	, 0
	.byte	TEMPO	, 60
	.byte	VOICE	, 57
	.byte	VOL	, v120
	.byte		N60	, Cn3, v120
	.byte	W60
	.byte	W03
	.byte	FINE

	.align 2
	.global song_0144
song_0144:	@ 0x087E6A14
	.byte	1		@ trackCount
	.byte	0		@ blockCount
	.byte	255		@ priority
	.byte	0		@ reverb

	.word	voicegroup003		@ voicegroup/tone

	.word	song_0144_1		@ track
