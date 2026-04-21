	.include "MPlayDef.s"

	.section .rodata

	@********************** Track  1 **********************@

	.align 2
	.global song_0001_1
song_0001_1:	@ 0x087D18F4
	.byte	KEYSH	, 0
	.byte	TEMPO	, 125
	.byte	VOICE	, 4
	.byte	VOL	, v062
	.byte	PAN	, c_v
	.byte	W06
	.byte	TEMPO	, 60
	.byte	W12
	.byte		N08	, Gn3, v127
	.byte	W18
	.byte		N04	, Bn3
	.byte	W06
	.byte			Cn4
	.byte	W06
	.byte			Cs4
	.byte	W12
	.byte		N12	, Dn4
	.byte	W18
	.byte		N08	, Bn3
	.byte	W12
	.byte			An3
	.byte	W12
	.byte			Gn3
	.byte	W12
	.byte		N08	
	.byte	W18
	.byte		N04	, Bn3
	.byte	W06
	.byte			Cn4
	.byte	W06
	.byte			Cs4
	.byte	W12
	.byte		N08	, Dn4
	.byte	W12
	.byte		N04	, Bn3
	.byte	W06
	.byte			An3
	.byte	W06
	.byte			Gs3
	.byte	W06
	.byte			Gn3
	.byte	W12
	.byte		N08	
	.byte	W12
song_0001_1_1:
	.byte		N08	, Gn4, v127
	.byte	W12
	.byte		N01	
	.byte	W06
	.byte	BEND	, c_v-57
	.byte		N24	, Cn5
	.byte	W01
	.byte	BEND	, c_v-47
	.byte	W01
	.byte		c_v-39
	.byte	W01
	.byte		c_v-32
	.byte	W01
	.byte		c_v-26
	.byte	W01
	.byte		c_v-22
	.byte	W01
	.byte		c_v-18
	.byte	W01
	.byte		c_v-15
	.byte	W01
	.byte		c_v-12
	.byte	W01
	.byte		c_v-10
	.byte	W01
	.byte		c_v-8
	.byte	W01
	.byte		c_v-7
	.byte	W01
	.byte		c_v-6
	.byte	W01
	.byte		c_v-4
	.byte	W02
	.byte		c_v-3
	.byte	W01
	.byte		c_v-2
	.byte	W02
	.byte		c_v-1
	.byte	W04
	.byte		c_v
	.byte	W08
	.byte		N08	, An4
	.byte	W12
	.byte		N01	, An3
	.byte	W06
	.byte		N28	, Fn4
	.byte	W30
	.byte	PEND
song_0001_1_2:
	.byte		N08	, Dn4, v127
	.byte	W18
	.byte		N18	, Gn4
	.byte	W18
	.byte		N12	, Fn4
	.byte	W12
	.byte		N07	, En4
	.byte	W06
	.byte		N01	, Gn3
	.byte	W06
	.byte		N04	, Fn4
	.byte	W06
	.byte		N18	, Gn4
	.byte	W30
	.byte	PEND
	.byte	PATT	
		.word	song_0001_1_1
