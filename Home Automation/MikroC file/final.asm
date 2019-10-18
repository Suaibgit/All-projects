
_out:

;final.c,18 :: 		void out(){
;final.c,19 :: 		x--;
	DECF       _x+0, 1
;final.c,20 :: 		if (x<0){
	MOVLW      128
	XORWF      _x+0, 0
	MOVWF      R0+0
	MOVLW      128
	XORLW      0
	SUBWF      R0+0, 0
	BTFSC      STATUS+0, 0
	GOTO       L_out0
;final.c,21 :: 		x=0;
	CLRF       _x+0
;final.c,22 :: 		portb = 0x00;
	CLRF       PORTB+0
;final.c,23 :: 		lcd_out(2,14,"   ");
	MOVLW      2
	MOVWF      FARG_Lcd_Out_row+0
	MOVLW      14
	MOVWF      FARG_Lcd_Out_column+0
	MOVLW      ?lstr1_final+0
	MOVWF      FARG_Lcd_Out_text+0
	CALL       _Lcd_Out+0
;final.c,24 :: 		}
L_out0:
;final.c,25 :: 		s1 = x % 10;
	MOVLW      10
	MOVWF      R4+0
	MOVF       _x+0, 0
	MOVWF      R0+0
	CALL       _Div_8X8_S+0
	MOVF       R8+0, 0
	MOVWF      R0+0
	MOVF       R0+0, 0
	MOVWF      _s1+0
;final.c,26 :: 		lcd1[1] = s1 + '0';
	MOVLW      48
	ADDWF      R0+0, 0
	MOVWF      _lcd1+1
;final.c,27 :: 		s2 = x / 10;
	MOVLW      10
	MOVWF      R4+0
	MOVF       _x+0, 0
	MOVWF      R0+0
	CALL       _Div_8X8_S+0
	MOVF       R0+0, 0
	MOVWF      _s2+0
;final.c,28 :: 		lcd1[0] = s2 + '0';
	MOVLW      48
	ADDWF      R0+0, 0
	MOVWF      _lcd1+0
;final.c,29 :: 		lcd_out(1,1,lcd1);
	MOVLW      1
	MOVWF      FARG_Lcd_Out_row+0
	MOVLW      1
	MOVWF      FARG_Lcd_Out_column+0
	MOVLW      _lcd1+0
	MOVWF      FARG_Lcd_Out_text+0
	CALL       _Lcd_Out+0
;final.c,30 :: 		s1 = s2 =0;
	CLRF       _s2+0
	CLRF       _s1+0
;final.c,31 :: 		delay_ms(500);
	MOVLW      6
	MOVWF      R11+0
	MOVLW      19
	MOVWF      R12+0
	MOVLW      173
	MOVWF      R13+0
L_out1:
	DECFSZ     R13+0, 1
	GOTO       L_out1
	DECFSZ     R12+0, 1
	GOTO       L_out1
	DECFSZ     R11+0, 1
	GOTO       L_out1
	NOP
	NOP
;final.c,32 :: 		}
L_end_out:
	RETURN
; end of _out

_in:

;final.c,33 :: 		void in(){
;final.c,35 :: 		x++;
	INCF       _x+0, 1
;final.c,36 :: 		s1 = x % 10;
	MOVLW      10
	MOVWF      R4+0
	MOVF       _x+0, 0
	MOVWF      R0+0
	CALL       _Div_8X8_S+0
	MOVF       R8+0, 0
	MOVWF      R0+0
	MOVF       R0+0, 0
	MOVWF      _s1+0
;final.c,37 :: 		lcd1[1] = s1 + '0';
	MOVLW      48
	ADDWF      R0+0, 0
	MOVWF      _lcd1+1
;final.c,38 :: 		s2 = x / 10;
	MOVLW      10
	MOVWF      R4+0
	MOVF       _x+0, 0
	MOVWF      R0+0
	CALL       _Div_8X8_S+0
	MOVF       R0+0, 0
	MOVWF      _s2+0
;final.c,39 :: 		lcd1[0] = s2 + '0';
	MOVLW      48
	ADDWF      R0+0, 0
	MOVWF      _lcd1+0
;final.c,40 :: 		lcd_out(1,1,lcd1);
	MOVLW      1
	MOVWF      FARG_Lcd_Out_row+0
	MOVLW      1
	MOVWF      FARG_Lcd_Out_column+0
	MOVLW      _lcd1+0
	MOVWF      FARG_Lcd_Out_text+0
	CALL       _Lcd_Out+0
;final.c,41 :: 		s1 = s2 =0;
	CLRF       _s2+0
	CLRF       _s1+0
;final.c,42 :: 		delay_ms(500);
	MOVLW      6
	MOVWF      R11+0
	MOVLW      19
	MOVWF      R12+0
	MOVLW      173
	MOVWF      R13+0
L_in2:
	DECFSZ     R13+0, 1
	GOTO       L_in2
	DECFSZ     R12+0, 1
	GOTO       L_in2
	DECFSZ     R11+0, 1
	GOTO       L_in2
	NOP
	NOP
;final.c,43 :: 		}
L_end_in:
	RETURN
