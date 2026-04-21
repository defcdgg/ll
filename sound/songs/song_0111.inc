	.include "MPlayDef.s"

	.section .rodata

	@********************** Track  1 **********************@

	.align 2
	.global song_0111_1
song_0111_1:	@ 0x087E6660
	.byte	KEYSH	, 0
	.byte	TEMPO	, 60
	.byte	VOICE	, 24
	.byte	VOL	, v120
	.byte		N13	, Cn3, v120
	.byte	W13
	.byte	FINE

	.align 2
	.global song_0111
song_0111:	@ 0x087E6670
	.byte	1		@ trackCount
	.byte	0		@ blockCount
	.byte	255		@ priority
	.byte	0		@ reverb

	.word	voicegroup003		@ voicegroup/tone

	.word	song_0111_1		@ track
