	.include "MPlayDef.s"

	.section .rodata

	@********************** Track  1 **********************@

	.align 2
	.global song_0022_1
song_0022_1:	@ 0x087D9CDC
	.byte	KEYSH	, 0
	.byte	TEMPO	, 125
	.byte	VOICE	, 3
	.byte	VOL	, v085
	.byte	PAN	, c_v
	.byte	W24
song_0022_1_3:
	.byte	TEMPO	, 46
	.byte		N72	, An3, v116
	.byte	W72
	.byte		N24	, En4
	.byte	W24
	.byte		N84	
	.byte	W96
song_0022_1_1:
	.byte		N60	, Bn3, v116
	.byte	W60
	.byte		N12	, Cn4
	.byte	W12
	.byte		N24	, Dn4
	.byte	W24
	.byte	PEND
	.byte		N84	, Bn3
	.byte	W96
song_0022_1_2:
	.byte		N36	, An3, v116
	.byte	W36
	.byte			Bn3
	.byte	W36
	.byte		N24	, Cn4
	.byte	W24
	.byte	PEND
	.byte		N72	, Dn4
	.byte	W72
	.byte		N24	, Cn4
	.byte	W24
	.byte		N60	, En4
	.byte	W60
	.byte		N12	, Dn4
	.byte	W12
	.byte			Cn4
	.byte	W12
	.byte			Dn4
	.byte	W12
	.byte		N72	, En4
	.byte	W96
	.byte			An3
	.byte	W72
	.byte		N24	, En4
	.byte	W24
	.byte		N84	
	.byte	W96
	.byte	PATT	
		.word	song_0022_1_1
	.byte		N84	, Bn3, v116
	.byte	W96
	.byte	PATT	
		.word	song_0022_1_2
	.byte		N36	, Bn3, v116
	.byte	W36
	.byte			An3
	.byte	W36
	.byte		N24	, Bn3
	.byte	W24
	.byte		TIE	, An3
	.byte	W96
	.byte	W48
	.byte		EOT	
	.byte	W48
	.byte	GOTO	
		.word	song_0022_1_3
	.byte	FINE

	@********************** Track  2 **********************@

	.global song_0022_2
song_0022_2:	@ 0x087D9D47
	.byte	KEYSH	, 0
	.byte	VOICE	, 19
	.byte	VOL	, v077
	.byte	PAN	, c_v
	.byte	W24
song_0022_2_1:
	.byte		N08	, Fn1, v100
	.byte	W08
	.byte			Fn2
	.byte	W08
	.byte			An2
	.byte	W08
	.byte			Cn3
	.byte	W08
	.byte			En3
	.byte	W08
	.byte			An3
	.byte	W08
	.byte			An4
	.byte	W08
	.byte			En4
	.byte	W08
	.byte			Cn4
	.byte	W08
	.byte			An3
	.byte	W08
	.byte			En3
	.byte	W08
	.byte			Cn3
	.byte	W08
	.byte	PEND
	.byte			Fn1
	.byte	W08
	.byte			Gn2
	.byte	W08
	.byte			Bn2
	.byte	W08
	.byte			En3
	.byte	W08
	.byte			Gn3
	.byte	W08
	.byte			Bn3
	.byte	W08
	.byte			Bn4
	.byte	W08
	.byte			Gn4
	.byte	W08
	.byte			En4
	.byte	W08
	.byte			Bn3
	.byte	W08
	.byte			Gn3
	.byte	W08
	.byte			En3
	.byte	W08
	.byte			En1
	.byte	W08
	.byte			Gn2
	.byte	W08
	.byte			Bn2
	.byte	W08
	.byte			En3
	.byte	W08
	.byte			Gn3
	.byte	W08
	.byte			Bn3
	.byte	W08
	.byte			Bn4
	.byte	W08
	.byte			Gn4
	.byte	W08
	.byte			En4
	.byte	W08
	.byte			Bn3
	.byte	W08
	.byte			Gn3
	.byte	W08
	.byte			En3
	.byte	W08
	.byte			An1
	.byte	W08
	.byte			Gn2
	.byte	W08
	.byte			An2
	.byte	W08
	.byte			Cs3
	.byte	W08
	.byte			En3
	.byte	W08
	.byte			An3
	.byte	W08
	.byte			Cs5
	.byte	W08
	.byte			An4
	.byte	W08
	.byte			En4
	.byte	W08
	.byte			Cs4
	.byte	W08
	.byte			An3
	.byte	W08
	.byte			Cs3
	.byte	W08
	.byte	PATT	
		.word	song_0022_2_1
