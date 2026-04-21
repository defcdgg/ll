	.include "MPlayDef.s"

	.section .rodata

	@********************** Track  1 **********************@

	.align 2
	.global song_0230_1
song_0230_1:	@ 0x087E73B0
	.byte	KEYSH	, 0
	.byte	TEMPO	, 60
	.byte	VOICE	, 15
	.byte	VOL	, v120
	.byte		N22	, Cn3, v120
	.byte	W22
	.byte	FINE

	.align 2
	.global song_0230
song_0230:	@ 0x087E73C0
	.byte	1		@ trackCount
	.byte	0		@ blockCount
	.byte	255		@ priority
	.byte	0		@ reverb

	.word	voicegroup004		@ voicegroup/tone

	.word	song_0230_1		@ track
