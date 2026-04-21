	.include "MPlayDef.s"

	.section .rodata

	@********************** Track  1 **********************@

	.align 2
	.global song_0248_1
song_0248_1:	@ 0x087E75AC
	.byte	KEYSH	, 0
	.byte	TEMPO	, 60
	.byte	VOICE	, 33
	.byte	VOL	, v120
	.byte		TIE	, Cn3, v120
	.byte	W96
	.byte	W48
	.byte	W01
	.byte		EOT	
	.byte	FINE

	.align 2
	.global song_0248
song_0248:	@ 0x087E75BC
	.byte	1		@ trackCount
	.byte	0		@ blockCount
	.byte	255		@ priority
	.byte	0		@ reverb

	.word	voicegroup004		@ voicegroup/tone

	.word	song_0248_1		@ track
