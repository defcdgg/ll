	.include "MPlayDef.s"

	.section .rodata

	@********************** Track  1 **********************@

	.align 2
	.global song_0179_1
song_0179_1:	@ 0x087E6DE8
	.byte	KEYSH	, 0
	.byte	TEMPO	, 60
	.byte	VOICE	, 92
	.byte	VOL	, v120
	.byte		TIE	, Cn3, v120
	.byte	W96
	.byte	W96
	.byte	W84
	.byte	W01
	.byte		EOT	
	.byte	FINE

	.align 2
	.global song_0179
song_0179:	@ 0x087E6DFC
	.byte	1		@ trackCount
	.byte	0		@ blockCount
	.byte	255		@ priority
	.byte	0		@ reverb

	.word	voicegroup003		@ voicegroup/tone

	.word	song_0179_1		@ track
