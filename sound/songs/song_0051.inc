	.include "MPlayDef.s"

	.section .rodata

	@********************** Track  1 **********************@

	.align 2
	.global song_0051_1
song_0051_1:	@ 0x087E2490
	.byte	KEYSH	, 0
	.byte	TEMPO	, 125
	.byte	VOICE	, 2
	.byte	VOL	, v075
	.byte	PAN	, c_v
	.byte	W24
song_0051_1_8:
	.byte	TEMPO	, 56
	.byte	W60
	.byte		N11	, Fs4, v127
	.byte	W12
	.byte		N13	, Fn4
	.byte	W12
	.byte		N14	, Fs4
	.byte	W12
song_0051_1_1:
	.byte		N24	, An4, v127
	.byte	W23
	.byte			Gn4
	.byte	W72
	.byte	W01
	.byte	PEND
song_0051_1_2:
	.byte	W56
	.byte	W03
	.byte		N14	, Gn4, v127
	.byte	W12
	.byte		N12	, Fs4
	.byte	W12
	.byte		N13	, Gn4
	.byte	W12
	.byte		N23	, Bn4
	.byte	W01
	.byte	PEND
song_0051_1_3:
	.byte	W23
	.byte		N24	, An4, v127
	.byte	W72
	.byte	W01
	.byte	PEND
song_0051_1_4:
	.byte	W23
	.byte		N08	, Dn4, v127
	.byte	W12
	.byte		N21	, Dn5
	.byte	W24
	.byte		N08	, Cn5
	.byte	W12
	.byte		N11	, Bn4
	.byte	W12
	.byte			An4
	.byte	W12
	.byte		N17	, Bn4
	.byte	W01
	.byte	PEND
song_0051_1_5:
	.byte	W23
	.byte		N24	, Gn4, v127
	.byte	W24
	.byte		N23	, Fs4
	.byte	W24
	.byte		N21	, En4
	.byte	W24
	.byte		N22	, An4
	.byte	W01
	.byte	PEND
