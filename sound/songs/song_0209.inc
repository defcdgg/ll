	.include "MPlayDef.s"

	.section .rodata

	@********************** Track  1 **********************@

	.align 2
	.global song_0209_1
song_0209_1:	@ 0x087E714C
	.byte	KEYSH	, 0
	.byte	TEMPO	, 60
	.byte	VOICE	, 122
	.byte	VOL	, v120
	.byte		TIE	, Cn3, v120
	.byte	W96
	.byte	W66
	.byte	W01
	.byte		EOT	
	.byte	FINE

	.align 2
	.global song_0209
song_0209:	@ 0x087E715C
	.byte	1		@ trackCount
	.byte	0		@ blockCount
	.byte	255		@ priority
	.byte	0		@ reverb

	.word	voicegroup003		@ voicegroup/tone

	.word	song_0209_1		@ track
