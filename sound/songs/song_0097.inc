	.include "MPlayDef.s"

	.section .rodata

	@********************** Track  1 **********************@

	.align 2
	.global song_0097_1
song_0097_1:	@ 0x087E64B8
	.byte	KEYSH	, 0
	.byte	TEMPO	, 60
	.byte	VOICE	, 10
	.byte	VOL	, v120
	.byte		N80	, Cn3, v120
	.byte	W80
	.byte	W02
	.byte	FINE

	.align 2
	.global song_0097
song_0097:	@ 0x087E64C8
	.byte	1		@ trackCount
	.byte	0		@ blockCount
	.byte	255		@ priority
	.byte	0		@ reverb

	.word	voicegroup003		@ voicegroup/tone

	.word	song_0097_1		@ track
