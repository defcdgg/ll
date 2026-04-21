	.include "MPlayDef.s"

	.section .rodata

	@********************** Track  1 **********************@

	.align 2
	.global song_0140_1
song_0140_1:	@ 0x087E6994
	.byte	KEYSH	, 0
	.byte	TEMPO	, 60
	.byte	VOICE	, 53
	.byte	VOL	, v120
	.byte		TIE	, Cn3, v120
	.byte	W96
	.byte	W07
	.byte		EOT	
	.byte	FINE

	.align 2
	.global song_0140
song_0140:	@ 0x087E69A4
	.byte	1		@ trackCount
	.byte	0		@ blockCount
	.byte	255		@ priority
	.byte	0		@ reverb

	.word	voicegroup003		@ voicegroup/tone

	.word	song_0140_1		@ track
