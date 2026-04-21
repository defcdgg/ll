	.include "MPlayDef.s"

	.section .rodata

	@********************** Track  1 **********************@

	.align 2
	.global song_0041_1
song_0041_1:	@ 0x087DF164
	.byte	KEYSH	, 0
	.byte	TEMPO	, 125
	.byte	VOICE	, 5
	.byte	VOL	, v103
	.byte	PAN	, c_v
	.byte	W24
song_0041_1_1:
	.byte	TEMPO	, 49
	.byte	W96
	.byte		N96	, Bn2, v127
	.byte		N96	, Cs3
	.byte	W96
	.byte		N16	, Bn2
	.byte		N16	, En3
	.byte	W96
	.byte		N96	, Bn2
	.byte		N96	, Cs3
	.byte	W96
	.byte		N12	, Bn2
	.byte		N12	, En3
	.byte	W96
	.byte	W96
	.byte	W96
	.byte		N96	, Bn2
	.byte		N96	, Cs3
	.byte	W96
	.byte		N12	, Bn2
	.byte		N12	, En3
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W48
	.byte		N16	, Bn3
	.byte	W24
	.byte		N16	
	.byte	W24
	.byte	GOTO	
		.word	song_0041_1_1
	.byte	FINE

	@********************** Track  2 **********************@

	.global song_0041_2
song_0041_2:	@ 0x087DF1A6
	.byte	KEYSH	, 0
	.byte	VOICE	, 0
	.byte	VOL	, v110
	.byte	PAN	, c_v
	.byte	W24
