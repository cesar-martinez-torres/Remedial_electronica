#include <16f1937.h>
#fuses XT, NOPROTECT, NOWRT, NOPUT, NOWDT, NOLVP, NOCPD //Órdenes para el programador
#use delay (clock=4000000)

#include <flex_lcd.c>
#define LCD_POWER  PIN_D7
//#include <lcd.c>  // Librería para el manejo del lcd              

const char linea1[]= {"Practica LCD"};
const char linea2[]= {"Mesa 2"};
void main(void)
{
    output_high(LCD_POWER);  // Turn on power to LCD
    output_low(LCD_RW);      // Set R/W pin on LCD to a low level
   lcd_init(); //inicializa lcd 

   while(TRUE){ //bucle...
      lcd_gotoxy(1,1) ; //ubica cursor para escribir mensaje
      lcd_putc(linea1) ; //muestra por pantalla el mensaje
      delay_ms(200);
      lcd_gotoxy(1,2);
      lcd_putc(linea2);
   } //...infinito

}