song_0051_1_6:
	.byte	W32
	.byte	W03
	.byte		N05	, Dn4, v127
	.byte	W12
	.byte		N09	, Fs4
	.byte	W07
	.byte		N03	, En4
	.byte	W05
	.byte		N04	, Fs4
	.byte	W05
	.byte		N03	, En4
	.byte	W05
	.byte			Fs4
	.byte	W04
	.byte			En4
	.byte	W04
	.byte			Fs4
	.byte	W03
	.byte			En4
	.byte	W04
	.byte			Fs4
	.byte	W03
	.byte		N02	, En4
	.byte	W03
	.byte		N03	, Dn4
	.byte	W03
	.byte		N04	, En4
	.byte	W03
	.byte	PEND
	.byte		N12	, Dn4
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
song_0051_1_7:
	.byte	W11
	.byte		N12	, Ds4, v127
	.byte	W12
	.byte		N13	, En4
	.byte	W12
	.byte		N12	, Fs4
	.byte	W12
	.byte		N24	, An4
	.byte	W24
	.byte		N21	, Gn4
	.byte	W24
	.byte	W01
	.byte	PEND
	.byte	W11
	.byte		N11	, Cs4
	.byte	W12
	.byte		N12	, Dn4
	.byte	W12
	.byte			En4
	.byte	W12
	.byte		N13	, Gn4
	.byte	W12
	.byte		N14	, Fs4
	.byte	W12
	.byte		N11	, En4
	.byte	W12
	.byte		N12	, Dn4
	.byte	W12
	.byte		N36	, Bn3
	.byte	W01
	.byte	W32
	.byte	W03
	.byte		N07	, Cs4
	.byte	W06
	.byte			Dn4
	.byte	W06
	.byte		N13	, An3
	.byte	W12
	.byte			Bn3
	.byte	W12
	.byte			Cs4
	.byte	W12
	.byte		N12	, Dn4
	.byte	W12
	.byte			Gn3
	.byte	W01
	.byte	W11
	.byte			An3
	.byte	W12
	.byte		N13	, Bn3
	.byte	W12
	.byte			Cs4
	.byte	W12
	.byte		N12	, Dn4
	.byte	W12
	.byte		N13	, Cs4
	.byte	W12
	.byte		N15	, Bn3
	.byte	W12
	.byte		N12	, Cs4
	.byte	W13
	.byte			Dn4
	.byte	W60
	.byte		N11	, Fs4
	.byte	W12
	.byte		N13	, Fn4
	.byte	W12
	.byte		N14	, Fs4
	.byte	W12
	.byte	PATT	
		.word	song_0051_1_1
	.byte	PATT	
		.word	song_0051_1_2
	.byte	PATT	
		.word	song_0051_1_3
	.byte	PATT	
		.word	song_0051_1_4
	.byte	PATT	
		.word	song_0051_1_5
	.byte	PATT	
		.word	song_0051_1_6
	.byte		N12	, Dn4, v127
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	PATT	
		.word	song_0051_1_7
	.byte	W12
	.byte		N14	, Fs4, v127
	.byte	W12
	.byte			Gs4
	.byte	W12
	.byte			As4
	.byte	W12
	.byte			Cs5
	.byte	W12
	.byte			Bn4
	.byte	W12
	.byte			Cs5
	.byte	W12
	.byte		N10	, Dn5
	.byte	W12
	.byte		N04	
	.byte	W12
	.byte		N04	
	.byte	W12
	.byte			Bn4
	.byte	W12
	.byte		N04	
	.byte	W12
	.byte			Gn4
	.byte	W12
	.byte		N04	
	.byte	W12
	.byte			Dn4
	.byte	W12
	.byte		N04	
	.byte	W12
	.byte			As4
	.byte	W12
	.byte		N04	
	.byte	W12
	.byte			Gn4
	.byte	W12
	.byte		N04	
	.byte	W12
	.byte			Dn4
	.byte	W12
	.byte		N04	
	.byte	W12
	.byte			As3
	.byte	W12
	.byte		N04	
	.byte	W12
	.byte	W12
	.byte		N11	, Fs3
	.byte	W12
	.byte			Gn3
	.byte	W12
	.byte			An3
	.byte	W12
	.byte			Bn3
	.byte	W12
	.byte			Cs4
	.byte	W12
	.byte			Dn4
	.byte	W12
	.byte			Fs4
	.byte	W12
	.byte		N05	, Gn4
	.byte	W06
	.byte		N05	
	.byte	W06
	.byte			Fs4
	.byte	W06
	.byte		N05	
	.byte	W06
	.byte			En4
	.byte	W06
	.byte		N05	
	.byte	W06
	.byte			Dn4
	.byte	W06
	.byte		N05	
	.byte	W06
	.byte			An4
	.byte	W06
	.byte		N05	
	.byte	W06
	.byte			Gn4
	.byte	W06
	.byte		N05	
	.byte	W06
	.byte			Fs4
	.byte	W06
	.byte		N05	
	.byte	W06
	.byte			En4
	.byte	W06
	.byte		N05	
	.byte	W06
	.byte		N16	, Dn4
	.byte	W48
	.byte			Dn5
	.byte	W48
	.byte	GOTO	
		.word	song_0051_1_8
	.byte	FINE

	@********************** Track  2 **********************@

	.global song_0051_2
song_0051_2:	@ 0x087E260B
	.byte	KEYSH	, 0
	.byte	VOICE	, 0
	.byte	VOL	, v075
	.byte	PAN	, c_v
	.byte	W24
