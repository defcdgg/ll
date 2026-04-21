	.include "MPlayDef.s"

	.section .rodata

	@********************** Track  1 **********************@

	.align 2
	.global song_0002_1
song_0002_1:	@ 0x087D21E8
	.byte	KEYSH	, 0
	.byte	TEMPO	, 125
	.byte	VOICE	, 4
	.byte	VOL	, v075
	.byte	PAN	, c_v
	.byte	W24
song_0002_1_4:
	.byte	TEMPO	, 72
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
song_0002_1_1:
	.byte		N48	, As3, v127
	.byte	W48
	.byte			Dn4
	.byte	W48
	.byte	PEND
song_0002_1_2:
	.byte		N48	, Cn4, v127
	.byte	W48
	.byte			Fn4
	.byte	W48
	.byte	PEND
song_0002_1_3:
	.byte		N16	, Ds4, v127
	.byte	W24
	.byte		TIE	, Dn4
	.byte	W72
	.byte	PEND
	.byte	W48
	.byte		EOT	
	.byte	W48
	.byte	PATT	
		.word	song_0002_1_1
	.byte	PATT	
		.word	song_0002_1_2
	.byte	PATT	
		.word	song_0002_1_3
	.byte	W48
	.byte		EOT	, Dn4
	.byte	W48
	.byte		TIE	, As3, v127
	.byte	W96
	.byte	W90
	.byte		EOT	
	.byte	W06
	.byte		N90	
	.byte	W96
	.byte			Cn4
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	GOTO	
		.word	song_0002_1_4
	.byte	FINE

	@********************** Track  2 **********************@

	.global song_0002_2
song_0002_2:	@ 0x087D2240
	.byte	KEYSH	, 0
	.byte	VOICE	, 5
	.byte	VOL	, v075
	.byte	PAN	, c_v
	.byte	W24
song_0002_2_6:
	.byte	W96
	.byte	W96
song_0002_2_1:
	.byte	W24
	.byte		N10	, Dn4, v127
	.byte	W24
	.byte		N48	, Fn4
	.byte	W48
	.byte	PEND
	.byte		N20	, En4
	.byte	W24
	.byte			Cn4
	.byte	W24
	.byte			En4
	.byte	W24
	.byte		N40	, Dn4
	.byte	W24
	.byte	W24
	.byte		N20	, As3
	.byte	W24
	.byte			Dn4
	.byte	W24
	.byte		N40	, Cn4
	.byte	W24
	.byte	W24
	.byte		N20	, An3
	.byte	W24
	.byte			As3
	.byte	W24
	.byte		N24	, Cn4
	.byte	W24
	.byte	PATT	
		.word	song_0002_2_1
	.byte		N20	, En4, v127
	.byte	W24
	.byte			Cn4
	.byte	W24
	.byte		N14	, En4
	.byte	W24
	.byte		N40	, Gn4
	.byte	W24
	.byte	W24
	.byte		N20	, As4
	.byte	W24
	.byte			An4
	.byte	W24
	.byte			Gn4
	.byte	W24
	.byte			An4
	.byte	W24
	.byte			Gn4
	.byte	W24
	.byte			Fn4
	.byte	W24
	.byte		N24	, An4
	.byte	W24
	.byte	W96
	.byte	W96
song_0002_2_2:
	.byte		N48	, As2, v127
	.byte	W48
	.byte			Dn3
	.byte	W48
	.byte	PEND
song_0002_2_3:
	.byte		N48	, Cn3, v127
	.byte	W48
	.byte			Fn3
	.byte	W48
	.byte	PEND
song_0002_2_4:
	.byte		N16	, Ds3, v127
	.byte	W24
	.byte		TIE	, Dn3
	.byte	W72
	.byte	PEND
	.byte	W48
	.byte		EOT	
	.byte	W48
	.byte	PATT	
		.word	song_0002_2_2
	.byte	PATT	
		.word	song_0002_2_3
	.byte	PATT	
		.word	song_0002_2_4
	.byte	W48
	.byte		EOT	, Dn3
	.byte	W48
