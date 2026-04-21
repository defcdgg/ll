	.include "MPlayDef.s"

	.section .rodata

	@********************** Track  1 **********************@

	.align 2
	.global song_0018_1
song_0018_1:	@ 0x087D8A64
	.byte	KEYSH	, 0
	.byte	TEMPO	, 57
	.byte	VOICE	, 18
	.byte	VOL	, v080
	.byte	PAN	, c_v
	.byte	W72
song_0018_1_1:
	.byte		N12	, An1, v127
	.byte	W12
	.byte		N01	
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte	BEND	, c_v-64
	.byte		N12	, An2
	.byte	W06
	.byte	BEND	, c_v
	.byte	W06
	.byte		N06	, An1
	.byte	W06
	.byte		N01	
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte		N01	
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte	BEND	, c_v-64
	.byte		N12	, An2
	.byte	W06
	.byte	BEND	, c_v
	.byte	W06
	.byte		N06	, An1
	.byte	W06
	.byte	PEND
song_0018_1_2:
	.byte		N12	, An1, v127
	.byte	W12
	.byte		N01	
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte	BEND	, c_v-64
	.byte		N12	, An2
	.byte	W06
	.byte	BEND	, c_v
	.byte	W06
	.byte		N06	, An1
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte		N12	, Dn2
	.byte	W06
	.byte	BEND	, c_v-64
	.byte	W06
	.byte		N12	, An2
	.byte	W06
	.byte	BEND	, c_v
	.byte	W06
	.byte		N06	, An1
	.byte	W06
	.byte		N01	
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte	PEND
	.byte	PATT	
		.word	song_0018_1_1
song_0018_1_3:
	.byte		N12	, An1, v127
	.byte	W12
	.byte		N01	
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte	BEND	, c_v-64
	.byte		N12	, An2
	.byte	W06
	.byte	BEND	, c_v
	.byte	W06
	.byte		N06	, En1
	.byte	W06
	.byte			Fs1
	.byte	W06
	.byte			Fs2
	.byte	W06
	.byte			Gn1
	.byte	W06
	.byte			Gn2
	.byte	W06
	.byte			An1
	.byte	W06
	.byte			An2
	.byte	W06
	.byte			Bn1
	.byte	W06
	.byte			Bn2
	.byte	W06
	.byte	PEND
	.byte	PATT	
		.word	song_0018_1_1
	.byte	PATT	
		.word	song_0018_1_2
	.byte	PATT	
		.word	song_0018_1_1
	.byte	PATT	
		.word	song_0018_1_3
	.byte	PATT	
		.word	song_0018_1_1
	.byte	PATT	
		.word	song_0018_1_2
	.byte	PATT	
		.word	song_0018_1_1
	.byte	PATT	
		.word	song_0018_1_3
	.byte	PATT	
		.word	song_0018_1_1
	.byte	PATT	
		.word	song_0018_1_2
	.byte	PATT	
		.word	song_0018_1_1
	.byte	PATT	
		.word	song_0018_1_3
song_0018_1_4:
	.byte		N06	, En1, v127
	.byte	W06
	.byte		N06	
	.byte	W12
	.byte		N06	
	.byte	W06
	.byte		N06	
	.byte	W12
	.byte		N06	
	.byte	W06
	.byte		N06	
	.byte	W12
	.byte		N06	
	.byte	W06
	.byte		N06	
	.byte	W12
	.byte		N06	
	.byte	W06
	.byte		N06	
	.byte	W12
	.byte		N06	
	.byte	W06
	.byte	PEND
song_0018_1_5:
	.byte		N72	, Fn1, v127
	.byte	W72
	.byte		N24	
	.byte	W24
	.byte	PEND
	.byte	PATT	
		.word	song_0018_1_4
	.byte	PATT	
		.word	song_0018_1_5
	.byte	PATT	
		.word	song_0018_1_4
	.byte	PATT	
		.word	song_0018_1_5
	.byte	PATT	
		.word	song_0018_1_4
	.byte		N48	, Fn1, v127
	.byte	W48
	.byte			Gn1
	.byte	W48
	.byte	PATT	
		.word	song_0018_1_1
	.byte	PATT	
		.word	song_0018_1_2
	.byte	PATT	
		.word	song_0018_1_1
	.byte	PATT	
		.word	song_0018_1_3
	.byte	GOTO	
		.word	song_0018_1_1
	.byte	FINE

	@********************** Track  2 **********************@

	.global song_0018_2
