	.include "MPlayDef.s"

	.section .rodata

	@********************** Track  1 **********************@

	.align 2
	.global song_0049_1
song_0049_1:	@ 0x087E22C8
	.byte	KEYSH	, 0
	.byte	TEMPO	, 125
	.byte	VOICE	, 8
	.byte	VOL	, v094
	.byte	PAN	, c_v
	.byte	W24
song_0049_1_1:
	.byte	TEMPO	, 30
	.byte		N19	, An3, v127
	.byte		N24	, Fn4
	.byte	W24
	.byte		TIE	, Dn3
	.byte	W12
	.byte		N11	, An3
	.byte	W12
	.byte			Cn4
	.byte	W12
	.byte			An3
	.byte	W12
	.byte		N08	, Ds4
	.byte	W12
	.byte		N11	, Fn4
	.byte	W12
	.byte		N92	, Fn3
	.byte		N92	, As3
	.byte		N68	, Dn4
	.byte	W72
	.byte		N09	, Ds4
	.byte	W12
	.byte		N08	, Fn4
	.byte	W10
	.byte		EOT	, Dn3
	.byte	W02
	.byte		N21	, Cn4
	.byte		N32	, Ds4
	.byte		N30	, Gn4
	.byte	W12
	.byte		N11	, Ds3
	.byte	W12
	.byte			Gs3
	.byte	W12
	.byte		N12	, Cn4
	.byte	W12
	.byte			Ds4
	.byte	W12
	.byte		N11	, Cn4
	.byte	W12
	.byte			Gn4
	.byte	W12
	.byte			Gs4
	.byte	W12
	.byte		N92	, Gn3
	.byte		N92	, As3
	.byte		N92	, Dn4
	.byte		N44	, Fn4
	.byte	W48
	.byte		N23	, Gn4
	.byte	W24
	.byte			Gs4
	.byte	W24
	.byte	W01
	.byte		N92	, Dn4
	.byte		N56	, Fn4
	.byte		N56	, As4
	.byte	W56
	.byte	W03
	.byte		N18	, Gs4
	.byte	W20
	.byte		N07	, Gn4
	.byte	W08
	.byte		N06	, Fn4
	.byte	W08
	.byte		N44	, Cn4
	.byte		N44	, Ds4
	.byte		N44	, Gn4
	.byte	W48
	.byte			As3
	.byte		N23	, Ds4
	.byte	W24
	.byte		N22	, Gn4
	.byte	W24
	.byte		N56	, An3
	.byte		N13	, Cn4
	.byte		N07	, Ds4
	.byte		N07	, Gn4
	.byte	W08
	.byte		N05	, Fn4
	.byte	W08
	.byte		N42	, Cn4
	.byte		N42	, Fn4
	.byte	W44
	.byte		N12	, Cn4
	.byte	W12
	.byte			Dn4
	.byte	W12
	.byte		N11	, Ds4
	.byte	W12
	.byte		N48	, Fn3
	.byte		N48	, Bn3
	.byte		N48	, Dn4
	.byte	W48
	.byte		N24	, Cn4
	.byte	W24
	.byte			Dn4
	.byte	W24
	.byte	GOTO	
		.word	song_0049_1_1
	.byte	FINE

	.align 2
	.global song_0049
song_0049:	@ 0x087E236C
	.byte	1		@ trackCount
	.byte	0		@ blockCount
	.byte	10		@ priority
	.byte	208		@ reverb

	.word	voicegroup000		@ voicegroup/tone

	.word	song_0049_1		@ track
