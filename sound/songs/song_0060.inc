	.include "MPlayDef.s"

	.section .rodata

	@********************** Track  1 **********************@

	.align 2
	.global song_0060_1
song_0060_1:	@ 0x087E5D84
	.byte	KEYSH	, 0
	.byte	TEMPO	, 125
	.byte	VOICE	, 17
	.byte	VOL	, v080
	.byte	PAN	, c_v
	.byte	W24
song_0060_1_2:
	.byte	TEMPO	, 60
	.byte		N16	, Cn3, v127
	.byte	W20
	.byte		N03	, Cn4
	.byte	W04
	.byte		N04	
	.byte	W12
	.byte			Gn3
	.byte	W12
	.byte			An3
	.byte	W12
	.byte			Gn3
	.byte	W12
	.byte			Fn3
	.byte	W12
	.byte			An3
	.byte	W12
song_0060_1_1:
	.byte		N04	, Gn3, v127
	.byte	W12
	.byte			Fn3
	.byte	W12
	.byte			En3
	.byte	W12
	.byte			Gn3
	.byte	W12
	.byte		N24	, Fn3
	.byte	W24
	.byte		N04	, Dn3
	.byte	W24
	.byte	PEND
	.byte		N16	, Cn3
	.byte	W20
	.byte		N03	, Cn4
	.byte	W04
	.byte		N04	
	.byte	W12
	.byte			Gn3
	.byte	W12
	.byte			An3
	.byte	W12
	.byte			Gn3
	.byte	W12
	.byte			Fn3
	.byte	W12
	.byte			An3
	.byte	W12
	.byte			Gn3
	.byte	W12
	.byte			Fn3
	.byte	W12
	.byte			En3
	.byte	W12
	.byte			Dn3
	.byte	W12
	.byte		N24	, Cn3
	.byte	W48
	.byte		N18	
	.byte	W20
	.byte		N03	, Cn4
	.byte	W04
	.byte		N04	
	.byte	W12
	.byte			Gn3
	.byte	W12
	.byte			An3
	.byte	W12
	.byte			Gn3
	.byte	W12
	.byte			Fn3
	.byte	W12
	.byte			An3
	.byte	W12
	.byte	PATT	
		.word	song_0060_1_1
	.byte		N20	, Cn3, v127
	.byte	W20
	.byte		N03	, Cn4
	.byte	W04
	.byte		N04	
	.byte	W12
	.byte			Gn3
	.byte	W12
	.byte			An3
	.byte	W12
	.byte			Gn3
	.byte	W12
	.byte			Fn3
	.byte	W12
	.byte			An3
	.byte	W12
	.byte		N20	, Gn3
	.byte	W20
	.byte		N04	, An3
	.byte	W04
	.byte			Bn3
	.byte	W12
	.byte			Gn3
	.byte	W12
	.byte		N06	, Cn4
	.byte	W48
	.byte	GOTO	
		.word	song_0060_1_2
	.byte	FINE

	@********************** Track  2 **********************@

	.global song_0060_2
song_0060_2:	@ 0x087E5E0E
	.byte	KEYSH	, 0
	.byte	VOICE	, 5
	.byte	VOL	, v075
	.byte	PAN	, c_v
	.byte	W24
song_0060_2_2:
	.byte	W48
	.byte	W48
	.byte	W96
	.byte	W96
	.byte	W56
	.byte		N16	, Gn1, v127
	.byte	W16
	.byte		N04	, An1
	.byte	W12
	.byte			Bn1
	.byte	W12