song_0001_1_3:
	.byte		N08	, Dn4, v127
	.byte	W18
	.byte		N18	, Gn4
	.byte	W18
	.byte		N12	, Fn4
	.byte	W12
	.byte		N07	, En4
	.byte	W06
	.byte		N06	, Dn4
	.byte	W12
	.byte		N22	, Cn4
	.byte	W30
	.byte	PEND
	.byte	PATT	
		.word	song_0001_1_1
	.byte	PATT	
		.word	song_0001_1_2
	.byte	PATT	
		.word	song_0001_1_1
	.byte	PATT	
		.word	song_0001_1_3
	.byte		N08	, An3, v127
	.byte	W12
	.byte		N06	, Bn3
	.byte	W06
	.byte		N18	, Cn4
	.byte	W18
	.byte		N08	, An3
	.byte	W12
	.byte			Bn3
	.byte	W12
	.byte		N06	, Cn4
	.byte	W06
	.byte		N18	, Dn4
	.byte	W18
	.byte		N08	, Bn3
	.byte	W12
	.byte			Cn4
	.byte	W12
	.byte		N06	, Dn4
	.byte	W06
	.byte		N18	, En4
	.byte	W18
	.byte		N12	, Cn4
	.byte	W12
	.byte			Dn4
	.byte	W12
	.byte			En4
	.byte	W12
	.byte			Fn4
	.byte	W12
	.byte			Gn4
	.byte	W12
	.byte	PATT	
		.word	song_0001_1_1
	.byte	PATT	
		.word	song_0001_1_2
	.byte	PATT	
		.word	song_0001_1_1
	.byte		N08	, Dn4, v127
	.byte	W18
	.byte		N18	, Gn4
	.byte	W18
	.byte		N12	, Fn4
	.byte	W12
	.byte		N07	, En4
	.byte	W06
	.byte		N06	, Dn4
	.byte	W12
	.byte		N14	, Cn4
	.byte	W17
	.byte		N12	
	.byte	W13
	.byte		N08	, Cn5
	.byte	W18
	.byte		N06	, Gn4
	.byte	W06
	.byte			An4
	.byte	W06
	.byte			Fn4
	.byte	W12
	.byte		N17	, Dn4
	.byte	W18
	.byte		N11	, En4
	.byte	W12
	.byte			Fn4
	.byte	W12
	.byte		N12	, Gn4
	.byte	W12
	.byte			Dn4
	.byte	W12
	.byte			En4
	.byte	W12
	.byte			Fn4
	.byte	W12
	.byte			Gn4
	.byte	W12
	.byte		N06	, En4
	.byte	W06
	.byte			Dn4
	.byte	W12
	.byte		N14	, Cn4
	.byte	W18
	.byte		N12	, Gn4
	.byte	W12
	.byte		N08	, Cn5
	.byte	W18
	.byte		N06	, Gn4
	.byte	W06
	.byte			An4
	.byte	W06
	.byte			Fn4
	.byte	W12
	.byte		N17	, Dn4
	.byte	W18
	.byte		N10	, En4
	.byte	W12
	.byte			Fn4
	.byte	W12
	.byte		N12	, Gn4
	.byte	W12
	.byte		N10	, Dn4
	.byte	W12
	.byte			En4
	.byte	W12
	.byte			Fn4
	.byte	W12
	.byte			Gn4
	.byte	W12
	.byte		N06	, En5
	.byte	W06
	.byte		N04	, Dn5
	.byte	W12
	.byte		N18	, Cn5
	.byte	W30
	.byte	W12
	.byte		N08	, Gn4
	.byte	W12
	.byte		N06	, As3
	.byte	W06
	.byte			Cn4
	.byte	W12
	.byte			Dn4
	.byte	W06
	.byte		N12	, Ds4
	.byte	W12
	.byte			Fn4
	.byte	W12
	.byte			Gn4
	.byte	W12
	.byte			Gs4
	.byte	W12
	.byte		N14	, As4
	.byte	W18
	.byte		N08	
	.byte	W18
	.byte		N42	, Gs4
	.byte	W60
	.byte		N14	, As4
	.byte	W18
	.byte		N08	
	.byte	W18
	.byte		N18	, Gs4
	.byte	W24
	.byte		N12	, Fn4
	.byte	W12
	.byte			Gn4
	.byte	W12
	.byte			Gs4
	.byte	W12
	.byte		N14	
	.byte	W18
	.byte		N08	
	.byte	W18
	.byte		N42	, Gn4
	.byte	W48
	.byte		N12	, As3
	.byte	W12
	.byte		N10	, Gn4
	.byte	W18
	.byte		N06	, As3
	.byte	W06
	.byte			Cn4
	.byte	W06
	.byte			Dn4
	.byte	W12
	.byte		N18	, Ds4
	.byte	W18
	.byte		N12	, Fn4
	.byte	W12
	.byte			Gn4
	.byte	W12
	.byte			Gs4
	.byte	W12
	.byte		N14	, As4
	.byte	W18
	.byte		N08	
	.byte	W18
	.byte		N42	, Gs4
	.byte	W48
	.byte		N12	, Fn4
	.byte	W12
	.byte		N02	, As4
	.byte	W02
	.byte			Cn5
	.byte	W02
	.byte		N12	, As4
	.byte	W14
	.byte		N08	
	.byte	W18
	.byte		N18	, Gs4
	.byte	W24
	.byte		N12	, Fn4
	.byte	W12
	.byte			Gn4
	.byte	W12
	.byte			Gs4
	.byte	W12
	.byte		N12	
	.byte	W18
	.byte		N08	, Gn4
	.byte	W18
	.byte		N28	, Ds4
	.byte	W36
	.byte		N24	, Cs4
	.byte	W24
	.byte		N06	, Cn4
	.byte	W06
	.byte			Bn3
	.byte	W06
	.byte		N04	, Cn4
	.byte	W06
	.byte		N06	, Ds4
	.byte	W06
	.byte			Dn4
	.byte	W06
	.byte		N04	, Ds4
	.byte	W06
	.byte		N06	, Gs4
	.byte	W06
	.byte			Gn4
	.byte	W06
	.byte		N04	, Gs4
	.byte	W06
	.byte		N06	, Cn5
	.byte	W06
	.byte			Bn4
	.byte	W06
	.byte		N04	, Cn5
	.byte	W06
	.byte		N06	, Ds5
	.byte	W06
	.byte			Dn5
	.byte	W06
	.byte			Ds5
	.byte	W06
	.byte			Gs5
	.byte	W06
	.byte			As5
	.byte	W06
	.byte			An5
	.byte	W06
	.byte		N04	, Gs5
	.byte	W12
	.byte		N08	, Gn5
	.byte	W12
	.byte		N06	, Gs5
	.byte	W06
	.byte		N12	, As5
	.byte	W12
	.byte		N06	, Ds4
	.byte	W06
	.byte			Dn4
	.byte	W06
	.byte			Ds4
	.byte	W06
	.byte		N07	, As4
	.byte	W06
	.byte		N06	, An4
	.byte	W06
	.byte			Gs4
	.byte	W06
	.byte			Gn4
	.byte	W06
	.byte			Cn5
	.byte	W06
	.byte			As4
	.byte	W06
	.byte			Gs4
	.byte	W06
	.byte			Gn4
	.byte	W06
	.byte			Gs4
	.byte	W06
	.byte			Gn4
	.byte	W06
	.byte			Gs4
	.byte	W06
	.byte		N04	, Ds5
	.byte	W06
	.byte		N06	, Gn4
	.byte	W06
	.byte			Gs4
	.byte	W06
	.byte		N04	, Cn5
	.byte	W06
	.byte		N06	, Gn4
	.byte	W06
	.byte			Gs4
	.byte	W06
	.byte		N04	, Ds5
	.byte	W06
	.byte		N06	, Gn4
	.byte	W06
	.byte			Cn5
	.byte	W06
	.byte			Dn5
	.byte	W06
	.byte			Dn4
	.byte	W06
	.byte			Ds5
	.byte	W06
	.byte			Ds4
	.byte	W06
	.byte			Fn5
	.byte	W06
	.byte			Fn4
	.byte	W06
	.byte			Ds5
	.byte	W06
	.byte			Ds4
	.byte	W06
	.byte			Dn5
	.byte	W06
	.byte			Dn4
	.byte	W06
	.byte			Cn5
	.byte	W06
	.byte			Cn4
	.byte	W06
	.byte			As4
	.byte	W06
	.byte			As3
	.byte	W06
	.byte			Gs4
	.byte	W06
	.byte			Gs3
	.byte	W06
	.byte		N08	, Gn4
	.byte	W18
	.byte		N06	, As3
	.byte	W06
	.byte			Cn4
	.byte	W06
	.byte			Dn4
	.byte	W12
	.byte		N16	, Ds4
	.byte	W18
	.byte		N10	, Fn4
	.byte	W12
	.byte			Gn4
	.byte	W12
	.byte		N12	, Ds4
	.byte	W12
	.byte		N08	, Gs4
	.byte	W18
	.byte		N06	, Cn4
	.byte	W06
	.byte			Dn4
	.byte	W06
	.byte			Ds4
	.byte	W12
	.byte		N16	, Fn4
	.byte	W18
	.byte		N10	, Gn4
	.byte	W12
	.byte			Gs4
	.byte	W12
	.byte		N12	, Fn4
	.byte	W12
	.byte		N04	, As4
	.byte	W12
	.byte			Cn5
	.byte	W12
	.byte			Dn5
	.byte	W12
	.byte			Cn5
	.byte	W12
	.byte			As4
	.byte	W12
	.byte			Gs4
	.byte	W12
	.byte			Gn4
	.byte	W12
	.byte			Fn4
	.byte	W12
	.byte			Ds4
	.byte	W12
	.byte			Dn4
	.byte	W12
	.byte		N06	, Cn4
	.byte	W06
	.byte			Dn4
	.byte	W12
	.byte		N30	, Ds4
	.byte	W54
	.byte	GOTO	
		.word	song_0001_1_1
	.byte	FINE

	@********************** Track  2 **********************@

	.global song_0001_2
