//////////////////////////////////////////////////////////////////////////
// device to enter low power mode 4 until woken by interrupt from a button
// press. Toggle LEDs, sleep, then toggle again upon release. No switch
// debounce.
//////////////////////// library includes ////////////////////////////////
#include <msp430.h>
#include <stdint.h>
//////////////////////// defines /////////////////////////////////////////
#define LED1_PIN 0x01U
#define LED2_PIN 0x80U
#define PUSH_BUTTON_PIN 0x02U
//////////////////////// function prototypes /////////////////////////////
void gpioInit(void);
//////////////////////////////////////////////////////////////////////////
/*
 * main.c
 */
void main(void) {

  WDTCTL = WDTPW | WDTHOLD;	                     // Stop watchdog timer

  gpioInit();
  _enable_interrupt();                           //enable all interrupts GIE bit from intrinsics.h

  while(1){
      LPM4;                                      //enter low power mode 4, from msp430f5529.h
  }
}

//////////////////////////////////////////////////////////////////////////
//ISR for push button on p2.1
//------------------------------------------------------------------------
#pragma vector = PORT2_VECTOR
__interrupt void P2_1_VECTOR(void)
{
  P1OUT ^= LED1_PIN;
  P4OUT ^= LED2_PIN;
  P2IES ^= PUSH_BUTTON_PIN;
  P2IFG &= ~PUSH_BUTTON_PIN;
}
//////////////////////////////////////////////////////////////////////////

void gpioInit(void)
{
  P1OUT &= ~LED1_PIN;                            //led1 on pin1.0
  P1DIR |= LED1_PIN;
  P4OUT |= LED2_PIN;                             //led2 on pin4.7
  P4DIR |= LED2_PIN;
  P2REN |= PUSH_BUTTON_PIN;                      //push button on p2.1 with pull up resistor
  P2OUT |= PUSH_BUTTON_PIN;
  P2IES |= PUSH_BUTTON_PIN;                      //falling edge
  P2IE  |= PUSH_BUTTON_PIN;                      //enable interrupts
  P2IFG &= ~PUSH_BUTTON_PIN;                     //clear interrupt flag
}
