	.include "MPlayDef.s"

	.section .rodata

	@********************** Track  1 **********************@

	.align 2
	.global song_0019_1
song_0019_1:	@ 0x087D8F08
	.byte	KEYSH	, 0
	.byte	TEMPO	, 125
	.byte	VOICE	, 12
	.byte	VOL	, v094
	.byte	PAN	, c_v
	.byte	W24
	.byte	TEMPO	, 65
	.byte		N72	, Gn2, v127
	.byte		N72	, Gn3
	.byte	W72
song_0019_1_1:
	.byte		N72	, Gn2, v127
	.byte		N72	, Gn3
	.byte	W72
	.byte			Fn3
	.byte		N72	, Gs3
	.byte	W72
	.byte			Ds3
	.byte		N72	, Gn3
	.byte	W72
	.byte		N72	
	.byte		N72	, Cn4
	.byte	W72
	.byte			Fn3
	.byte		N72	, Bn3
	.byte	W72
	.byte		N72	
	.byte		N72	, Fn4
	.byte	W72
	.byte			Cn4
	.byte		N72	, Ds4
	.byte	W72
	.byte			Gs3
	.byte		N72	, Ds4
	.byte	W72
	.byte			Cn4
	.byte		N72	, Fn4
	.byte	W72
	.byte			Gs3
	.byte		N72	, Dn4
	.byte	W72
	.byte			Ds4
	.byte		N72	, Gn4
	.byte	W72
	.byte			Fn3
	.byte		N72	, Bn3
	.byte	W72
	.byte		TIE	, Gn3
	.byte		TIE	, Cn4
	.byte	W72
	.byte	W72
	.byte		EOT	, Gn3
	.byte			Cn4
	.byte		N72	, Gn3
	.byte		N72	, Cs4
	.byte	W72
	.byte			An3
	.byte		N72	, Cs4
	.byte	W72
	.byte			An3
	.byte		N72	, Dn4
	.byte	W72
	.byte		N72	
	.byte		N72	, Fn4
	.byte	W72
	.byte			Cs4
	.byte		N72	, En4
	.byte	W72
	.byte			Cs4
	.byte		N72	, An4
	.byte	W72
	.byte			Cn4
	.byte		N72	, Fn4
	.byte	W72
	.byte			An3
	.byte		N72	, Dn4
	.byte	W72
	.byte			Gn3
	.byte		N72	, As3
	.byte	W72
	.byte			Ds4
	.byte		N72	, Gn4
	.byte	W72
	.byte			Gn3
	.byte		N72	, Dn4
	.byte	W72
	.byte			En3
	.byte		N72	, Cs4
	.byte	W72
	.byte			As3
	.byte		N72	, Dn4
	.byte	W72
	.byte			Gn3
	.byte		N72	, Dn4
	.byte	W72
	.byte		TIE	, En3
	.byte		N72	, Dn4
	.byte	W72
	.byte			Cs4
	.byte	W72
	.byte		EOT	, En3
	.byte		TIE	, An3
	.byte		TIE	, Dn4
	.byte	W72
	.byte	W72
	.byte		EOT	, An3
	.byte			Dn4
	.byte	GOTO	
		.word	song_0019_1_1
	.byte	FINE

	@********************** Track  2 **********************@

	.global song_0019_2
song_0019_2:	@ 0x087D8FA7
	.byte	KEYSH	, 0
	.byte	VOICE	, 22
	.byte	VOL	, v094
	.byte	PAN	, c_v
	.byte	W24
	.byte	W72
song_0019_2_1:
	.byte		N24	, Gn1, v127
	.byte	W24
	.byte		N24	
	.byte	W24
	.byte		N24	
	.byte	W24
	.byte	PEND
	.byte	PATT	
		.word	song_0019_2_1
	.byte	PATT	
		.word	song_0019_2_1
	.byte	PATT	
		.word	song_0019_2_1
	.byte	PATT	
		.word	song_0019_2_1
	.byte	PATT	
		.word	song_0019_2_1
song_0019_2_3:
	.byte		N24	, Gs1, v127
	.byte	W24
	.byte		N24	
	.byte	W24
	.byte		N24	
	.byte	W24
	.byte	PEND
	.byte	PATT	
		.word	song_0019_2_1
song_0019_2_2:
	.byte		N24	, Fn1, v127
	.byte	W24
	.byte		N24	
	.byte	W24
	.byte		N24	
	.byte	W24
	.byte	PEND
	.byte	PATT	
		.word	song_0019_2_2
	.byte	PATT	
		.word	song_0019_2_1
	.byte	PATT	
		.word	song_0019_2_1
	.byte	PATT	
		.word	song_0019_2_3
	.byte	PATT	
		.word	song_0019_2_3
