	.include "MPlayDef.s"

	.section .rodata

	@********************** Track  1 **********************@

	.align 2
	.global song_0039_1
song_0039_1:	@ 0x087DEC1C
	.byte	KEYSH	, 0
	.byte	TEMPO	, 65
	.byte	VOICE	, 4
	.byte	VOL	, v085
	.byte	PAN	, c_v
	.byte	W24
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W72
	.byte	VOICE	, 2
	.byte	W24
song_0039_1_1:
	.byte		N22	, Cn4, v127
	.byte	W24
	.byte		N04	
	.byte	W12
	.byte		N04	
	.byte	W12
	.byte		N16	
	.byte	W19
	.byte		N02	
	.byte	W05
	.byte		N04	
	.byte	W12
	.byte		N04	
	.byte	W12
	.byte	PEND
song_0039_1_2:
	.byte		N16	, Cn4, v127
	.byte	W19
	.byte		N02	
	.byte	W05
	.byte		N04	
	.byte	W12
	.byte		N04	
	.byte	W06
	.byte		N03	, Dn4
	.byte	W03
	.byte			Cn4
	.byte	W03
	.byte		N12	, Bn3
	.byte	W12
	.byte			Cn4
	.byte	W12
	.byte			Dn4
	.byte	W12
	.byte			En4
	.byte	W12
	.byte	PEND
song_0039_1_3:
	.byte		N22	, Cn4, v127
	.byte	W24
	.byte		N04	
	.byte	W12
	.byte		N04	
	.byte	W12
	.byte		N16	
	.byte	W18
	.byte		N02	
	.byte	W06
	.byte		N04	
	.byte	W12
	.byte		N04	
	.byte	W12
	.byte	PEND
song_0039_1_4:
	.byte		N16	, Cn4, v127
	.byte	W19
	.byte		N02	
	.byte	W05
	.byte		N04	
	.byte	W12
	.byte		N06	, Dn4
	.byte	W06
	.byte			En4
	.byte	W06
	.byte		N12	, Fn4
	.byte	W12
	.byte		N06	, En4
	.byte	W06
	.byte		N03	, Fn4
	.byte	W03
	.byte			En4
	.byte	W03
	.byte		N12	, Dn4
	.byte	W24
	.byte	PEND
song_0039_1_5:
	.byte		N08	, Gn4, v127
	.byte	W19
	.byte		N02	, Cn4
	.byte	W05
	.byte		N04	
	.byte	W12
	.byte		N04	
	.byte	W12
	.byte		N04	
	.byte	W12
	.byte		N04	
	.byte	W12
	.byte		N24	
	.byte	W24
	.byte	PEND
song_0039_1_6:
	.byte		N16	, Dn4, v127
	.byte	W19
	.byte		N02	, En4
	.byte	W05
	.byte		N04	, Fn4
	.byte	W12
	.byte			En4
	.byte	W06
	.byte		N03	, Fn4
	.byte	W03
	.byte			En4
	.byte	W03
	.byte		N12	, Dn4
	.byte	W12
	.byte			En4
	.byte	W12
	.byte			Fn4
	.byte	W12
	.byte			Dn4
	.byte	W12
	.byte	PEND
song_0039_1_7:
	.byte		N10	, Gn4, v127
	.byte	W19
	.byte		N02	, Cn4
	.byte	W05
	.byte		N04	
	.byte	W12
	.byte		N04	
	.byte	W12
	.byte		N04	
	.byte	W12
	.byte		N04	
	.byte	W12
	.byte		N24	
	.byte	W24
	.byte	PEND
	.byte		N12	, An3
	.byte	W12
	.byte		N06	, Bn3
	.byte	W06
	.byte			Cn4
	.byte	W06
	.byte			Dn4
	.byte	W06
	.byte			En4
	.byte	W06
	.byte			Fn4
	.byte	W06
	.byte			En4
	.byte	W06
	.byte			Fn4
	.byte	W06
	.byte			En4
	.byte	W06
	.byte			Fn4
	.byte	W06
	.byte			En4
	.byte	W06
	.byte		N04	, Dn4
	.byte	W12
	.byte			Gn4
	.byte	W06
	.byte	VOICE	, 5
	.byte	W06
