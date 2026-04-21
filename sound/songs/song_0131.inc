	.include "MPlayDef.s"

	.section .rodata

	@********************** Track  1 **********************@

	.align 2
	.global song_0131_1
song_0131_1:	@ 0x087E6898
	.byte	KEYSH	, 0
	.byte	TEMPO	, 60
	.byte	VOICE	, 44
	.byte	VOL	, v120
	.byte		N40	, Cn3, v120
	.byte	W40
	.byte	FINE

	.align 2
	.global song_0131
song_0131:	@ 0x087E68A8
	.byte	1		@ trackCount
	.byte	0		@ blockCount
	.byte	255		@ priority
	.byte	0		@ reverb

	.word	voicegroup003		@ voicegroup/tone

	.word	song_0131_1		@ track
