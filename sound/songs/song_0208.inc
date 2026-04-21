	.include "MPlayDef.s"

	.section .rodata

	@********************** Track  1 **********************@

	.align 2
	.global song_0208_1
song_0208_1:	@ 0x087E7124
	.byte	VOL	, v127
	.byte	KEYSH	, 0
song_0208_1_1:
	.byte	TEMPO	, 60
	.byte	VOICE	, 121
	.byte		TIE	, Cn3, v100
	.byte	W96
	.byte	W96
	.byte	W52
	.byte	W01
	.byte	GOTO	
		.word	song_0208_1_1
	.byte	W01
	.byte		EOT	, Cn3
	.byte	W01
	.byte	FINE

	.align 2
	.global song_0208
song_0208:	@ 0x087E7140
	.byte	1		@ trackCount
	.byte	0		@ blockCount
	.byte	255		@ priority
	.byte	0		@ reverb

	.word	voicegroup003		@ voicegroup/tone

	.word	song_0208_1		@ track
