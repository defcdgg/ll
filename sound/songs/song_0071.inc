	.include "MPlayDef.s"

	.section .rodata

	@********************** Track  1 **********************@

	.align 2
	.global song_0071_1
song_0071_1:	@ 0x087E61DC
	.byte	KEYSH	, 0
	.byte	TEMPO	, 60
	.byte	VOICE	, 8
	.byte	VOL	, v120
	.byte		N08	, Cn3, v120
	.byte	W09
	.byte	FINE

	.align 2
	.global song_0071
song_0071:	@ 0x087E61EC
	.byte	1		@ trackCount
	.byte	0		@ blockCount
	.byte	255		@ priority
	.byte	0		@ reverb

	.word	voicegroup002		@ voicegroup/tone

	.word	song_0071_1		@ track