song_0001_2:	@ 0x087D1B98
	.byte	KEYSH	, 0
	.byte	VOICE	, 5
	.byte	VOL	, v075
	.byte	PAN	, c_v
	.byte	W06
	.byte	W12
	.byte		N10	, Dn3, v127
	.byte		N10	, Gn3
	.byte	W96
	.byte			Dn3
	.byte		N10	, Gn3
	.byte	W84
	.byte			Dn3
	.byte		N10	, Gn3
	.byte	W12
song_0001_2_1:
	.byte		N08	, Cn2, v127
	.byte	W18
	.byte		N18	, En2
	.byte	W18
	.byte		N08	, Gn2
	.byte	W12
	.byte			Fn2
	.byte	W18
	.byte		N18	, An2
	.byte	W18
	.byte		N08	, Cn3
	.byte	W12
	.byte	PEND
song_0001_2_2:
	.byte		N08	, Gn2, v127
	.byte	W18
	.byte		N18	, Bn1
	.byte	W18
	.byte		N08	, Dn2
	.byte	W12
	.byte		N04	, Cn2
	.byte	W08
	.byte		N03	
	.byte	W04
	.byte		N08	, Dn2
	.byte	W12
	.byte			En2
	.byte	W12
	.byte			Gn2
	.byte	W12
	.byte	PEND
	.byte	PATT	
		.word	song_0001_2_1