song_0051_2_1:
	.byte		N05	, Dn4, v127
	.byte	W06
	.byte			Fs4
	.byte	W06
	.byte			Dn4
	.byte	W06
	.byte			Fs4
	.byte	W06
	.byte			Dn4
	.byte	W06
	.byte			Fs4
	.byte	W06
	.byte			Dn4
	.byte	W06
	.byte			Fs4
	.byte	W06
	.byte			Dn4
	.byte	W06
	.byte			Fs4
	.byte	W06
	.byte			Dn4
	.byte	W06
	.byte			Fs4
	.byte	W06
	.byte			Dn4
	.byte	W06
	.byte			Fs4
	.byte	W06
	.byte			Dn4
	.byte	W06
	.byte			Fs4
	.byte	W06
	.byte	PEND
song_0051_2_2:
	.byte		N05	, Dn4, v127
	.byte	W06
	.byte			En4
	.byte	W06
	.byte			Dn4
	.byte	W06
	.byte			En4
	.byte	W06
	.byte			Dn4
	.byte	W06
	.byte			En4
	.byte	W06
	.byte			Dn4
	.byte	W06
	.byte			En4
	.byte	W06
	.byte			Dn4
	.byte	W06
	.byte			En4
	.byte	W06
	.byte			Dn4
	.byte	W06
	.byte			En4
	.byte	W06
	.byte			Dn4
	.byte	W06
	.byte			En4
	.byte	W06
	.byte			Dn4
	.byte	W06
	.byte			En4
	.byte	W06
	.byte	PEND
song_0051_2_3:
	.byte		N05	, Cs4, v127
	.byte	W06
	.byte			En4
	.byte	W06
	.byte			Cs4
	.byte	W06
	.byte			En4
	.byte	W06
	.byte			Cs4
	.byte	W06
	.byte			En4
	.byte	W06
	.byte			Cs4
	.byte	W06
	.byte			En4
	.byte	W06
	.byte			Cs4
	.byte	W06
	.byte			En4
	.byte	W06
	.byte			Cs4
	.byte	W06
	.byte			En4
	.byte	W06
	.byte			Cs4
	.byte	W06
	.byte			En4
	.byte	W06
	.byte			Cs4
	.byte	W06
	.byte			En4
	.byte	W06
	.byte	PEND
	.byte	PATT	
		.word	song_0051_2_1
song_0051_2_4:
	.byte		N05	, Cn4, v127
	.byte	W06
	.byte			Dn4
	.byte	W06
	.byte			Cn4
	.byte	W06
	.byte			Dn4
	.byte	W06
	.byte			Cn4
	.byte	W06
	.byte			Dn4
	.byte	W06
	.byte			Cn4
	.byte	W06
	.byte			Dn4
	.byte	W06
	.byte			Cn4
	.byte	W06
	.byte			Dn4
	.byte	W06
	.byte			Cn4
	.byte	W06
	.byte			Dn4
	.byte	W06
	.byte			Cn4
	.byte	W06
	.byte			Dn4
	.byte	W06
	.byte			Cn4
	.byte	W06
	.byte			Dn4
	.byte	W06
	.byte	PEND
song_0051_2_5:
	.byte		N05	, Bn3, v127
	.byte	W06
	.byte			Dn4
	.byte	W06
	.byte			Bn3
	.byte	W06
	.byte			Dn4
	.byte	W06
	.byte			Bn3
	.byte	W06
	.byte			Dn4
	.byte	W06
	.byte			Bn3
	.byte	W06
	.byte			Dn4
	.byte	W06
	.byte			Bn3
	.byte	W06
	.byte			En4
	.byte	W06
	.byte			Bn3
	.byte	W06
	.byte			En4
	.byte	W06
	.byte			Bn3
	.byte	W06
	.byte			En4
	.byte	W06
	.byte			Bn3
	.byte	W06
	.byte			En4
	.byte	W06
	.byte	PEND
