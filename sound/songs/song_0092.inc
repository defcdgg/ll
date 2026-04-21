	.include "MPlayDef.s"

	.section .rodata

	@********************** Track  1 **********************@

	.align 2
	.global song_0092_1
song_0092_1:	@ 0x087E642C
	.byte	VOL	, v127
	.byte	KEYSH	, 0
	.byte	TEMPO	, 60
	.byte	VOICE	, 5
	.byte		N32	, Cn3, v100
	.byte	W32
	.byte	W03
	.byte	FINE

	.align 2
	.global song_0092
song_0092:	@ 0x087E643C
	.byte	1		@ trackCount
	.byte	0		@ blockCount
	.byte	255		@ priority
	.byte	0		@ reverb

	.word	voicegroup003		@ voicegroup/tone

	.word	song_0092_1		@ track
