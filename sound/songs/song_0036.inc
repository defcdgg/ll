	.include "MPlayDef.s"

	.section .rodata

	@********************** Track  1 **********************@

	.align 2
	.global song_0036_1
song_0036_1:	@ 0x087DE00C
	.byte	KEYSH	, 0
	.byte	TEMPO	, 125
	.byte	VOICE	, 3
	.byte	VOL	, v103
	.byte	PAN	, c_v
	.byte	W24
song_0036_1_9:
	.byte	TEMPO	, 33
	.byte		N64	, En4, v127
	.byte	W68
	.byte	W03
	.byte		N06	, An3
	.byte	W05
	.byte			Cn4
	.byte	W06
	.byte		N13	, Dn4
	.byte	W13
	.byte		N76	, En4
	.byte	W01
	.byte	W84
	.byte	W01
	.byte		N06	, Dn4
	.byte	W05
	.byte		N07	, Cn4
	.byte	W06
song_0036_1_1:
	.byte	W01
	.byte		N32	, Dn4, v127
	.byte	W32
	.byte	W01
	.byte			Bn3
	.byte	W32
	.byte	W03
	.byte		N24	, Gn3
	.byte	W24
	.byte	W02
	.byte			An3
	.byte	W01
	.byte	PEND
song_0036_1_2:
	.byte	W23
	.byte		N24	, Bn3, v127
	.byte	W24
	.byte			Cn4
	.byte	W23
	.byte		N13	, Dn4
	.byte	W13
	.byte		N11	, En4
	.byte	W11
	.byte		N06	, Ds4
	.byte	W02
	.byte	PEND
song_0036_1_3:
	.byte		N76	, En4, v127
	.byte	W80
	.byte		N06	, Dn4
	.byte	W09
	.byte		N08	, Cn4
	.byte	W07
	.byte	PEND
song_0036_1_4:
	.byte	W01
	.byte		N06	, En4, v127
	.byte	W05
	.byte		N03	, Dn4
	.byte	W04
	.byte		N68	, En4
	.byte	W68
	.byte	W02
	.byte		N06	, Dn4
	.byte	W07
	.byte		N07	, Cn4
	.byte	W07
	.byte		N36	, Dn4
	.byte	W02
	.byte	PEND
song_0036_1_5:
	.byte	W36
	.byte		N32	, Bn3, v127
	.byte	W32
	.byte	W02
	.byte		N23	, Gn3
	.byte	W24
	.byte	W02
	.byte	PEND
song_0036_1_6:
	.byte		N24	, An3, v127
	.byte	W23
	.byte		N23	, Bn3
	.byte	W24
	.byte		N22	, Cn4
	.byte	W24
	.byte		N13	, Dn4
	.byte	W12
	.byte		N12	, En4
	.byte	W13
	.byte	PEND
song_0036_1_7:
	.byte		N28	, An4, v127
	.byte	W30
	.byte	W01
	.byte		N08	, Fn4
	.byte	W08
	.byte			En4
	.byte	W08
	.byte		N36	, Cn4
	.byte	W36
	.byte	W01
	.byte		N13	, An3
	.byte	W12
	.byte	PEND
song_0036_1_8:
	.byte		N44	, Cn4, v127
	.byte	W44
	.byte	W03
	.byte		N10	, Bn3
	.byte	W10
	.byte		N06	, Cn4
	.byte	W05
	.byte		N03	, Bn3
	.byte	W04
	.byte			Cn4
	.byte	W02
	.byte		N02	, Bn3
	.byte	W03
	.byte		N03	, Cn4
	.byte	W02
	.byte		N02	, Bn3
	.byte	W02
	.byte			Cn4
	.byte	W02
	.byte			Bn3
	.byte	W02
	.byte		N01	, Cn4
	.byte	W02
	.byte		N02	, Bn3
	.byte	W02
	.byte			Cn4
	.byte	W02
	.byte			Bn3
	.byte	W02
	.byte		N06	, Cn4
	.byte	W03
	.byte		N05	, Bn3
	.byte	W05
	.byte		TIE	, An3
	.byte	W01
	.byte	PEND
	.byte	W96
	.byte	W15
	.byte		EOT	
	.byte	W32
	.byte		N12	
	.byte	W11
	.byte		N13	, Bn3
	.byte	W12
	.byte		N12	, Cn4
	.byte	W12
	.byte			Dn4
	.byte	W11
	.byte		N03	, Ds4
	.byte	W03
	.byte		N07	, En4
	.byte	W06
	.byte		N05	, Dn4
	.byte	W04
	.byte		N60	, En4
	.byte	W60
	.byte	W01
	.byte		N06	, An3
	.byte	W07
	.byte		N05	, Cn4
	.byte	W07
	.byte		N07	, Dn4
	.byte	W09
	.byte		N09	, En4
	.byte	W02
	.byte	W07
	.byte		N07	, Gn4
	.byte	W06
	.byte		N78	, En4
	.byte	W80
	.byte	W03
	.byte	PATT	
		.word	song_0036_1_1
	.byte	PATT	
		.word	song_0036_1_2
	.byte	PATT	
		.word	song_0036_1_3
	.byte	PATT	
		.word	song_0036_1_4
	.byte	PATT	
		.word	song_0036_1_5
	.byte	PATT	
		.word	song_0036_1_6
	.byte	PATT	
		.word	song_0036_1_7
	.byte	PATT	
		.word	song_0036_1_8
	.byte	W96
	.byte	W15
	.byte		EOT	, An3
	.byte	W80
	.byte	W01
	.byte	GOTO	
		.word	song_0036_1_9
	.byte	FINE

	@********************** Track  2 **********************@

	.global song_0036_2
