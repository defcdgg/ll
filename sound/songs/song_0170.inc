	.include "MPlayDef.s"

	.section .rodata

	@********************** Track  1 **********************@

	.align 2
	.global song_0170_1
song_0170_1:	@ 0x087E6CEC
	.byte	KEYSH	, 0
	.byte	TEMPO	, 60
	.byte	VOICE	, 83
	.byte	VOL	, v120
	.byte		N36	, Cn3, v120
	.byte	W36
	.byte	W03
	.byte	FINE

	.align 2
	.global song_0170
song_0170:	@ 0x087E6CFC
	.byte	1		@ trackCount
	.byte	0		@ blockCount
	.byte	255		@ priority
	.byte	0		@ reverb

	.word	voicegroup003		@ voicegroup/tone

	.word	song_0170_1		@ track