song_0051_2_6:
	.byte		N05	, An3, v127
	.byte	W06
	.byte			Dn4
	.byte	W06
	.byte			An3
	.byte	W06
	.byte			Dn4
	.byte	W06
	.byte			An3
	.byte	W06
	.byte			Dn4
	.byte	W06
	.byte			An3
	.byte	W06
	.byte			Dn4
	.byte	W06
	.byte			An3
	.byte	W06
	.byte			Cs4
	.byte	W06
	.byte			An3
	.byte	W06
	.byte			Cs4
	.byte	W06
	.byte			An3
	.byte	W06
	.byte			Cs4
	.byte	W06
	.byte			An3
	.byte	W06
	.byte			Cs4
	.byte	W06
	.byte	PEND
	.byte	PATT	
		.word	song_0051_2_1
	.byte	PATT	
		.word	song_0051_2_2
	.byte	PATT	
		.word	song_0051_2_3
	.byte	PATT	
		.word	song_0051_2_1
song_0051_2_7:
	.byte		N32	, Ds4, v127
	.byte		N44	, Fs4
	.byte	W36
	.byte	W02
	.byte		N06	, Cs4
	.byte	W05
	.byte			Ds4
	.byte	W05
	.byte		N44	, En4
	.byte		N44	, Gn4
	.byte	W48
	.byte	PEND
	.byte		N32	, Cs4
	.byte		N44	, En4
	.byte	W36
	.byte	W02
	.byte		N06	, Bn3
	.byte	W05
	.byte			Cs4
	.byte	W05
	.byte		N44	, Dn4
	.byte		N44	, Fs4
	.byte	W48
	.byte			Bn3
	.byte		N44	, Dn4
	.byte	W48
	.byte		N44	
	.byte		N44	, En4
	.byte	W48
	.byte			Cs4
	.byte		N44	, En4
	.byte	W48
	.byte		N22	, An3
	.byte		N22	, En4
	.byte	W24
	.byte			Cs4
	.byte		N22	, Gn4
	.byte	W24
	.byte	PATT	
		.word	song_0051_2_1
	.byte	PATT	
		.word	song_0051_2_2
	.byte	PATT	
		.word	song_0051_2_3
	.byte	PATT	
		.word	song_0051_2_1
	.byte	PATT	
		.word	song_0051_2_4
	.byte	PATT	
		.word	song_0051_2_5
	.byte	PATT	
		.word	song_0051_2_6
	.byte	PATT	
		.word	song_0051_2_1
	.byte	PATT	
		.word	song_0051_2_2
	.byte	PATT	
		.word	song_0051_2_3
	.byte	PATT	
		.word	song_0051_2_1
	.byte	PATT	
		.word	song_0051_2_7
	.byte		N36	, Cs4, v127
	.byte		N44	, En4
	.byte	W36
	.byte	W02
	.byte		N06	, Bn3
	.byte	W05
	.byte			Cs4
	.byte	W05
	.byte		N44	, Dn4
	.byte		N44	, Fs4
	.byte	W48
	.byte		N04	, Gn5
	.byte		N04	, Bn5
	.byte	W12
	.byte			Gn5
	.byte		N04	, Bn5
	.byte	W12
	.byte			Dn5
	.byte		N04	, Gn5
	.byte	W12
	.byte			Dn5
	.byte		N04	, Gn5
	.byte	W12
	.byte			Bn4
	.byte		N04	, Dn5
	.byte	W12
	.byte			Bn4
	.byte		N04	, Dn5
	.byte	W12
	.byte			Gn4
	.byte		N04	, Bn4
	.byte	W12
	.byte			Gn4
	.byte		N04	, Bn4
	.byte	W12
	.byte			Dn5
	.byte		N04	, Gn5
	.byte	W12
	.byte			Dn5
	.byte		N04	, Gn5
	.byte	W12
	.byte			As4
	.byte		N04	, Dn5
	.byte	W12
	.byte			As4
	.byte		N04	, Dn5
	.byte	W12
	.byte			Gn4
	.byte		N04	, As4
	.byte	W12
	.byte			Gn4
	.byte		N04	, As4
	.byte	W12
	.byte			En4
	.byte		N04	, Gn4
	.byte	W12
	.byte			En4
	.byte		N04	, Gn4
	.byte	W12
	.byte		N44	, An3
	.byte		N44	, Dn4
	.byte	W48
	.byte			Bn3
	.byte		N44	, Dn4
	.byte	W48
	.byte		N06	, Bn3
	.byte		N05	, Bn4
	.byte	W06
	.byte		N05	
	.byte	W06
	.byte		N22	, Bn3
	.byte		N05	, An4
	.byte	W06
	.byte		N05	
	.byte	W06
	.byte			Gn4
	.byte	W06
	.byte		N05	
	.byte	W06
	.byte		N08	, Bn3
	.byte		N05	, Fs4
	.byte	W06
	.byte		N05	
	.byte	W06
	.byte		N06	, Cs4
	.byte		N05	, Cs5
	.byte	W06
	.byte		N05	
	.byte	W06
	.byte		N22	, Cs4
	.byte		N05	, Bn4
	.byte	W06
	.byte		N05	
	.byte	W06
	.byte			An4
	.byte	W06
	.byte		N05	
	.byte	W06
	.byte		N08	, Cs4
	.byte		N05	, Gn4
	.byte	W06
	.byte		N05	
	.byte	W06
	.byte		N16	, Dn4
	.byte		N16	, Fs4
	.byte	W24
	.byte		N06	, An3
	.byte	W06
	.byte			Gn3
	.byte	W06
	.byte			Fs3
	.byte	W06
	.byte			En3
	.byte	W06
	.byte		N16	, Dn4
	.byte		N16	, An4
	.byte	W48
	.byte	GOTO	
		.word	song_0051_2_1
	.byte	FINE

	@********************** Track  3 **********************@

	.global song_0051_3