; end of _in

_fire:

;final.c,44 :: 		void fire(){
;final.c,45 :: 		portb.rb0 = portb.rb1 = portb.rb2 = 0;
	BCF        PORTB+0, 2
	BTFSC      PORTB+0, 2
	GOTO       L__fire34
	BCF        PORTB+0, 1
	GOTO       L__fire35
L__fire34:
	BSF        PORTB+0, 1
L__fire35:
	BTFSC      PORTB+0, 1
	GOTO       L__fire36
	BCF        PORTB+0, 0
	GOTO       L__fire37
L__fire36:
	BSF        PORTB+0, 0
L__fire37:
;final.c,46 :: 		while(1){
L_fire3:
;final.c,47 :: 		Lcd_Cmd(_LCD_CLEAR);
	MOVLW      1
	MOVWF      FARG_Lcd_Cmd_out_char+0
	CALL       _Lcd_Cmd+0
;final.c,48 :: 		Lcd_out(1,1,"Fire Detected");
	MOVLW      1
	MOVWF      FARG_Lcd_Out_row+0
	MOVLW      1
	MOVWF      FARG_Lcd_Out_column+0
	MOVLW      ?lstr2_final+0
	MOVWF      FARG_Lcd_Out_text+0
	CALL       _Lcd_Out+0
;final.c,49 :: 		Sound_Play(458, 250);
	MOVLW      202
	MOVWF      FARG_Sound_Play_freq_in_hz+0
	MOVLW      1
	MOVWF      FARG_Sound_Play_freq_in_hz+1
	MOVLW      250
	MOVWF      FARG_Sound_Play_duration_ms+0
	CLRF       FARG_Sound_Play_duration_ms+1
	CALL       _Sound_Play+0
;final.c,50 :: 		Sound_Play(356, 250);
	MOVLW      100
	MOVWF      FARG_Sound_Play_freq_in_hz+0
	MOVLW      1
	MOVWF      FARG_Sound_Play_freq_in_hz+1
	MOVLW      250
	MOVWF      FARG_Sound_Play_duration_ms+0
	CLRF       FARG_Sound_Play_duration_ms+1
	CALL       _Sound_Play+0
;final.c,51 :: 		if (porta.ra5){
	BTFSS      PORTA+0, 5
	GOTO       L_fire5
;final.c,52 :: 		lcd_cmd(_lcd_clear);
	MOVLW      1
	MOVWF      FARG_Lcd_Cmd_out_char+0
	CALL       _Lcd_Cmd+0
;final.c,53 :: 		lcd_out(1,1,"TEMP:     STATUS");
	MOVLW      1
	MOVWF      FARG_Lcd_Out_row+0
	MOVLW      1
	MOVWF      FARG_Lcd_Out_column+0
	MOVLW      ?lstr3_final+0
	MOVWF      FARG_Lcd_Out_text+0
	CALL       _Lcd_Out+0
;final.c,54 :: 		delay_ms(10);
	MOVLW      26
	MOVWF      R12+0
	MOVLW      248
	MOVWF      R13+0
L_fire6:
	DECFSZ     R13+0, 1
	GOTO       L_fire6
	DECFSZ     R12+0, 1
	GOTO       L_fire6
	NOP
;final.c,55 :: 		lcd_out(2,1,"PRESENCE:");
	MOVLW      2
	MOVWF      FARG_Lcd_Out_row+0
	MOVLW      1
	MOVWF      FARG_Lcd_Out_column+0
	MOVLW      ?lstr4_final+0
	MOVWF      FARG_Lcd_Out_text+0
	CALL       _Lcd_Out+0
;final.c,56 :: 		lcd_out(2,10,lcd2);
	MOVLW      2
	MOVWF      FARG_Lcd_Out_row+0
	MOVLW      10
	MOVWF      FARG_Lcd_Out_column+0
	MOVLW      _lcd2+0
	MOVWF      FARG_Lcd_Out_text+0
	CALL       _Lcd_Out+0
;final.c,57 :: 		break;
	GOTO       L_fire4
;final.c,58 :: 		}
L_fire5:
;final.c,59 :: 		}
	GOTO       L_fire3
L_fire4:
;final.c,60 :: 		}
L_end_fire:
	RETURN