song_0060_2_1:
	.byte		N04	, Cn2, v127
	.byte	W12
	.byte		N08	
	.byte	W08
	.byte	BEND	, c_v-24
	.byte		N16	, Cn3
	.byte	W01
	.byte	BEND	, c_v-15
	.byte	W01
	.byte		c_v-9
	.byte	W01
	.byte		c_v-5
	.byte	W01
	.byte		c_v-3
	.byte	W01
	.byte		c_v-2
	.byte	W01
	.byte		c_v-1
	.byte	W01
	.byte		c_v
	.byte	W09
	.byte		N04	, Gn2
	.byte	W12
	.byte			An2
	.byte	W12
	.byte			Gn2
	.byte	W12
	.byte			Fn2
	.byte	W12
	.byte			An2
	.byte	W12
	.byte	PEND
	.byte			Gn2
	.byte	W12
	.byte			Fn2
	.byte	W12
	.byte			En2
	.byte	W12
	.byte			Gn2
	.byte	W12
	.byte		N24	, Fn2
	.byte	W24
	.byte		N04	, Dn2
	.byte	W24
	.byte	PATT	
		.word	song_0060_2_1
	.byte		N16	, Gn2, v127
	.byte	W54
	.byte		N01	
	.byte	W06
	.byte		N12	
	.byte	W12
	.byte			Cn2
	.byte	W24
	.byte	GOTO	
		.word	song_0060_2_2
	.byte	FINE

	@********************** Track  3 **********************@

	.global song_0060_3
song_0060_3:	@ 0x087E5E6E
	.byte	KEYSH	, 0
	.byte	VOICE	, 1
	.byte	VOL	, v075
	.byte	PAN	, c_v
	.byte	W24
song_0060_3_2:
	.byte	W48
	.byte	W48
	.byte	W96
	.byte	W96
	.byte		N04	, Gn3, v127
	.byte	W12
	.byte			Fn3
	.byte	W12
	.byte			En3
	.byte	W12
	.byte			Dn3
	.byte	W12
	.byte		N08	, Cn3
	.byte	W08
	.byte			Gn2
	.byte	W16
	.byte		N04	, An2
	.byte	W12
	.byte			Bn2
	.byte	W12
song_0060_3_1:
	.byte		N12	, Cn3, v127
	.byte	W12
	.byte		N06	, Gn3
	.byte	W06
	.byte			Cn4
	.byte	W06
	.byte			Gn2
	.byte	W06
	.byte			En4
	.byte	W06
	.byte			Gn3
	.byte	W06
	.byte			Cn4
	.byte	W06
	.byte		N12	, Fn2
	.byte	W12
	.byte		N06	, An3
	.byte	W06
	.byte			Cn4
	.byte	W06
	.byte			Cn3
	.byte	W06
	.byte			Fn4
	.byte	W06
	.byte			An3
	.byte	W06
	.byte			Cn4
	.byte	W06
	.byte	PEND
	.byte		N12	, Cn3
	.byte	W12
	.byte		N06	, Gn3
	.byte	W06
	.byte			Cn4
	.byte	W06
	.byte			Gn2
	.byte	W06
	.byte			En4
	.byte	W06
	.byte			Gn3
	.byte	W06
	.byte			Cn4
	.byte	W06
	.byte			Gn2
	.byte	W06
	.byte		N12	, Gn3
	.byte		N12	, Dn4
	.byte	W12
	.byte		N06	, Bn3
	.byte	W06
	.byte			Gn2
	.byte	W06
	.byte			Gn3
	.byte	W06
	.byte			Bn3
	.byte	W06
	.byte			Dn4
	.byte	W06
	.byte	PATT	
		.word	song_0060_3_1
	.byte		N03	, Gn3, v127
	.byte	W03
	.byte		N03	
	.byte	W03
	.byte		N03	
	.byte	W03
	.byte		N03	
	.byte	W04
	.byte		N03	
	.byte	W03
	.byte		N03	
	.byte	W04
	.byte			An3
	.byte	W04
	.byte			Bn3
	.byte	W12
	.byte			Gn3
	.byte	W12
	.byte			Cn4
	.byte	W48
	.byte	GOTO	
		.word	song_0060_3_2
	.byte	FINE

	@********************** Track  4 **********************@

	.global song_0060_4
song_0060_4:	@ 0x087E5EF4
	.byte	KEYSH	, 0
	.byte	VOICE	, 22
	.byte	VOL	, v080
	.byte	PAN	, c_v
	.byte	W24