song_0002_2_5:
	.byte	W36
	.byte	W02
	.byte		N03	, Dn4, v127
	.byte	W05
	.byte		N03	
	.byte	W05
	.byte		N48	
	.byte	W48
	.byte	PEND
	.byte	PATT	
		.word	song_0002_2_5
	.byte	PATT	
		.word	song_0002_2_5
	.byte	W36
	.byte	W02
	.byte		N03	, Fn4, v127
	.byte	W05
	.byte		N03	
	.byte	W05
	.byte		N48	
	.byte	W48
	.byte	W96
	.byte	W96
	.byte	GOTO	
		.word	song_0002_2_6
	.byte	FINE

	@********************** Track  3 **********************@

	.global song_0002_3
song_0002_3:	@ 0x087D22E7
	.byte	KEYSH	, 0
	.byte	VOICE	, 0
	.byte	VOL	, v066
	.byte	PAN	, c_v-64
	.byte	W24
song_0002_3_7:
	.byte		N04	, Gn4, v127
	.byte	W06
	.byte			An4
	.byte	W06
	.byte			As4
	.byte	W06
	.byte			Cn5
	.byte	W06
	.byte			Dn5
	.byte	W06
	.byte			En5
	.byte	W06
	.byte			Fn5
	.byte	W06
	.byte			En5
	.byte	W06
	.byte			Dn5
	.byte	W06
	.byte			En5
	.byte	W06
	.byte			Fn5
	.byte	W06
	.byte			En5
	.byte	W06
	.byte			Dn5
	.byte	W06
	.byte			En5
	.byte	W06
	.byte			Fn5
	.byte	W06
	.byte			En5
	.byte	W06
	.byte			Dn5
	.byte	W06
	.byte			En5
	.byte	W06
	.byte			Fn5
	.byte	W06
	.byte			En5
	.byte	W06
	.byte			Dn5
	.byte	W06
	.byte			En5
	.byte	W06
	.byte			Fn5
	.byte	W06
	.byte			En5
	.byte	W06
	.byte			Dn5
	.byte	W06
	.byte			En5
	.byte	W06
	.byte			Fn5
	.byte	W06
	.byte			En5
	.byte	W06
	.byte			Dn5
	.byte	W06
	.byte			En5
	.byte	W06
	.byte			Fn5
	.byte	W06
	.byte			En5
	.byte	W06
song_0002_3_1:
	.byte		N04	, Dn5, v127
	.byte	W06
	.byte			En5
	.byte	W06
	.byte			Fn5
	.byte	W06
	.byte			En5
	.byte	W06
	.byte			Dn5
	.byte	W06
	.byte			En5
	.byte	W06
	.byte			Fn5
	.byte	W06
	.byte			En5
	.byte	W06
	.byte			Dn5
	.byte	W06
	.byte			En5
	.byte	W06
	.byte			Fn5
	.byte	W06
	.byte			En5
	.byte	W06
	.byte			Dn5
	.byte	W06
	.byte			En5
	.byte	W06
	.byte			Fn5
	.byte	W06
	.byte			Gn5
	.byte	W06
	.byte	PEND
song_0002_3_2:
	.byte		N04	, As5, v127
	.byte	W06
	.byte			An5
	.byte	W06
	.byte			Gn5
	.byte	W06
	.byte			An5
	.byte	W06
	.byte			As5
	.byte	W06
	.byte			An5
	.byte	W06
	.byte			Gn5
	.byte	W06
	.byte			An5
	.byte	W06
	.byte			As5
	.byte	W06
	.byte			An5
	.byte	W06
	.byte			Gn5
	.byte	W06
	.byte			An5
	.byte	W06
	.byte			As5
	.byte	W06
	.byte			An5
	.byte	W06
	.byte			Gn5
	.byte	W06
	.byte			Dn5
	.byte	W06
	.byte	PEND
