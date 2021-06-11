#INCLUDE <16F1937.h>
#USE  DELAY  (crystal=4000000)
#FUSES XT,NOWDT,PUT,NOLVP,NOBROWNOUT,NOWRT,NOPROTECT
#use standard_io(c)
void main()
{
setup_timer_2(t2_div_by_4,249,1); //Setup para PWM 1KHz
setup_ccp1(ccp_pwm); 
      while(1){
      set_pwm1_duty(200); //PWM dut cycle
}   
}