song_0036_2:	@ 0x087DE135
	.byte	KEYSH	, 0
	.byte	VOICE	, 1
	.byte	VOL	, v103
	.byte	PAN	, c_v
	.byte	W24
song_0036_2_2:
	.byte		N92	, Fn1, v127
	.byte		N24	, An2
	.byte	W01
	.byte		N09	, Cn3
	.byte		N32	, En3
	.byte	W11
	.byte		N09	, Cn2
	.byte	W12
	.byte			Fn2
	.byte	W12
	.byte		N56	, An2
	.byte		N56	, Cn3
	.byte	W60
	.byte		N92	, Fn1
	.byte		N23	, An2
	.byte	W01
	.byte		N11	, Bn2
	.byte		N32	, En3
	.byte	W11
	.byte		N09	, Cn2
	.byte	W12
	.byte		N10	, Fn2
	.byte	W12
	.byte		N56	, Bn2
	.byte	W60
	.byte		N96	, En1
	.byte		N11	, En2
	.byte	W01
	.byte		N22	, Bn2
	.byte		N32	, Dn3
	.byte	W11
	.byte		N11	, Bn1
	.byte	W12
	.byte		N12	, Gn2
	.byte	W12
	.byte		N56	, Bn2
	.byte		N56	, En3
	.byte	W60
	.byte		N32	, An1
	.byte		N10	, En2
	.byte	W01
	.byte		N09	, An2
	.byte		N22	, Cn3
	.byte		N10	, En3
	.byte	W11
	.byte			En2
	.byte	W12
	.byte		N23	, An2
	.byte	W12
	.byte		N11	, An1
	.byte	W12
	.byte		N32	, Gn1
	.byte		N11	, En2
	.byte		N11	, Gn2
	.byte		N11	, Cn3
	.byte	W12
	.byte		N07	, En2
	.byte	W12
	.byte		N23	, Gn2
	.byte		N12	, Dn3
	.byte	W12
	.byte		N13	, Gn1
	.byte		N11	, En3
	.byte	W12
	.byte		N92	, Fn1
	.byte		N21	, Fn2
	.byte	W01
	.byte		N32	, An2
	.byte		N10	, Cn3
	.byte	W01
	.byte		N09	, En3
	.byte	W10
	.byte		N11	, Cn2
	.byte	W12
	.byte		N10	, Fn2
	.byte	W12
	.byte		N56	, An2
	.byte		N56	, Cn3
	.byte	W60
	.byte		N92	, Fn1
	.byte		N10	, An2
	.byte	W01
	.byte		N21	, Bn2
	.byte		N21	, En3
	.byte	W11
	.byte		N10	, Cn2
	.byte	W12
	.byte		N11	, Fn2
	.byte	W12
	.byte		N56	, Bn2
	.byte		N56	, En3
	.byte	W60
	.byte		N80	, En1
	.byte		N12	, En2
	.byte	W01
	.byte		N32	, Bn2
	.byte		N32	, Dn3
	.byte		N11	, En3
	.byte	W11
	.byte			Bn1
	.byte	W12
	.byte			En2
	.byte	W12
	.byte		N56	, Gn2
	.byte		N56	, Bn2
	.byte	W48
	.byte		N13	, En1
	.byte	W12
	.byte		N22	, An1
	.byte		N23	, Gn2
	.byte		N22	, An2
	.byte		N22	, En3
	.byte	W24
	.byte		N12	, En2
	.byte		N12	, Gn2
	.byte		N12	, Bn2
	.byte	W12
	.byte		N11	, An1
	.byte	W12
	.byte		N08	, Gn1
	.byte		N11	, En2
	.byte		N11	, Gn2
	.byte		N11	, Cn3
	.byte	W12
	.byte		N13	, Gn1
	.byte	W12
	.byte		N11	, En2
	.byte		N12	, Gn2
	.byte		N11	, Dn3
	.byte	W12
	.byte		N12	, Gn1
	.byte	W12
	.byte		N48	, Fn1
	.byte		N11	, An2
	.byte	W01
	.byte		N10	, Cn3
	.byte		N10	, En3
	.byte	W11
	.byte		N12	, Cn2
	.byte	W12
	.byte		N11	, Fn2
	.byte	W12
	.byte		N12	, Cn2
	.byte	W12
	.byte		N44	, Fn1
	.byte	W12
	.byte		N12	, Cn2
	.byte	W12
	.byte			An2
	.byte		N12	, Cn3
	.byte	W12
	.byte			Cn2
	.byte	W12
	.byte		N44	, En1
	.byte		N12	, An2
	.byte	W01
	.byte		N11	, Cn3
	.byte	W11
	.byte			An1
	.byte	W12
	.byte		N19	, En2
	.byte	W23
	.byte		N48	, En1
	.byte	W02
	.byte		N44	, En2
	.byte		N44	, Gs2
	.byte	W01
	.byte			Bn2
	.byte	W44
	.byte	W02
	.byte		TIE	, An1
	.byte		TIE	, En2
	.byte		TIE	, An2
	.byte	W01
	.byte		N16	, Bn2
	.byte		TIE	, En3
	.byte	W92
	.byte	W03
	.byte	W05
	.byte		EOT	, An2
	.byte			En3
	.byte	W01
	.byte			An1
	.byte			En2
	.byte	W40
	.byte	W01
	.byte		N22	, An2
	.byte	W01
	.byte			En3
	.byte	W23
	.byte		N24	, Gn2
	.byte	W01
	.byte			En3
	.byte	W24
	.byte		N10	, Fn1
	.byte	W12
	.byte		N12	, Fn2
	.byte	W12
	.byte			Cn3
	.byte	W12
	.byte			Fn2
	.byte	W12
	.byte			En3
	.byte	W12
	.byte			Fn2
	.byte	W12
	.byte			Cn3
	.byte	W12
	.byte			Fn2
	.byte	W12