song_0002_3_3:
	.byte		N04	, Gn5, v127
	.byte	W06
	.byte			An5
	.byte	W06
	.byte			As5
	.byte	W06
	.byte			An5
	.byte	W06
	.byte			Gn5
	.byte	W06
	.byte			An5
	.byte	W06
	.byte			As5
	.byte	W06
	.byte			An5
	.byte	W06
	.byte			Gn5
	.byte	W06
	.byte			An5
	.byte	W06
	.byte			As5
	.byte	W06
	.byte			An5
	.byte	W06
	.byte			Gn5
	.byte	W06
	.byte			An5
	.byte	W06
	.byte			As5
	.byte	W06
	.byte			Cn6
	.byte	W06
	.byte	PEND
	.byte			Dn6
	.byte	W06
	.byte			Cn6
	.byte	W06
	.byte			As5
	.byte	W06
	.byte			An5
	.byte	W06
	.byte			As5
	.byte	W06
	.byte			An5
	.byte	W06
	.byte			Gn5
	.byte	W06
	.byte			Fn5
	.byte	W06
	.byte			Ds5
	.byte	W06
	.byte			Dn5
	.byte	W06
	.byte			Cn5
	.byte	W06
	.byte			As4
	.byte	W06
	.byte			Cn5
	.byte	W06
	.byte			Dn5
	.byte	W06
	.byte			Ds5
	.byte	W06
	.byte			Fn5
	.byte	W06
	.byte	PATT	
		.word	song_0002_3_1
	.byte	PATT	
		.word	song_0002_3_2
	.byte	PATT	
		.word	song_0002_3_3
	.byte		N04	, Dn6, v127
	.byte	W06
	.byte			Cn6
	.byte	W06
	.byte			As5
	.byte	W06
	.byte			An5
	.byte	W06
	.byte			As5
	.byte	W06
	.byte			An5
	.byte	W06
	.byte			Gn5
	.byte	W06
	.byte			Fn5
	.byte	W06
	.byte			An5
	.byte	W06
	.byte			Gn5
	.byte	W06
	.byte			Fn5
	.byte	W06
	.byte			Ds5
	.byte	W06
	.byte			Fn5
	.byte	W06
	.byte			Ds5
	.byte	W06
	.byte			Dn5
	.byte	W06
	.byte			Cn5
	.byte	W06
	.byte			Gn5
	.byte	W06
	.byte			Fn5
	.byte	W06
	.byte			Dn5
	.byte	W06
	.byte			Cn5
	.byte	W06
	.byte			As4
	.byte	W06
	.byte			Gn4
	.byte	W06
	.byte		N04	
	.byte	W06
	.byte			Fn4
	.byte	W06
	.byte			Gn4
	.byte	W06
	.byte			Fn4
	.byte	W06
	.byte			Dn4
	.byte	W06
	.byte			Cn4
	.byte	W06
	.byte			As3
	.byte	W06
	.byte			Gn3
	.byte	W06
	.byte			Fn3
	.byte	W06
	.byte			Dn3
	.byte	W06
song_0002_3_4:
	.byte		N04	, Gn3, v127
	.byte	W06
	.byte			An3
	.byte	W06
	.byte			As3
	.byte	W06
	.byte			An3
	.byte	W06
	.byte			Gn3
	.byte	W06
	.byte			An3
	.byte	W06
	.byte			As3
	.byte	W06
	.byte			An3
	.byte	W06
	.byte			Gn3
	.byte	W06
	.byte			An3
	.byte	W06
	.byte			As3
	.byte	W06
	.byte			An3
	.byte	W06
	.byte			Gn3
	.byte	W06
	.byte			An3
	.byte	W06
	.byte			As3
	.byte	W06
	.byte			An3
	.byte	W06
	.byte	PEND
	.byte	PATT	
		.word	song_0002_3_4
	.byte	PATT	
		.word	song_0002_3_4
