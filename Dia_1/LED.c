#include <16F1937.h> 
#FUSES NOWDT //No Watch Dog Timer 
#use delay(clock=4000000) 
#use standard_io(B) 
#define LED pin_b0
void main() 
{ 
set_tris_b(0b00001111); 
while(true){ 
if(input(pin_b4)==1) 
  output_high(LED); 
else 
  output_low(LED); 
} 
}  
