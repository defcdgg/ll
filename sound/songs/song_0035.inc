	.include "MPlayDef.s"

	.section .rodata

	@********************** Track  1 **********************@

	.align 2
	.global song_0035_1
song_0035_1:	@ 0x087DDDBC
	.byte	KEYSH	, 0
	.byte	TEMPO	, 125
	.byte	VOICE	, 22
	.byte	VOL	, v094
	.byte	PAN	, c_v
	.byte	W24
song_0035_1_3:
	.byte	TEMPO	, 72
	.byte		TIE	, En1, v127
	.byte	W96
	.byte	W96
	.byte		EOT	
	.byte		TIE	
	.byte	W96
	.byte	W96
	.byte		EOT	
	.byte		TIE	
	.byte	W96
	.byte	W96
	.byte		EOT	
	.byte		N96	
	.byte	W96
song_0035_1_2:
	.byte		N12	, Dn2, v127
	.byte	W12
	.byte		N12	
	.byte	W12
	.byte		N12	
	.byte	W12
	.byte		N12	
	.byte	W12
	.byte		N12	
	.byte	W12
	.byte		N12	
	.byte	W12
	.byte		N12	
	.byte	W12
	.byte		N12	
	.byte	W12
	.byte	PEND
	.byte		N40	, En2
	.byte	W48
	.byte			En1
	.byte	W48
song_0035_1_1:
	.byte		N40	, En1, v127
	.byte	W48
	.byte		N40	
	.byte	W48
	.byte	PEND
	.byte	PATT	
		.word	song_0035_1_1
	.byte	PATT	
		.word	song_0035_1_1
	.byte	PATT	
		.word	song_0035_1_1
	.byte	PATT	
		.word	song_0035_1_1
	.byte	PATT	
		.word	song_0035_1_1
	.byte	PATT	
		.word	song_0035_1_2
	.byte	GOTO	
		.word	song_0035_1_3
	.byte	FINE

	@********************** Track  2 **********************@

	.global song_0035_2
song_0035_2:	@ 0x087DDE1C
	.byte	KEYSH	, 0
	.byte	VOICE	, 0
	.byte	VOL	, v100
	.byte	PAN	, c_v-40
	.byte	W24
song_0035_2_1:
	.byte		N08	, Bn4, v127
	.byte	W12
	.byte		N08	
	.byte	W12
	.byte		N30	
	.byte	W72
	.byte	PEND
song_0035_2_2:
	.byte	W48
	.byte		N13	, Bn4, v127
	.byte	W24
	.byte		N08	
	.byte	W12
	.byte		N08	
	.byte	W12
	.byte	PEND
song_0035_2_3:
	.byte		N08	, Dn5, v127
	.byte	W12
	.byte		N08	
	.byte	W12
	.byte		N30	
	.byte	W72
	.byte	PEND
song_0035_2_4:
	.byte	W48
	.byte		N13	, Dn5, v127
	.byte	W24
	.byte		N08	
	.byte	W12
	.byte		N08	
	.byte	W12
	.byte	PEND
song_0035_2_5:
	.byte		N08	, Cs5, v127
	.byte	W12
	.byte		N08	
	.byte	W12
	.byte		N30	
	.byte	W72
	.byte	PEND
song_0035_2_6:
	.byte	W48
	.byte		N13	, Cs5, v127
	.byte	W24
	.byte		N08	
	.byte	W12
	.byte		N08	
	.byte	W12
	.byte	PEND
song_0035_2_7:
	.byte		N08	, An4, v127
	.byte	W12
	.byte		N08	
	.byte	W12
	.byte		N30	
	.byte	W72
	.byte	PEND
song_0035_2_8:
	.byte	W48
	.byte		N08	, An4, v127
	.byte	W12
	.byte		N08	
	.byte	W12
	.byte		N08	
	.byte	W12
	.byte		N08	
	.byte	W12
	.byte	PEND
	.byte	PATT	
		.word	song_0035_2_1
	.byte	PATT	
		.word	song_0035_2_2
	.byte	PATT	
		.word	song_0035_2_3
	.byte	PATT	
		.word	song_0035_2_4
	.byte	PATT	
		.word	song_0035_2_5
	.byte	PATT	
		.word	song_0035_2_6
	.byte	PATT	
		.word	song_0035_2_7
	.byte	PATT	
		.word	song_0035_2_8
	.byte	GOTO	
		.word	song_0035_2_1
	.byte	FINE

	@********************** Track  3 **********************@

	.global song_0035_3
song_0035_3:	@ 0x087DDEA1
	.byte	KEYSH	, 0
	.byte	VOICE	, 5
	.byte	VOL	, v100
	.byte	PAN	, c_v-40
	.byte	W24
song_0035_3_1:
	.byte		N08	, En3, v127
	.byte	W12
	.byte		N08	
	.byte	W12
	.byte		N30	
	.byte	W72
	.byte	PEND
song_0035_3_2:
	.byte	W48
	.byte		N13	, En3, v127
	.byte	W24
	.byte		N08	
	.byte	W12
	.byte		N08	
	.byte	W12
	.byte	PEND
song_0035_3_3:
	.byte		N08	, Gn3, v127
	.byte	W12
	.byte		N08	
	.byte	W12
	.byte		N30	
	.byte	W72
	.byte	PEND
song_0035_3_4:
	.byte	W48
	.byte		N13	, Gn3, v127
	.byte	W24
	.byte		N08	
	.byte	W12
	.byte		N08	
	.byte	W12
	.byte	PEND
song_0035_3_5:
	.byte		N08	, Fs3, v127
	.byte	W12
	.byte		N08	
	.byte	W12
	.byte		N30	
	.byte	W72
	.byte	PEND
