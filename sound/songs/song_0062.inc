	.include "MPlayDef.s"

	.section .rodata

	@********************** Track  1 **********************@

	.align 2
	.global song_0062_1
song_0062_1:	@ 0x087E60A8
	.byte	KEYSH	, 0
	.byte	TEMPO	, 125
	.byte	VOICE	, 8
	.byte	VOL	, v094
	.byte	PAN	, c_v
	.byte	W24
	.byte		N24	, Cn4, v127
	.byte	W24
	.byte		N04	, Gn4
	.byte	W12
	.byte		N24	
	.byte	W24
	.byte	TEMPO	, 65
	.byte		N04	, Cn3
	.byte		N04	, Cn4
	.byte	W06
	.byte	TEMPO	, 63
	.byte	W06
	.byte	TEMPO	, 61
	.byte		N18	, Fn3
	.byte		N18	, Dn4
	.byte	W06
	.byte	TEMPO	, 58
	.byte	W06
	.byte	TEMPO	, 54
	.byte	W06
	.byte	TEMPO	, 51
	.byte		N06	, En3
	.byte		N06	, En4
	.byte	W06
	.byte	TEMPO	, 47
	.byte		N08	, Dn3
	.byte		N08	, Fn4
	.byte	W06
	.byte	TEMPO	, 42
	.byte	W06
	.byte	TEMPO	, 36
	.byte			Cn3
	.byte	W01
	.byte			En4
	.byte	W01
	.byte			Cn5
	.byte	W08
	.byte	FINE

	.align 2
	.global song_0062
song_0062:	@ 0x087E60F0
	.byte	1		@ trackCount
	.byte	0		@ blockCount
	.byte	10		@ priority
	.byte	168		@ reverb

	.word	voicegroup000		@ voicegroup/tone

	.word	song_0062_1		@ track
