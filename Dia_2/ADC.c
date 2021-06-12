#include <16f1937.h>
#fuses XT, NOPROTECT, NOWRT, NOPUT, NOWDT, NOLVP, NOCPD //Órdenes para el programador
#use delay (clock=4000000)

#include <flex_lcd.c>
#define LCD_POWER  PIN_D7
//#include <lcd.c>  // Librería para el manejo del lcd              

void main(void)
{
    output_high(LCD_POWER);  // Turn on power to LCD
    output_low(LCD_RW);      // Set R/W pin on LCD to a low level
     int16 q;
   setup_adc_ports(ALL_ANALOG);
   setup_adc(adc_clock_internal);
   lcd_init(); //inicializa lcd 

   while(TRUE){ //bucle...
      set_adc_channel(0);
      delay_us(20);
      lcd_gotoxy(1,1);
      q=read_adc();
      printf(lcd_putc," ADC = %4Ld",q);
   } //...infinito

}