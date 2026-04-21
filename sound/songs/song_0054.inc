	.include "MPlayDef.s"

	.section .rodata

	@********************** Track  1 **********************@

	.align 2
	.global song_0054_1
song_0054_1:	@ 0x087E3180
	.byte	KEYSH	, 0
	.byte	TEMPO	, 125
	.byte	VOICE	, 5
	.byte	VOL	, v075
	.byte	PAN	, c_v
	.byte	W24
	.byte	TEMPO	, 77
	.byte	W24
	.byte		N18	, Cs4, v127
	.byte	W18
	.byte		N04	, Bn3
	.byte	W06
	.byte		N06	, An3
	.byte	W12
	.byte		N18	, Fs3
	.byte		N18	, Fs4
	.byte	W18
	.byte		N04	, En4
	.byte	W06
	.byte		N06	, Dn4
	.byte	W12
	.byte			Gs4
	.byte	W12
	.byte		TIE	
	.byte	W12
	.byte	W96
	.byte		EOT	
song_0054_1_1:
	.byte		N12	, En3, v080
	.byte	W12
	.byte		N02	
	.byte	W06
	.byte		N02	
	.byte	W06
	.byte		N06	
	.byte	W12
	.byte		N23	
	.byte	W24
	.byte		N11	
	.byte	W12
	.byte		N11	
	.byte	W12
	.byte		N11	
	.byte	W12
	.byte	PEND
song_0054_1_2:
	.byte		N12	, Ds3, v080
	.byte	W12
	.byte		N02	
	.byte	W06
	.byte		N02	
	.byte	W06
	.byte		N06	
	.byte	W12
	.byte		N23	
	.byte	W24
	.byte		N11	
	.byte	W12
	.byte		N11	
	.byte	W12
	.byte		N11	
	.byte	W12
	.byte	PEND
song_0054_1_3:
	.byte		N12	, Dn3, v080
	.byte	W12
	.byte		N02	
	.byte	W06
	.byte		N02	
	.byte	W06
	.byte		N06	
	.byte	W12
	.byte		N23	
	.byte	W24
	.byte		N11	
	.byte	W12
	.byte		N11	
	.byte	W12
	.byte		N11	
	.byte	W12
	.byte	PEND
song_0054_1_4:
	.byte		N12	, Cs3, v080
	.byte	W12
	.byte		N02	
	.byte	W06
	.byte		N02	
	.byte	W06
	.byte		N06	
	.byte	W12
	.byte		N23	
	.byte	W24
	.byte		N11	
	.byte	W12
	.byte		N11	
	.byte	W12
	.byte		N11	
	.byte	W12
	.byte	PEND
	.byte	PATT	
		.word	song_0054_1_1
	.byte	PATT	
		.word	song_0054_1_2
	.byte	PATT	
		.word	song_0054_1_3
	.byte	PATT	
		.word	song_0054_1_4
	.byte	GOTO	
		.word	song_0054_1_1
	.byte	FINE

	@********************** Track  2 **********************@

	.global song_0054_2
song_0054_2:	@ 0x087E320F
	.byte	KEYSH	, 0
	.byte	VOICE	, 4
	.byte	VOL	, v069
	.byte	PAN	, c_v
	.byte	W24
	.byte	W24
	.byte	W96
	.byte	W96
song_0054_2_1:
	.byte		N12	, En3, v127
	.byte	W12
	.byte		N02	
	.byte	W06
	.byte		N02	
	.byte	W06
	.byte		N06	
	.byte	W12
	.byte		N23	
	.byte	W24
	.byte		N11	
	.byte	W12
	.byte		N11	
	.byte	W12
	.byte		N11	
	.byte	W12
	.byte	PEND
song_0054_2_2:
	.byte		N12	, Ds3, v127
	.byte	W12
	.byte		N02	
	.byte	W06
	.byte		N02	
	.byte	W06
	.byte		N06	
	.byte	W12
	.byte		N23	
	.byte	W24
	.byte		N11	
	.byte	W12
	.byte		N11	
	.byte	W12
	.byte		N11	
	.byte	W12
	.byte	PEND
song_0054_2_3:
	.byte		N12	, Dn3, v127
	.byte	W12
	.byte		N02	
	.byte	W06
	.byte		N02	
	.byte	W06
	.byte		N06	
	.byte	W12
	.byte		N23	
	.byte	W24
	.byte		N11	
	.byte	W12
	.byte		N11	
	.byte	W12
	.byte		N11	
	.byte	W12
	.byte	PEND
song_0054_2_4:
	.byte		N12	, Cs3, v127
	.byte	W12
	.byte		N02	
	.byte	W06
	.byte		N02	
	.byte	W06
	.byte		N06	
	.byte	W12
	.byte		N23	
	.byte	W24
	.byte		N11	
	.byte	W12
	.byte		N11	
	.byte	W12
	.byte		N11	
	.byte	W12
	.byte	PEND
	.byte	PATT	
		.word	song_0054_2_1
	.byte	PATT	
		.word	song_0054_2_2
	.byte	PATT	
		.word	song_0054_2_3
	.byte	PATT	
		.word	song_0054_2_4
	.byte	GOTO	
		.word	song_0054_2_1
	.byte	FINE

	@********************** Track  3 **********************@

	.global song_0054_3