song_0001_2_3:
	.byte		N08	, Gn2, v127
	.byte	W18
	.byte		N18	, Bn1
	.byte	W18
	.byte		N08	, Dn2
	.byte	W12
	.byte			Cn2
	.byte	W12
	.byte			Gn1
	.byte	W12
	.byte			Cn2
	.byte	W24
	.byte	PEND
	.byte	PATT	
		.word	song_0001_2_1
	.byte	PATT	
		.word	song_0001_2_2
	.byte	PATT	
		.word	song_0001_2_1
	.byte	PATT	
		.word	song_0001_2_3
	.byte	W18
	.byte		N17	, Fn2, v127
	.byte	W18
	.byte		N11	
	.byte	W30
	.byte		N17	, Gn2
	.byte	W18
	.byte		N11	
	.byte	W12
	.byte	W18
	.byte		N17	, Fn2
	.byte	W18
	.byte		N11	
	.byte	W48
	.byte			Gn1
	.byte	W12
	.byte	PATT	
		.word	song_0001_2_1
	.byte	PATT	
		.word	song_0001_2_2
	.byte	PATT	
		.word	song_0001_2_1
	.byte		N08	, Gn2, v127
	.byte	W18
	.byte		N18	, Bn1
	.byte	W18
	.byte		N08	, Dn2
	.byte	W12
	.byte			Cn2
	.byte	W12
	.byte			Gn1
	.byte	W12
	.byte		N11	, Cn2
	.byte	W24
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W48
	.byte		N05	, Gn2
	.byte	W06
	.byte			Fn2
	.byte	W12
	.byte		N17	, En2
	.byte	W30
song_0001_2_4:
	.byte		N08	, Ds2, v127
	.byte	W18
	.byte		N17	, Gn2
	.byte	W18
	.byte		N08	, As1
	.byte	W12
	.byte		N18	, Ds2
	.byte	W06
	.byte	BEND	, c_v-35
	.byte	W06
	.byte		c_v
	.byte	W06
	.byte		N17	, Gn2
	.byte	W18
	.byte		N08	, As1
	.byte	W12
	.byte	PEND
song_0001_2_5:
	.byte		N08	, Fn2, v127
	.byte	W18
	.byte		N17	, Gs2
	.byte	W18
	.byte		N08	, Cn2
	.byte	W12
	.byte		N18	, Fn2
	.byte	W06
	.byte	BEND	, c_v-35
	.byte	W06
	.byte		c_v
	.byte	W06
	.byte		N17	, Gs2
	.byte	W18
	.byte		N08	, Cn2
	.byte	W12
	.byte	PEND