song_0039_1_8:
	.byte	PATT	
		.word	song_0039_1_1
	.byte	PATT	
		.word	song_0039_1_2
	.byte	PATT	
		.word	song_0039_1_3
	.byte	PATT	
		.word	song_0039_1_4
	.byte	PATT	
		.word	song_0039_1_5
	.byte	PATT	
		.word	song_0039_1_6
	.byte	PATT	
		.word	song_0039_1_7
	.byte		N12	, An3, v127
	.byte	W12
	.byte		N06	, Bn3
	.byte	W06
	.byte			Cn4
	.byte	W06
	.byte			Dn4
	.byte	W06
	.byte			En4
	.byte	W06
	.byte			Fn4
	.byte	W06
	.byte			En4
	.byte	W06
	.byte			Fn4
	.byte	W06
	.byte			En4
	.byte	W06
	.byte			Fn4
	.byte	W06
	.byte			En4
	.byte	W06
	.byte		N04	, Dn4
	.byte	W12
	.byte			Gn4
	.byte	W06
	.byte	VOICE	, 4
	.byte	W06
	.byte		N24	, As3
	.byte	W24
	.byte		N04	
	.byte	W12
	.byte		N04	
	.byte	W12
	.byte			Ds4
	.byte	W12
	.byte		N04	
	.byte	W12
	.byte		N04	
	.byte	W12
	.byte			Ds3
	.byte	W12
	.byte		N18	, Fn3
	.byte	W19
	.byte		N06	, Gn3
	.byte	W05
	.byte		N04	, Gs3
	.byte	W12
	.byte			As3
	.byte	W12
	.byte			Gs3
	.byte	W12
	.byte			Gn3
	.byte	W04
	.byte			Gs3
	.byte	W04
	.byte			Gn3
	.byte	W04
	.byte			Fn3
	.byte	W12
	.byte		N12	, As2
	.byte	W12
	.byte		N04	, Ds3
	.byte	W12
	.byte			Fn3
	.byte	W12
	.byte			Gn3
	.byte	W12
	.byte			Gs3
	.byte	W12
	.byte		N12	, As3
	.byte	W12
	.byte		N04	, Ds3
	.byte	W12
	.byte			Ds4
	.byte	W12
	.byte			As4
	.byte	W12
	.byte			Gs4
	.byte	W12
	.byte			Gn4
	.byte	W04
	.byte			Gs4
	.byte	W04
	.byte			Gn4
	.byte	W04
	.byte			Fn4
	.byte	W12
	.byte			Gs4
	.byte	W12
	.byte			As4
	.byte	W12
	.byte			As3
	.byte	W12
	.byte			As4
	.byte	W12
	.byte			As3
	.byte	W12
	.byte			As4
	.byte	W12
	.byte			As3
	.byte	W12
	.byte			As4
	.byte	W12
	.byte			As3
	.byte	W12
	.byte		N06	, An4
	.byte	W06
	.byte			Fn4
	.byte	W06
	.byte		N04	, An4
	.byte	W12
	.byte			Fn4
	.byte	W12
	.byte			An4
	.byte	W12
	.byte			Gs4
	.byte	W12
	.byte			Fn4
	.byte	W12
	.byte			Gs4
	.byte	W12
	.byte			Fn4
	.byte	W12
	.byte			Ds4
	.byte	W12
	.byte			Dn4
	.byte	W04
	.byte			Ds4
	.byte	W04
	.byte			Dn4
	.byte	W04
	.byte			Cn4
	.byte	W12
	.byte			Dn4
	.byte	W12
	.byte		N12	, Ds2
	.byte	W12
	.byte		N06	, Fn2
	.byte	W06
	.byte			Gn2
	.byte	W06
	.byte			Gs2
	.byte	W06
	.byte			As2
	.byte	W06
	.byte			Cn3
	.byte	W06
	.byte			Dn3
	.byte	W06
	.byte		N04	, Ds3
	.byte	W12
	.byte			Fs3
	.byte	W12
	.byte			An3
	.byte	W12
	.byte			Dn4
	.byte	W12
	.byte		N06	, Cn4
	.byte	W06
	.byte			Dn4
	.byte	W06
	.byte			Ds4
	.byte	W06
	.byte			Fn4
	.byte	W06
	.byte		N04	, Ds4
	.byte	W12
	.byte			Fn4
	.byte	W12
	.byte		N16	, Gn4
	.byte	W24
	.byte			Fn4
	.byte	W12
	.byte		N06	, Gn5
	.byte	W06
	.byte		N03	, An5
	.byte	W03
	.byte			Bn5
	.byte	W03
	.byte		N16	, Cn6
	.byte	W96
	.byte	W96
	.byte	GOTO	
		.word	song_0039_1_8
	.byte	FINE

	@********************** Track  2 **********************@

	.global song_0039_2