song_0036_2_1:
	.byte		N11	, Fn1, v127
	.byte	W12
	.byte		N12	, Fn2
	.byte	W12
	.byte			Bn2
	.byte	W12
	.byte			Fn2
	.byte	W12
	.byte			En3
	.byte	W12
	.byte			Fn2
	.byte	W12
	.byte			Bn2
	.byte	W12
	.byte			Fn2
	.byte	W12
	.byte	PEND
	.byte			En1
	.byte	W12
	.byte			Gn2
	.byte	W12
	.byte			Bn2
	.byte	W12
	.byte			Gn2
	.byte	W12
	.byte			Dn3
	.byte	W12
	.byte			Gn2
	.byte	W12
	.byte		N11	, Bn2
	.byte	W12
	.byte			Gn2
	.byte	W12
	.byte		N10	, An1
	.byte	W12
	.byte		N11	, En2
	.byte	W12
	.byte		N12	, An2
	.byte	W12
	.byte		N11	, An1
	.byte	W12
	.byte			Gn1
	.byte	W12
	.byte			En2
	.byte	W12
	.byte		N12	, Dn3
	.byte	W12
	.byte		N10	, En3
	.byte	W12
	.byte			Fn1
	.byte	W12
	.byte		N12	, Fn2
	.byte	W12
	.byte			An2
	.byte	W12
	.byte			Fn2
	.byte	W12
	.byte			En3
	.byte	W12
	.byte			Fn2
	.byte	W12
	.byte			An2
	.byte	W12
	.byte			Fn2
	.byte	W12
	.byte	PATT	
		.word	song_0036_2_1
	.byte		N10	, En1, v127
	.byte	W12
	.byte		N12	, Gn2
	.byte	W12
	.byte			Bn2
	.byte	W12
	.byte			Gn2
	.byte	W12
	.byte			En3
	.byte	W12
	.byte			Gn2
	.byte	W12
	.byte		N11	, Bn2
	.byte	W12
	.byte		N12	, Gn2
	.byte	W12
	.byte		N21	, An1
	.byte	W24
	.byte		N10	, Gn2
	.byte		N10	, Bn2
	.byte	W12
	.byte		N11	, An1
	.byte	W12
	.byte		N12	, Gn2
	.byte		N12	, Cn3
	.byte	W12
	.byte		N10	, Gn1
	.byte	W12
	.byte		N12	, Gn2
	.byte		N12	, Dn3
	.byte	W12
	.byte		N11	, En3
	.byte	W12
	.byte		N10	, Fn1
	.byte	W12
	.byte		N12	, Cn2
	.byte	W12
	.byte		N11	, Fn2
	.byte	W12
	.byte			Cn2
	.byte	W12
	.byte		N12	, Fn1
	.byte	W12
	.byte			Cn2
	.byte	W12
	.byte			Cn3
	.byte	W12
	.byte			Cn2
	.byte	W12
	.byte		N10	, En1
	.byte	W12
	.byte		N11	, An1
	.byte	W12
	.byte		N19	, En2
	.byte	W24
	.byte	W01
	.byte		N44	
	.byte		N44	, Gs2
	.byte	W01
	.byte			Bn2
	.byte	W44
	.byte	W02
	.byte		N11	, An1
	.byte	W12
	.byte			An2
	.byte	W12
	.byte			Bn2
	.byte	W12
	.byte			An2
	.byte	W12
	.byte			En3
	.byte	W12
	.byte			An2
	.byte	W12
	.byte		N12	, Bn2
	.byte	W12
	.byte		N11	, An2
	.byte	W12
	.byte		N10	, An1
	.byte	W12
	.byte		N12	, An2
	.byte	W12
	.byte			Bn2
	.byte	W12
	.byte			An2
	.byte	W12
	.byte			En3
	.byte	W12
	.byte			An2
	.byte	W12
	.byte			Bn2
	.byte	W12
	.byte			An2
	.byte	W12
	.byte	GOTO	
		.word	song_0036_2_2
	.byte	FINE

	@********************** Track  3 **********************@

	.global song_0036_3
