	.include "MPlayDef.s"

	.section .rodata

	@********************** Track  1 **********************@

	.align 2
	.global song_0065_1
song_0065_1:	@ 0x087E6134
	.byte	KEYSH	, 0
	.byte	TEMPO	, 60
	.byte	VOICE	, 2
	.byte	VOL	, v120
	.byte		N32	, Cn3, v120
	.byte	W32
	.byte	W01
	.byte	FINE

	.align 2
	.global song_0065
song_0065:	@ 0x087E6144
	.byte	1		@ trackCount
	.byte	0		@ blockCount
	.byte	255		@ priority
	.byte	0		@ reverb

	.word	voicegroup002		@ voicegroup/tone

	.word	song_0065_1		@ track