song_0018_2:	@ 0x087D8B85
	.byte	KEYSH	, 0
	.byte	VOICE	, 12
	.byte	VOL	, v075
	.byte	PAN	, c_v
	.byte	W72
song_0018_2_2:
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W84
	.byte		N05	, En4, v127
	.byte	W06
	.byte			Gn4
	.byte	W06
	.byte			An4
	.byte	W06
	.byte			Cn5
	.byte	W06
	.byte			An4
	.byte	W06
	.byte			Gn4
	.byte	W06
	.byte			En4
	.byte	W06
	.byte			Gn4
	.byte	W06
	.byte			An4
	.byte	W06
	.byte			Cn5
	.byte	W06
	.byte			An4
	.byte	W06
	.byte			Gn4
	.byte	W06
	.byte			En4
	.byte	W06
	.byte			Gn4
	.byte	W06
	.byte			An4
	.byte	W06
	.byte			Cn5
	.byte	W06
	.byte			An4
	.byte	W06
	.byte			Gn4
	.byte	W06
	.byte			En4
	.byte	W06
	.byte			Gn4
	.byte	W06
	.byte			An4
	.byte	W06
	.byte			Cn5
	.byte	W06
	.byte			An4
	.byte	W06
	.byte			Gn4
	.byte	W06
	.byte			En4
	.byte	W06
	.byte			Gn4
	.byte	W06
	.byte			An4
	.byte	W06
	.byte			Cn5
	.byte	W06
	.byte			An4
	.byte	W06
	.byte			Gn4
	.byte	W06
	.byte			En4
	.byte	W06
	.byte			Gn4
	.byte	W06
	.byte			An4
	.byte	W06
	.byte			Dn5
	.byte	W06
	.byte			An4
	.byte	W06
	.byte			Gn4
	.byte	W06
	.byte			En4
	.byte	W06
	.byte			Gn4
	.byte	W06
	.byte			An4
	.byte	W06
	.byte			Cn5
	.byte	W06
	.byte			An4
	.byte	W06
	.byte			Gn4
	.byte	W06
	.byte			En4
	.byte	W06
	.byte			Gn4
	.byte	W06
	.byte			An4
	.byte	W06
	.byte			Dn5
	.byte	W06
	.byte		N04	, An4
	.byte	W04
	.byte			Gn4
	.byte	W04
	.byte			En4
	.byte	W04
	.byte			Gn4
	.byte	W04
	.byte			An4
	.byte	W04
	.byte			Cn5
	.byte	W04
	.byte			An4
	.byte	W04
	.byte			Gn4
	.byte	W04
	.byte			En4
	.byte	W04
	.byte			Gn4
	.byte	W04
	.byte			An4
	.byte	W04
	.byte			Dn5
	.byte	W04
	.byte			En5
	.byte	W04
	.byte			Gn4
	.byte	W04
	.byte			En4
	.byte	W04
	.byte			An4
	.byte	W04
	.byte			Cn5
	.byte	W04
	.byte			An4
	.byte	W04
	.byte			Gn4
	.byte	W04
	.byte			En4
	.byte	W04
	.byte			An4
	.byte	W04
	.byte			Dn5
	.byte	W04
	.byte			Gn4
	.byte	W04
	.byte		N03	, En4
	.byte	W03
	.byte			Gn4
	.byte	W04
	.byte			An4
	.byte	W03
	.byte			Cn5
	.byte	W04
	.byte			An4
	.byte	W03
	.byte			Gn4
	.byte	W04
	.byte			En4
	.byte	W03
	.byte			Gn4
	.byte	W04
	.byte		N04	, An4
	.byte	W04
	.byte			Dn5
	.byte	W04
	.byte			An4
	.byte	W04
	.byte			Gn4
	.byte	W04
	.byte			En4
	.byte	W04
	.byte			Gn4
	.byte	W04
	.byte			An4
	.byte	W04
	.byte			Cn5
	.byte	W04
	.byte			An4
	.byte	W04
	.byte			Gn4
	.byte	W04
	.byte			En4
	.byte	W04
	.byte			Gn4
	.byte	W04
	.byte			Dn5
	.byte	W04
	.byte			An4
	.byte	W04
	.byte			Gn4
	.byte	W04
	.byte			En4
	.byte	W04
	.byte			Gn4
	.byte	W04
	.byte			An4
	.byte	W04
	.byte			Cn5
	.byte	W04
	.byte			An4
	.byte	W04
	.byte			Gn4
	.byte	W04
	.byte			En4
	.byte	W04
	.byte			An4
	.byte	W04
	.byte			Dn5
	.byte	W04
	.byte			An4
	.byte	W04
	.byte			Gn4
	.byte	W04
	.byte			An4
	.byte	W04
	.byte			En4
	.byte	W04
	.byte			Gn4
	.byte	W04
	.byte			An4
	.byte	W04
	.byte			Cn5
	.byte	W04
	.byte			An4
	.byte	W04
	.byte			Gn4
	.byte	W04
	.byte			En4
	.byte	W04
	.byte			An4
	.byte	W04
	.byte			Dn5
	.byte	W04
	.byte			An4
	.byte	W04
	.byte			Gn4
	.byte	W04
	.byte			En4
	.byte	W04
	.byte			An4
	.byte	W04
	.byte			Cn5
	.byte	W04
	.byte		N03	, An4
	.byte	W03
	.byte			Gn4
	.byte	W04
	.byte			En4
	.byte	W03
	.byte			Gn4
	.byte	W04
	.byte			An4
	.byte	W03
	.byte			Dn5
	.byte	W04
	.byte			An4
	.byte	W03
	.byte			Gn4
	.byte	W04
	.byte		N04	, En4
	.byte	W04
	.byte			Cn5
	.byte	W04
	.byte			An4
	.byte	W04
	.byte			Gn4
	.byte	W04
	.byte			En4
	.byte	W04
	.byte			Gn4
	.byte	W04
	.byte			Dn5
	.byte	W04
	.byte			An4
	.byte	W04
	.byte			Gn4
	.byte	W04
	.byte			En4
	.byte	W04
	.byte			An4
	.byte	W04
	.byte		N03	, Cn5
	.byte	W03
	.byte			Gn4
	.byte	W04
	.byte			En4
	.byte	W03
	.byte			Fn4
	.byte	W03
	.byte			Cn5
	.byte	W03
	.byte			An4
	.byte	W03
	.byte			Gn4
	.byte	W03
	.byte			En4
	.byte	W03
	.byte			An4
	.byte	W03
	.byte			Gn4
	.byte	W03
	.byte			Bn4
	.byte	W03
	.byte			En4
	.byte	W03
	.byte			Dn5
	.byte	W03
	.byte			An4
	.byte	W03
	.byte			Gn4
	.byte	W03
	.byte			En4
	.byte	W03
	.byte			An4
	.byte	W03
	.byte		N01	, En4
	.byte		N01	, Gn4
	.byte	W01
	.byte			Bn4
	.byte	W01
	.byte		N54	, En5
	.byte	W92
	.byte	W02
	.byte	W92
	.byte	W03
	.byte		N23	, Bn4
	.byte		N01	, Ds5
	.byte		N23	, En5
	.byte	W01
	.byte	W32
	.byte		N01	, An4
	.byte	W64
