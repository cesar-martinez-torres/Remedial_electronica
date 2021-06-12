#include <16F1937.h> 
#FUSES NOWDT //No Watch Dog Timer 
#use delay(clock=4000000) 
#use standard_io(B) 
#define LED pin_b1
void main() 
{ 
set_tris_b(0b11110000); 
set_tris_b(0b11110000); 
while(true){ 
if(input(pin_b4)==1 && input(pin_b5)==1) 
  output_low(LED); 
else 
  output_high(LED); 
} 
}  
