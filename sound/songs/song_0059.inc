	.include "MPlayDef.s"

	.section .rodata

	@********************** Track  1 **********************@

	.align 2
	.global song_0059_1
song_0059_1:	@ 0x087E5868
	.byte	KEYSH	, 0
	.byte	TEMPO	, 125
	.byte	VOICE	, 6
	.byte	VOL	, v086
	.byte	PAN	, c_v
	.byte	BEND	, c_v
	.byte	W24
	.byte	TEMPO	, 42
	.byte		TIE	, Gn3, v100
	.byte		TIE	, Cn4
	.byte	W48
	.byte	W48
	.byte	W48
	.byte	W32
	.byte	W02
	.byte		EOT	, Gn3
	.byte			Cn4
	.byte	W14
song_0059_1_4:
	.byte		N92	, Gn3, v080
	.byte	W96
	.byte			Fn3
	.byte	W96
song_0059_1_1:
	.byte		N68	, Gn3, v080
	.byte	W72
	.byte		N22	
	.byte	W24
	.byte	PEND
	.byte		N92	
	.byte	W96
	.byte		N92	
	.byte	W96
	.byte			Fn3
	.byte	W96
	.byte			Gn3
	.byte	W96
	.byte		N66	, Fn3
	.byte	W72
	.byte		N24	, Gs2
	.byte	W24
	.byte		N92	, Gn3
	.byte	W96
	.byte			Fn3
	.byte	W96
	.byte		N68	, Gn3
	.byte	W72
	.byte		N22	, As2
	.byte	W24
	.byte		N92	, Gn3
	.byte	W96
	.byte			Ds3
	.byte	W96
	.byte			Fn3
	.byte	W96
	.byte			Gn3
	.byte	W96
	.byte			Fn3
	.byte	W96
	.byte		N22	, Ds4, v112
	.byte	W24
	.byte		N11	, Gn4
	.byte	W12
	.byte		N09	, Cn5
	.byte	W12
	.byte		N18	, Gn5
	.byte	W18
	.byte			Fn5
	.byte	W18
	.byte		N12	, Ds5
	.byte	W12
	.byte		N13	, Dn5
	.byte	W12
	.byte		N10	, Cn5
	.byte	W12
	.byte		N14	, Dn5
	.byte	W12
	.byte		N60	, Ds5
	.byte	W60
	.byte		N22	, Ds4
	.byte	W24
	.byte		N12	, Gn4
	.byte	W12
	.byte			Cn5
	.byte	W12
	.byte		N18	, Gn5
	.byte	W18
	.byte			Fn5
	.byte	W18
	.byte		N12	, Ds5
	.byte	W12
	.byte			Dn5
	.byte	W12
	.byte			Ds5
	.byte	W12
	.byte			Fn5
	.byte	W12
	.byte		N30	, Gn5
	.byte	W60
	.byte		N68	, Ds4, v080
	.byte	W84
	.byte		N60	, Bn3
	.byte	W12
song_0059_1_2:
	.byte	W48
	.byte		N15	, Fn3, v080
	.byte	W16
	.byte			Ds3
	.byte	W16
	.byte			Fn3
	.byte	W16
	.byte	PEND
	.byte		N92	, As3
	.byte	W96
