	.include "MPlayDef.s"

	.section .rodata

	@********************** Track  1 **********************@

	.align 2
	.global song_0167_1
song_0167_1:	@ 0x087E6C94
	.byte	KEYSH	, 0
	.byte	TEMPO	, 60
	.byte	VOICE	, 80
	.byte	VOL	, v120
	.byte		TIE	, Cn3, v120
	.byte	W96
	.byte	W08
	.byte		EOT	
	.byte	W01
	.byte	FINE

	.align 2
	.global song_0167
song_0167:	@ 0x087E6CA4
	.byte	1		@ trackCount
	.byte	0		@ blockCount
	.byte	255		@ priority
	.byte	0		@ reverb

	.word	voicegroup003		@ voicegroup/tone

	.word	song_0167_1		@ track
