	.include "MPlayDef.s"

	.section .rodata

	@********************** Track  1 **********************@

	.align 2
	.global song_0281_1
song_0281_1:	@ 0x087E7954
	.byte	KEYSH	, 0
	.byte	TEMPO	, 37
	.byte	W01
	.byte	MOD	, 0
	.byte	BEND	, c_v
	.byte	W01
	.byte	VOICE	, 20
	.byte	VOL	, v078
	.byte	W01
	.byte	PAN	, c_v
	.byte	W03
	.byte		N56	, Fs3, v116
	.byte	W60
	.byte	W01
	.byte		N11	, Fs3, v100
	.byte	W12
	.byte		N10	, Gn3, v096
	.byte	W11
	.byte		N14	, Fs3, v108
	.byte	W12
	.byte	W01
	.byte		N48	, En3, v124
	.byte	W60
	.byte		N12	, En3, v112
	.byte	W13
	.byte		N13	, Fs3
	.byte	W12
	.byte		N08	, En3, v120
	.byte	W10
	.byte	W03
	.byte		N12	, En3, v108
	.byte	W11
	.byte		N18	, Dn3
	.byte	W18
	.byte		N07	, Cs3, v092
	.byte	W08
	.byte		N10	, Dn3, v104
	.byte	W10
	.byte		N32	, Bn3, v124
	.byte	W32
	.byte	W01
	.byte		N09	, Dn3
	.byte	W12
	.byte		N36	, Dn3, v096
	.byte	W01
	.byte	W48
	.byte		N32	, Cs3, v100
	.byte	W48
	.byte	W01
	.byte		N23	, Dn3, v116
	.byte	W24
	.byte	W01
	.byte		N32	, Bn3, v120
	.byte	W36
	.byte		N11	, Bn3, v100
	.byte	W11
	.byte		N10	, An3, v112
	.byte	W10
	.byte		N08	, Gn3, v104
	.byte	W12
	.byte		N06	
	.byte	W01
	.byte	W07
	.byte		N05	, Fs3, v096
	.byte	W09
	.byte		N52	, Fs3, v104
	.byte	W68
	.byte		N14	, Dn3
	.byte	W12
	.byte	W01
	.byte		N52	, En3, v112
	.byte	W60
	.byte	W01
	.byte		N10	
	.byte	W10
	.byte		N11	, Fs3, v108
	.byte	W13
	.byte		N10	, Dn3, v127
	.byte	W11
	.byte		N80	, En3, v112
	.byte	W84
	.byte	FINE

	.align 2
	.global song_0281
song_0281:	@ 0x087E79E4
	.byte	1		@ trackCount
	.byte	0		@ blockCount
	.byte	255		@ priority
	.byte	188		@ reverb

	.word	voicegroup000		@ voicegroup/tone

	.word	song_0281_1		@ track
