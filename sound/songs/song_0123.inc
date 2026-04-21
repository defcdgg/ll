	.include "MPlayDef.s"

	.section .rodata

	@********************** Track  1 **********************@

	.align 2
	.global song_0123_1
song_0123_1:	@ 0x087E67B0
	.byte	KEYSH	, 0
	.byte	TEMPO	, 60
	.byte	VOICE	, 36
	.byte	VOL	, v120
	.byte		N07	, Cn3, v120
	.byte	W07
	.byte	FINE

	.align 2
	.global song_0123
song_0123:	@ 0x087E67C0
	.byte	1		@ trackCount
	.byte	0		@ blockCount
	.byte	255		@ priority
	.byte	0		@ reverb

	.word	voicegroup003		@ voicegroup/tone

	.word	song_0123_1		@ track