song_0039_2:	@ 0x087DEDDC
	.byte	KEYSH	, 0
	.byte	VOICE	, 19
	.byte	VOL	, v085
	.byte	PAN	, c_v
	.byte	W12
	.byte		N12	, Gn1, v127
	.byte	W12
song_0039_2_1:
	.byte		N08	, Cn2, v127
	.byte	W12
	.byte		N06	, En3
	.byte		N06	, Gn3
	.byte	W12
	.byte		N08	, Cn2
	.byte	W12
	.byte		N06	, En3
	.byte		N06	, Gn3
	.byte	W12
	.byte		N08	, Cn2
	.byte	W12
	.byte		N06	, Ds3
	.byte		N06	, Fs3
	.byte	W12
	.byte		N08	, Cn2
	.byte	W12
	.byte		N06	, Ds3
	.byte		N06	, Fs3
	.byte	W12
	.byte	PEND
song_0039_2_2:
	.byte		N08	, Cn2, v127
	.byte	W12
	.byte		N06	, Dn3
	.byte		N06	, Fn3
	.byte	W12
	.byte		N08	, Cn2
	.byte	W12
	.byte		N06	, Dn3
	.byte		N06	, Fn3
	.byte	W12
	.byte		N08	, Gn1
	.byte	W12
	.byte		N06	, Cn3
	.byte		N06	, Dn3
	.byte	W12
	.byte		N08	, Gn2
	.byte	W12
	.byte		N06	, Dn3
	.byte		N06	, Gn3
	.byte	W12
	.byte	PEND
	.byte	PATT	
		.word	song_0039_2_1
	.byte	PATT	
		.word	song_0039_2_2
	.byte	PATT	
		.word	song_0039_2_1
	.byte	PATT	
		.word	song_0039_2_2
	.byte	PATT	
		.word	song_0039_2_1
	.byte	PATT	
		.word	song_0039_2_2
	.byte	PATT	
		.word	song_0039_2_1
	.byte		N08	, Cn2, v127
	.byte	W12
	.byte		N06	, Cn3
	.byte		N06	, Dn3
	.byte		N06	, Fn3
	.byte	W12
	.byte		N08	, Cn2
	.byte	W12
	.byte		N06	, Cn3
	.byte		N06	, Dn3
	.byte		N06	, Fn3
	.byte	W12
	.byte		N08	, Gn1
	.byte	W12
	.byte		N06	, Cn3
	.byte		N06	, Dn3
	.byte	W12
	.byte		N08	, Gn2
	.byte	W12
	.byte		N06	, Dn3
	.byte		N06	, Gn3
	.byte	W12
	.byte	PATT	
		.word	song_0039_2_1
	.byte	PATT	
		.word	song_0039_2_2