song_0001_2_6:
	.byte		N08	, Fn2, v127
	.byte	W18
	.byte		N17	, Gs2
	.byte	W18
	.byte		N08	, As1
	.byte	W12
	.byte		N18	, Fn2
	.byte	W06
	.byte	BEND	, c_v-35
	.byte	W06
	.byte		c_v
	.byte	W06
	.byte		N17	, Gs2
	.byte	W18
	.byte		N08	, As1
	.byte	W12
	.byte	PEND
	.byte		N16	, Ds2
	.byte	W18
	.byte		N08	
	.byte	W18
	.byte		N12	
	.byte	W18
	.byte		N06	
	.byte	W06
	.byte		N08	, As1
	.byte	W12
	.byte			Cn2
	.byte	W12
	.byte			As1
	.byte	W12
	.byte	PATT	
		.word	song_0001_2_4
	.byte	PATT	
		.word	song_0001_2_5
	.byte	PATT	
		.word	song_0001_2_6
	.byte		N16	, Gs2, v127
	.byte	W18
	.byte		N08	, Gn2
	.byte	W18
	.byte		N12	, Ds2
	.byte	W18
	.byte		N06	
	.byte	W06
	.byte		N08	, As1
	.byte	W12
	.byte			Ds2
	.byte	W12
	.byte		N12	, Gn1
	.byte	W12
	.byte		N08	, Gs1
	.byte	W18
	.byte		N17	, Cn2
	.byte	W18
	.byte		N11	, Ds2
	.byte	W12
	.byte		N17	, Gs2
	.byte	W06
	.byte	BEND	, c_v-35
	.byte	W06
	.byte		c_v
	.byte	W06
	.byte		N17	, Cn3
	.byte	W18
	.byte		N11	, Dn3
	.byte	W12
	.byte		N08	, Ds3
	.byte	W18
	.byte		N17	, As2
	.byte	W18
	.byte		N11	, Ds2
	.byte	W18
	.byte		N17	, Gn2
	.byte	W06
	.byte	BEND	, c_v-35
	.byte	W06
	.byte		c_v
	.byte	W06
	.byte		N11	, As2
	.byte	W12
	.byte			Ds2
	.byte	W12
	.byte		N08	, Gs2
	.byte	W18
	.byte		N17	, Cn2
	.byte	W18
	.byte		N11	, Ds2
	.byte	W12
	.byte		N17	, Gs2
	.byte	W06
	.byte	BEND	, c_v-35
	.byte	W06
	.byte		c_v
	.byte	W06
	.byte		N17	, Cn3
	.byte	W18
	.byte		N07	, Gs2
	.byte	W09
	.byte		N04	, Cn3
	.byte	W03
	.byte		N06	, Dn3
	.byte	W12
	.byte			Cn3
	.byte	W12
	.byte			As2
	.byte	W12
	.byte		N08	, Gs2
	.byte	W08
	.byte			As2
	.byte	W12
	.byte		N03	
	.byte	W04
	.byte		N08	, Gs2
	.byte	W12
	.byte			Gn2
	.byte	W12
	.byte			Fn2
	.byte	W12
	.byte			Ds2
	.byte	W12
	.byte			As1
	.byte	W12
	.byte		N06	, Ds2
	.byte	W18
	.byte		N23	, Gn2
	.byte	W12
	.byte	BEND	, c_v-35
	.byte	W06
	.byte		c_v
	.byte	W12
	.byte		N08	, As2
	.byte	W12
	.byte		N12	, Ds2
	.byte	W12
	.byte		N08	, Fn2
	.byte	W12
	.byte			Cn2
	.byte	W12
	.byte		N06	, Fn2
	.byte	W18
	.byte		N23	, Gs2
	.byte	W12
	.byte	BEND	, c_v-35
	.byte	W06
	.byte		c_v
	.byte	W12
	.byte		N08	, Cn3
	.byte	W12
	.byte		N12	, Fn2
	.byte	W12
	.byte		N06	, As2
	.byte	W12
	.byte			Cn2
	.byte	W12
	.byte			Dn2
	.byte	W12
	.byte			Ds2
	.byte	W12
	.byte			Dn2
	.byte	W12
	.byte			Ds2
	.byte	W12
	.byte			Fn2
	.byte	W12
	.byte			As2
	.byte	W12
	.byte			Ds3
	.byte	W12
	.byte			Dn3
	.byte	W12
	.byte		N05	, Cn3
	.byte	W06
	.byte			Dn3
	.byte	W12
	.byte		N18	, Ds3
	.byte	W30
	.byte		N22	, Ds1
	.byte	W24
	.byte	GOTO	
		.word	song_0001_2_1
	.byte	FINE

	@********************** Track  3 **********************@

	.global song_0001_3
song_0001_3:	@ 0x087D1D6F
	.byte	KEYSH	, 0
	.byte	VOICE	, 22
	.byte	VOL	, v080
	.byte	PAN	, c_v
	.byte	W06
	.byte	W12
	.byte	W96
	.byte	W96
song_0001_3_6:
	.byte	W18
	.byte		N18	, Cn2, v127
	.byte	W18
	.byte		N12	, En1
	.byte	W12
	.byte		N08	, Fn1
	.byte	W18
	.byte		N18	, Fn2
	.byte	W18
	.byte		N12	, Fn1
	.byte	W12
song_0001_3_2:
	.byte		N08	, Gn1, v127
	.byte	W18
	.byte		N18	, Gn2
	.byte	W18
	.byte		N12	, Gn1
	.byte	W12
	.byte			Cn2
	.byte	W12
	.byte		N01	
	.byte	W06
	.byte		N06	, Dn2
	.byte	W06
	.byte		N12	, En2
	.byte	W12
	.byte			Gn2
	.byte	W12
	.byte	PEND