song_0022_2_2:
	.byte		N08	, Gn1, v100
	.byte	W08
	.byte			Gn2
	.byte	W08
	.byte			Bn2
	.byte	W08
	.byte			Dn3
	.byte	W08
	.byte			Gn3
	.byte	W08
	.byte			Bn3
	.byte	W08
	.byte			Bn4
	.byte	W08
	.byte			Gn4
	.byte	W08
	.byte			Dn4
	.byte	W08
	.byte			Bn3
	.byte	W08
	.byte			Gn3
	.byte	W08
	.byte			Dn3
	.byte	W08
	.byte	PEND
	.byte			Cn2
	.byte	W08
	.byte			Gn2
	.byte	W08
	.byte			Bn2
	.byte	W08
	.byte			Cn3
	.byte	W08
	.byte			Gn3
	.byte	W08
	.byte			Bn3
	.byte	W08
	.byte			Bn4
	.byte	W08
	.byte			Gn4
	.byte	W08
	.byte			En4
	.byte	W08
	.byte			Cn4
	.byte	W08
	.byte			Gn3
	.byte	W08
	.byte			Cn3
	.byte	W08
	.byte			Bn1
	.byte	W08
	.byte			Gs2
	.byte	W08
	.byte			Bn2
	.byte	W08
	.byte			Dn3
	.byte	W08
	.byte			Gs3
	.byte	W08
	.byte			Bn3
	.byte	W08
	.byte			Bn4
	.byte	W08
	.byte			Gs4
	.byte	W08
	.byte			En4
	.byte	W08
	.byte			Dn4
	.byte	W08
	.byte			Gs3
	.byte	W08
	.byte			En3
	.byte	W08
	.byte			An1
	.byte	W08
	.byte			En2
	.byte	W08
	.byte			An2
	.byte	W08
	.byte			Cn3
	.byte	W08
	.byte			En3
	.byte	W08
	.byte			An3
	.byte	W08
	.byte			An4
	.byte	W08
	.byte			En4
	.byte	W08
	.byte			Cn4
	.byte	W08
	.byte			An3
	.byte	W08
	.byte			En3
	.byte	W08
	.byte			Cn3
	.byte	W08
	.byte			Gn1
	.byte	W08
	.byte			Gn2
	.byte	W08
	.byte			Bn2
	.byte	W08
	.byte			En3
	.byte	W08
	.byte			Gn3
	.byte	W08
	.byte			Bn3
	.byte	W08
	.byte			Bn4
	.byte	W08
	.byte			Gn4
	.byte	W08
	.byte			En4
	.byte	W08
	.byte			Bn3
	.byte	W08
	.byte			Gn3
	.byte	W08
	.byte			En3
	.byte	W08
	.byte			Fn1
	.byte	W08
	.byte			An2
	.byte	W08
	.byte			Cn3
	.byte	W08
	.byte			En3
	.byte	W08
	.byte			An3
	.byte	W08
	.byte			Cn4
	.byte	W08
	.byte			Cn5
	.byte	W08
	.byte			An4
	.byte	W08
	.byte			En4
	.byte	W08
	.byte			Cn4
	.byte	W08
	.byte			An3
	.byte	W08
	.byte			En3
	.byte	W08
	.byte			En1
	.byte	W08
	.byte			En2
	.byte	W08
	.byte			Gn2
	.byte	W08
	.byte			Bn2
	.byte	W08
	.byte			Dn3
	.byte	W08
	.byte			Gn3
	.byte	W08
	.byte			Bn4
	.byte	W08
	.byte			Gn4
	.byte	W08
	.byte			Dn4
	.byte	W08
	.byte			Bn3
	.byte	W08
	.byte			Gn3
	.byte	W08
	.byte			Dn3
	.byte	W08
	.byte	PATT	
		.word	song_0022_2_1
	.byte	PATT	
		.word	song_0022_2_2
	.byte		N08	, An1, v100
	.byte	W08
	.byte			An2
	.byte	W08
	.byte			Cn3
	.byte	W08
	.byte			En3
	.byte	W08
	.byte			An3
	.byte	W08
	.byte			Cn4
	.byte	W08
	.byte			Cn5
	.byte	W08
	.byte			An4
	.byte	W08
	.byte			En4
	.byte	W08
	.byte			Cn4
	.byte	W08
	.byte			An3
	.byte	W08
	.byte			Cn3
	.byte	W08
	.byte			An1
	.byte	W08
	.byte			En2
	.byte	W08
	.byte			An2
	.byte	W08
	.byte		N24	, En3
	.byte		N24	, An3
	.byte		N24	, Cn4
	.byte	W24
	.byte		N48	, Dn3
	.byte		N48	, Gn3
	.byte		N48	, Bn3
	.byte	W24
	.byte		N24	, Gn1
	.byte	W24
	.byte	GOTO	
		.word	song_0022_2_1
	.byte	FINE

	@********************** Track  3 **********************@

	.global song_0022_3