song_0041_2_2:
	.byte		N07	, En4, v127
	.byte	W07
	.byte		N04	, Fs4
	.byte	W05
	.byte			En4
	.byte	W04
	.byte			Fs4
	.byte	W04
	.byte			En4
	.byte	W04
	.byte			Fs4
	.byte	W03
	.byte			En4
	.byte	W02
	.byte			Fs4
	.byte	W03
	.byte			En4
	.byte	W02
	.byte			Fs4
	.byte	W03
	.byte			En4
	.byte	W03
	.byte			Fs4
	.byte	W04
	.byte			En4
	.byte	W04
	.byte			Fs4
	.byte	W03
	.byte			En4
	.byte	W04
	.byte			Fs4
	.byte	W06
	.byte			En4
	.byte	W03
	.byte			Fs4
	.byte	W04
	.byte			En4
	.byte	W04
	.byte			Fs4
	.byte	W03
	.byte			En4
	.byte	W04
	.byte			Fs4
	.byte	W06
	.byte			En4
	.byte	W02
	.byte		N01	, Fs4
	.byte	W01
	.byte		N04	
	.byte	W04
	.byte			En4
	.byte	W04
	.byte	W72
	.byte		N06	, An5
	.byte	W12
	.byte			Gn5
	.byte	W12
	.byte		N08	, En5
	.byte	W96
	.byte		N07	, En4
	.byte	W07
	.byte		N04	, Fs4
	.byte	W05
	.byte			En4
	.byte	W04
	.byte			Fs4
	.byte	W04
	.byte			En4
	.byte	W04
	.byte			Fs4
	.byte	W03
	.byte			En4
	.byte	W04
	.byte			Fs4
	.byte	W06
	.byte			En4
	.byte	W03
	.byte			Fs4
	.byte	W04
	.byte			En4
	.byte	W04
	.byte			Fs4
	.byte	W03
	.byte			En4
	.byte	W04
	.byte			Fs4
	.byte	W06
	.byte			En4
	.byte	W03
	.byte			Fs4
	.byte	W04
	.byte			En4
	.byte	W04
	.byte			Fs4
	.byte	W03
	.byte			En4
	.byte	W04
	.byte			Fs4
	.byte	W06
	.byte			En4
	.byte	W03
	.byte			Fs4
	.byte	W04
	.byte			En4
	.byte	W04
	.byte	W96
	.byte	W96
	.byte		N07	
	.byte	W07
	.byte		N04	, Fs4
	.byte	W05
	.byte			En4
	.byte	W04
	.byte			Fs4
	.byte	W04
	.byte			En4
	.byte	W04
	.byte			Fs4
	.byte	W03
	.byte			En4
	.byte	W04
	.byte			Fs4
	.byte	W01
	.byte			En4
	.byte	W05
	.byte		N04	
	.byte	W03
	.byte			Fs4
	.byte	W04
	.byte			En4
	.byte	W04
	.byte			Fs4
	.byte	W03
	.byte			En4
	.byte	W04
	.byte			Fs4
	.byte	W01
	.byte			En4
	.byte	W05
	.byte		N04	
	.byte	W03
	.byte			Fs4
	.byte	W04
	.byte			En4
	.byte	W04
	.byte			Fs4
	.byte	W03
	.byte			En4
	.byte	W04
	.byte			Fs4
	.byte	W01
	.byte			En4
	.byte	W05
	.byte		N04	
	.byte	W03
	.byte			Fs4
	.byte	W04
	.byte			En4
	.byte	W04
	.byte	W96
	.byte	W96
	.byte		N05	, En3
	.byte	W06
	.byte		N05	
	.byte	W06
	.byte			Ds3
	.byte	W06
	.byte		N05	
	.byte	W06
	.byte			Fn3
	.byte	W06
	.byte		N05	
	.byte	W06
	.byte			En3
	.byte	W06
	.byte		N05	
	.byte	W06
	.byte			Gn3
	.byte	W06
	.byte		N05	
	.byte	W06
	.byte			Fs3
	.byte	W06
	.byte		N05	
	.byte	W06
	.byte			An3
	.byte	W06
	.byte		N05	
	.byte	W06
	.byte			Gn3
	.byte	W06
	.byte		N05	
	.byte	W06
	.byte		N11	, En3
	.byte	W96
	.byte		N05	, Bn3
	.byte	W06
	.byte		N05	
	.byte	W06
	.byte			As3
	.byte	W06
	.byte		N05	
	.byte	W06
	.byte			Cn4
	.byte	W06
	.byte		N05	
	.byte	W06
	.byte			Bn3
	.byte	W06
	.byte		N05	
	.byte	W06
	.byte			Dn4
	.byte	W06
	.byte		N05	
	.byte	W06
	.byte			Cs4
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
	.byte		N11	, Bn3
	.byte	W96
song_0041_2_1:
	.byte		N05	, En4, v127
	.byte	W06
	.byte		N05	
	.byte	W06
	.byte			Ds4
	.byte	W06
	.byte		N05	
	.byte	W06
	.byte			Fn4
	.byte	W06
	.byte		N05	
	.byte	W06
	.byte			En4
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
	.byte			An4
	.byte	W06
	.byte		N05	
	.byte	W06
	.byte			Gn4
	.byte	W06
	.byte		N05	
	.byte	W06
	.byte	PEND
	.byte	PATT	
		.word	song_0041_2_1
	.byte	PATT	
		.word	song_0041_2_1
	.byte		N05	, En4, v127
	.byte	W06
	.byte		N05	
	.byte	W06
	.byte			Ds4
	.byte	W06
	.byte		N05	
	.byte	W06
	.byte			Fn4
	.byte	W06
	.byte		N05	
	.byte	W06
	.byte			En4
	.byte	W06
	.byte		N05	
	.byte	W06
	.byte			Gn5
	.byte	W06
	.byte		N05	
	.byte	W06
	.byte			Fs5
	.byte	W06
	.byte		N05	
	.byte	W06
	.byte			An5
	.byte	W06
	.byte		N05	
	.byte	W06
	.byte			Gn5
	.byte	W06
	.byte		N05	
	.byte	W06
	.byte	GOTO	
		.word	song_0041_2_2
	.byte	FINE

	@********************** Track  3 **********************@

	.global song_0041_3