song_0054_3:	@ 0x087E3281
	.byte	KEYSH	, 0
	.byte	VOICE	, 18
	.byte	VOL	, v080
	.byte	PAN	, c_v
	.byte	BEND	, c_v
	.byte	W24
	.byte	W24
	.byte		N36	, An1, v127
	.byte	W36
	.byte			Dn2
	.byte	W36
	.byte		N12	, En2
	.byte	W12
	.byte		N30	
	.byte	W12
	.byte	W18
	.byte		N06	
	.byte	W06
	.byte		N12	
	.byte	W12
	.byte		N24	
	.byte	W24
	.byte		N12	
	.byte	W12
	.byte			En3
	.byte	W12
	.byte			En2
	.byte	W12
song_0054_3_1:
	.byte		N18	, An1, v127
	.byte	W18
	.byte		N06	
	.byte	W06
	.byte		N12	
	.byte	W12
	.byte		N24	
	.byte	W24
	.byte		N12	
	.byte	W12
	.byte		N24	
	.byte	W24
	.byte	PEND
	.byte	PATT	
		.word	song_0054_3_1
	.byte	PATT	
		.word	song_0054_3_1
song_0054_3_2:
	.byte		N18	, An1, v127
	.byte	W18
	.byte		N06	
	.byte	W06
	.byte		N12	
	.byte	W12
	.byte		N18	
	.byte	W18
	.byte		N06	, An2
	.byte	W06
	.byte		N12	, An1
	.byte	W12
	.byte	BEND	, c_v
	.byte		N12	, Gn2
	.byte	W04
	.byte	BEND	, c_v+3
	.byte	W01
	.byte		c_v+15
	.byte	W01
	.byte		c_v+63
	.byte	W06
	.byte		c_v
	.byte		N12	, An1
	.byte	W12
	.byte	PEND
	.byte	PATT	
		.word	song_0054_3_1
	.byte	PATT	
		.word	song_0054_3_1
	.byte	PATT	
		.word	song_0054_3_1
	.byte	PATT	
		.word	song_0054_3_2
	.byte	GOTO	
		.word	song_0054_3_1
	.byte	FINE

	@********************** Track  4 **********************@

	.global song_0054_4
song_0054_4:	@ 0x087E32F9
	.byte	KEYSH	, 0
	.byte	VOICE	, 0
	.byte	VOL	, v075
	.byte	PAN	, c_v
	.byte	W24
	.byte		N03	, En3, v100
	.byte	W03
	.byte			Fs3
	.byte	W03
	.byte			Gn3
	.byte	W03
	.byte			An3
	.byte	W03
	.byte			Bn3
	.byte	W03
	.byte			Cs4
	.byte	W03
	.byte			Dn4
	.byte	W03
	.byte			En4
	.byte	W03
	.byte		N36	, En4, v127
	.byte	W36
	.byte			Dn4
	.byte	W36
	.byte		N06	, En4
	.byte	W12
	.byte		TIE	
	.byte	W12
	.byte	W96
	.byte		EOT	
song_0054_4_1:
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	GOTO	
		.word	song_0054_4_1
	.byte	FINE

	@********************** Track  5 **********************@

	.global song_0054_5
song_0054_5:	@ 0x087E332F
	.byte	KEYSH	, 0
	.byte	VOICE	, 126
	.byte	VOL	, v062
	.byte	PAN	, c_v
	.byte	W24
	.byte	W24
	.byte		N06	, Dn1, v127
	.byte		N30	, Cs2
	.byte	W36
	.byte		N06	, Dn1
	.byte		N32	, An2
	.byte	W36
	.byte		N06	, Dn1
	.byte	W12
	.byte		N06	
	.byte		N28	, Cs2
	.byte	W12
	.byte		N06	, Cn1
	.byte	W18
	.byte			Dn1
	.byte	W06
	.byte		N06	
	.byte	W12
	.byte		N06	
	.byte	W12
	.byte			Cn1
	.byte	W12
	.byte			Dn1
	.byte	W12
	.byte		N06	
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte		N06	
	.byte	W12
song_0054_5_3:
	.byte		N06	, Cn1, v127
	.byte		N17	, Cs2
	.byte	W18
	.byte		N06	, Dn1
	.byte	W06
	.byte		N06	
	.byte	W12
	.byte			Cn1
	.byte	W24
	.byte		N06	
	.byte	W12
	.byte			Dn1
	.byte	W24
song_0054_5_1:
	.byte		N06	, Cn1, v127
	.byte	W18
	.byte			Dn1
	.byte	W06
	.byte		N06	
	.byte	W12
	.byte			Cn1
	.byte	W24
	.byte		N06	
	.byte	W12
	.byte			Dn1
	.byte	W24
	.byte	PEND
	.byte	PATT	
		.word	song_0054_5_1
song_0054_5_2:
	.byte		N06	, Cn1, v127
	.byte	W18
	.byte			Dn1
	.byte	W06
	.byte		N06	
	.byte	W12
	.byte			Cn1
	.byte	W24
	.byte		N06	
	.byte	W12
	.byte			Dn1
	.byte	W06
	.byte		N06	
	.byte	W18
	.byte	PEND
	.byte	PATT	
		.word	song_0054_5_1
	.byte	PATT	
		.word	song_0054_5_1
	.byte	PATT	
		.word	song_0054_5_1
	.byte	PATT	
		.word	song_0054_5_2
	.byte	GOTO	
		.word	song_0054_5_3
	.byte	FINE

	.align 2
	.global song_0054
song_0054:	@ 0x087E33B0
	.byte	5		@ trackCount
	.byte	0		@ blockCount
	.byte	10		@ priority
	.byte	168		@ reverb

	.word	voicegroup000		@ voicegroup/tone

	.word	song_0054_1		@ track
	.word	song_0054_2		@ track
	.word	song_0054_3		@ track
	.word	song_0054_4		@ track
	.word	song_0054_5		@ track