song_0059_1_3:
	.byte		N40	, Bn3, v080
	.byte	W40
	.byte		N04	, Cn4
	.byte	W04
	.byte			Cs4
	.byte	W04
	.byte		N44	, Dn4
	.byte	W48
	.byte	PEND
	.byte		N32	, Gn4
	.byte	W36
	.byte		N22	, As3
	.byte	W24
	.byte		N11	, Cn4
	.byte	W12
	.byte			Ds4
	.byte	W12
	.byte			Gn4
	.byte	W12
	.byte		N68	, Fn4
	.byte	W72
	.byte		N22	, Dn4
	.byte	W24
	.byte		N32	, Gn4
	.byte	W36
	.byte		N22	, Gn3
	.byte	W24
	.byte		N11	, Cn4
	.byte	W12
	.byte			Ds4
	.byte	W12
	.byte			Gn4
	.byte	W12
	.byte		N05	, Gs4
	.byte	W06
	.byte			Gn4
	.byte	W06
	.byte		N80	, Gs4
	.byte	W84
	.byte	W24
	.byte		N12	, Fn4
	.byte	W12
	.byte			Gn4
	.byte	W12
	.byte			Gs4
	.byte	W12
	.byte			As4
	.byte	W12
	.byte		N22	, Cn5
	.byte	W24
	.byte		N40	, As4
	.byte	W40
	.byte		N04	, An4
	.byte	W04
	.byte			Gs4
	.byte	W04
	.byte		N44	, Gn4
	.byte	W48
	.byte	W24
	.byte		N12	, Gs4
	.byte	W12
	.byte			As4
	.byte	W12
	.byte			Cn5
	.byte	W12
	.byte			Dn5
	.byte	W12
	.byte		N24	, Ds5
	.byte	W24
	.byte		N92	, Fn5
	.byte	W96
	.byte			Gn3
	.byte	W96
	.byte			Fn3
	.byte	W96
	.byte	PATT	
		.word	song_0059_1_1
	.byte		N92	, Gn3, v080
	.byte	W96
	.byte			Ds3
	.byte	W96
	.byte			Fn3
	.byte	W96
	.byte			Gn3
	.byte	W96
	.byte			Fn3
	.byte	W96
	.byte		N22	, Ds3, v112
	.byte	W24
	.byte		N11	, Gn3
	.byte	W12
	.byte		N09	, Cn4
	.byte	W12
	.byte		N18	, Gn4
	.byte	W18
	.byte			Fn4
	.byte	W18
	.byte		N12	, Ds4
	.byte	W12
	.byte		N13	, Dn4
	.byte	W12
	.byte		N10	, Cn4
	.byte	W12
	.byte		N12	, Dn4
	.byte	W12
	.byte		N56	, Ds4
	.byte	W60
	.byte		N22	, Ds3
	.byte	W24
	.byte		N12	, Gn3
	.byte	W12
	.byte			Cn4
	.byte	W12
	.byte		N18	, Gn4
	.byte	W18
	.byte			Fn4
	.byte	W18
	.byte		N12	, Ds4
	.byte	W12
	.byte			Dn4
	.byte	W12
	.byte			Ds4
	.byte	W12
	.byte			Fn4
	.byte	W12
	.byte		N56	, Gn4
	.byte	W60
	.byte		N68	, Cn4, v080
	.byte	W84
	.byte		N54	, Bn3
	.byte	W12
	.byte	PATT	
		.word	song_0059_1_2
	.byte		N92	, As3, v080
	.byte	W96
	.byte	PATT	
		.word	song_0059_1_3
	.byte	GOTO	
		.word	song_0059_1_4
	.byte	FINE

	@********************** Track  2 **********************@

	.global song_0059_2
song_0059_2:	@ 0x087E59C5
	.byte	KEYSH	, 0
	.byte	VOICE	, 3
	.byte	VOL	, v094
	.byte	PAN	, c_v
	.byte	BEND	, c_v
	.byte	W24
	.byte	W48
	.byte	W48
	.byte	W48
	.byte	W48
song_0059_2_15:
	.byte		N68	, Ds4, v127
	.byte	W72
	.byte		N22	, As4
	.byte	W24
	.byte		N80	
	.byte	W96
song_0059_2_1:
	.byte		N56	, Ds4, v127
	.byte	W56
	.byte	W01
	.byte		N15	, Fn4
	.byte	W15
	.byte		N20	, Gn4
	.byte	W24
	.byte	PEND
	.byte		N80	
	.byte	W96
song_0059_2_2:
	.byte	W01
	.byte		N05	, Gn4, v127
	.byte	W04
	.byte			Gs4
	.byte	W06
	.byte		N40	, Gn4
	.byte	W48
	.byte		N24	, Fn4
	.byte	W22
	.byte		N08	, Ds4
	.byte	W08
	.byte		N07	, Fn4
	.byte	W07
	.byte	PEND
