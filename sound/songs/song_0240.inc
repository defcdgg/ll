	.include "MPlayDef.s"

	.section .rodata

	@********************** Track  1 **********************@

	.align 2
	.global song_0240_1
song_0240_1:	@ 0x087E74C8
	.byte	KEYSH	, 0
	.byte	TEMPO	, 60
	.byte	VOICE	, 25
	.byte	VOL	, v120
	.byte		TIE	, Cn3, v120
	.byte	W96
	.byte	W84
	.byte	W03
	.byte		EOT	
	.byte	FINE

	.align 2
	.global song_0240
song_0240:	@ 0x087E74D8
	.byte	1		@ trackCount
	.byte	0		@ blockCount
	.byte	255		@ priority
	.byte	0		@ reverb

	.word	voicegroup004		@ voicegroup/tone

	.word	song_0240_1		@ track
