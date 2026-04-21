	.include "MPlayDef.s"

	.section .rodata

	@********************** Track  1 **********************@

	.align 2
	.global song_0266_1
song_0266_1:	@ 0x087E77AC
	.byte	KEYSH	, 0
	.byte	TEMPO	, 60
	.byte	VOICE	, 51
	.byte	VOL	, v120
	.byte		N56	, Cn3, v120
	.byte	W56
	.byte	W01
	.byte	FINE

	.align 2
	.global song_0266
song_0266:	@ 0x087E77BC
	.byte	1		@ trackCount
	.byte	0		@ blockCount
	.byte	255		@ priority
	.byte	0		@ reverb

	.word	voicegroup004		@ voicegroup/tone

	.word	song_0266_1		@ track