song_0059_2_3:
	.byte		N48	, Dn4, v127
	.byte	W48
	.byte		N40	, As4
	.byte	W48
	.byte	PEND
song_0059_2_4:
	.byte		N07	, Gn4, v127
	.byte	W07
	.byte			Gs4
	.byte	W06
	.byte		N40	, Gn4
	.byte	W44
	.byte	W03
	.byte		N21	, Fn4
	.byte	W20
	.byte		N09	, Ds4
	.byte	W08
	.byte		N08	, Fn4
	.byte	W07
	.byte		N72	, Dn4
	.byte	W01
	.byte	PEND
	.byte	W96
song_0059_2_5:
	.byte		N66	, Ds4, v127
	.byte	W68
	.byte	W03
	.byte		N08	, Fn4
	.byte	W06
	.byte		N06	, Ds4
	.byte	W07
	.byte			Dn4
	.byte	W05
	.byte		N07	, Ds4
	.byte	W06
	.byte		N60	, As4
	.byte	W01
	.byte	PEND
song_0059_2_6:
	.byte	W72
	.byte		N07	, As4, v127
	.byte	W09
	.byte		N05	, Cn5
	.byte	W08
	.byte			Dn5
	.byte	W07
	.byte	PEND
song_0059_2_7:
	.byte	W02
	.byte		N56	, Ds5, v127
	.byte	W56
	.byte	W01
	.byte		N13	, Fn5
	.byte	W13
	.byte		N19	, Gn5
	.byte	W24
	.byte	PEND
song_0059_2_8:
	.byte	W01
	.byte		TIE	, Gn5, v127
	.byte	W92
	.byte	W03
	.byte	PEND
	.byte	W13
	.byte		EOT	
	.byte	W21
	.byte		N06	, As5
	.byte	W10
	.byte		N05	, Gs5
	.byte	W08
	.byte		N06	
	.byte	W08
	.byte		N05	, Gn5
	.byte	W07
	.byte		N03	, Fn5
	.byte	W06
	.byte		N06	
	.byte	W08
	.byte		N05	, Ds5
	.byte	W07
	.byte		N04	, Dn5
	.byte	W08
song_0059_2_9:
	.byte		N44	, Dn5, v127
	.byte	W44
	.byte	W01
	.byte		N04	, Bn4
	.byte	W03
	.byte		N24	, Cn5
	.byte	W23
	.byte		N23	, As4
	.byte	W24
	.byte	W01
	.byte	PEND
song_0059_2_10:
	.byte	W01
	.byte		N08	, Cn5, v127
	.byte	W06
	.byte		N06	, As4
	.byte	W07
	.byte		TIE	, Cn5
	.byte	W80
	.byte	W02
	.byte	PEND
song_0059_2_11:
	.byte	W44
	.byte	W03
	.byte		N44	, As4, v127
	.byte	W02
	.byte	PEND
	.byte		EOT	, Cn5
	.byte	W44
	.byte	W03
	.byte	W96
	.byte	W96
	.byte	W96
song_0059_2_12:
	.byte	W92
	.byte	W01
	.byte		N04	, Bn4, v127
	.byte	W02
	.byte		N18	, Cn5
	.byte	W01
	.byte	PEND
song_0059_2_13:
	.byte	W23
	.byte		N22	, As4, v127
	.byte	W24
	.byte	W01
	.byte		N12	, Gs4
	.byte	W11
	.byte			Gn4
	.byte	W11
	.byte		N13	, Gs4
	.byte	W14
	.byte		N54	, Ds5
	.byte	W12
	.byte	PEND
