	.include "MPlayDef.s"

	.section .rodata

	@********************** Track  1 **********************@

	.align 2
	.global song_0102_1
song_0102_1:	@ 0x087E6548
	.byte	VOL	, v127
	.byte	KEYSH	, 0
	.byte	TEMPO	, 60
	.byte	VOICE	, 15
	.byte		TIE	, Cn3, v100
	.byte	W96
song_0102_1_1:
	.byte	W36
	.byte	W03
	.byte	GOTO	
		.word	song_0102_1_1
	.byte	W01
	.byte		EOT	, Cn3
	.byte	FINE

	.align 2
	.global song_0102
song_0102:	@ 0x087E6560
	.byte	1		@ trackCount
	.byte	0		@ blockCount
	.byte	255		@ priority
	.byte	0		@ reverb

	.word	voicegroup003		@ voicegroup/tone

	.word	song_0102_1		@ track
