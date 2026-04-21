	.include "MPlayDef.s"

	.section .rodata

	@********************** Track  1 **********************@

	.align 2
	.global song_0211_1
song_0211_1:	@ 0x087E7184
	.byte	KEYSH	, 0
	.byte	TEMPO	, 60
	.byte	VOICE	, 124
	.byte	VOL	, v120
	.byte		N20	, Cn3, v120
	.byte	W21
	.byte	FINE

	.align 2
	.global song_0211
song_0211:	@ 0x087E7194
	.byte	1		@ trackCount
	.byte	0		@ blockCount
	.byte	255		@ priority
	.byte	0		@ reverb

	.word	voicegroup003		@ voicegroup/tone

	.word	song_0211_1		@ track
