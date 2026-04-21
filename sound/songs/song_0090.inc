	.include "MPlayDef.s"

	.section .rodata

	@********************** Track  1 **********************@

	.align 2
	.global song_0090_1
song_0090_1:	@ 0x087E63F0
	.byte	KEYSH	, 0
	.byte	TEMPO	, 60
	.byte	VOICE	, 3
	.byte	VOL	, v120
	.byte		TIE	, Cn3, v120
	.byte	W96
	.byte	W40
	.byte	W01
	.byte		EOT	
	.byte	W01
	.byte	FINE

	.align 2
	.global song_0090
song_0090:	@ 0x087E6404
	.byte	1		@ trackCount
	.byte	0		@ blockCount
	.byte	255		@ priority
	.byte	0		@ reverb

	.word	voicegroup003		@ voicegroup/tone

	.word	song_0090_1		@ track