song_0039_2_5:
	.byte	PATT	
		.word	song_0039_2_1
	.byte	PATT	
		.word	song_0039_2_2
	.byte	PATT	
		.word	song_0039_2_1
	.byte	PATT	
		.word	song_0039_2_2
	.byte	PATT	
		.word	song_0039_2_1
	.byte	PATT	
		.word	song_0039_2_2
	.byte	PATT	
		.word	song_0039_2_1
	.byte	PATT	
		.word	song_0039_2_2
song_0039_2_3:
	.byte		N12	, Ds1, v127
	.byte	W12
	.byte		N06	, Gn3
	.byte		N06	, As3
	.byte	W12
	.byte		N12	, Ds1
	.byte	W12
	.byte		N06	, Gn3
	.byte		N06	, As3
	.byte	W12
	.byte		N12	, Ds1
	.byte	W12
	.byte		N06	, Fs3
	.byte		N06	, An3
	.byte	W12
	.byte		N12	, Ds1
	.byte	W12
	.byte		N06	, Fs3
	.byte		N06	, An3
	.byte	W12
	.byte	PEND
song_0039_2_4:
	.byte		N12	, Ds1, v127
	.byte	W12
	.byte		N06	, Fn3
	.byte		N06	, Gs3
	.byte	W12
	.byte		N12	, Ds1
	.byte	W12
	.byte		N06	, Fn3
	.byte		N06	, Gs3
	.byte	W12
	.byte		N12	, As1
	.byte	W12
	.byte		N06	, Ds3
	.byte		N06	, Fn3
	.byte	W12
	.byte		N12	, As1
	.byte	W12
	.byte		N06	, Fn3
	.byte		N06	, As3
	.byte	W12
	.byte	PEND
	.byte	PATT	
		.word	song_0039_2_3
	.byte	PATT	
		.word	song_0039_2_4
	.byte	PATT	
		.word	song_0039_2_3
	.byte	PATT	
		.word	song_0039_2_4
	.byte	PATT	
		.word	song_0039_2_3
	.byte	PATT	
		.word	song_0039_2_4
	.byte	PATT	
		.word	song_0039_2_1
	.byte	PATT	
		.word	song_0039_2_2
	.byte	GOTO	
		.word	song_0039_2_5
	.byte	FINE

	@********************** Track  3 **********************@

	.global song_0039_3
song_0039_3:	@ 0x087DEF19
	.byte	KEYSH	, 0
	.byte	VOICE	, 126
	.byte	VOL	, v085
	.byte	PAN	, c_v
	.byte	W12
	.byte		N12	, Gn2, v127
	.byte	W12
song_0039_3_1:
	.byte		N01	, Fs7, v127
	.byte	W06
	.byte		N01	
	.byte	W06
	.byte			Gn6
	.byte		N01	, Fs7
	.byte	W06
	.byte		N01	
	.byte	W06
	.byte			Gn6
	.byte		N01	, Fs7
	.byte	W06
	.byte		N01	
	.byte	W06
	.byte		N01	
	.byte	W06
	.byte		N01	
	.byte	W06
	.byte		N01	
	.byte	W06
	.byte		N01	
	.byte	W06
	.byte		N01	
	.byte	W06
	.byte		N01	
	.byte	W06
	.byte		N01	
	.byte	W06
	.byte		N01	
	.byte	W06
	.byte		N01	
	.byte	W06
	.byte		N01	
	.byte	W06
	.byte	PEND
	.byte	PATT	
		.word	song_0039_3_1
	.byte	PATT	
		.word	song_0039_3_1
	.byte	PATT	
		.word	song_0039_3_1
	.byte	PATT	
		.word	song_0039_3_1
	.byte	PATT	
		.word	song_0039_3_1
	.byte	PATT	
		.word	song_0039_3_1
	.byte	PATT	
		.word	song_0039_3_1
	.byte	PATT	
		.word	song_0039_3_1
	.byte	PATT	
		.word	song_0039_3_1
	.byte	PATT	
		.word	song_0039_3_1
	.byte		N01	, Fs7, v127
	.byte	W06
	.byte		N01	
	.byte	W06
	.byte			Gn6
	.byte		N01	, Fs7
	.byte	W06
	.byte		N01	
	.byte	W06
	.byte			Gn6
	.byte		N01	, Fs7
	.byte	W06
	.byte		N01	
	.byte	W06
	.byte		N01	
	.byte	W06
	.byte		N01	
	.byte	W06
	.byte		N01	
	.byte	W06
	.byte		N01	
	.byte	W06
	.byte		N01	
	.byte	W06
	.byte		N01	
	.byte	W06
	.byte		N01	
	.byte	W06
	.byte		N01	
	.byte	W06
	.byte			Fs2
	.byte		N01	, Fs7
	.byte	W06
	.byte		N01	
	.byte	W06
