	.include "MPlayDef.s"

	.section .rodata

	@********************** Track  1 **********************@

	.align 2
	.global song_0153_1
song_0153_1:	@ 0x087E6B0C
	.byte	VOL	, v127
	.byte	KEYSH	, 0
	.byte	TEMPO	, 60
	.byte	VOICE	, 66
	.byte		TIE	, Cn3, v100
	.byte	W96
	.byte	W03
	.byte		EOT	
	.byte	FINE

	.align 2
	.global song_0153
song_0153:	@ 0x087E6B1C
	.byte	1		@ trackCount
	.byte	0		@ blockCount
	.byte	255		@ priority
	.byte	0		@ reverb

	.word	voicegroup003		@ voicegroup/tone

	.word	song_0153_1		@ track