song_0059_2_14:
	.byte	W44
	.byte	W03
	.byte		N15	, Fn5, v127
	.byte	W16
	.byte		N18	, Ds5
	.byte	W17
	.byte		N14	, Fn5
	.byte	W14
	.byte		TIE	, Dn5
	.byte	W02
	.byte	PEND
	.byte	W96
	.byte	W64
	.byte		EOT	
	.byte	W32
	.byte		N68	, Ds4
	.byte	W68
	.byte	W02
	.byte		N22	, As4
	.byte	W24
	.byte	W02
	.byte		N80	
	.byte	W96
	.byte	PATT	
		.word	song_0059_2_1
	.byte		N80	, Gn4, v127
	.byte	W96
	.byte	PATT	
		.word	song_0059_2_2
	.byte	PATT	
		.word	song_0059_2_3
	.byte	PATT	
		.word	song_0059_2_4
	.byte	W96
	.byte	PATT	
		.word	song_0059_2_5
	.byte	PATT	
		.word	song_0059_2_6
	.byte	PATT	
		.word	song_0059_2_7
	.byte	PATT	
		.word	song_0059_2_8
	.byte	W13
	.byte		EOT	, Gn5
	.byte	W21
	.byte		N06	, As5, v127
	.byte	W10
	.byte		N05	, Gs5
	.byte	W08
	.byte		N06	
	.byte	W08
	.byte		N05	, Gn5
	.byte	W07
	.byte		N03	, Fn5
	.byte	W06
	.byte		N06	
	.byte	W08
	.byte		N05	, Ds5
	.byte	W07
	.byte		N04	, Dn5
	.byte	W08
	.byte	PATT	
		.word	song_0059_2_9
	.byte	PATT	
		.word	song_0059_2_10
	.byte	PATT	
		.word	song_0059_2_11
	.byte		EOT	, Cn5
	.byte	W44
	.byte	W03
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	PATT	
		.word	song_0059_2_12
	.byte	PATT	
		.word	song_0059_2_13
	.byte	PATT	
		.word	song_0059_2_14
	.byte	W96
	.byte	W64
	.byte		EOT	, Dn5
	.byte	W03
	.byte		N06	, Dn5, v127
	.byte	W28
	.byte	W01
	.byte	GOTO	
		.word	song_0059_2_15
	.byte	FINE

	@********************** Track  3 **********************@

	.global song_0059_3
song_0059_3:	@ 0x087E5B4D
	.byte	KEYSH	, 0
	.byte	VOICE	, 19
	.byte	VOL	, v094
	.byte	PAN	, c_v
	.byte	BEND	, c_v
	.byte	W24
	.byte		N06	, Gn5, v127
	.byte	W06
	.byte			Gs5
	.byte	W06
	.byte			Gn5
	.byte	W06
	.byte			Ds5
	.byte	W06
	.byte			Cn5
	.byte	W06
	.byte			Gs4
	.byte	W06
	.byte			Gn4
	.byte	W06
	.byte			Gs4
	.byte	W06
	.byte			Gn4
	.byte	W06
	.byte			Ds4
	.byte	W06
	.byte			Cn4
	.byte	W06
	.byte			Gs3
	.byte	W06
	.byte			Gn3
	.byte	W06
	.byte			Ds2
	.byte	W06
	.byte			Gn2
	.byte	W06
	.byte			Gs2
	.byte	W06
	.byte		N05	, Cn3
	.byte	W06
	.byte			Ds3
	.byte	W06
	.byte		N03	, Gn3
	.byte	W04
	.byte		N05	, Gs3
	.byte	W04
	.byte			Cn4
	.byte	W04
	.byte			Ds4
	.byte	W04
	.byte		N04	, Gn4
	.byte	W04
	.byte		N05	, Gs4
	.byte	W04
	.byte		N03	, Cn5
	.byte	W04
	.byte		N05	, Ds5
	.byte	W04
	.byte		N03	, Gn5
	.byte	W04
	.byte		N01	, Cn4
	.byte	W01
	.byte			Ds4
	.byte	W02
	.byte			Gn4
	.byte	W01
	.byte			Cn5
	.byte	W01
	.byte			Ds5
	.byte		N01	, Gn5
	.byte	W01
	.byte		N18	, Cn6
	.byte	W42
song_0059_3_1:
	.byte		N12	, Ds2, v127
	.byte	W12
	.byte			As2
	.byte	W12
	.byte			Ds3
	.byte	W12
	.byte			As2
	.byte	W12
	.byte			Gn3
	.byte	W12
	.byte			As2
	.byte	W12
	.byte			Ds3
	.byte	W12
	.byte			As2
	.byte	W12
	.byte	PEND
