	.include "MPlayDef.s"

	.section .rodata

	@********************** Track  1 **********************@

	.align 2
	.global song_0212_1
song_0212_1:	@ 0x087E71A0
	.byte	KEYSH	, 0
	.byte	TEMPO	, 60
	.byte	VOICE	, 125
	.byte	VOL	, v120
	.byte		TIE	, Cn3, v120
	.byte	W96
	.byte	W96
	.byte	W02
	.byte		EOT	
	.byte	W01
	.byte	FINE

	.align 2
	.global song_0212
song_0212:	@ 0x087E71B4
	.byte	1		@ trackCount
	.byte	0		@ blockCount
	.byte	255		@ priority
	.byte	0		@ reverb

	.word	voicegroup003		@ voicegroup/tone

	.word	song_0212_1		@ track