song_0022_3:	@ 0x087D9EA4
	.byte	KEYSH	, 0
	.byte	VOICE	, 22
	.byte	VOL	, v070
	.byte	PAN	, c_v
	.byte	W24
song_0022_3_1:
	.byte		N96	, Fn0, v127
	.byte	W96
	.byte			Fn1
	.byte	W96
	.byte		N84	, En1
	.byte	W84
	.byte		N12	, Bn0
	.byte	W12
	.byte		N48	, An0
	.byte	W48
	.byte		N18	, An1
	.byte	W18
	.byte		N16	, Gn1
	.byte	W16
	.byte		N14	, En1
	.byte	W14
	.byte		N48	, Fn1
	.byte	W48
	.byte			Fn0
	.byte	W48
	.byte		N84	, Gn0
	.byte	W84
	.byte		N12	
	.byte	W12
	.byte		N96	, Cn1
	.byte	W96
	.byte		N48	, Bn0
	.byte	W48
	.byte			En0
	.byte	W48
	.byte		TIE	, An0
	.byte	W96
	.byte		N48	, Bn1
	.byte	W05
	.byte		EOT	, An0
	.byte	W42
	.byte	W01
	.byte		N36	, Gn1
	.byte	W36
	.byte		N12	, En1
	.byte	W12
	.byte		N96	, Fn1
	.byte	W96
	.byte		N72	, En1
	.byte	W72
	.byte		N24	, En0
	.byte	W24
	.byte		N72	, Fn0
	.byte	W72
	.byte		N24	
	.byte	W24
	.byte		N72	, Gn0
	.byte	W72
	.byte		N24	
	.byte	W24
	.byte		TIE	, An0
	.byte	W96
	.byte	W48
	.byte		EOT	
	.byte		N48	, Gn0
	.byte	W48
	.byte	GOTO	
		.word	song_0022_3_1
	.byte	FINE

	.align 2
	.global song_0022
song_0022:	@ 0x087D9F08
	.byte	3		@ trackCount
	.byte	0		@ blockCount
	.byte	10		@ priority
	.byte	168		@ reverb

	.word	voicegroup000		@ voicegroup/tone

	.word	song_0022_1		@ track
	.word	song_0022_2		@ track
	.word	song_0022_3		@ track
