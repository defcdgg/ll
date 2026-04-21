	.include "MPlayDef.s"

	.section .rodata

	@********************** Track  1 **********************@

	.align 2
	.global song_0252_1
song_0252_1:	@ 0x087E761C
	.byte	KEYSH	, 0
	.byte	TEMPO	, 60
	.byte	VOICE	, 37
	.byte	VOL	, v120
	.byte		TIE	, Cn3, v120
	.byte	W96
	.byte	W96
	.byte	W88
	.byte		EOT	
	.byte	FINE

	.align 2
	.global song_0252
song_0252:	@ 0x087E762C
	.byte	1		@ trackCount
	.byte	0		@ blockCount
	.byte	255		@ priority
	.byte	0		@ reverb

	.word	voicegroup004		@ voicegroup/tone

	.word	song_0252_1		@ track
