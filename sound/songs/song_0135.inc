	.include "MPlayDef.s"

	.section .rodata

	@********************** Track  1 **********************@

	.align 2
	.global song_0135_1
song_0135_1:	@ 0x087E6908
	.byte	KEYSH	, 0
	.byte	TEMPO	, 60
	.byte	VOICE	, 48
	.byte	VOL	, v120
	.byte		N07	, Cn3, v120
	.byte	W07
	.byte	FINE

	.align 2
	.global song_0135
song_0135:	@ 0x087E6918
	.byte	1		@ trackCount
	.byte	0		@ blockCount
	.byte	255		@ priority
	.byte	0		@ reverb

	.word	voicegroup003		@ voicegroup/tone

	.word	song_0135_1		@ track