song_0018_2_1:
	.byte	W84
	.byte	W01
	.byte		N02	, Bn4, v127
	.byte	W11
	.byte	PEND
	.byte			Ds5
	.byte	W02
	.byte		N23	, Bn4
	.byte		N23	, En5
	.byte	W92
	.byte	W02
	.byte	PATT	
		.word	song_0018_2_1
	.byte		N02	, Ds5, v127
	.byte	W02
	.byte		N19	, Bn4
	.byte		N19	, En5
	.byte	W90
	.byte		N01	, Cn5
	.byte	W02
	.byte			Dn5
	.byte	W01
	.byte			En5
	.byte	W01
	.byte		N48	, Fn5
	.byte	W48
	.byte		N14	, En5
	.byte	W12
	.byte		N04	, Dn5
	.byte	W12
	.byte		N15	, Cn5
	.byte	W12
	.byte		N04	, Bn4
	.byte	W12
	.byte		N06	, Cn5
	.byte	W06
	.byte			Bn4
	.byte	W06
	.byte		TIE	, An4
	.byte	W84
	.byte	W80
	.byte	W03
	.byte		EOT	
	.byte	W13
	.byte	W96
	.byte	W96
	.byte	GOTO	
		.word	song_0018_2_2
	.byte	FINE

	@********************** Track  3 **********************@

	.global song_0018_3
