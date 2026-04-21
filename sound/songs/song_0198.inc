	.include "MPlayDef.s"

	.section .rodata

	@********************** Track  1 **********************@

	.align 2
	.global song_0198_1
song_0198_1:	@ 0x087E700C
	.byte	VOL	, v127
	.byte	KEYSH	, 0
	.byte	TEMPO	, 60
	.byte	VOICE	, 111
	.byte		N28	, Cn3, v100
	.byte	W30
	.byte	FINE

	.align 2
	.global song_0198
song_0198:	@ 0x087E701C
	.byte	1		@ trackCount
	.byte	0		@ blockCount
	.byte	255		@ priority
	.byte	0		@ reverb

	.word	voicegroup003		@ voicegroup/tone

	.word	song_0198_1		@ track
