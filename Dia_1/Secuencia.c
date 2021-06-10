#include <16F1937.h> 
#FUSES NOWDT //No Watch Dog Timer 
#use delay(clock=4000000) 
#use standard_io(B)
 void main ( void )
 {
 while(true) {
    output_high ( PIN_B0 );
    delay_ms ( 200 );
	output_low ( PIN_B0 );
    output_high ( PIN_B1 );
    delay_ms ( 200 );
    output_low ( PIN_B1 );
    output_high ( PIN_B2 );
    delay_ms ( 200 );
    output_low ( PIN_B2 );
    output_high ( PIN_B3 );
    delay_ms ( 200 );
    output_low ( PIN_B3 );
    output_high ( PIN_B2 );
    delay_ms ( 200 );
    output_low ( PIN_B2 );
    output_high ( PIN_B1 );
    delay_ms ( 200 ); 
    output_low ( PIN_B1 );
    output_high ( PIN_B0 );
    delay_ms ( 200 );
    output_low ( PIN_B0 );
}
}