song_0059_3_2:
	.byte		N12	, Dn2, v127
	.byte	W12
	.byte			As2
	.byte	W12
	.byte			Dn3
	.byte	W12
	.byte			As2
	.byte	W12
	.byte			Fn3
	.byte	W12
	.byte			As2
	.byte	W12
	.byte			Dn3
	.byte	W12
	.byte			As2
	.byte	W12
	.byte	PEND
song_0059_3_3:
	.byte		N12	, Cn2, v127
	.byte	W12
	.byte			Gn2
	.byte	W12
	.byte			Ds3
	.byte	W12
	.byte			Cn3
	.byte	W12
	.byte			Gn3
	.byte	W12
	.byte			Gn2
	.byte	W12
	.byte			Ds3
	.byte	W12
	.byte			Gn2
	.byte	W12
	.byte	PEND
song_0059_3_4:
	.byte		N12	, Gs1, v127
	.byte	W12
	.byte			Gs2
	.byte	W12
	.byte			Ds3
	.byte	W12
	.byte			Cn3
	.byte	W12
	.byte			Gn3
	.byte	W12
	.byte			Gs2
	.byte	W12
	.byte			Ds3
	.byte	W12
	.byte			Cn3
	.byte	W12
	.byte	PEND
song_0059_3_5:
	.byte		N12	, Fn1, v127
	.byte	W12
	.byte			Fn2
	.byte	W12
	.byte			Cn3
	.byte	W12
	.byte			Gs2
	.byte	W12
	.byte			Ds3
	.byte	W12
	.byte			Gs2
	.byte	W12
	.byte			Cn3
	.byte	W12
	.byte			Gs2
	.byte	W12
	.byte	PEND
song_0059_3_6:
	.byte		N12	, Gn1, v127
	.byte	W12
	.byte			Gn2
	.byte	W12
	.byte			As2
	.byte	W12
	.byte			Gn2
	.byte	W12
	.byte			Dn3
	.byte	W12
	.byte			Gn2
	.byte	W12
	.byte			As2
	.byte	W12
	.byte			Gn2
	.byte	W12
	.byte	PEND
song_0059_3_7:
	.byte		N12	, Gs1, v127
	.byte	W12
	.byte			Gs2
	.byte	W12
	.byte			Cn3
	.byte	W12
	.byte			Gs2
	.byte	W12
	.byte			Ds3
	.byte	W12
	.byte			Gs2
	.byte	W12
	.byte			Cn3
	.byte	W12
	.byte			Gs2
	.byte	W12
	.byte	PEND
song_0059_3_8:
	.byte		N12	, As1, v127
	.byte	W12
	.byte			Fn2
	.byte	W12
	.byte			As2
	.byte	W12
	.byte			Fn2
	.byte	W12
	.byte			Dn3
	.byte	W12
	.byte			Fn2
	.byte	W12
	.byte			As2
	.byte	W12
	.byte			Fn2
	.byte	W12
	.byte	PEND
	.byte	PATT	
		.word	song_0059_3_1
	.byte	PATT	
		.word	song_0059_3_2
	.byte	PATT	
		.word	song_0059_3_3
	.byte	PATT	
		.word	song_0059_3_4
	.byte	PATT	
		.word	song_0059_3_5
	.byte	PATT	
		.word	song_0059_3_6
	.byte	PATT	
		.word	song_0059_3_7
	.byte	PATT	
		.word	song_0059_3_8
song_0059_3_9:
	.byte		N12	, Gs1, v127
	.byte	W12
	.byte			Gs2
	.byte	W12
	.byte			Cn3
	.byte	W12
	.byte			Gs2
	.byte	W12
	.byte			Gn3
	.byte	W12
	.byte			Gs2
	.byte	W12
	.byte			Cn3
	.byte	W12
	.byte			Gs2
	.byte	W12
	.byte	PEND