song_0060_4_1:
	.byte	W48
	.byte	W48
	.byte	W96
	.byte	W96
	.byte	W54
	.byte		N18	, Gn0, v127
	.byte	W18
	.byte		N12	, An0
	.byte	W12
	.byte			Bn0
	.byte	W12
	.byte			Cn1
	.byte	W24
	.byte			Gn0
	.byte	W24
	.byte		N08	, Fn0
	.byte	W12
	.byte		N12	
	.byte	W12
	.byte			An0
	.byte	W12
	.byte			Cn1
	.byte	W12
	.byte		N08	, En1
	.byte	W12
	.byte		N12	, Cn1
	.byte	W12
	.byte			Gn0
	.byte	W12
	.byte			Cn1
	.byte	W18
	.byte		N18	, Gn0
	.byte	W18
	.byte		N12	, An0
	.byte	W12
	.byte			Bn0
	.byte	W12
	.byte			Cn1
	.byte	W24
	.byte			Gn0
	.byte	W24
	.byte			Fn0
	.byte	W24
	.byte		N12	
	.byte	W24
	.byte		N16	, Gn0
	.byte	W54
	.byte		N01	
	.byte	W06
	.byte		N12	
	.byte	W12
	.byte			Cn1
	.byte	W24
	.byte	GOTO	
		.word	song_0060_4_1
	.byte	FINE

	@********************** Track  5 **********************@

	.global song_0060_5
song_0060_5:	@ 0x087E5F41
	.byte	KEYSH	, 0
	.byte	VOICE	, 126
	.byte	VOL	, v075
	.byte	PAN	, c_v
	.byte	W24
song_0060_5_3:
	.byte		N06	, Gs1, v080
	.byte	W12
	.byte		N06	
	.byte	W24
	.byte		N06	
	.byte	W12
	.byte	W12
	.byte		N06	
	.byte	W24
	.byte		N06	
	.byte	W12
song_0060_5_1:
	.byte		N06	, Gs1, v080
	.byte	W12
	.byte		N06	
	.byte	W24
	.byte		N06	
	.byte	W24
	.byte		N06	
	.byte	W24
	.byte		N06	
	.byte	W12
	.byte	PEND
	.byte	PATT	
		.word	song_0060_5_1
	.byte		N06	, Gs1, v080
	.byte	W12
	.byte		N06	
	.byte	W24
	.byte		N06	
	.byte	W08
	.byte			Dn1, v127
	.byte	W16
	.byte			Gs1, v080
	.byte	W08
	.byte		N04	, Dn1, v127
	.byte	W04
	.byte		N06	, Cn1
	.byte		N06	, Dn1
	.byte	W08
	.byte		N04	
	.byte	W04
	.byte		N06	
	.byte	W12
	.byte			Cn1
	.byte		N96	, Gn2
	.byte	W12
	.byte		N06	, Dn1
	.byte	W12
	.byte			Cn1
	.byte	W12
	.byte			Dn1
	.byte	W12
	.byte			Cn1
	.byte	W12
	.byte			Dn1
	.byte	W12
	.byte			Cn1
	.byte	W12
	.byte			Dn1
	.byte	W12
song_0060_5_2:
	.byte		N06	, Cn1, v127
	.byte	W12
	.byte			Dn1
	.byte	W12
	.byte			Cn1
	.byte	W12
	.byte			Dn1
	.byte	W12
	.byte			Cn1
	.byte	W12
	.byte			Dn1
	.byte	W12
	.byte			Cn1
	.byte	W12
	.byte			Dn1
	.byte	W12
	.byte	PEND
	.byte	PATT	
		.word	song_0060_5_2
	.byte		N06	, Cn1, v127
	.byte		N06	, Dn1
	.byte	W12
	.byte			Gs1, v080
	.byte	W24
	.byte		N06	
	.byte	W18
	.byte		N03	, Dn1, v127
	.byte	W03
	.byte		N03	
	.byte	W03
	.byte		N06	, Cn1
	.byte		N06	, Dn1
	.byte	W12
	.byte		N06	
	.byte	W12
	.byte			Cn1
	.byte		N24	, Gn2
	.byte	W12
	.byte	GOTO	
		.word	song_0060_5_3
	.byte	W12
	.byte	FINE

	.align 2
	.global song_0060
song_0060:	@ 0x087E5FD4
	.byte	5		@ trackCount
	.byte	0		@ blockCount
	.byte	10		@ priority
	.byte	168		@ reverb

	.word	voicegroup000		@ voicegroup/tone

	.word	song_0060_1		@ track
	.word	song_0060_2		@ track
	.word	song_0060_3		@ track
	.word	song_0060_4		@ track
	.word	song_0060_5		@ track