song_0001_3_1:
	.byte		N08	, Cn2, v127
	.byte	W18
	.byte		N18	, Cn3
	.byte	W18
	.byte		N12	, En1
	.byte	W12
	.byte		N08	, Fn1
	.byte	W18
	.byte		N18	, Fn2
	.byte	W18
	.byte		N12	, Fn1
	.byte	W12
	.byte	PEND
	.byte		N08	, Gn1
	.byte	W18
	.byte		N18	, Gn2
	.byte	W18
	.byte		N12	, Gn1
	.byte	W12
	.byte		N08	, Cn2
	.byte	W08
	.byte		N04	
	.byte	W04
	.byte		N12	, Gn1
	.byte	W12
	.byte			Cn2
	.byte	W12
	.byte			Gn1
	.byte	W12
	.byte	PATT	
		.word	song_0001_3_1
	.byte	PATT	
		.word	song_0001_3_2
	.byte	PATT	
		.word	song_0001_3_1
	.byte		N08	, Gn1, v127
	.byte	W18
	.byte		N18	, Gn2
	.byte	W18
	.byte		N12	, Gn1
	.byte	W12
	.byte		N08	, Cn2
	.byte	W08
	.byte		N04	
	.byte	W04
	.byte		N12	, Gn1
	.byte	W12
	.byte			Cn2
	.byte	W12
	.byte			En1
	.byte	W12
	.byte		N18	, Fn1
	.byte	W18
	.byte			An1
	.byte	W18
	.byte		N12	, Cn2
	.byte	W12
	.byte		N18	, Gn1
	.byte	W18
	.byte			Bn1
	.byte	W18
	.byte		N12	, Dn2
	.byte	W12
	.byte		N08	, Fn1
	.byte	W18
	.byte		N18	, An1
	.byte	W18
	.byte		N12	, Cn2
	.byte	W12
	.byte			Gn1
	.byte	W12
	.byte			An1
	.byte	W12
	.byte			Bn1
	.byte	W12
	.byte			Gn1
	.byte	W12
	.byte		N08	, Cn2
	.byte	W18
	.byte		N18	
	.byte	W18
	.byte		N12	, Fn1
	.byte	W12
	.byte		N08	
	.byte	W18
	.byte		N18	, Fn2
	.byte	W18
	.byte		N12	, Fn1
	.byte	W12
	.byte		N08	, Gn1
	.byte	W18
	.byte		N18	, Gn2
	.byte	W18
	.byte		N12	, Gn1
	.byte	W12
	.byte			Cn2
	.byte	W12
	.byte			Dn2
	.byte	W12
	.byte			En2
	.byte	W12
	.byte			Gn2
	.byte	W12
	.byte		N08	, Cn3
	.byte	W18
	.byte		N18	, Cn2
	.byte	W18
	.byte		N12	, En1
	.byte	W12
	.byte		N08	, Fn1
	.byte	W18
	.byte		N18	, Fn2
	.byte	W18
	.byte		N06	, Fn1
	.byte	W06
	.byte			Fs1
	.byte	W06
	.byte		N08	, Gn1
	.byte	W18
	.byte		N18	, Gn2
	.byte	W18
	.byte		N12	, Gn1
	.byte	W12
	.byte		N08	, Cn2
	.byte	W12
	.byte			Gn1
	.byte	W12
	.byte		N12	, Cn2
	.byte	W23
	.byte	BEND	, c_v-43
	.byte		N09	, Cn3
	.byte	W01
	.byte	BEND	, c_v
	.byte	W18
	.byte		N06	, Gn2
	.byte	W06
	.byte			An2
	.byte	W06
	.byte			Fn2
	.byte	W12
	.byte		N18	, Dn2
	.byte	W18
	.byte		N12	, En2
	.byte	W12
	.byte			Fn2
	.byte	W12
	.byte			Gn2
	.byte	W12
	.byte			Dn2
	.byte	W12
	.byte			En2
	.byte	W12
	.byte			Fn2
	.byte	W12
	.byte			Gn2
	.byte	W12
	.byte		N06	, En2
	.byte	W06
	.byte			Dn2
	.byte	W12
	.byte		N14	, Cn2
	.byte	W18
	.byte		N12	, Gn2
	.byte	W12
	.byte	BEND	, c_v
	.byte		N08	, Cn3
	.byte	W18
	.byte		N06	, Gn2
	.byte	W06
	.byte			An2
	.byte	W06
	.byte			Fn2
	.byte	W12
	.byte		N18	, Dn2
	.byte	W18
	.byte		N12	, En2
	.byte	W12
	.byte			Fn2
	.byte	W12
	.byte			Gn2
	.byte	W12
	.byte			Dn2
	.byte	W12
	.byte			En2
	.byte	W12
	.byte			Fn2
	.byte	W12
	.byte			Gn2
	.byte	W12
	.byte		N06	, En2
	.byte	W06
	.byte			Dn2
	.byte	W12
	.byte		N18	, Cn2
	.byte	W18
	.byte		N12	, As1
	.byte	W12
song_0001_3_3:
	.byte		N12	, Ds1, v127
	.byte	W24
	.byte			As1
	.byte	W24
	.byte			Ds2
	.byte	W24
	.byte			As1
	.byte	W24
	.byte	PEND
song_0001_3_4:
	.byte		N12	, Fn1, v127
	.byte	W24
	.byte			Cn2
	.byte	W24
	.byte			Fn2
	.byte	W24
	.byte			Cn2
	.byte	W24
	.byte	PEND