song_0051_3:	@ 0x087E2818
	.byte	KEYSH	, 0
	.byte	VOICE	, 17
	.byte	VOL	, v075
	.byte	PAN	, c_v
	.byte	W24
song_0051_3_6:
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
song_0051_3_1:
	.byte	W60
	.byte		N13	, Fs3, v127
	.byte	W12
	.byte		N11	, Fn3
	.byte	W11
	.byte		N13	, Fs3
	.byte	W13
	.byte	PEND
song_0051_3_2:
	.byte		N24	, An3, v127
	.byte	W24
	.byte			Gn3
	.byte	W72
	.byte	PEND
song_0051_3_3:
	.byte	W56
	.byte	W03
	.byte		N13	, Gn3, v127
	.byte	W12
	.byte		N11	, Fs3
	.byte	W12
	.byte			Gn3
	.byte	W12
	.byte		N24	, Bn3
	.byte	W01
	.byte	PEND
song_0051_3_4:
	.byte	W23
	.byte		N24	, An3, v127
	.byte	W72
	.byte	W01
	.byte	PEND
song_0051_3_5:
	.byte		N44	, Bn2, v127
	.byte	W48
	.byte			En3
	.byte	W48
	.byte	PEND
	.byte			An2
	.byte	W48
	.byte			Dn3
	.byte	W48
	.byte			Gn2
	.byte	W48
	.byte			An2
	.byte	W48
	.byte		N44	
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	PATT	
		.word	song_0051_3_1
	.byte	PATT	
		.word	song_0051_3_2
	.byte	PATT	
		.word	song_0051_3_3
	.byte	PATT	
		.word	song_0051_3_4
	.byte	PATT	
		.word	song_0051_3_5
	.byte		N44	, Fs2, v127
	.byte	W48
	.byte			Bn2
	.byte	W48
	.byte	W60
	.byte		N11	, En3
	.byte	W12
	.byte			Fs3
	.byte	W12
	.byte			Gn3
	.byte	W12
	.byte		N92	
	.byte	W96
	.byte		N44	, Fs3
	.byte	W48
	.byte			Bn2
	.byte	W48
	.byte		N06	, En3
	.byte	W12
	.byte		N22	
	.byte	W24
	.byte		N08	
	.byte	W12
	.byte		N06	, An2
	.byte	W12
	.byte		N22	
	.byte	W24
	.byte		N08	
	.byte	W12
	.byte		N16	, Dn3
	.byte	W24
	.byte		N06	, An2
	.byte	W06
	.byte			Gn2
	.byte	W06
	.byte			Fs2
	.byte	W06
	.byte			En2
	.byte	W06
	.byte		N16	, Dn2
	.byte	W48
	.byte	GOTO	
		.word	song_0051_3_6
	.byte	FINE

	@********************** Track  4 **********************@

	.global song_0051_4