song_0019_2_4:
	.byte		N24	, An1, v127
	.byte	W24
	.byte		N24	
	.byte	W24
	.byte		N24	
	.byte	W24
	.byte	PEND
	.byte	PATT	
		.word	song_0019_2_4
song_0019_2_5:
	.byte		N24	, Dn2, v127
	.byte	W24
	.byte		N24	
	.byte	W24
	.byte		N24	
	.byte	W24
	.byte	PEND
	.byte	PATT	
		.word	song_0019_2_5
	.byte	PATT	
		.word	song_0019_2_5
	.byte	PATT	
		.word	song_0019_2_5
	.byte	PATT	
		.word	song_0019_2_5
	.byte	PATT	
		.word	song_0019_2_5
song_0019_2_6:
	.byte		N24	, Ds2, v127
	.byte	W24
	.byte		N24	
	.byte	W24
	.byte		N24	
	.byte	W24
	.byte	PEND
	.byte	PATT	
		.word	song_0019_2_6
	.byte	PATT	
		.word	song_0019_2_4
	.byte	PATT	
		.word	song_0019_2_4
	.byte		N24	, As1, v127
	.byte	W24
	.byte		N24	
	.byte	W24
	.byte		N24	
	.byte	W24
	.byte	PATT	
		.word	song_0019_2_1
	.byte	PATT	
		.word	song_0019_2_4
	.byte	PATT	
		.word	song_0019_2_4
	.byte	PATT	
		.word	song_0019_2_5
	.byte	PATT	
		.word	song_0019_2_5
	.byte	GOTO	
		.word	song_0019_2_1
	.byte	FINE

	@********************** Track  3 **********************@

	.global song_0019_3
song_0019_3:	@ 0x087D9072
	.byte	KEYSH	, 0
	.byte	VOICE	, 0
	.byte	VOL	, v094
	.byte	PAN	, c_v
	.byte	W24
	.byte	W72
song_0019_3_8:
	.byte		N04	, Gn2, v127
	.byte		N04	, Dn4
	.byte	W12
	.byte			Dn3
	.byte		N04	, Gn4
	.byte	W12
	.byte			Gn2
	.byte		N04	, Dn4
	.byte	W12
	.byte			Dn3
	.byte		N04	, Gn4
	.byte	W12
	.byte			Gn2
	.byte		N04	, Dn4
	.byte	W12
	.byte			Dn3
	.byte		N04	, Gn4
	.byte	W12
	.byte			Gn2
	.byte		N04	, Bn3
	.byte	W12
	.byte			Dn3
	.byte		N04	, Gs4
	.byte	W12
	.byte			Gn2
	.byte		N04	, Bn3
	.byte	W12
	.byte			Dn3
	.byte		N04	, Gs4
	.byte	W12
	.byte			Gn2
	.byte		N04	, Bn3
	.byte	W12
	.byte			Dn3
	.byte		N04	, Gs4
	.byte	W12
song_0019_3_2:
	.byte		N04	, Gn2, v127
	.byte		N04	, Cn4
	.byte	W12
	.byte			Ds3
	.byte		N04	, Gn4
	.byte	W12
	.byte			Gn2
	.byte		N04	, Cn4
	.byte	W12
	.byte			Ds3
	.byte		N04	, Gn4
	.byte	W12
	.byte			Gn2
	.byte		N04	, Cn4
	.byte	W12
	.byte			Ds3
	.byte		N04	, Gn4
	.byte	W12
	.byte	PEND