song_0001_3_5:
	.byte		N12	, As1, v127
	.byte	W24
	.byte			Fn2
	.byte	W24
	.byte			As1
	.byte	W24
	.byte		N12	
	.byte	W24
	.byte	PEND
	.byte		N18	, Ds2
	.byte	W18
	.byte		N18	
	.byte	W18
	.byte		N18	
	.byte	W18
	.byte		N06	, As1
	.byte	W06
	.byte		N12	
	.byte	W12
	.byte			Cn2
	.byte	W12
	.byte			As1
	.byte	W12
	.byte	PATT	
		.word	song_0001_3_3
	.byte	PATT	
		.word	song_0001_3_4
	.byte	PATT	
		.word	song_0001_3_5
	.byte		N18	, Gs1, v127
	.byte	W18
	.byte		N18	
	.byte	W18
	.byte		N12	, Ds2
	.byte	W18
	.byte		N06	
	.byte	W06
	.byte		N12	, As1
	.byte	W12
	.byte			Ds2
	.byte	W12
	.byte			Gn1
	.byte	W12
	.byte			Gs1
	.byte	W24
	.byte			Cn2
	.byte	W24
	.byte			Ds2
	.byte	W24
	.byte			Gs2
	.byte	W24
	.byte			Gn2
	.byte	W24
	.byte			Ds2
	.byte	W24
	.byte			As2
	.byte	W24
	.byte			Ds2
	.byte	W24
	.byte			Gs2
	.byte	W24
	.byte		N12	
	.byte	W24
	.byte			Ds2
	.byte	W24
	.byte			Gs2
	.byte	W24
	.byte			As2
	.byte	W24
	.byte			Fn2
	.byte	W24
	.byte			Dn2
	.byte	W24
	.byte			As1
	.byte	W24
	.byte			Ds2
	.byte	W24
	.byte			As1
	.byte	W24
	.byte			Ds2
	.byte	W24
	.byte			As1
	.byte	W24
	.byte			Fn2
	.byte	W24
	.byte			Cn2
	.byte	W24
	.byte			Fn2
	.byte	W24
	.byte			Cn2
	.byte	W24
	.byte	PATT	
		.word	song_0001_3_5
	.byte		N12	, Ds2, v127
	.byte	W12
	.byte			Dn2
	.byte	W12
	.byte		N06	, Cn2
	.byte	W06
	.byte			Dn2
	.byte	W12
	.byte		N30	, Ds2
	.byte	W54
	.byte	GOTO	
		.word	song_0001_3_6
	.byte	FINE

	@********************** Track  4 **********************@

	.global song_0001_4
song_0001_4:	@ 0x087D1F48
	.byte	KEYSH	, 0
	.byte	VOICE	, 126
	.byte	VOL	, v075
	.byte	PAN	, c_v
	.byte	W06
	.byte		N06	, Dn1, v127
	.byte	W12
	.byte		N06	
	.byte	W96
	.byte		N06	
	.byte	W72
	.byte			Cn1
	.byte	W12
	.byte			Dn1
	.byte	W12
song_0001_4_1:
	.byte		N06	, Cn1, v127
	.byte		N06	, Dn5
	.byte	W12
	.byte		N06	
	.byte	W06
	.byte		N06	
	.byte	W12
	.byte		N06	
	.byte	W06
	.byte		N06	
	.byte	W12
	.byte			Cn1
	.byte		N06	, Dn5
	.byte	W12
	.byte		N06	
	.byte	W06
	.byte		N06	
	.byte	W12
	.byte		N06	
	.byte	W06
	.byte		N06	
	.byte	W12
	.byte	PEND
song_0001_4_2:
	.byte		N06	, Cn1, v127
	.byte		N06	, Dn5
	.byte	W12
	.byte		N06	
	.byte	W06
	.byte		N06	
	.byte	W12
	.byte		N06	
	.byte	W06
	.byte			Cn1
	.byte		N06	, Dn5
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte			Cn1
	.byte		N06	, Dn5
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte		N06	
	.byte	W12
	.byte			Cn1
	.byte		N06	, Dn5
	.byte	W12
	.byte		N06	
	.byte	W12
	.byte	PEND
	.byte	PATT	
		.word	song_0001_4_1
	.byte	PATT	
		.word	song_0001_4_2
	.byte	PATT	
		.word	song_0001_4_1
	.byte	PATT	
		.word	song_0001_4_2
	.byte	PATT	
		.word	song_0001_4_1
	.byte	PATT	
		.word	song_0001_4_2
	.byte		N06	, Cn1, v127
	.byte		N04	, Dn5
	.byte	W04
	.byte		N04	
	.byte	W04
	.byte		N04	
	.byte	W04
	.byte		N06	
	.byte	W12
	.byte			Cn1
	.byte		N06	, Dn5
	.byte	W06
	.byte		N06	
	.byte	W12
	.byte		N06	
	.byte	W06
	.byte			Cn1
	.byte		N06	, Dn5
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte			Cn1
	.byte		N06	, Dn5
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte			Cn1
	.byte		N04	, Dn5
	.byte	W04
	.byte		N03	
	.byte	W03
	.byte		N04	
	.byte	W05
	.byte		N06	
	.byte	W12
	.byte			Cn1
	.byte		N06	, Dn5
	.byte	W06
	.byte		N06	
	.byte	W12
	.byte		N06	
	.byte	W06
	.byte			Cn1
	.byte		N06	, Dn5
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte			Cn1
	.byte		N06	, Dn5
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte	PATT	
		.word	song_0001_4_1
	.byte	PATT	
		.word	song_0001_4_2
	.byte	PATT	
		.word	song_0001_4_1
	.byte		N06	, Cn1, v127
	.byte		N06	, Dn5
	.byte	W12
	.byte		N06	
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte			Cn1
	.byte	W06
	.byte			Dn5
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte			Cn1
	.byte		N06	, Dn5
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte		N06	
	.byte	W12
	.byte			Cn1
	.byte		N06	, Dn5
	.byte	W24
