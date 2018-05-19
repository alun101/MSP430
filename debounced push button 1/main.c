//////////////////////////////////////////////////////////////////////////
#include <msp430.h>
#include <stdbool.h>
#include <stdint.h>
#include <intrinsics.h>
//////////////////////////////////////////////////////////////////////////
bool isButtonPushed(void);                                 //prototype
//////////////////////////////////////////////////////////////////////////

void main(void) {
  WDTCTL = WDTPW | WDTHOLD;	                               //Stop watchdog timer

  P1OUT &= ~0x01;                                          //led on p1.0 default off
  P1DIR |=  0x01;                                          //led output
  P1REN |=  0x02;                                          //push button on p1.1
  P1OUT |=  0x02;                                          //push button with pullup resistor

  TA0CCR0 = 4361;                                          //compare register, should be about 4.16ms, 0.00416s, from default speed of SMCLK
  TA0CCTL0 |= CCIE;                                        //enable interrupts for compare register 0
  TA0CTL |= MC__UP|ID__1|TASSEL__SMCLK|TACLR;              //up mode, clock /1, sourced from SMCLK, start timer

  _enable_interrupt();                                     //enable all interrupts from intrinsics.h

  while(1){
    ;
  }
}
//////////////////////////////////////////////////////////////////////////
//ISR for timer A0
//------------------------------------------------------------------------
#pragma vector = TIMER0_A0_VECTOR
__interrupt void T0AO_ISR(void)
{
  if(isButtonPushed()==true){
    P1OUT ^= 0x01;
  }
}
//////////////////////////////////////////////////////////////////////////
bool isButtonPushed(){
  uint16_t static  switch_state = 0;
  switch_state = (switch_state<<1)|(P1IN & 0x02)|(0xe000); //needs 12 consecutive closed button reads
  if(switch_state==0xf000){
    return true;
  }
  return false;
}
