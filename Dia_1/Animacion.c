#include <16f1937.h>
#fuses XT, NOPROTECT, NOWRT, NOPUT, NOWDT, NOLVP, NOCPD //Órdenes para el programador
#use delay (clock=4000000)

#include <flex_lcd.c>
#define LCD_POWER  PIN_D7
//#include <lcd.c>  // Librería para el manejo del lcd              

///DECLARACION DE FUNCIONES
void recarga(void);      //funcion que crea el nuevo caracter

///DECLARACION DE VARIABLES GLOBALES
char cont=0;      //contador que apunta al nuevo caracter diseñado
   int8    bat0[]={0b00001110,0b00001010,0b00010001,0b00010001,0b00010001,0b000010001,0b00010001,0b00011111},
bat20[]={0b00001110,0b00001010,0b00010001,0b00010001,0b00010001,0b00010001,0b00011111,0b00011111},
bat40[]={0b00001110,0b00001010,0b00010001,0b00010001,0b00010001,0b00011111,0b00011111,0b00011111},
bat60[]={0b00001110,0b00001010,0b00010001,0b00010001,0b00011111,0b00011111,0b00011111,0b00011111},
bat80[]={0b00001110,0b00001010,0b00010001,0b00011111,0b00011111,0b00011111,0b00011111,0b00011111},
bat100[]={0b00001110,0b00001010,0b00011111,0b00011111,0b00011111,0b00011111,0b00011111,0b00011111};  
void main(void)
{
    output_high(LCD_POWER);  // Turn on power to LCD
    output_low(LCD_RW);      // Set R/W pin on LCD to a low level
   
   lcd_init();       //inicializa lcd

   recarga();         //crea 1 animacion
   
   lcd_gotoxy(5,1);   //presentacion...
   lcd_putc("CARGANDO");

   
   for( ; ; ){   //bucle...
      lcd_gotoxy(2,1);      //donde se va a mostrar la animacion de la bateria
      lcd_send_byte(1,0);    //muestra animacion
      delay_ms(25);         
      cont++;               //apunta a siguiente animacion
      recarga();            //crea animacion
         }   //...infinito
}
///FUNCION ENCARGADA DE CREAR ANIMACION
void recarga(void){
   char i;      //indice para for
   
   lcd_send_byte(0,0x40); // se escribe en la GCRAM posicion 0x40
   
   switch(cont){   //selecciona animacion
      case 0: for(i=0;i<8;i++)   //bateria al 0%
               lcd_send_byte(1,bat0[ i ]);
               lcd_gotoxy(5,2);
               printf(LCD_PUTC, "0 PORCIENTO   ");  
				delay_ms(5000);
              
            break;
      case 1: for(i=0;i<8;i++)   //bateria al 20%
               lcd_send_byte(1,bat20[ i ]); 
               lcd_gotoxy(4,2);
               printf(LCD_PUTC, "20 PORCIENTO   "); 
				delay_ms(5000);
            break;
      case 2: for(i=0;i<8;i++)   //bateria al 40%
               lcd_send_byte(1,bat40[ i ]);
               lcd_gotoxy(4,2);
               printf(LCD_PUTC, "40 PORCIENTO   "); 
				delay_ms(5000); 
            break;
      case 3: for(i=0;i<8;i++)   //bateria al 60%
               lcd_send_byte(1,bat60[ i ]);
               lcd_gotoxy(4,2);
               printf(LCD_PUTC, "6O PORCIENTO   ");  
				delay_ms(5000);
            break;
      case 4: for(i=0;i<8;i++)   //bateria al 80%
               lcd_send_byte(1,bat80[ i ]);
               lcd_gotoxy(4,2);
               printf(LCD_PUTC, "80 PORCIENTO   "); 
				delay_ms(5000); 
            break;
      case 5: for(i=0;i<8;i++)   //bateria al 100%
               lcd_send_byte(1,bat100[ i ]);
               lcd_gotoxy(4,2);
               printf(LCD_PUTC, "100 PORCIENTO   "); 
				delay_ms(5000); 
               cont=0;         //restaura indice de crear animacion 
         }
}         