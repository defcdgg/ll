	.include "MPlayDef.s"

	.section .rodata

	@********************** Track  1 **********************@

	.align 2
	.global song_0038_1
song_0038_1:	@ 0x087DEA90
	.byte	KEYSH	, 0
	.byte	TEMPO	, 125
	.byte	VOICE	, 5
	.byte	VOL	, v110
	.byte	PAN	, c_v
	.byte	W24
song_0038_1_2:
	.byte	TEMPO	, 74
	.byte		N16	, En3, v127
	.byte	W24
	.byte		N16	
	.byte	W24
	.byte			Fn3
	.byte	W48
	.byte	W96
	.byte		N30	, En3
	.byte	W36
	.byte		N04	, Bn3
	.byte	W12
	.byte		N30	
	.byte	W36
	.byte		N04	, An3
	.byte	W12
	.byte		N30	
	.byte	W36
	.byte		N04	, Gn3
	.byte	W12
	.byte		N12	
	.byte	W12
	.byte		N04	, Fn3
	.byte	W12
	.byte			Dn3
	.byte	W12
	.byte			Fn3
	.byte	W12
	.byte		N30	, En3
	.byte		N30	, Bn3
	.byte	W36
	.byte		N04	
	.byte		N04	, En4
	.byte	W12
	.byte		N30	, Bn3
	.byte		N30	, En4
	.byte	W36
	.byte		N04	, An3
	.byte		N04	, Fn4
	.byte	W12
	.byte		N30	, An3
	.byte		N30	, Fn4
	.byte	W36
	.byte		N04	, Gn3
	.byte		N04	, Cn4
	.byte	W12
	.byte		N12	, Gn3
	.byte		N12	, Cn4
	.byte	W12
	.byte		N04	, Fn3
	.byte		N04	, An3
	.byte	W12
	.byte			Dn3
	.byte		N04	, An3
	.byte	W12
	.byte			Fn3
	.byte		N04	, Dn4
	.byte	W12
	.byte		N12	, En3
	.byte		N12	, Bn3
	.byte	W96
	.byte	W96
song_0038_1_1:
	.byte		N16	, Gn2, v127
	.byte		N16	, Bn2
	.byte	W24
	.byte			Gn2
	.byte		N16	, Bn2
	.byte	W24
	.byte			An2
	.byte		N16	, Cn3
	.byte	W48
	.byte	PEND
	.byte	W96
	.byte	PATT	
		.word	song_0038_1_1
	.byte	W96
	.byte	GOTO	
		.word	song_0038_1_2
	.byte	FINE

	@********************** Track  2 **********************@

	.global song_0038_2
song_0038_2:	@ 0x087DEB10
	.byte	KEYSH	, 0
	.byte	VOICE	, 0
	.byte	VOL	, v110
	.byte	PAN	, c_v
	.byte	W24
song_0038_2_1:
	.byte		N16	, En4, v127
	.byte	W24
	.byte		N16	
	.byte	W24
	.byte			Fn4
	.byte	W48
	.byte	PEND
	.byte	W96
	.byte	PATT	
		.word	song_0038_2_1
	.byte	W96
	.byte	PATT	
		.word	song_0038_2_1
	.byte	W96
	.byte		N16	, En4, v127
	.byte	W24
	.byte		N16	
	.byte	W24
	.byte			Fn4
	.byte	W24
	.byte		N05	, An2
	.byte	W06
	.byte			Gn2
	.byte	W06
	.byte			An2
	.byte	W06
	.byte			Bn2
	.byte	W06
	.byte			Cn3
	.byte		N05	, An4
	.byte	W06
	.byte			Bn2
	.byte		N05	, Gn4
	.byte	W06
	.byte			An2
	.byte		N05	, Fn4
	.byte	W06
	.byte			Bn2
	.byte		N05	, Gn4
	.byte	W06
	.byte			Cn3
	.byte		N05	, An4
	.byte	W06
	.byte			Bn2
	.byte		N05	, Gn4
	.byte	W06
	.byte			An2
	.byte		N05	, Fn4
	.byte	W06
	.byte			Bn2
	.byte		N05	, Gn4
	.byte	W06
	.byte			Cn3
	.byte		N05	, An4
	.byte	W06
	.byte			Bn2
	.byte		N05	, Gn4
	.byte	W06
	.byte			Cn3
	.byte		N05	, An4
	.byte	W06
	.byte			Dn3
	.byte		N05	, Bn4
	.byte	W06
	.byte			En3
	.byte		N05	, Cn5
	.byte	W06
	.byte			Fn3
	.byte		N05	, Dn5
	.byte	W06
	.byte			Gn3
	.byte		N05	, En5
	.byte	W06
	.byte			An3
	.byte		N05	, Fn5
	.byte	W06
	.byte		N44	, Bn3
	.byte		N92	, Gn5
	.byte	W48
	.byte		N44	, Cn4
	.byte	W48
	.byte		N32	, An3
	.byte		N32	, Fn5
	.byte	W36
	.byte			Gn3
	.byte		N32	, En5
	.byte	W36
	.byte		N22	, Fn3
	.byte		N11	, Dn5
	.byte	W12
	.byte			Cn5
	.byte	W12
	.byte		N44	, Dn4
	.byte		N44	, Bn4
	.byte	W48
	.byte			Cn4
	.byte		N44	, Cn5
	.byte	W48
	.byte		N32	, An3
	.byte		N32	, An4
	.byte	W36
	.byte			Gn3
	.byte		N32	, Gn4
	.byte	W36
	.byte		N22	, Fn3
	.byte		N22	, Fn4
	.byte	W24
	.byte	GOTO	
		.word	song_0038_2_1
	.byte	FINE

	@********************** Track  3 **********************@

	.global song_0038_3
song_0038_3:	@ 0x087DEBB5
	.byte	KEYSH	, 0
	.byte	VOICE	, 126
	.byte	VOL	, v095
	.byte	PAN	, c_v
	.byte	W24
song_0038_3_2:
	.byte		N56	, Bn2, v127
	.byte	W60
	.byte		N12	, Fn3
	.byte	W12
	.byte			Dn4
	.byte	W12
	.byte		N12	
	.byte	W12
	.byte	PEND
song_0038_3_1:
	.byte		N12	, Dn4, v127
	.byte	W12
	.byte			Fn3
	.byte	W12
	.byte		N06	
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte		N12	, Dn4
	.byte	W12
	.byte		N06	
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte		N12	, Fn3
	.byte	W12
	.byte		N12	
	.byte	W12
	.byte			Dn4
	.byte	W12
	.byte	PEND
	.byte		N48	, Bn2
	.byte	W96
	.byte	W96
	.byte	W60
	.byte		N12	, Fn3
	.byte	W12
	.byte			Dn4
	.byte	W12
	.byte		N12	
	.byte	W12
	.byte	PATT	
		.word	song_0038_3_1
	.byte	W96
	.byte	W96
	.byte	PATT	
		.word	song_0038_3_2
	.byte	PATT	
		.word	song_0038_3_1
	.byte	W96
	.byte	W96
	.byte	GOTO	
		.word	song_0038_3_2
	.byte	FINE

	.align 2
	.global song_0038
song_0038:	@ 0x087DEC08
	.byte	3		@ trackCount
	.byte	0		@ blockCount
	.byte	10		@ priority
	.byte	168		@ reverb

	.word	voicegroup000		@ voicegroup/tone

	.word	song_0038_1		@ track
	.word	song_0038_2		@ track
	.word	song_0038_3		@ track
