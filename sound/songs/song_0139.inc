	.include "MPlayDef.s"

	.section .rodata

	@********************** Track  1 **********************@

	.align 2
	.global song_0139_1
song_0139_1:	@ 0x087E6978
	.byte	KEYSH	, 0
	.byte	TEMPO	, 60
	.byte	VOICE	, 52
	.byte	VOL	, v120
	.byte		N10	, Cn3, v120
	.byte	W10
	.byte	FINE

	.align 2
	.global song_0139
song_0139:	@ 0x087E6988
	.byte	1		@ trackCount
	.byte	0		@ blockCount
	.byte	255		@ priority
	.byte	0		@ reverb

	.word	voicegroup003		@ voicegroup/tone

	.word	song_0139_1		@ track
