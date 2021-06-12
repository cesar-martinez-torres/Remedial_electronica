#include <16F1937.h> 
#FUSES NOWDT //No Watch Dog Timer 
#use delay(clock=4000000) 
#use standard_io(B) 
// 0= Salida; 1=Entrada
#define LED pin_b1
void main() 
{ 
set_tris_b(0b00000001); 
while(true){ 
if(input(pin_b0)==1) 
  output_high(LED); 
else 
  output_low(LED); 
} 
}  