song_0001_4_3:
	.byte		N06	, Cn1, v127
	.byte		N06	, Dn5
	.byte	W12
	.byte		N06	
	.byte	W12
	.byte			Cn1
	.byte		N06	, Dn5
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte			Cn1
	.byte		N06	, Dn5
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte			Cn1
	.byte		N06	, Dn5
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte	PEND
	.byte			Cn1
	.byte		N06	, Dn5
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte			Cn1
	.byte		N06	, Dn5
	.byte	W12
	.byte		N06	
	.byte	W12
	.byte			Cn1
	.byte		N06	, Dn5
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte			Cn1
	.byte		N06	, Dn5
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte	PATT	
		.word	song_0001_4_3
	.byte		N06	, Cn1, v127
	.byte		N06	, Dn5
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte		N06	
	.byte	W12
	.byte			Cn1
	.byte		N06	, Dn5
	.byte	W12
	.byte		N03	
	.byte	W03
	.byte		N03	
	.byte	W03
	.byte		N03	
	.byte	W03
	.byte		N03	
	.byte	W03
	.byte		N06	, Cn1
	.byte		N06	, Dn5
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte			Cn1
	.byte		N06	, Dn5
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte		N06	
	.byte	W06
song_0001_4_5:
	.byte		N06	, Cn1, v127
	.byte		N06	, Dn5
	.byte	W12
	.byte		N06	
	.byte	W12
	.byte		N06	
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte			Cn1
	.byte		N06	, Dn5
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte	PEND
song_0001_4_4:
	.byte		N06	, Cn1, v127
	.byte		N06	, Dn5
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte			Cn1
	.byte		N06	, Dn5
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte	PEND
	.byte	PATT	
		.word	song_0001_4_4
song_0001_4_6:
	.byte		N06	, Cn1, v127
	.byte		N06	, Dn5
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte			Cn1
	.byte		N06	, Dn5
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte			Cn1
	.byte		N06	, Dn5
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte	PEND
	.byte	PATT	
		.word	song_0001_4_5
	.byte	PATT	
		.word	song_0001_4_4
	.byte	PATT	
		.word	song_0001_4_4
	.byte	PATT	
		.word	song_0001_4_6
	.byte	PATT	
		.word	song_0001_4_4
	.byte		N06	, Cn1, v127
	.byte		N06	, Dn5
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte			Cn1
	.byte		N03	, Dn5
	.byte	W03
	.byte		N03	
	.byte	W03
	.byte		N06	
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte	PATT	
		.word	song_0001_4_4
	.byte		N06	, Cn1, v127
	.byte		N06	, Dn5
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte			Cn1
	.byte		N06	, Dn5
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte		N03	
	.byte	W03
	.byte		N03	
	.byte	W03
	.byte		N06	
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte			Cn1
	.byte		N06	, Dn5
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte	PATT	
		.word	song_0001_4_4
	.byte	PATT	
		.word	song_0001_4_4
	.byte	PATT	
		.word	song_0001_4_4
	.byte		N06	, Cn1, v127
	.byte		N06	, Dn5
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte			Cn1
	.byte		N06	, Dn5
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte		N05	
	.byte	W05
	.byte		N01	
	.byte	W01
	.byte		N06	, Cn1
	.byte		N06	, Dn5
	.byte	W24
	.byte	GOTO	
		.word	song_0001_4_1
	.byte	FINE

	.align 2
	.global song_0001
song_0001:	@ 0x087D21D0
	.byte	4		@ trackCount
	.byte	0		@ blockCount
	.byte	10		@ priority
	.byte	168		@ reverb

	.word	voicegroup000		@ voicegroup/tone

	.word	song_0001_1		@ track
	.word	song_0001_2		@ track
	.word	song_0001_3		@ track
	.word	song_0001_4		@ track