song_0019_3_1:
	.byte		N04	, Gn2, v127
	.byte		N04	, Ds4
	.byte	W12
	.byte			Ds3
	.byte		N04	, Cn5
	.byte	W12
	.byte			Gn2
	.byte		N04	, Ds4
	.byte	W12
	.byte			Ds3
	.byte		N04	, Cn5
	.byte	W12
	.byte			Gn2
	.byte		N04	, Ds4
	.byte	W12
	.byte			Ds3
	.byte		N04	, Cn5
	.byte	W12
	.byte	PEND
	.byte			Gn2
	.byte		N04	, Dn4
	.byte	W12
	.byte			Dn3
	.byte		N04	, Bn4
	.byte	W12
	.byte			Gn2
	.byte		N04	, Dn4
	.byte	W12
	.byte			Dn3
	.byte		N04	, Bn4
	.byte	W12
	.byte			Gn2
	.byte		N04	, Dn4
	.byte	W12
	.byte			Dn3
	.byte		N04	, Bn4
	.byte	W12
	.byte			Gn2
	.byte		N04	, Fn4
	.byte	W12
	.byte			Dn3
	.byte		N04	, Dn5
	.byte	W12
	.byte			Gn2
	.byte		N04	, Fn4
	.byte	W12
	.byte			Dn3
	.byte		N04	, Dn5
	.byte	W12
	.byte			Gn2
	.byte		N04	, Fn4
	.byte	W12
	.byte			Dn3
	.byte		N04	, Dn5
	.byte	W12
	.byte			Gs2
	.byte		N04	, Ds4
	.byte	W12
	.byte			Ds3
	.byte		N04	, Ds5
	.byte	W12
	.byte			Gs2
	.byte		N04	, Ds4
	.byte	W12
	.byte			Ds3
	.byte		N04	, Ds5
	.byte	W12
	.byte			Gs2
	.byte		N04	, Ds4
	.byte	W12
	.byte			Ds3
	.byte		N04	, Ds5
	.byte	W12
	.byte	PATT	
		.word	song_0019_3_1
	.byte		N04	, Fn2, v127
	.byte		N04	, Gs3
	.byte	W12
	.byte			Cn3
	.byte		N04	, Fn4
	.byte	W12
	.byte			Fn2
	.byte		N04	, Gs3
	.byte	W12
	.byte			Cn3
	.byte		N04	, Fn4
	.byte	W12
	.byte			Fn2
	.byte		N04	, Gs3
	.byte	W12
	.byte			Cn3
	.byte		N04	, Fn4
	.byte	W12
	.byte			Fn2
	.byte		N04	, Dn4
	.byte	W12
	.byte			Dn3
	.byte		N04	, Gs4
	.byte	W12
	.byte			Fn2
	.byte		N04	, Dn4
	.byte	W12
	.byte			Dn3
	.byte		N04	, Gs4
	.byte	W12
	.byte			Fn2
	.byte		N04	, Dn4
	.byte	W12
	.byte			Dn3
	.byte		N04	, Gs4
	.byte	W12
	.byte	PATT	
		.word	song_0019_3_2
	.byte		N04	, Gn2, v127
	.byte		N04	, Bn3
	.byte	W12
	.byte			Fn3
	.byte		N04	, Gn4
	.byte	W12
	.byte			Gn2
	.byte		N04	, Bn3
	.byte	W12
	.byte			Fn3
	.byte		N04	, Gn4
	.byte	W12
	.byte			Gn2
	.byte		N04	, Bn3
	.byte	W12
	.byte			Fn3
	.byte		N04	, Gn4
	.byte	W12
song_0019_3_3:
	.byte		N04	, Gs2, v127
	.byte		N04	, Cn4
	.byte	W12
	.byte			Ds3
	.byte		N04	, Cn5
	.byte	W12
	.byte			Gs2
	.byte		N04	, Cn4
	.byte	W12
	.byte			Ds3
	.byte		N04	, Cn5
	.byte	W12
	.byte			Gs2
	.byte		N04	, Cn4
	.byte	W12
	.byte			Ds3
	.byte		N04	, Cn5
	.byte	W12
	.byte	PEND
	.byte	PATT	
		.word	song_0019_3_3
	.byte		N04	, An2, v127
	.byte		N04	, Cs4
	.byte	W12
	.byte			En3
	.byte		N04	, An4
	.byte	W12
	.byte			An2
	.byte		N04	, Cs4
	.byte	W12
	.byte			En3
	.byte		N04	, An4
	.byte	W12
	.byte			An2
	.byte		N04	, Cs4
	.byte	W12
	.byte			En3
	.byte		N04	, An4
	.byte	W12
	.byte		N06	, Gn3
	.byte	W06
	.byte			An3
	.byte	W06
	.byte			Cs4
	.byte	W06
	.byte			En4
	.byte	W06
	.byte			An3
	.byte	W06
	.byte			Cs4
	.byte	W06
	.byte			En4
	.byte	W06
	.byte			Gn4
	.byte	W06
	.byte			Cs4
	.byte	W06
	.byte			En4
	.byte	W06
	.byte			Gn4
	.byte	W06
	.byte			Cs5
	.byte	W06
