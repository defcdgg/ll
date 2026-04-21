	.include "MPlayDef.s"

	.section .rodata

	@********************** Track  1 **********************@

	.align 2
	.global song_0214_1
song_0214_1:	@ 0x087E71DC
	.byte	VOL	, v127
	.byte	KEYSH	, 0
song_0214_1_1:
	.byte	TEMPO	, 60
	.byte	VOICE	, 127
	.byte		TIE	, Cn3, v100
	.byte	W96
	.byte	W48
	.byte	W02
	.byte	GOTO	
		.word	song_0214_1_1
	.byte	W01
	.byte		EOT	, Cn3
	.byte	W01
	.byte	FINE

	.align 2
	.global song_0214
song_0214:	@ 0x087E71F4
	.byte	1		@ trackCount
	.byte	0		@ blockCount
	.byte	255		@ priority
	.byte	0		@ reverb

	.word	voicegroup003		@ voicegroup/tone

	.word	song_0214_1		@ track