song_0036_3:	@ 0x087DE34D
	.byte	KEYSH	, 0
	.byte	VOICE	, 4
	.byte	VOL	, v103
	.byte	PAN	, c_v
	.byte	W24
song_0036_3_2:
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
	.byte	W44
	.byte	W02
	.byte		N24	, An0, v127
	.byte	W24
	.byte			Gn0
	.byte	W24
	.byte	W02
	.byte		N96	, Fn0
	.byte	W96
	.byte		N96	
	.byte	W96
	.byte			En0
	.byte	W96
song_0036_3_1:
	.byte		N48	, An0, v127
	.byte	W48
	.byte			Gn0
	.byte	W48
	.byte	PEND
	.byte		N96	, Fn0
	.byte	W96
	.byte		N96	
	.byte	W96
	.byte			En0
	.byte	W96
	.byte	PATT	
		.word	song_0036_3_1
	.byte		N96	, Fn0, v127
	.byte	W96
	.byte		N48	, En0
	.byte	W48
	.byte		N48	
	.byte	W48
	.byte		TIE	, An0
	.byte	W96
	.byte	W96
	.byte		EOT	
	.byte	GOTO	
		.word	song_0036_3_2
	.byte	FINE

	@********************** Track  4 **********************@

	.global song_0036_4
song_0036_4:	@ 0x087DE398
	.byte	KEYSH	, 0
	.byte	VOICE	, 126
	.byte	VOL	, v095
	.byte	PAN	, c_v
	.byte	W24
song_0036_4_2:
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
	.byte	W72
	.byte		N06	, Gn2, v080
	.byte	W24
song_0036_4_1:
	.byte		N06	, Cn1, v127
	.byte	W42
	.byte		N06	
	.byte	W06
	.byte		N06	
	.byte	W48
	.byte	PEND
	.byte	PATT	
		.word	song_0036_4_1
	.byte	PATT	
		.word	song_0036_4_1
	.byte	PATT	
		.word	song_0036_4_1
	.byte	PATT	
		.word	song_0036_4_1
	.byte	PATT	
		.word	song_0036_4_1
	.byte	PATT	
		.word	song_0036_4_1
	.byte	PATT	
		.word	song_0036_4_1
	.byte	PATT	
		.word	song_0036_4_1
	.byte	PATT	
		.word	song_0036_4_1
	.byte	PATT	
		.word	song_0036_4_1
	.byte		N06	, Cn1, v127
	.byte	W42
	.byte		N06	
	.byte	W06
	.byte		N06	
	.byte		N06	, Gn2, v080
	.byte	W48
	.byte	GOTO	
		.word	song_0036_4_2
	.byte	FINE

	.align 2
	.global song_0036
song_0036:	@ 0x087DE400
	.byte	4		@ trackCount
	.byte	0		@ blockCount
	.byte	10		@ priority
	.byte	168		@ reverb

	.word	voicegroup000		@ voicegroup/tone

	.word	song_0036_1		@ track
	.word	song_0036_2		@ track
	.word	song_0036_3		@ track
	.word	song_0036_4		@ track
