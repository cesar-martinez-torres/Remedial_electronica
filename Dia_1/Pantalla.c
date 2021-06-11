#include <16f1937.h>
#fuses XT,NOWDT
#use delay (crystal=4000000)
#use standard_io(D)
#use standard_io(A)
//LCD module connectrions
#define lcd_DATA4      PIN_D4 //pin de la lcd
#define lcd_DATA5      PIN_D5 //pin de la lcd
#define lcd_DATA6      PIN_D6 //pin de la lcd
#define lcd_DATA7      PIN_D7 //pin de la lcd
#define lcd_enable_pin pin_d3 //pin de la lcd
#define lcd_rs_pin pin_d0 //pin de la lcd
#define lcd_rw_pin pin_d1 //pin de la lcd
#include <lcd.c> //incluir libreria de la lcd
INT32 I1,I2;
int M;
//I1 = PRIMER ID  y  I2 = SEGUNDO ID
// ID=150000 | ID=150001 | MESA1
// ID=150002 | ID=150003 | MESA2
// ID=150004 | ID=150005 | MESA3
// ID=150006 | ID=150007 | MESA4
// ID=150008 | ID=150009 | MESA5
// ID=150010 | ID=150011 | MESA6
// ID=150012 | ID=150013 | MESA7
// ID=150014 | ID=150015 | MESA8
// ID=150016 | ID=150017 | MESA9
void main()
{
lcd_init();
   while (true){
I1=150002; //cambiar ID para cambiar MESA
I2=150003; //cambiar ID para cambiar MESA
	switch(1){
		case 1:
			if (I1==150000 && I2==150001){
				M=1;
			      lcd_gotoxy(1,1);
			      Printf(lcd_putc,"%lu|%lu",I1,I2);
			      lcd_gotoxy(1,2);
			      Printf(lcd_putc,"MESA=%i",M);
			}
		case 2:
			if (I1==150002 && I2==150003){
				M=2;
			      lcd_gotoxy(1,1);
			      Printf(lcd_putc,"%lu|%lu",I1,I2);
			      lcd_gotoxy(1,2);
			      Printf(lcd_putc,"MESA=%i",M);
			}
		case 3:
			if (I1==150004 && I2==150005){
				M=3;
			      lcd_gotoxy(1,1);
			      Printf(lcd_putc,"%lu|%lu",I1,I2);
			      lcd_gotoxy(1,2);
			      Printf(lcd_putc,"MESA=%i",M);
			}
		case 4:
			if (I1==150006 && I2==150007){
				M=4;
			      lcd_gotoxy(1,1);
			      Printf(lcd_putc,"%lu|%lu",I1,I2);
			      lcd_gotoxy(1,2);
			      Printf(lcd_putc,"MESA=%i",M);
			}
		case 5:
			if (I1==150008 && I2==150009){
				M=5;
			      lcd_gotoxy(1,1);
			      Printf(lcd_putc,"%lu|%lu",I1,I2);
			      lcd_gotoxy(1,2);
			      Printf(lcd_putc,"MESA=%i",M);
			}
		case 6:
			if (I1==150010 && I2==150011){
				M=6;
			      lcd_gotoxy(1,1);
			      Printf(lcd_putc,"%lu|%lu",I1,I2);
			      lcd_gotoxy(1,2);
			      Printf(lcd_putc,"MESA=%i",M);
			}
		case 7:
			if (I1==150012 && I2==150013){
				M=7;
			      lcd_gotoxy(1,1);
			      Printf(lcd_putc,"%lu|%lu",I1,I2);
			      lcd_gotoxy(1,2);
			      Printf(lcd_putc,"MESA=%i",M);
			}
		case 8:
			if (I1==150014 && I2==150015){
				M=8;
			      lcd_gotoxy(1,1);
			      Printf(lcd_putc,"%lu|%lu",I1,I2);
			      lcd_gotoxy(1,2);
			      Printf(lcd_putc,"MESA=%i",M);
			}
		case 9:
			if (I1==150016 && I2==150017){
				M=9;
			      lcd_gotoxy(1,1);
			      Printf(lcd_putc,"%lu|%lu",I1,I2);
			      lcd_gotoxy(1,2);
			      Printf(lcd_putc,"MESA=%i",M);
			}
     }
   }
}