song_0051_4:	@ 0x087E28BA
	.byte	KEYSH	, 0
	.byte	VOICE	, 19
	.byte	VOL	, v075
	.byte	PAN	, c_v
	.byte	W24
song_0051_4_1:
	.byte		N44	, Dn1, v127
	.byte	W48
	.byte			Dn2
	.byte	W48
	.byte	PEND
song_0051_4_2:
	.byte		N44	, En2, v127
	.byte	W48
	.byte		N22	
	.byte	W24
	.byte			Bn1
	.byte	W24
	.byte	PEND
song_0051_4_3:
	.byte		N44	, An1, v127
	.byte	W48
	.byte			An2
	.byte	W48
	.byte	PEND
song_0051_4_4:
	.byte		N44	, Dn2, v127
	.byte	W48
	.byte		N22	
	.byte	W24
	.byte			An1
	.byte	W24
	.byte	PEND
	.byte	PATT	
		.word	song_0051_4_1
song_0051_4_5:
	.byte		N44	, Gn1, v127
	.byte	W48
	.byte			En1
	.byte	W48
	.byte	PEND
song_0051_4_6:
	.byte		N44	, An1, v127
	.byte	W48
	.byte		N44	
	.byte	W48
	.byte	PEND
song_0051_4_7:
	.byte		N44	, Dn1, v127
	.byte	W24
	.byte		N07	, Fs3
	.byte		N07	, Dn4
	.byte	W24
	.byte		N05	, Fs4
	.byte		N05	, Dn5
	.byte	W48
	.byte	PEND
song_0051_4_8:
	.byte		N24	, En3, v127
	.byte	W24
	.byte		N04	, Gn3
	.byte		N04	, En4
	.byte	W24
	.byte		N05	, Gn4
	.byte		N05	, En5
	.byte	W48
	.byte	PEND
song_0051_4_9:
	.byte		N22	, An2, v127
	.byte	W24
	.byte		N05	, En3
	.byte		N05	, An3
	.byte	W24
	.byte		N04	, En4
	.byte		N04	, An4
	.byte	W48
	.byte	PEND
song_0051_4_10:
	.byte		N22	, Dn3, v127
	.byte	W24
	.byte		N05	, An3
	.byte		N05	, Dn4
	.byte	W24
	.byte		N07	, An4
	.byte		N07	, Dn5
	.byte	W48
	.byte	PEND
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W72
	.byte		N22	, An1
	.byte	W24
	.byte	PATT	
		.word	song_0051_4_1
	.byte	PATT	
		.word	song_0051_4_2
	.byte	PATT	
		.word	song_0051_4_3
	.byte	PATT	
		.word	song_0051_4_4
	.byte	PATT	
		.word	song_0051_4_1
	.byte	PATT	
		.word	song_0051_4_5
	.byte	PATT	
		.word	song_0051_4_6
	.byte	PATT	
		.word	song_0051_4_7
	.byte	PATT	
		.word	song_0051_4_8
	.byte	PATT	
		.word	song_0051_4_9
	.byte	PATT	
		.word	song_0051_4_10
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	GOTO	
		.word	song_0051_4_1
	.byte	FINE

	.align 2
	.global song_0051
song_0051:	@ 0x087E2980
	.byte	4		@ trackCount
	.byte	0		@ blockCount
	.byte	10		@ priority
	.byte	168		@ reverb

	.word	voicegroup000		@ voicegroup/tone

	.word	song_0051_1		@ track
	.word	song_0051_2		@ track
	.word	song_0051_3		@ track
	.word	song_0051_4		@ track