song_0002_3_5:
	.byte		N04	, Gn3, v127
	.byte	W06
	.byte			An3
	.byte	W06
	.byte			As3
	.byte	W06
	.byte			An3
	.byte	W06
	.byte			Gn3
	.byte	W06
	.byte			An3
	.byte	W06
	.byte			As3
	.byte	W06
	.byte			An3
	.byte	W06
	.byte			Gn3
	.byte	W06
	.byte			An3
	.byte	W06
	.byte			As3
	.byte	W06
	.byte			Dn4
	.byte	W06
	.byte			Gn4
	.byte	W06
	.byte			An4
	.byte	W06
	.byte			As4
	.byte	W06
	.byte			Dn5
	.byte	W06
	.byte	PEND
song_0002_3_6:
	.byte		N04	, Gn5, v127
	.byte	W06
	.byte			An5
	.byte	W06
	.byte			As5
	.byte	W06
	.byte			An5
	.byte	W06
	.byte			Gn5
	.byte	W06
	.byte			Fn5
	.byte	W06
	.byte			Dn5
	.byte	W06
	.byte			Fn5
	.byte	W06
	.byte			Dn5
	.byte	W06
	.byte			Cn5
	.byte	W06
	.byte			As4
	.byte	W06
	.byte			An4
	.byte	W06
	.byte			Gn4
	.byte	W06
	.byte			Fn4
	.byte	W06
	.byte			Dn4
	.byte	W06
	.byte			Cn4
	.byte	W06
	.byte	PEND
	.byte	PATT	
		.word	song_0002_3_4
	.byte	PATT	
		.word	song_0002_3_4
	.byte	PATT	
		.word	song_0002_3_5
	.byte	PATT	
		.word	song_0002_3_6
	.byte		N84	, Dn4, v127
	.byte	W84
	.byte		N06	, Cn4
	.byte	W06
	.byte			Dn4
	.byte	W06
	.byte		N72	, Gn4
	.byte	W72
	.byte		N24	, An4
	.byte	W24
	.byte		N48	, As4
	.byte	W48
	.byte			An4
	.byte	W48
	.byte			Dn5
	.byte	W48
	.byte			Cn5
	.byte	W48
	.byte	W12
	.byte		N12	, Dn5
	.byte	W12
	.byte		N08	, Cn5
	.byte	W36
	.byte		N12	, Dn5
	.byte	W12
	.byte		N08	, Cn5
	.byte	W24
	.byte	W12
	.byte			Dn5
	.byte	W24
	.byte			Cn5
	.byte	W24
	.byte			As4
	.byte	W24
	.byte		N12	, An4
	.byte	W12
	.byte	GOTO	
		.word	song_0002_3_7
	.byte	FINE

	@********************** Track  4 **********************@

	.global song_0002_4
song_0002_4:	@ 0x087D24C8
	.byte	KEYSH	, 0
	.byte	VOICE	, 22
	.byte	VOL	, v075
	.byte	PAN	, c_v
	.byte	W01
	.byte	MOD	, 0
	.byte	BEND	, c_v
	.byte	W23
song_0002_4_2:
	.byte	W96
	.byte	W72
	.byte		N08	, Dn2, v127
	.byte	W08
	.byte		N04	, Cs2
	.byte	W04
	.byte			Cn2
	.byte	W04
	.byte			As1
	.byte	W04
	.byte			An1
	.byte	W04
	.byte		N66	, Gn1
	.byte	W72
	.byte		N22	
	.byte	W24
	.byte		N60	, Cn2
	.byte	W72
	.byte		N84	, Gn2
	.byte	W24
	.byte	W72
	.byte		N40	, Ds2
	.byte	W24
	.byte	W24
	.byte		N16	
	.byte	W24
	.byte			Fn2
	.byte	W24
	.byte		N21	
	.byte	W24
	.byte		N66	, Gn1
	.byte	W72
	.byte		N18	
	.byte	W24
	.byte		N60	, Cn2
	.byte	W72
	.byte		N72	, Ds2
	.byte	W24
	.byte	W48
	.byte		N48	, Ds1
	.byte	W48
	.byte			Fn1
	.byte	W48
	.byte			Fn2
	.byte	W48
	.byte		N16	, Gn2
	.byte	W24
	.byte		N08	, Gn1
	.byte	W24
	.byte		N08	
	.byte	W24
	.byte		N08	
	.byte	W24
	.byte		N08	
	.byte	W24
	.byte		N08	
	.byte	W24
	.byte		N08	
	.byte	W24
	.byte		N08	
	.byte	W24
	.byte		N16	
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte		N96	
	.byte	W96
	.byte			Fn1
	.byte	W96
	.byte		TIE	, Gn1
	.byte	W96
	.byte	W96
	.byte		EOT	