song_0018_3:	@ 0x087D8D32
	.byte	KEYSH	, 0
	.byte	VOICE	, 2
	.byte	VOL	, v075
	.byte	PAN	, c_v
	.byte	W72
song_0018_3_2:
	.byte		N96	, An3, v127
	.byte	W96
	.byte			Cn4
	.byte	W96
	.byte			Bn3
	.byte	W96
	.byte			Gn3
	.byte	W96
	.byte			An3
	.byte	W96
	.byte			Cn4
	.byte	W96
	.byte			Bn3
	.byte	W96
	.byte			Gn3
	.byte	W96
	.byte			An3
	.byte	W96
	.byte			Cn4
	.byte	W96
	.byte			Bn3
	.byte	W96
	.byte			Gn3
	.byte	W96
	.byte			An3
	.byte	W96
	.byte			Cn4
	.byte	W96
	.byte			Bn3
	.byte	W96
	.byte			Gn3
	.byte	W96
song_0018_3_1:
	.byte		N06	, Bn3, v127
	.byte	W06
	.byte		N06	
	.byte	W12
	.byte		N06	
	.byte	W06
	.byte		N06	
	.byte	W12
	.byte		N06	
	.byte	W06
	.byte		N06	
	.byte	W12
	.byte		N06	
	.byte	W06
	.byte		N06	
	.byte	W12
	.byte		N06	
	.byte	W06
	.byte		N06	
	.byte	W12
	.byte		N06	
	.byte	W06
	.byte	PEND
	.byte		N96	, Cn4
	.byte	W96
	.byte	PATT	
		.word	song_0018_3_1
	.byte		N96	, Cn4, v127
	.byte	W96
	.byte	PATT	
		.word	song_0018_3_1
	.byte		N96	, Cn4, v127
	.byte	W96
	.byte	PATT	
		.word	song_0018_3_1
	.byte		N48	, Cn4, v127
	.byte	W48
	.byte			Bn3
	.byte	W48
	.byte		N96	, An3
	.byte	W96
	.byte			Cn4
	.byte	W96
	.byte			Bn3
	.byte	W96
	.byte			Gn3
	.byte	W96
	.byte	GOTO	
		.word	song_0018_3_2
	.byte	FINE

	@********************** Track  4 **********************@

	.global song_0018_4
song_0018_4:	@ 0x087D8DA5
	.byte	KEYSH	, 0
	.byte	VOICE	, 126
	.byte	VOL	, v075
	.byte	PAN	, c_v
	.byte	W18
	.byte		N03	, Dn1, v127
	.byte	W03
	.byte		N03	
	.byte	W03
	.byte		N06	
	.byte	W06
	.byte		N06	
	.byte	W12
	.byte			Cn1
	.byte	W06
	.byte			Dn1
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte			Cn1
	.byte	W06
	.byte			Dn1
	.byte	W06
song_0018_4_2:
	.byte		N06	, Cn1, v127
	.byte		N24	, Cs2
	.byte	W24
	.byte		N06	, Dn1
	.byte	W24
	.byte			Cn1
	.byte	W24
	.byte			Dn1
	.byte	W24
	.byte	PEND
song_0018_4_1:
	.byte		N06	, Cn1, v127
	.byte	W24
	.byte			Dn1
	.byte	W24
	.byte			Cn1
	.byte	W24
	.byte			Dn1
	.byte	W24
	.byte	PEND
	.byte	PATT	
		.word	song_0018_4_1
