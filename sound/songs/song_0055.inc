	.include "MPlayDef.s"

	.section .rodata

	@********************** Track  1 **********************@

	.align 2
	.global song_0055_1
song_0055_1:	@ 0x087E33CC
	.byte	KEYSH	, 0
	.byte	TEMPO	, 78
	.byte	VOICE	, 12
	.byte	VOL	, v080
	.byte	PAN	, c_v
	.byte	W24
	.byte	W96
	.byte	W96
	.byte		N96	, Cn4, v127
	.byte		N96	, Ds4
	.byte	W96
song_0055_1_1:
	.byte		N96	, As3, v127
	.byte		N96	, Dn4
	.byte	W96
	.byte			Cn4
	.byte		N96	, Ds4
	.byte	W96
	.byte			Dn4
	.byte		N96	, Fn4
	.byte	W96
	.byte			Cn4
	.byte		N96	, Ds4
	.byte	W96
	.byte			As3
	.byte		N96	, Dn4
	.byte	W96
	.byte			Cn4
	.byte		N96	, Ds4
	.byte	W96
	.byte			Dn4
	.byte		N96	, Fn4
	.byte	W96
	.byte			Cn4
	.byte		N96	, Ds4
	.byte	W96
	.byte	GOTO	
		.word	song_0055_1_1
	.byte	FINE

	@********************** Track  2 **********************@

	.global song_0055_2
song_0055_2:	@ 0x087E3407
	.byte	KEYSH	, 0
	.byte	VOICE	, 4
	.byte	VOL	, v075
	.byte	PAN	, c_v
	.byte	W24
	.byte		N16	, Ds4, v127
	.byte	W24
	.byte		N10	
	.byte	W12
	.byte		N12	, Fn4
	.byte	W24
	.byte			Cs4
	.byte	W12
	.byte			Ds4
	.byte	W12
	.byte			Fn4
	.byte	W12
	.byte		N08	, Gn4
	.byte	W12
	.byte		N12	, Dn4
	.byte	W12
	.byte			Cn4
	.byte	W12
	.byte			Gn3
	.byte	W48
	.byte		N12	
	.byte	W12
	.byte		N16	, Cn4
	.byte		N96	, Ds4, v092
	.byte	W96
song_0055_2_1:
	.byte		N96	, Dn4, v092
	.byte	W96
	.byte			Cn4
	.byte	W92
	.byte	W03
	.byte			As3
	.byte	W01
	.byte	W96
	.byte			Ds4
	.byte	W96
	.byte			Dn4
	.byte	W96
	.byte			Ds4
	.byte	W96
	.byte			Fn4
	.byte	W96
	.byte			Ds4
	.byte	W96
	.byte	GOTO	
		.word	song_0055_2_1
	.byte	FINE

	@********************** Track  3 **********************@

	.global song_0055_3
song_0055_3:	@ 0x087E344B
	.byte	KEYSH	, 0
	.byte	VOICE	, 22
	.byte	VOL	, v075
	.byte	PAN	, c_v
	.byte	W24
	.byte		N12	, Gs1, v127
	.byte	W12
	.byte			Gn2
	.byte	W12
	.byte			Gs2
	.byte	W12
	.byte			Fn1
	.byte	W36
	.byte		N24	
	.byte	W24
	.byte		N12	, Gn1
	.byte	W12
	.byte			Fn2
	.byte	W12
	.byte			Gn2
	.byte	W12
	.byte			Gn1
	.byte	W12
	.byte			Fn1
	.byte	W12
	.byte			Gn1
	.byte	W12
	.byte		N01	
	.byte	W12
	.byte		N12	
	.byte	W12
song_0055_3_1:
	.byte		N18	, Cn2, v127
	.byte	W18
	.byte			Gn1
	.byte	W18
	.byte		N12	, As1
	.byte	W12
	.byte		N01	
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte		N12	, Gn1
	.byte	W12
	.byte			As1
	.byte	W12
	.byte			Bn1
	.byte	W12
	.byte	PEND
song_0055_3_2:
	.byte	PATT	
		.word	song_0055_3_1
	.byte	PATT	
		.word	song_0055_3_1
	.byte	PATT	
		.word	song_0055_3_1
	.byte	PATT	
		.word	song_0055_3_1
	.byte	PATT	
		.word	song_0055_3_1
	.byte	PATT	
		.word	song_0055_3_1
	.byte	PATT	
		.word	song_0055_3_1
	.byte	PATT	
		.word	song_0055_3_1
	.byte	GOTO	
		.word	song_0055_3_2
	.byte	FINE

	@********************** Track  4 **********************@

	.global song_0055_4