song_0019_3_4:
	.byte		N06	, Fn5, v127
	.byte	W06
	.byte			Dn5
	.byte	W06
	.byte			An4
	.byte	W06
	.byte			Fn4
	.byte	W06
	.byte			Fn5
	.byte	W06
	.byte			Dn5
	.byte	W06
	.byte			An4
	.byte	W06
	.byte			Fn4
	.byte	W06
	.byte			Fn5
	.byte	W06
	.byte			Dn5
	.byte	W06
	.byte			An4
	.byte	W06
	.byte			Fn4
	.byte	W06
	.byte	PEND
	.byte	PATT	
		.word	song_0019_3_4
song_0019_3_5:
	.byte		N06	, En5, v127
	.byte	W06
	.byte			Cs5
	.byte	W06
	.byte			An4
	.byte	W06
	.byte			En4
	.byte	W06
	.byte			En5
	.byte	W06
	.byte			Cs5
	.byte	W06
	.byte			An4
	.byte	W06
	.byte			En4
	.byte	W06
	.byte			En5
	.byte	W06
	.byte			Cs5
	.byte	W06
	.byte			An4
	.byte	W06
	.byte			En4
	.byte	W06
	.byte	PEND
	.byte	PATT	
		.word	song_0019_3_5
	.byte	PATT	
		.word	song_0019_3_4
	.byte	PATT	
		.word	song_0019_3_4
song_0019_3_6:
	.byte		N06	, Gn5, v127
	.byte	W06
	.byte			Dn5
	.byte	W06
	.byte			As4
	.byte	W06
	.byte			Gn4
	.byte	W06
	.byte			Gn5
	.byte	W06
	.byte			Dn5
	.byte	W06
	.byte			As4
	.byte	W06
	.byte			Gn4
	.byte	W06
	.byte			Gn5
	.byte	W06
	.byte			Dn5
	.byte	W06
	.byte			As4
	.byte	W06
	.byte			Gn4
	.byte	W06
	.byte	PEND
	.byte	PATT	
		.word	song_0019_3_6
	.byte		N06	, Gn5, v127
	.byte	W06
	.byte			En5
	.byte	W06
	.byte			An4
	.byte	W06
	.byte			Gn4
	.byte	W06
	.byte			Gn5
	.byte	W06
	.byte			En5
	.byte	W06
	.byte			An4
	.byte	W06
	.byte			Gn4
	.byte	W06
	.byte			Gn5
	.byte	W06
	.byte			En5
	.byte	W06
	.byte			An4
	.byte	W06
	.byte			Gn4
	.byte	W06
	.byte	PATT	
		.word	song_0019_3_5
song_0019_3_7:
	.byte		N06	, Fn5, v127
	.byte	W06
	.byte			Dn5
	.byte	W06
	.byte			As4
	.byte	W06
	.byte			Fn4
	.byte	W06
	.byte			Fn5
	.byte	W06
	.byte			Dn5
	.byte	W06
	.byte			As4
	.byte	W06
	.byte			Fn4
	.byte	W06
	.byte			Fn5
	.byte	W06
	.byte			Dn5
	.byte	W06
	.byte			As4
	.byte	W06
	.byte			Fn4
	.byte	W06
	.byte	PEND
	.byte	PATT	
		.word	song_0019_3_7
	.byte		N06	, En5, v127
	.byte	W06
	.byte			Dn5
	.byte	W06
	.byte			An4
	.byte	W06
	.byte			Gn4
	.byte	W06
	.byte			En5
	.byte	W06
	.byte			Dn5
	.byte	W06
	.byte			An4
	.byte	W06
	.byte			Gn4
	.byte	W06
	.byte			En5
	.byte	W06
	.byte			Dn5
	.byte	W06
	.byte			An4
	.byte	W06
	.byte			Gn4
	.byte	W06
	.byte	PATT	
		.word	song_0019_3_5
	.byte		N04	, An2, v127
	.byte		N04	, Fn4
	.byte	W06
	.byte		N04	
	.byte	W06
	.byte			Fn3
	.byte		N04	, An4
	.byte	W06
	.byte		N04	
	.byte	W06
	.byte			En3
	.byte		N04	, Gn4
	.byte	W06
	.byte		N04	
	.byte	W06
	.byte			Dn3
	.byte		N04	, Fn4
	.byte	W06
	.byte		N04	
	.byte	W06
	.byte			An2
	.byte		N04	, Dn4
	.byte	W06
	.byte		N04	
	.byte	W06
	.byte			Gn2
	.byte		N04	, Cn4
	.byte	W06
	.byte		N04	
	.byte	W06
	.byte			Fn2
	.byte		N04	, An3
	.byte	W06
	.byte		N04	
	.byte	W06
	.byte			En2
	.byte		N04	, Gn3
	.byte	W06
	.byte		N04	
	.byte	W06
	.byte			Dn2
	.byte		N04	, Fn3
	.byte	W06
	.byte		N04	
	.byte	W06
	.byte			En2
	.byte		N04	, Gn3
	.byte	W06
	.byte		N04	
	.byte	W06
	.byte			Fn2
	.byte		N04	, An3
	.byte	W06
	.byte		N04	
	.byte	W06
	.byte			An2
	.byte		N04	, Dn4
	.byte	W06
	.byte		N04	
	.byte	W06
	.byte	GOTO	
		.word	song_0019_3_8
	.byte	FINE

	@********************** Track  4 **********************@

	.global song_0019_4
