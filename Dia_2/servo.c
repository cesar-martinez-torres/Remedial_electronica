#INCLUDE <16F1937.H>
#FUSES XT, NOWDT, NOLVP
#USE DELAY(CLOCK=400000)


#USE STANDARD_IO(D)
// Naranja - pulso; Rojo - VCC; Café - GND

void main()
{
output_low(pin_D2);
delay_ms(4000);
int i; 
while(true)
{
for(i=0;i<60;i++)
{
//MOVER A 0 GRADOS
output_high(PIN_D2);
delay_us(2000);
output_low(PIN_D2);
delay_ms(20);
}
delay_ms(3000);
for(i=0;i<60;i++)
{
//Mover a 58 grados?
output_high(PIN_D2);
delay_us(1322);
output_low(PIN_D2);
delay_ms(20);
}



}
}