song_0035_3_6:
	.byte	W48
	.byte		N13	, Fs3, v127
	.byte	W24
	.byte		N08	
	.byte	W12
	.byte		N08	
	.byte	W12
	.byte	PEND
song_0035_3_7:
	.byte		N08	, Dn3, v127
	.byte	W12
	.byte		N08	
	.byte	W12
	.byte		N30	
	.byte	W72
	.byte	PEND
song_0035_3_8:
	.byte	W48
	.byte		N08	, Dn3, v127
	.byte	W12
	.byte		N08	
	.byte	W12
	.byte		N08	
	.byte	W12
	.byte		N08	
	.byte	W12
	.byte	PEND
	.byte	PATT	
		.word	song_0035_3_1
	.byte	PATT	
		.word	song_0035_3_2
	.byte	PATT	
		.word	song_0035_3_3
	.byte	PATT	
		.word	song_0035_3_4
	.byte	PATT	
		.word	song_0035_3_5
	.byte	PATT	
		.word	song_0035_3_6
	.byte	PATT	
		.word	song_0035_3_7
	.byte	PATT	
		.word	song_0035_3_8
	.byte	GOTO	
		.word	song_0035_3_1
	.byte	FINE

	@********************** Track  4 **********************@

	.global song_0035_4
song_0035_4:	@ 0x087DDF26
	.byte	KEYSH	, 0
	.byte	VOICE	, 126
	.byte	VOL	, v078
	.byte	PAN	, c_v
	.byte	W24
song_0035_4_4:
	.byte		N96	, Bn2, v127
	.byte		N96	, Cn5
	.byte	W96
	.byte	W96
	.byte		N96	
	.byte	W96
	.byte	W48
	.byte		N12	
	.byte	W12
	.byte		N12	
	.byte	W12
	.byte		N12	
	.byte	W12
	.byte		N12	
	.byte	W12
	.byte		N96	, Bn2
	.byte		N96	, Cn5
	.byte	W96
	.byte	W84
	.byte		N04	
	.byte	W04
	.byte		N04	
	.byte	W04
	.byte		N04	
	.byte	W04
	.byte		N96	
	.byte	W96
	.byte	W24
	.byte		N03	, Dn4
	.byte	W03
	.byte		N03	
	.byte	W03
	.byte		N03	
	.byte	W03
	.byte		N03	
	.byte	W03
	.byte		N03	
	.byte	W03
	.byte		N03	
	.byte	W03
	.byte		N03	
	.byte	W03
	.byte		N03	
	.byte	W03
	.byte		N03	
	.byte	W03
	.byte		N03	
	.byte	W03
	.byte		N03	
	.byte	W03
	.byte		N03	
	.byte	W03
	.byte		N03	
	.byte	W03
	.byte		N03	
	.byte	W03
	.byte		N03	
	.byte	W03
	.byte		N03	
	.byte	W03
	.byte		N03	
	.byte	W03
	.byte		N03	
	.byte	W03
	.byte		N03	
	.byte	W03
	.byte		N03	
	.byte	W03
	.byte		N03	
	.byte	W03
	.byte		N03	
	.byte	W03
	.byte		N03	
	.byte	W03
	.byte		N03	
	.byte	W03
song_0035_4_1:
	.byte		N48	, Bn2, v127
	.byte		N48	, En4
	.byte		N48	, Cn5
	.byte	W48
	.byte			En4
	.byte		N48	, Cn5
	.byte	W48
	.byte	PEND
song_0035_4_2:
	.byte		N48	, En4, v127
	.byte		N48	, Cn5
	.byte	W48
	.byte		N36	, En4
	.byte		N36	, Cn5
	.byte	W36
	.byte		N04	, En4
	.byte		N04	, Cn5
	.byte	W04
	.byte			En4
	.byte		N04	, Cn5
	.byte	W04
	.byte			En4
	.byte		N04	, Cn5
	.byte	W04
	.byte	PEND
song_0035_4_3:
	.byte		N48	, En4, v127
	.byte		N48	, Cn5
	.byte	W48
	.byte			En4
	.byte		N48	, Cn5
	.byte	W48
	.byte	PEND
	.byte			En4
	.byte		N48	, Cn5
	.byte	W48
	.byte		N12	, En4
	.byte		N12	, Cn5
	.byte	W12
	.byte			En4
	.byte		N12	, Cn5
	.byte	W12
	.byte			En4
	.byte		N12	, Cn5
	.byte	W12
	.byte			En4
	.byte		N12	, Cn5
	.byte	W12
	.byte	PATT	
		.word	song_0035_4_1
	.byte	PATT	
		.word	song_0035_4_2
	.byte	PATT	
		.word	song_0035_4_3
	.byte		N48	, Dn4, v127
	.byte		N48	, Cn5
	.byte	W48
	.byte		N12	, Dn4
	.byte		N12	, Cn5
	.byte	W12
	.byte			Dn4
	.byte		N12	, Cn5
	.byte	W12
	.byte			Dn4
	.byte		N12	, Cn5
	.byte	W12
	.byte			Dn4
	.byte		N12	, Cn5
	.byte	W12
	.byte	GOTO	
		.word	song_0035_4_4
	.byte	FINE

	.align 2
	.global song_0035
song_0035:	@ 0x087DDFF4
	.byte	4		@ trackCount
	.byte	0		@ blockCount
	.byte	10		@ priority
	.byte	168		@ reverb

	.word	voicegroup000		@ voicegroup/tone

	.word	song_0035_1		@ track
	.word	song_0035_2		@ track
	.word	song_0035_3		@ track
	.word	song_0035_4		@ track
