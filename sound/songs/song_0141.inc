	.include "MPlayDef.s"

	.section .rodata

	@********************** Track  1 **********************@

	.align 2
	.global song_0141_1
song_0141_1:	@ 0x087E69B0
	.byte	KEYSH	, 0
	.byte	TEMPO	, 60
	.byte	VOICE	, 54
	.byte	VOL	, v120
	.byte		N24	, Cn3, v120
	.byte	W24
	.byte	W03
	.byte	FINE

	.align 2
	.global song_0141
song_0141:	@ 0x087E69C0
	.byte	1		@ trackCount
	.byte	0		@ blockCount
	.byte	255		@ priority
	.byte	0		@ reverb

	.word	voicegroup003		@ voicegroup/tone

	.word	song_0141_1		@ track
