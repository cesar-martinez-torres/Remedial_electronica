#include <16f1937.h>
#device adc=10
#fuses hs,nowdt
#use delay(clock=4M)
#define lcd_rs_pin pin_b0
#define lcd_rw_pin pin_b1
#define lcd_enable_pin pin_b2
#define lcd_data4 pin_b4
#define lcd_data5 pin_b5
#define lcd_data6 pin_b6
#define lcd_data7 pin_b7
#include <lcd.c>
void main()
{
   int16 q;
   setup_adc_ports(ALL_ANALOG);
   setup_adc(adc_clock_internal);
   lcd_init();
   while(true)
   {
      set_adc_channel(0);
      delay_us(20);
      lcd_gotoxy(1,2);
      q=read_adc();
      printf(lcd_putc," ADC = %4Ld",q);
     
   }
}