; end of _fire

_temp:

;final.c,61 :: 		void temp(){
;final.c,62 :: 		t = ADC_Read(0);
	CLRF       FARG_ADC_Read_channel+0
	CALL       _ADC_Read+0
	MOVF       R0+0, 0
	MOVWF      _t+0
	MOVF       R0+1, 0
	MOVWF      _t+1
;final.c,63 :: 		t = t * 0.4882;
	CALL       _word2double+0
	MOVLW      90
	MOVWF      R4+0
	MOVLW      245
	MOVWF      R4+1
	MOVLW      121
	MOVWF      R4+2
	MOVLW      125
	MOVWF      R4+3
	CALL       _Mul_32x32_FP+0
	CALL       _double2word+0
	MOVF       R0+0, 0
	MOVWF      FLOC__temp+0
	MOVF       R0+1, 0
	MOVWF      FLOC__temp+1
	MOVF       FLOC__temp+0, 0
	MOVWF      _t+0
	MOVF       FLOC__temp+1, 0
	MOVWF      _t+1
;final.c,64 :: 		a = t/10;
	MOVLW      10
	MOVWF      R4+0
	MOVLW      0
	MOVWF      R4+1
	MOVF       FLOC__temp+0, 0
	MOVWF      R0+0
	MOVF       FLOC__temp+1, 0
	MOVWF      R0+1
	CALL       _Div_16X16_U+0
	MOVF       R0+0, 0
	MOVWF      _a+0
;final.c,65 :: 		lcd1[0] = a + '0';
	MOVLW      48
	ADDWF      R0+0, 0
	MOVWF      _lcd1+0
;final.c,66 :: 		a = t%10;
	MOVLW      10
	MOVWF      R4+0
	MOVLW      0
	MOVWF      R4+1
	MOVF       FLOC__temp+0, 0
	MOVWF      R0+0
	MOVF       FLOC__temp+1, 0
	MOVWF      R0+1
	CALL       _Div_16X16_U+0
	MOVF       R8+0, 0
	MOVWF      R0+0
	MOVF       R8+1, 0
	MOVWF      R0+1
	MOVF       R0+0, 0
	MOVWF      _a+0
;final.c,67 :: 		lcd1[1] = a + '0';
	MOVLW      48
	ADDWF      R0+0, 0
	MOVWF      _lcd1+1
;final.c,68 :: 		delay_ms(10);
	MOVLW      26
	MOVWF      R12+0
	MOVLW      248
	MOVWF      R13+0
L_temp7:
	DECFSZ     R13+0, 1
	GOTO       L_temp7
	DECFSZ     R12+0, 1
	GOTO       L_temp7
	NOP
;final.c,69 :: 		Lcd_out(1,6,lcd1);
	MOVLW      1
	MOVWF      FARG_Lcd_Out_row+0
	MOVLW      6
	MOVWF      FARG_Lcd_Out_column+0
	MOVLW      _lcd1+0
	MOVWF      FARG_Lcd_Out_text+0
	CALL       _Lcd_Out+0
;final.c,70 :: 		Lcd_chr(1,8,0xdf);
	MOVLW      1
	MOVWF      FARG_Lcd_Chr_row+0
	MOVLW      8
	MOVWF      FARG_Lcd_Chr_column+0
	MOVLW      223
	MOVWF      FARG_Lcd_Chr_out_char+0
	CALL       _Lcd_Chr+0
;final.c,71 :: 		if (t>=30){
	MOVLW      0
	SUBWF      _t+1, 0
	BTFSS      STATUS+0, 2
	GOTO       L__temp39
	MOVLW      30
	SUBWF      _t+0, 0
L__temp39:
	BTFSS      STATUS+0, 0
	GOTO       L_temp8
;final.c,72 :: 		portb.f1 = 0;
	BCF        PORTB+0, 1
;final.c,73 :: 		lcd_out(2,14," ");
	MOVLW      2
	MOVWF      FARG_Lcd_Out_row+0
	MOVLW      14
	MOVWF      FARG_Lcd_Out_column+0
	MOVLW      ?lstr5_final+0
	MOVWF      FARG_Lcd_Out_text+0
	CALL       _Lcd_Out+0
;final.c,74 :: 		delay_ms(10);
	MOVLW      26
	MOVWF      R12+0
	MOVLW      248
	MOVWF      R13+0
L_temp9:
	DECFSZ     R13+0, 1
	GOTO       L_temp9
	DECFSZ     R12+0, 1
	GOTO       L_temp9
	NOP
;final.c,75 :: 		portb.f2 = 1;
	BSF        PORTB+0, 2
;final.c,76 :: 		lcd_out(2,15,"A");
	MOVLW      2
	MOVWF      FARG_Lcd_Out_row+0
	MOVLW      15
	MOVWF      FARG_Lcd_Out_column+0
	MOVLW      ?lstr6_final+0
	MOVWF      FARG_Lcd_Out_text+0
	CALL       _Lcd_Out+0
;final.c,77 :: 		}
	GOTO       L_temp10
L_temp8:
;final.c,78 :: 		else if (t>=25 && t<=29){
	MOVLW      0
	SUBWF      _t+1, 0
	BTFSS      STATUS+0, 2
	GOTO       L__temp40
	MOVLW      25
	SUBWF      _t+0, 0
L__temp40:
	BTFSS      STATUS+0, 0
	GOTO       L_temp13
	MOVF       _t+1, 0
	SUBLW      0
	BTFSS      STATUS+0, 2
	GOTO       L__temp41
	MOVF       _t+0, 0
	SUBLW      29
L__temp41:
	BTFSS      STATUS+0, 0
	GOTO       L_temp13
L__temp30:
;final.c,79 :: 		portb.f1 = 1;
	BSF        PORTB+0, 1
;final.c,80 :: 		lcd_out(2,14,"F");
	MOVLW      2
	MOVWF      FARG_Lcd_Out_row+0
	MOVLW      14
	MOVWF      FARG_Lcd_Out_column+0
	MOVLW      ?lstr7_final+0
	MOVWF      FARG_Lcd_Out_text+0
	CALL       _Lcd_Out+0
;final.c,81 :: 		delay_ms(10);
	MOVLW      26
	MOVWF      R12+0
	MOVLW      248
	MOVWF      R13+0
L_temp14:
	DECFSZ     R13+0, 1
	GOTO       L_temp14
	DECFSZ     R12+0, 1
	GOTO       L_temp14
	NOP
;final.c,82 :: 		portb.f2 = 0;
	BCF        PORTB+0, 2
;final.c,83 :: 		lcd_out(2,15," ");
	MOVLW      2
	MOVWF      FARG_Lcd_Out_row+0
	MOVLW      15
	MOVWF      FARG_Lcd_Out_column+0
	MOVLW      ?lstr8_final+0
	MOVWF      FARG_Lcd_Out_text+0
	CALL       _Lcd_Out+0
;final.c,84 :: 		}
	GOTO       L_temp15
L_temp13:
;final.c,86 :: 		portb.f1 = 0;
	BCF        PORTB+0, 1
;final.c,87 :: 		lcd_out(2,15," ");
	MOVLW      2
	MOVWF      FARG_Lcd_Out_row+0
	MOVLW      15
	MOVWF      FARG_Lcd_Out_column+0
	MOVLW      ?lstr9_final+0
	MOVWF      FARG_Lcd_Out_text+0
	CALL       _Lcd_Out+0
;final.c,88 :: 		delay_ms(10);
	MOVLW      26
	MOVWF      R12+0
	MOVLW      248
	MOVWF      R13+0
L_temp16:
	DECFSZ     R13+0, 1
	GOTO       L_temp16
	DECFSZ     R12+0, 1
	GOTO       L_temp16
	NOP
;final.c,89 :: 		portb.f2 = 0;
	BCF        PORTB+0, 2
;final.c,90 :: 		lcd_out(2,14," ");
	MOVLW      2
	MOVWF      FARG_Lcd_Out_row+0
	MOVLW      14
	MOVWF      FARG_Lcd_Out_column+0
	MOVLW      ?lstr10_final+0
	MOVWF      FARG_Lcd_Out_text+0
	CALL       _Lcd_Out+0
;final.c,91 :: 		}
L_temp15:
L_temp10:
;final.c,92 :: 		}
L_end_temp:
	RETURN
