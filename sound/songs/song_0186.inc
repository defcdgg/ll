	.include "MPlayDef.s"

	.section .rodata

	@********************** Track  1 **********************@

	.align 2
	.global song_0186_1
song_0186_1:	@ 0x087E6EB4
	.byte	KEYSH	, 0
	.byte	TEMPO	, 60
	.byte	VOICE	, 99
	.byte	VOL	, v120
	.byte		TIE	, Cn3, v120
	.byte	W96
	.byte	W42
	.byte	W01
	.byte		EOT	
	.byte	FINE

	.align 2
	.global song_0186
song_0186:	@ 0x087E6EC4
	.byte	1		@ trackCount
	.byte	0		@ blockCount
	.byte	255		@ priority
	.byte	0		@ reverb

	.word	voicegroup003		@ voicegroup/tone

	.word	song_0186_1		@ track