song_0002_4_1:
	.byte		N16	, Ds2, v127
	.byte	W24
	.byte		N16	
	.byte	W24
	.byte		N16	
	.byte	W24
	.byte		N16	
	.byte	W24
	.byte	PEND
	.byte	PATT	
		.word	song_0002_4_1
	.byte	PATT	
		.word	song_0002_4_1
	.byte		N16	, Fn2, v127
	.byte	W24
	.byte		N16	
	.byte	W24
	.byte		N16	
	.byte	W24
	.byte		N16	
	.byte	W24
	.byte	W36
	.byte		N12	, Fn1
	.byte	W12
	.byte		N08	, Gn1
	.byte	W36
	.byte		N12	, Fn1
	.byte	W12
	.byte		N08	, Gn1
	.byte	W24
	.byte		N12	
	.byte	W24
	.byte		N12	
	.byte	W24
	.byte		N12	
	.byte	W24
	.byte	GOTO	
		.word	song_0002_4_2
	.byte	FINE

	@********************** Track  5 **********************@

	.global song_0002_5
song_0002_5:	@ 0x087D2566
	.byte	KEYSH	, 0
	.byte	VOICE	, 126
	.byte	VOL	, v080
	.byte	PAN	, c_v
	.byte	W24
song_0002_5_2:
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W48
	.byte		N12	, Fn3, v127
	.byte	W24
	.byte		N12	
	.byte	W24
	.byte			Gn3
	.byte	W84
	.byte		N04	
	.byte	W04
	.byte		N04	
	.byte	W04
	.byte		N04	
	.byte	W04
	.byte		N12	, Cn4
	.byte	W72
	.byte			Gn3
	.byte	W24
	.byte	W72
	.byte		N12	
	.byte	W24
	.byte			Fn3
	.byte	W24
	.byte		N12	
	.byte	W24
	.byte		N12	
	.byte	W24
	.byte		N12	
	.byte	W24
	.byte			Gn3
	.byte	W60
	.byte		N06	
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte		N08	, Dn4
	.byte	W12
	.byte		N06	, Gn3
	.byte	W06
	.byte			Dn4
	.byte	W06
	.byte		N11	, Gn3
	.byte	W36
	.byte		N06	
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte		N09	, Dn4
	.byte	W12
	.byte		N06	, Gn3
	.byte	W06
	.byte			Dn4
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte			Gn3
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte			Dn4
	.byte	W06
	.byte		N10	, Gn3
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W84
	.byte		N06	
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte		N09	
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
song_0002_5_1:
	.byte		N12	, Cn5, v127
	.byte	W24
	.byte		N12	
	.byte	W24
	.byte		N12	
	.byte	W24
	.byte		N12	
	.byte	W24
	.byte	PEND
	.byte	PATT	
		.word	song_0002_5_1
	.byte	PATT	
		.word	song_0002_5_1
	.byte	PATT	
		.word	song_0002_5_1
	.byte		N12	, Cn5, v127
	.byte	W48
	.byte		N12	
	.byte	W48
	.byte	PATT	
		.word	song_0002_5_1
	.byte	GOTO	
		.word	song_0002_5_2
	.byte	FINE

	.align 2
	.global song_0002
song_0002:	@ 0x087D25F4
	.byte	5		@ trackCount
	.byte	0		@ blockCount
	.byte	10		@ priority
	.byte	168		@ reverb

	.word	voicegroup000		@ voicegroup/tone

	.word	song_0002_1		@ track
	.word	song_0002_2		@ track
	.word	song_0002_3		@ track
	.word	song_0002_4		@ track
	.word	song_0002_5		@ track
