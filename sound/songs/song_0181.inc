	.include "MPlayDef.s"

	.section .rodata

	@********************** Track  1 **********************@

	.align 2
	.global song_0181_1
song_0181_1:	@ 0x087E6E24
	.byte	KEYSH	, 0
	.byte	TEMPO	, 60
	.byte	VOICE	, 94
	.byte	VOL	, v120
	.byte		TIE	, Cn3, v120
	.byte	W96
	.byte	W48
	.byte	W02
	.byte		EOT	
	.byte	W01
	.byte	FINE

	.align 2
	.global song_0181
song_0181:	@ 0x087E6E38
	.byte	1		@ trackCount
	.byte	0		@ blockCount
	.byte	255		@ priority
	.byte	0		@ reverb

	.word	voicegroup003		@ voicegroup/tone

	.word	song_0181_1		@ track