; end of _temp

_main:

;final.c,93 :: 		void main(){
;final.c,94 :: 		trisa = 0x3f;
	MOVLW      63
	MOVWF      TRISA+0
;final.c,95 :: 		trisb = 0x00;
	CLRF       TRISB+0
;final.c,96 :: 		adcon1 = 0x8e;
	MOVLW      142
	MOVWF      ADCON1+0
;final.c,97 :: 		portb = 0x00;
	CLRF       PORTB+0
;final.c,98 :: 		Lcd_Init();
	CALL       _Lcd_Init+0
;final.c,99 :: 		adc_init();
	CALL       _ADC_Init+0
;final.c,100 :: 		sound_init(&portb,7);
	MOVLW      PORTB+0
	MOVWF      FARG_Sound_Init_snd_port+0
	MOVLW      7
	MOVWF      FARG_Sound_Init_snd_pin+0
	CALL       _Sound_Init+0
;final.c,101 :: 		Lcd_Cmd(_LCD_CURSOR_OFF);
	MOVLW      12
	MOVWF      FARG_Lcd_Cmd_out_char+0
	CALL       _Lcd_Cmd+0
;final.c,102 :: 		Lcd_Cmd(_LCD_CLEAR);
	MOVLW      1
	MOVWF      FARG_Lcd_Cmd_out_char+0
	CALL       _Lcd_Cmd+0
;final.c,103 :: 		lcd_out(1,1,"SMART HOME");
	MOVLW      1
	MOVWF      FARG_Lcd_Out_row+0
	MOVLW      1
	MOVWF      FARG_Lcd_Out_column+0
	MOVLW      ?lstr11_final+0
	MOVWF      FARG_Lcd_Out_text+0
	CALL       _Lcd_Out+0
;final.c,104 :: 		delay_ms(200);
	MOVLW      3
	MOVWF      R11+0
	MOVLW      8
	MOVWF      R12+0
	MOVLW      119
	MOVWF      R13+0
L_main17:
	DECFSZ     R13+0, 1
	GOTO       L_main17
	DECFSZ     R12+0, 1
	GOTO       L_main17
	DECFSZ     R11+0, 1
	GOTO       L_main17
;final.c,105 :: 		lcd_out(2,1,"INITIALIZING");
	MOVLW      2
	MOVWF      FARG_Lcd_Out_row+0
	MOVLW      1
	MOVWF      FARG_Lcd_Out_column+0
	MOVLW      ?lstr12_final+0
	MOVWF      FARG_Lcd_Out_text+0
	CALL       _Lcd_Out+0
;final.c,106 :: 		delay_ms(1000);
	MOVLW      11
	MOVWF      R11+0
	MOVLW      38
	MOVWF      R12+0
	MOVLW      93
	MOVWF      R13+0
L_main18:
	DECFSZ     R13+0, 1
	GOTO       L_main18
	DECFSZ     R12+0, 1
	GOTO       L_main18
	DECFSZ     R11+0, 1
	GOTO       L_main18
	NOP
	NOP
;final.c,107 :: 		Lcd_Cmd(_LCD_CLEAR);
	MOVLW      1
	MOVWF      FARG_Lcd_Cmd_out_char+0
	CALL       _Lcd_Cmd+0
;final.c,108 :: 		lcd_out(1,1,"TEMP:     STATUS");
	MOVLW      1
	MOVWF      FARG_Lcd_Out_row+0
	MOVLW      1
	MOVWF      FARG_Lcd_Out_column+0
	MOVLW      ?lstr13_final+0
	MOVWF      FARG_Lcd_Out_text+0
	CALL       _Lcd_Out+0
;final.c,109 :: 		delay_ms(10);
	MOVLW      26
	MOVWF      R12+0
	MOVLW      248
	MOVWF      R13+0
L_main19:
	DECFSZ     R13+0, 1
	GOTO       L_main19
	DECFSZ     R12+0, 1
	GOTO       L_main19
	NOP
;final.c,110 :: 		lcd_out(2,1,"PRESENCE:");
	MOVLW      2
	MOVWF      FARG_Lcd_Out_row+0
	MOVLW      1
	MOVWF      FARG_Lcd_Out_column+0
	MOVLW      ?lstr14_final+0
	MOVWF      FARG_Lcd_Out_text+0
	CALL       _Lcd_Out+0
;final.c,111 :: 		lcd_out(2,10,lcd2);
	MOVLW      2
	MOVWF      FARG_Lcd_Out_row+0
	MOVLW      10
	MOVWF      FARG_Lcd_Out_column+0
	MOVLW      _lcd2+0
	MOVWF      FARG_Lcd_Out_text+0
	CALL       _Lcd_Out+0
;final.c,112 :: 		while(1){
L_main20:
;final.c,113 :: 		temp ();
	CALL       _temp+0
;final.c,114 :: 		if (porta.f1)
	BTFSS      PORTA+0, 1
	GOTO       L_main22
;final.c,115 :: 		in();
	CALL       _in+0
L_main22:
;final.c,116 :: 		if (porta.f2)
	BTFSS      PORTA+0, 2
	GOTO       L_main23
;final.c,117 :: 		out();
	CALL       _out+0
L_main23:
;final.c,118 :: 		if (!porta.ra4)
	BTFSC      PORTA+0, 4
	GOTO       L_main24
;final.c,119 :: 		fire();
	CALL       _fire+0
L_main24:
;final.c,120 :: 		if(!porta.ra3){
	BTFSC      PORTA+0, 3
	GOTO       L_main25
;final.c,121 :: 		portb.rb0 = 1;
	BSF        PORTB+0, 0
;final.c,122 :: 		delay_ms(10);
	MOVLW      26
	MOVWF      R12+0
	MOVLW      248
	MOVWF      R13+0
L_main26:
	DECFSZ     R13+0, 1
	GOTO       L_main26
	DECFSZ     R12+0, 1
	GOTO       L_main26
	NOP
;final.c,123 :: 		lcd_out(2,16,"L");
	MOVLW      2
	MOVWF      FARG_Lcd_Out_row+0
	MOVLW      16
	MOVWF      FARG_Lcd_Out_column+0
	MOVLW      ?lstr15_final+0
	MOVWF      FARG_Lcd_Out_text+0
	CALL       _Lcd_Out+0
;final.c,124 :: 		}
	GOTO       L_main27
L_main25:
;final.c,126 :: 		portb.rb0 = 0;
	BCF        PORTB+0, 0
;final.c,127 :: 		delay_ms(10);
	MOVLW      26
	MOVWF      R12+0
	MOVLW      248
	MOVWF      R13+0
L_main28:
	DECFSZ     R13+0, 1
	GOTO       L_main28
	DECFSZ     R12+0, 1
	GOTO       L_main28
	NOP
;final.c,128 :: 		lcd_out(2,16," ");
	MOVLW      2
	MOVWF      FARG_Lcd_Out_row+0
	MOVLW      16
	MOVWF      FARG_Lcd_Out_column+0
	MOVLW      ?lstr16_final+0
	MOVWF      FARG_Lcd_Out_text+0
	CALL       _Lcd_Out+0
;final.c,129 :: 		}
L_main27:
;final.c,131 :: 		delay_ms(100);
	MOVLW      2
	MOVWF      R11+0
	MOVLW      4
	MOVWF      R12+0
	MOVLW      186
	MOVWF      R13+0
L_main29:
	DECFSZ     R13+0, 1
	GOTO       L_main29
	DECFSZ     R12+0, 1
	GOTO       L_main29
	DECFSZ     R11+0, 1
	GOTO       L_main29
	NOP
;final.c,132 :: 		}
	GOTO       L_main20
;final.c,133 :: 		}
L_end_main:
	GOTO       $+0
; end of _main