song_0019_4:	@ 0x087D92ED
	.byte	KEYSH	, 0
	.byte	VOICE	, 126
	.byte	VOL	, v094
	.byte	PAN	, c_v
	.byte	W24
	.byte	W72
song_0019_4_3:
	.byte		N06	, Cn1, v127
	.byte		N21	, Cs2
	.byte	W24
	.byte		N06	, Cn1
	.byte	W24
	.byte		N06	
	.byte	W24
song_0019_4_1:
	.byte		N06	, Cn1, v127
	.byte	W24
	.byte		N06	
	.byte	W12
	.byte			Dn1
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte			Cn1
	.byte		N06	, Dn1
	.byte	W24
	.byte	PEND
song_0019_4_2:
	.byte		N06	, Cn1, v127
	.byte	W24
	.byte		N06	
	.byte	W24
	.byte		N06	
	.byte	W24
	.byte	PEND
	.byte	PATT	
		.word	song_0019_4_1
	.byte	PATT	
		.word	song_0019_4_2
	.byte	PATT	
		.word	song_0019_4_1
	.byte	PATT	
		.word	song_0019_4_2
	.byte	PATT	
		.word	song_0019_4_1
	.byte	PATT	
		.word	song_0019_4_2
	.byte	PATT	
		.word	song_0019_4_1
	.byte	PATT	
		.word	song_0019_4_2
	.byte	PATT	
		.word	song_0019_4_1
	.byte	PATT	
		.word	song_0019_4_2
	.byte	PATT	
		.word	song_0019_4_1
	.byte	PATT	
		.word	song_0019_4_2
	.byte		N06	, Cn1, v127
	.byte	W06
	.byte			Cn2
	.byte	W06
	.byte		N06	
	.byte	W12
	.byte			Cn1
	.byte		N06	, An1
	.byte	W12
	.byte			Dn1
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte			Cn1
	.byte		N06	, Dn1
	.byte	W06
	.byte			Fn1
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte			Cn1
	.byte		N22	, An2
	.byte	W24
	.byte		N06	, Cn1
	.byte	W24
	.byte		N06	
	.byte	W24
	.byte	PATT	
		.word	song_0019_4_1
	.byte	PATT	
		.word	song_0019_4_2
	.byte	PATT	
		.word	song_0019_4_1
	.byte	PATT	
		.word	song_0019_4_2
	.byte	PATT	
		.word	song_0019_4_1
	.byte	PATT	
		.word	song_0019_4_2
	.byte	PATT	
		.word	song_0019_4_1
	.byte	PATT	
		.word	song_0019_4_2
	.byte	PATT	
		.word	song_0019_4_1
	.byte	PATT	
		.word	song_0019_4_2
	.byte	PATT	
		.word	song_0019_4_1
	.byte	PATT	
		.word	song_0019_4_2
	.byte	PATT	
		.word	song_0019_4_1
	.byte	PATT	
		.word	song_0019_4_2
	.byte		N06	, Cn1, v127
	.byte	W24
	.byte		N06	
	.byte	W12
	.byte			Dn1
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte			Cn1
	.byte		N06	, Dn1
	.byte	W12
	.byte		N06	
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte	GOTO	
		.word	song_0019_4_3
	.byte	FINE

	.align 2
	.global song_0019
song_0019:	@ 0x087D93D8
	.byte	4		@ trackCount
	.byte	0		@ blockCount
	.byte	10		@ priority
	.byte	188		@ reverb

	.word	voicegroup000		@ voicegroup/tone

	.word	song_0019_1		@ track
	.word	song_0019_2		@ track
	.word	song_0019_3		@ track
	.word	song_0019_4		@ track
