	.include "MPlayDef.s"

	.section .rodata

	@********************** Track  1 **********************@

	.align 2
	.global song_0061_1
song_0061_1:	@ 0x087E5FF0
	.byte	KEYSH	, 0
	.byte	TEMPO	, 125
	.byte	VOICE	, 17
	.byte	VOL	, v080
	.byte	PAN	, c_v
	.byte	W24
	.byte	TEMPO	, 60
	.byte		N18	, Gs3, v127
	.byte	W18
	.byte		N06	, As3
	.byte	W06
	.byte		N12	, Gs3
	.byte	W12
	.byte		N12	
	.byte	W16
	.byte			Cs4
	.byte	W12
	.byte	FINE

	@********************** Track  2 **********************@

	.global song_0061_2
song_0061_2:	@ 0x087E600C
	.byte	KEYSH	, 0
	.byte	VOICE	, 1
	.byte	VOL	, v075
	.byte	PAN	, c_v
	.byte	W24
	.byte		N03	, Gn3, v127
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
	.byte			An3
	.byte	W06
	.byte			Gn3
	.byte	W12
	.byte		N03	
	.byte	W12
	.byte			Cn4
	.byte	W03
	.byte	FINE

	@********************** Track  3 **********************@

	.global song_0061_3
song_0061_3:	@ 0x087E602C
	.byte	KEYSH	, 0
	.byte	VOICE	, 1
	.byte	VOL	, v075
	.byte	PAN	, c_v
	.byte	W24
	.byte		N16	, Bn2, v127
	.byte		N16	, Dn3
	.byte		N16	, Fn3
	.byte	W48
	.byte		N01	, Bn2
	.byte		N01	, Dn3
	.byte		N01	, Fn3
	.byte	W06
	.byte			Bn2
	.byte		N01	, Dn3
	.byte		N01	, Fn3
	.byte	W06
	.byte		N12	, Bn2
	.byte		N12	, Dn3
	.byte		N12	, Fn3
	.byte	W12
	.byte			Cn3
	.byte		N12	, En3
	.byte	W12
	.byte	FINE

	@********************** Track  4 **********************@

	.global song_0061_4
song_0061_4:	@ 0x087E6056
	.byte	KEYSH	, 0
	.byte	VOICE	, 2
	.byte	VOL	, v075
	.byte	PAN	, c_v
	.byte	W24
	.byte		N16	, Gn0, v127
	.byte	W54
	.byte		N01	
	.byte	W06
	.byte		N12	
	.byte	W12
	.byte			Cn1
	.byte	W12
	.byte	FINE

	@********************** Track  5 **********************@

	.global song_0061_5
song_0061_5:	@ 0x087E606A
	.byte	KEYSH	, 0
	.byte	VOICE	, 126
	.byte	VOL	, v075
	.byte	PAN	, c_v
	.byte	W24
	.byte		N06	, Cn1, v127
	.byte		N06	, Dn1
	.byte	W12
	.byte			Gs1
	.byte	W24
	.byte		N06	
	.byte	W18
	.byte		N03	, Dn1
	.byte	W03
	.byte		N03	
	.byte	W03
	.byte		N06	, Cn1
	.byte		N06	, Dn1
	.byte	W12
	.byte		N06	
	.byte	W12
	.byte			Gn6
	.byte	W06
	.byte	FINE

	.align 2
	.global song_0061
song_0061:	@ 0x087E608C
	.byte	5		@ trackCount
	.byte	0		@ blockCount
	.byte	10		@ priority
	.byte	168		@ reverb

	.word	voicegroup000		@ voicegroup/tone

	.word	song_0061_1		@ track
	.word	song_0061_2		@ track
	.word	song_0061_3		@ track
	.word	song_0061_4		@ track
	.word	song_0061_5		@ track
