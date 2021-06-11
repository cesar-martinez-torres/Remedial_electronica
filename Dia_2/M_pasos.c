#INCLUDE <16f1937.h>
#fuses XT,NOPROTECT,NOWDT,NOBROWNOUT,PUT,NOLVP,WRT
#use delay(crystal=4000000)
#BYTE TRISB = 0x8D            
#BYTE PORTB = 0x0D            
#BYTE TRISC = 0x8E            
#BYTE PORTC = 0x0E            
#define SW PORTC,0
 
//!INT CONT;
//!byte const HORARIO[4] = {  0b1100,
//!                           0b0110,
//!                           0b0011,
//!                           0b1001};
//!                           
//!byte const ANTIH[4] ={     0b1001,
//!                           0b0011,
//!                           0b0110,
//!                           0b1100};
                           
void main()
{
   TRISB=(0B00000000);                
   WHILE(TRUE)
   {
//!    PORTB=0b00001001; //Sentido contrario a las manecillas del reloj (-)
//!    delay_ms(1000);
//!    PORTB=0b00000011;
//!    delay_ms(1000);
//!    PORTB=0b00000110;
//!    delay_ms(1000);
//!    PORTB=0b00001100;
//!    delay_ms(5000);
//!    PORTB=0b00001100; // sentido de las manecillas del reloj (+)
//!    delay_ms(1000);
//!    PORTB=0b00000110;
//!    delay_ms(1000);
//!    PORTB=0b00000011;
//!    delay_ms(1000);
//!    PORTB=0b00001001;
//!    delay_ms(1000);
//!     PORTB=0b1100; // sentido de las manecillas del reloj (+)
//!    delay_ms(1000);
//!    PORTB=0b0110;
//!    delay_ms(1000);
//!    PORTB=0b0011;
//!    delay_ms(1000);
//!    PORTB=0b1001;
    delay_ms(1000);   
    PORTB=0b1000; 
    delay_ms(3000);
    PORTB=0b1100;
    delay_ms(3000);
    PORTB=0b0100;
    delay_ms(3000);
    PORTB=0b0110;
    delay_ms(3000);   
    PORTB=0b0010; 
    delay_ms(3000);
    PORTB=0b0011;
    delay_ms(3000);
    PORTB=0b0001;
    delay_ms(3000);
    PORTB=0b1001;
    delay_ms(3000);   
   }
}