song_0055_4:	@ 0x087E34B4
	.byte	KEYSH	, 0
	.byte	VOICE	, 0
	.byte	VOL	, v075
	.byte	PAN	, c_v
	.byte	W24
	.byte	W48
	.byte		N06	, Gs4, v127
	.byte	W06
	.byte			As4
	.byte	W06
	.byte			Cn5
	.byte	W06
	.byte			Cs5
	.byte	W06
	.byte			Ds5
	.byte	W06
	.byte			Fn5
	.byte	W06
	.byte			Gn5
	.byte	W06
	.byte			Gs5
	.byte	W06
	.byte		N12	, Gn5
	.byte	W36
	.byte		N12	
	.byte	W48
	.byte		N12	
	.byte	W12
	.byte		N16	, Cn6
	.byte	W96
song_0055_4_1:
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	GOTO	
		.word	song_0055_4_1
	.byte	FINE

	@********************** Track  5 **********************@

	.global song_0055_5
song_0055_5:	@ 0x087E34E8
	.byte	KEYSH	, 0
	.byte	VOICE	, 126
	.byte	VOL	, v075
	.byte	PAN	, c_v
	.byte	W24
	.byte		N06	, Dn1, v127
	.byte	W12
	.byte			Cn2
	.byte	W06
	.byte			An1
	.byte	W06
	.byte			Fn1
	.byte	W12
	.byte			Dn1
	.byte	W12
	.byte			Cn1
	.byte	W12
	.byte		N06	
	.byte	W12
	.byte			Dn1
	.byte	W12
	.byte			Cn1
	.byte	W11
	.byte		N01	, Dn1
	.byte	W01
	.byte		N06	
	.byte	W12
	.byte			Cn1
	.byte	W12
	.byte		N06	
	.byte	W11
	.byte		N01	, Dn1
	.byte	W01
	.byte		N06	
	.byte	W12
	.byte			Cn1
	.byte	W12
	.byte		N06	
	.byte	W12
	.byte			Dn1
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte			Fn1
	.byte	W12
	.byte			Cn1
	.byte		N21	, Cs2
	.byte	W24
	.byte		N06	, Cn1
	.byte	W24
	.byte		N06	
	.byte	W12
	.byte			Dn1
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte		N06	
	.byte	W24
song_0055_5_1:
	.byte		N06	, Cn1, v127
	.byte	W24
	.byte		N06	
	.byte	W24
	.byte		N06	
	.byte	W12
	.byte			Dn1
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte		N06	
	.byte	W24
	.byte	PEND
	.byte	PATT	
		.word	song_0055_5_1
song_0055_5_2:
	.byte		N06	, Cn1, v127
	.byte	W24
	.byte		N06	
	.byte	W18
	.byte			Dn1
	.byte	W06
	.byte			Cn1
	.byte	W06
	.byte			Dn1
	.byte	W12
	.byte		N06	
	.byte	W06
	.byte			Cn1
	.byte	W06
	.byte			Dn1
	.byte	W06
	.byte		N06	
	.byte	W12
	.byte	PEND
	.byte			Cn1
	.byte		N23	, Gn2
	.byte	W24
	.byte		N06	, Cn1
	.byte	W24
	.byte		N06	
	.byte	W12
	.byte			Dn1
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte		N06	
	.byte	W24
	.byte	PATT	
		.word	song_0055_5_1
	.byte	PATT	
		.word	song_0055_5_1
	.byte	PATT	
		.word	song_0055_5_2
	.byte		N06	, Cn1, v127
	.byte		N22	, Cs2
	.byte	W24
	.byte		N06	, Cn1
	.byte	W24
	.byte		N06	
	.byte	W12
	.byte			Dn1
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte		N06	
	.byte	W24
	.byte	GOTO	
		.word	song_0055_5_1
	.byte	FINE

	.align 2
	.global song_0055
song_0055:	@ 0x087E358C
	.byte	5		@ trackCount
	.byte	0		@ blockCount
	.byte	10		@ priority
	.byte	168		@ reverb

	.word	voicegroup000		@ voicegroup/tone

	.word	song_0055_1		@ track
	.word	song_0055_2		@ track
	.word	song_0055_3		@ track
	.word	song_0055_4		@ track
	.word	song_0055_5		@ track