song_0059_3_10:
	.byte		N12	, Gn1, v127
	.byte	W12
	.byte			Gn2
	.byte	W12
	.byte			Fn3
	.byte	W12
	.byte		N22	, Gn3
	.byte	W24
	.byte		N12	, Gn2
	.byte	W12
	.byte			Ds3
	.byte	W12
	.byte			Gn2
	.byte	W12
	.byte	PEND
	.byte	PATT	
		.word	song_0059_3_9
	.byte		N12	, Gn1, v127
	.byte	W12
	.byte			Gn2
	.byte	W12
	.byte			Fn3
	.byte	W12
	.byte		N21	, Gn3
	.byte	W24
	.byte		N12	, Gn2
	.byte	W12
	.byte			Ds3
	.byte	W12
	.byte			Gn2
	.byte	W12
song_0059_3_11:
	.byte		N12	, Fn1, v127
	.byte	W12
	.byte			Fn2
	.byte	W12
	.byte			Cn3
	.byte	W12
	.byte			Gs2
	.byte	W12
	.byte			Gs3
	.byte	W12
	.byte			Gs2
	.byte	W12
	.byte			Cn3
	.byte	W12
	.byte		N24	, Fn1
	.byte	W12
	.byte	PEND
song_0059_3_12:
	.byte	W12
	.byte		N12	, Fn2, v127
	.byte	W12
	.byte			Bn2
	.byte	W12
	.byte			Gs2
	.byte	W12
	.byte			Ds3
	.byte	W12
	.byte			Gs2
	.byte	W12
	.byte			Bn2
	.byte	W12
	.byte			Gs2
	.byte	W12
	.byte	PEND
	.byte	PATT	
		.word	song_0059_3_6
	.byte		N12	, Gn1, v127
	.byte	W12
	.byte			Gn2
	.byte	W12
	.byte			Dn3
	.byte	W12
	.byte			Gn2
	.byte	W13
	.byte			Fn3
	.byte	W11
	.byte			Fn2
	.byte	W12
	.byte			Dn3
	.byte	W12
	.byte			As2
	.byte	W12
	.byte	PATT	
		.word	song_0059_3_1
	.byte	PATT	
		.word	song_0059_3_2
	.byte	PATT	
		.word	song_0059_3_3
	.byte	PATT	
		.word	song_0059_3_4
	.byte	PATT	
		.word	song_0059_3_5
	.byte	PATT	
		.word	song_0059_3_6
	.byte	PATT	
		.word	song_0059_3_7
	.byte	PATT	
		.word	song_0059_3_8
	.byte	PATT	
		.word	song_0059_3_1
	.byte	PATT	
		.word	song_0059_3_2
	.byte	PATT	
		.word	song_0059_3_3
	.byte	PATT	
		.word	song_0059_3_4
	.byte	PATT	
		.word	song_0059_3_5
	.byte	PATT	
		.word	song_0059_3_6
	.byte	PATT	
		.word	song_0059_3_7
	.byte	PATT	
		.word	song_0059_3_8
	.byte	PATT	
		.word	song_0059_3_9
	.byte	PATT	
		.word	song_0059_3_10
	.byte	PATT	
		.word	song_0059_3_9
	.byte	PATT	
		.word	song_0059_3_10
	.byte	PATT	
		.word	song_0059_3_11
	.byte	PATT	
		.word	song_0059_3_12
	.byte	PATT	
		.word	song_0059_3_6
	.byte		N12	, Gn1, v127
	.byte	W12
	.byte			Gn2
	.byte	W12
	.byte			Dn3
	.byte	W12
	.byte			Gn2
	.byte	W12
	.byte			As1
	.byte	W12
	.byte			Fn2
	.byte	W12
	.byte			Dn3
	.byte	W12
	.byte			As2
	.byte	W12
	.byte	GOTO	
		.word	song_0059_3_1
	.byte	FINE

	.align 2
	.global song_0059
song_0059:	@ 0x087E5D70
	.byte	3		@ trackCount
	.byte	0		@ blockCount
	.byte	10		@ priority
	.byte	188		@ reverb

	.word	voicegroup000		@ voicegroup/tone

	.word	song_0059_1		@ track
	.word	song_0059_2		@ track
	.word	song_0059_3		@ track