song_0018_4_3:
	.byte		N06	, Cn1, v127
	.byte	W24
	.byte			Dn1
	.byte	W24
	.byte			Cn1
	.byte	W24
	.byte			Dn1
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte			Cn1
	.byte	W06
	.byte			Dn1
	.byte	W06
	.byte	PEND
	.byte	PATT	
		.word	song_0018_4_2
	.byte	PATT	
		.word	song_0018_4_1
	.byte	PATT	
		.word	song_0018_4_1
	.byte		N06	, Cn1, v127
	.byte	W24
	.byte			Dn1
	.byte	W12
	.byte			Cn1
	.byte	W06
	.byte		N01	, Cn2
	.byte	W03
	.byte		N01	
	.byte	W03
	.byte		N06	, Cn1
	.byte		N01	, Cn2
	.byte	W06
	.byte		N01	
	.byte	W06
	.byte		N06	, Cn1
	.byte	W06
	.byte		N01	, An1
	.byte	W06
	.byte		N06	, Dn1
	.byte	W06
	.byte		N01	, Fn1
	.byte	W06
	.byte		N06	, Cn1
	.byte	W06
	.byte		N01	, Fn1
	.byte	W06
	.byte		N06	, Cn1
	.byte		N32	, An2
	.byte	W24
	.byte		N06	, Dn1
	.byte	W24
	.byte			Cn1
	.byte	W24
	.byte			Dn1
	.byte	W24
	.byte	PATT	
		.word	song_0018_4_1
	.byte	PATT	
		.word	song_0018_4_1
	.byte	PATT	
		.word	song_0018_4_3
	.byte		N06	, Cn1, v127
	.byte		N30	, Cs2
	.byte	W24
	.byte		N06	, Dn1
	.byte	W24
	.byte			Cn1
	.byte	W24
	.byte			Dn1
	.byte	W24
	.byte	PATT	
		.word	song_0018_4_1
	.byte	PATT	
		.word	song_0018_4_1
	.byte		N06	, Cn1, v127
	.byte	W24
	.byte			Dn1
	.byte	W12
	.byte		N21	, An2
	.byte	W12
	.byte		N06	, Cn1
	.byte	W06
	.byte			Dn1
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
song_0018_4_4:
	.byte		N06	, Dn1, v127
	.byte	W06
	.byte		N06	
	.byte	W12
	.byte		N06	
	.byte	W06
	.byte		N06	
	.byte	W12
	.byte		N06	
	.byte	W06
	.byte		N06	
	.byte	W12
	.byte		N06	
	.byte	W06
	.byte		N06	
	.byte	W12
	.byte		N06	
	.byte	W06
	.byte		N06	
	.byte	W12
	.byte		N06	
	.byte	W06
	.byte	PEND
song_0018_4_5:
	.byte		N06	, Cn1, v127
	.byte		N36	, Cs2
	.byte	W24
	.byte		N06	, Cn1
	.byte	W24
	.byte		N06	
	.byte	W24
	.byte		N06	
	.byte	W24
	.byte	PEND
	.byte	PATT	
		.word	song_0018_4_4
	.byte		N06	, Cn1, v127
	.byte		N30	, Cs2
	.byte	W24
	.byte		N06	, Cn1
	.byte	W24
	.byte		N06	
	.byte	W24
	.byte		N06	
	.byte	W24
	.byte	PATT	
		.word	song_0018_4_4
	.byte	PATT	
		.word	song_0018_4_5
	.byte	PATT	
		.word	song_0018_4_4
	.byte		N06	, Cn1, v127
	.byte		N32	, Cs2
	.byte	W48
	.byte		N23	
	.byte	W06
	.byte		N06	, Dn1
	.byte	W12
	.byte		N06	
	.byte	W06
	.byte		N19	, An2
	.byte	W06
	.byte		N06	, Dn1
	.byte	W06
	.byte		N06	
	.byte	W12
	.byte			Cn1
	.byte		N32	, Cs2
	.byte	W24
	.byte		N06	, Dn1
	.byte	W24
	.byte			Cn1
	.byte	W24
	.byte			Dn1
	.byte	W24
	.byte	PATT	
		.word	song_0018_4_1
	.byte	PATT	
		.word	song_0018_4_1
	.byte	PATT	
		.word	song_0018_4_3
	.byte	GOTO	
		.word	song_0018_4_2
	.byte	FINE

	.align 2
	.global song_0018
song_0018:	@ 0x087D8EF0
	.byte	4		@ trackCount
	.byte	0		@ blockCount
	.byte	10		@ priority
	.byte	168		@ reverb

	.word	voicegroup000		@ voicegroup/tone

	.word	song_0018_1		@ track
	.word	song_0018_2		@ track
	.word	song_0018_3		@ track
	.word	song_0018_4		@ track
