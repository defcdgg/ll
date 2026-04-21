	.include "MPlayDef.s"

	.section .rodata

	@********************** Track  1 **********************@

	.align 2
	.global song_0216_1
song_0216_1:	@ 0x087E721C
	.byte	VOL	, v127
	.byte	KEYSH	, 0
song_0216_1_1:
	.byte	TEMPO	, 60
	.byte	VOICE	, 1
	.byte		TIE	, Cn3, v100
	.byte	W96
	.byte	W21
	.byte		EOT	
	.byte	GOTO	
		.word	song_0216_1_1
	.byte	W01
	.byte	FINE

	.align 2
	.global song_0216
song_0216:	@ 0x087E7234
	.byte	1		@ trackCount
	.byte	0		@ blockCount
	.byte	255		@ priority
	.byte	0		@ reverb

	.word	voicegroup004		@ voicegroup/tone

	.word	song_0216_1		@ track