song_0041_3:	@ 0x087DF2F6
	.byte	KEYSH	, 0
	.byte	VOICE	, 22
	.byte	VOL	, v103
	.byte	PAN	, c_v
	.byte	W24
song_0041_3_1:
	.byte		N05	, En1, v127
	.byte	W12
	.byte			Ds1
	.byte	W12
	.byte			Fn1
	.byte	W12
	.byte			En1
	.byte	W12
	.byte			Gn1
	.byte	W12
	.byte			Fs1
	.byte	W12
	.byte			An1
	.byte	W12
	.byte			Gn1
	.byte	W12
	.byte	PEND
	.byte	PATT	
		.word	song_0041_3_1
	.byte	PATT	
		.word	song_0041_3_1
	.byte	PATT	
		.word	song_0041_3_1
	.byte	PATT	
		.word	song_0041_3_1
	.byte	PATT	
		.word	song_0041_3_1
	.byte	PATT	
		.word	song_0041_3_1
	.byte	PATT	
		.word	song_0041_3_1
	.byte	PATT	
		.word	song_0041_3_1
	.byte	PATT	
		.word	song_0041_3_1
	.byte	PATT	
		.word	song_0041_3_1
	.byte	PATT	
		.word	song_0041_3_1
	.byte	PATT	
		.word	song_0041_3_1
	.byte	PATT	
		.word	song_0041_3_1
	.byte	PATT	
		.word	song_0041_3_1
	.byte	PATT	
		.word	song_0041_3_1
	.byte		N05	, En1, v127
	.byte	W12
	.byte			Ds1
	.byte	W12
	.byte			Fn1
	.byte	W24
	.byte		N16	, Bn1
	.byte	W24
	.byte		N16	
	.byte	W24
	.byte	GOTO	
		.word	song_0041_3_1
	.byte	FINE

	@********************** Track  4 **********************@

	.global song_0041_4
song_0041_4:	@ 0x087DF370
	.byte	KEYSH	, 0
	.byte	VOICE	, 126
	.byte	VOL	, v103
	.byte	PAN	, c_v
	.byte	W24
song_0041_4_4:
	.byte	W96
	.byte	W96
song_0041_4_1:
	.byte		N06	, En4, v127
	.byte	W12
	.byte		N24	, Bn3
	.byte	W36
	.byte		N06	
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte		N24	
	.byte	W36
	.byte	PEND
	.byte	W96
song_0041_4_2:
	.byte	W12
	.byte		N24	, Bn3, v127
	.byte	W36
	.byte		N06	
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte		N24	
	.byte	W36
	.byte	PEND
	.byte	W96
	.byte	PATT	
		.word	song_0041_4_1
	.byte	W96
	.byte	PATT	
		.word	song_0041_4_2
	.byte	W96
	.byte	PATT	
		.word	song_0041_4_1
	.byte	W96
	.byte	PATT	
		.word	song_0041_4_2
	.byte		N24	, Bn3, v127
	.byte	W96
	.byte		N24	
	.byte	W96
song_0041_4_3:
	.byte		N24	, Bn3, v127
	.byte	W24
	.byte		N24	
	.byte	W24
	.byte		N24	
	.byte	W24
	.byte		N24	
	.byte	W24
	.byte	PEND
	.byte	PATT	
		.word	song_0041_4_3
	.byte	GOTO	
		.word	song_0041_4_4
	.byte	FINE

	.align 2
	.global song_0041
song_0041:	@ 0x087DF3CC
	.byte	4		@ trackCount
	.byte	0		@ blockCount
	.byte	10		@ priority
	.byte	168		@ reverb

	.word	voicegroup000		@ voicegroup/tone

	.word	song_0041_1		@ track
	.word	song_0041_2		@ track
	.word	song_0041_3		@ track
	.word	song_0041_4		@ track
