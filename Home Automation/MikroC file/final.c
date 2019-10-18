sbit LCD_RS at Rc2_bit;
sbit LCD_EN at Rc3_bit;
sbit LCD_D4 at Rc4_bit;
sbit LCD_D5 at Rc5_bit;
sbit LCD_D6 at Rc6_bit;
sbit LCD_D7 at Rc7_bit;
sbit LCD_RS_Direction at TRISc2_bit;
sbit LCD_EN_Direction at TRISc3_bit;
sbit LCD_D4_Direction at TRISc4_bit;
sbit LCD_D5_Direction at TRISc5_bit;
sbit LCD_D6_Direction at TRISc6_bit;
sbit LCD_D7_Direction at TRISc7_bit;

unsigned char lcd1[] = "00 C", lcd2[] = "00", a, s1, s2;
signed char x=0;
unsigned int t;

void out(){
     x--;
     if (x<0){
        x=0;
        portb = 0x00;
        lcd_out(2,14,"   ");
     }
     s1 = x % 10;
     lcd1[1] = s1 + '0';
     s2 = x / 10;
     lcd1[0] = s2 + '0';
     lcd_out(1,1,lcd1);
     s1 = s2 =0;
     delay_ms(500);
}
void in(){

                            x++;
                            s1 = x % 10;
                            lcd1[1] = s1 + '0';
                            s2 = x / 10;
                            lcd1[0] = s2 + '0';
                            lcd_out(1,1,lcd1);
                            s1 = s2 =0;
                            delay_ms(500);
           }
void fire(){
     portb.rb0 = portb.rb1 = portb.rb2 = 0;
             while(1){
                    Lcd_Cmd(_LCD_CLEAR);
                    Lcd_out(1,1,"Fire Detected");
                    Sound_Play(458, 250);
                    Sound_Play(356, 250);
                    if (porta.ra5){
                       lcd_cmd(_lcd_clear);
                       lcd_out(1,1,"TEMP:     STATUS");
                       delay_ms(10);
                       lcd_out(2,1,"PRESENCE:");
                       lcd_out(2,10,lcd2);
                       break;
                    }
             }
}
void temp(){
     t = ADC_Read(0);
        t = t * 0.4882;
        a = t/10;
        lcd1[0] = a + '0';
        a = t%10;
        lcd1[1] = a + '0';
        delay_ms(10);
        Lcd_out(1,6,lcd1);
        Lcd_chr(1,8,0xdf);
        if (t>=30){
                portb.f1 = 0;
                lcd_out(2,14," ");
                delay_ms(10);
                portb.f2 = 1;
                lcd_out(2,15,"A");
            }
            else if (t>=25 && t<=29){
                 portb.f1 = 1;
                 lcd_out(2,14,"F");
                 delay_ms(10);
                 portb.f2 = 0;
                 lcd_out(2,15," ");
            }
            else {
                 portb.f1 = 0;
                 lcd_out(2,15," ");
                 delay_ms(10);
                 portb.f2 = 0;
                 lcd_out(2,14," ");
            }
}
void main(){
     trisa = 0x3f;
     trisb = 0x00;
     adcon1 = 0x8e;
     portb = 0x00;
     Lcd_Init();
     adc_init();
     sound_init(&portb,7);
     Lcd_Cmd(_LCD_CURSOR_OFF);
     Lcd_Cmd(_LCD_CLEAR);
     lcd_out(1,1,"SMART HOME");
     delay_ms(200);
     lcd_out(2,1,"INITIALIZING");
     delay_ms(1000);
     Lcd_Cmd(_LCD_CLEAR);
     lcd_out(1,1,"TEMP:     STATUS");
     delay_ms(10);
     lcd_out(2,1,"PRESENCE:");
     lcd_out(2,10,lcd2);
     while(1){
        temp ();
        if (porta.f1)
           in();
        if (porta.f2)
           out();
        if (!porta.ra4)
           fire();
        if(!porta.ra3){
                portb.rb0 = 1;
                delay_ms(10);
                lcd_out(2,16,"L");
        }
            else {
                portb.rb0 = 0;
                delay_ms(10);
                lcd_out(2,16," ");
            }

         delay_ms(100);
     }
}