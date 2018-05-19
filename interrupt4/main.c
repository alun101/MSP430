/*
 * main.c
 */
//////////////////////////////////////////////////////////////////////////
//program to flash LEDs on an interrupt timer. Processor to enter low power
//mode 3 between interrupts then return to main to toggle LEDs. Timer to be
//sourced from ACLK with a period of approx 0.5 seconds.
//////////////////////////////////////////////////////////////////////////
//////////////////////// Private includes ////////////////////////////////
#include "project.h"
//////////////////////////////////////////////////////////////////////////

void main(void)
{
  WDTCTL = WDTPW | WDTHOLD;	                     // Stop watchdog timer

  gpioInit();                                    //setup gpio
  timerA0Init();                                 //setup and start timerA0
  _enable_interrupt();                           //enable all interrupts from intrinsics.h
  while(1){
    LPM3;                                        //from msp430f5529.h could be _low_power_mode_3() from intrinsics.h
    P1OUT ^= LED1_PIN;
    P4OUT ^= LED2_PIN;
  }
}
//////////////////////////////////////////////////////////////////////////
//ISR for timer A0
//------------------------------------------------------------------------
#pragma vector = TIMER0_A0_VECTOR
__interrupt void T0AO_ISR(void)
{
    LPM3_EXIT;                                   //low power mode off on exit from msp430f5529.h
}                                                //could be __low_power_mode_off_on_exit() from intrinsics.h
