#include "project.h"
/////////////////////////////////////////////////////////////////////
void main()
{
  WDTCTL = WDTPW | WDTHOLD;                                //stop watchdog

  gpioInit();                                              //setup gpio
  timerA0Init();                                           //setup and start timerA0
  _enable_interrupt();                                     //enable interrupts from intrinsics.h
  while(1){
    ;
  }
}
/////////////////////////////////////////////////////////////////////////////////////////////////
//ISR for timer A0
//--------------------------------------------------------------------------------------------
#pragma vector = TIMER0_A0_VECTOR
__interrupt void T0AO_ISR(void)
{
  P1OUT ^= LED1_PIN;
  P4OUT ^= LED2_PIN;
}
