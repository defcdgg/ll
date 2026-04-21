	.include "MPlayDef.s"

	.section .rodata

	@********************** Track  1 **********************@

	.align 2
	.global song_0274_1
song_0274_1:	@ 0x087E788C
	.byte	KEYSH	, 0
	.byte	TEMPO	, 60
	.byte	VOICE	, 59
	.byte	VOL	, v120
	.byte		N64	, Cn3, v120
	.byte	W66
	.byte	FINE

	.align 2
	.global song_0274
song_0274:	@ 0x087E789C
	.byte	1		@ trackCount
	.byte	0		@ blockCount
	.byte	255		@ priority
	.byte	0		@ reverb

	.word	voicegroup004		@ voicegroup/tone

	.word	song_0274_1		@ track