song_0039_3_2:
	.byte		N01	, Cn1, v127
	.byte		N01	, Fs7
	.byte	W06
	.byte		N01	
	.byte	W06
	.byte			Fs2
	.byte		N01	, Gn6
	.byte		N01	, Fs7
	.byte	W06
	.byte		N01	
	.byte	W06
	.byte			Cn1
	.byte		N01	, Gn6
	.byte		N01	, Fs7
	.byte	W06
	.byte		N01	
	.byte	W06
	.byte			Fs2
	.byte		N01	, Fs7
	.byte	W06
	.byte		N01	
	.byte	W06
	.byte			Cn1
	.byte		N01	, Fs7
	.byte	W06
	.byte		N01	
	.byte	W06
	.byte			Fs2
	.byte		N01	, Fs7
	.byte	W06
	.byte		N01	
	.byte	W06
	.byte			Cn1
	.byte		N01	, Fs7
	.byte	W06
	.byte		N01	
	.byte	W06
	.byte			Fs2
	.byte		N01	, Fs7
	.byte	W06
	.byte		N01	
	.byte	W06
	.byte	PEND
	.byte	PATT	
		.word	song_0039_3_2
	.byte	PATT	
		.word	song_0039_3_2
	.byte	PATT	
		.word	song_0039_3_2
	.byte	PATT	
		.word	song_0039_3_2
	.byte	PATT	
		.word	song_0039_3_2
	.byte	PATT	
		.word	song_0039_3_2
	.byte	PATT	
		.word	song_0039_3_2
	.byte	PATT	
		.word	song_0039_3_2
	.byte	PATT	
		.word	song_0039_3_2
	.byte	PATT	
		.word	song_0039_3_2
	.byte	PATT	
		.word	song_0039_3_2
	.byte	PATT	
		.word	song_0039_3_2
	.byte	PATT	
		.word	song_0039_3_2
	.byte	PATT	
		.word	song_0039_3_2
	.byte	PATT	
		.word	song_0039_3_2
	.byte		N01	, Cn1, v127
	.byte		N01	, Fs2
	.byte		N01	, Fs7
	.byte	W12
	.byte			Gn6
	.byte	W12
	.byte		N01	
	.byte	W72
	.byte	W12
	.byte		N01	
	.byte	W12
	.byte		N01	
	.byte	W60
	.byte			As1
	.byte	W12
	.byte	GOTO	
		.word	song_0039_3_2
	.byte	FINE

	.align 2
	.global song_0039
song_0039:	@ 0x087DF044
	.byte	3		@ trackCount
	.byte	0		@ blockCount
	.byte	10		@ priority
	.byte	168		@ reverb

	.word	voicegroup000		@ voicegroup/tone

	.word	song_0039_1		@ track
	.word	song_0039_2		@ track
	.word	song_0039_3		@ track
