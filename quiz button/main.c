//////////////////////////////////////////////////////////////////////////
//device to act as a quiz buzzer, entering lpm 4 until woken by a button
//push. Button 1 to light led1 and button 2 to control led2, buttons remain
//lit for 2 seconds. All presses to be ignored while an LED is lit. No
//button debounce.
//////////////////////// library includes ////////////////////////////////
#include <msp430.h>
#include <stdint.h>
//////////////////////// defines /////////////////////////////////////////
#define LED_1_PIN 0x01U
#define LED_2_PIN 0x80U
#define PUSH_BUTTON_1_PIN 0x02U
#define PUSH_BUTTON_2_PIN 0x02U
//////////////////////// function prototypes /////////////////////////////
void gpioInit(void);
void timerA0Init(void);
//////////////////////////////////////////////////////////////////////////
/*
 * main.c
 */
void main(void)
{
  WDTCTL = WDTPW | WDTHOLD;	                     // Stop watchdog timer
	gpioInit();
  _enable_interrupt();                           //enable all interrupts GIE bit from intrinsics.h
  while(1){
    LPM4;                                        //enter low power mode 4, from msp430f5529.h
  }
}
//////////////////////////////////////////////////////////////////////////
//ISR for push button 1 on p2.1 and led on p1.0
//------------------------------------------------------------------------
#pragma vector = PORT2_VECTOR
__interrupt void P2_1_VECTOR(void)
{
  P2IE   &= ~PUSH_BUTTON_1_PIN;                  //disable interrupts on buttons 1 & 2
  P1IE   &= ~PUSH_BUTTON_2_PIN;
  P1OUT  |= LED_1_PIN;                           //turn on LED1
  TA0CTL |= TASSEL__ACLK|MC__CONTINUOUS;         //timer A0 from ACLK continuous mode about 2 seconds
  TA0CTL &= ~TAIFG;                              //clear flag
  TA0CTL |= TACLR;                               //set clear bit to start timer
  while((TA0CTL & TAIFG) == 0){
    ;
  }
  P1OUT &= ~LED_1_PIN;                           //turn off LED1
  P2IE  |= PUSH_BUTTON_1_PIN;                    //enable interrupts on push button 1
  P1IE  |= PUSH_BUTTON_2_PIN;                    //enable interrupts on push button 2
  P2IFG &= ~PUSH_BUTTON_1_PIN;                   //clear flag
  P1IFG &= ~PUSH_BUTTON_2_PIN;
}
//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
//ISR for push button 2 on p1.1 and led on p4.7
//------------------------------------------------------------------------
#pragma vector = PORT1_VECTOR
__interrupt void P1_1_VECTOR(void)
{
  P2IE   &= ~PUSH_BUTTON_1_PIN;                  //disable interrupts on buttons 1 & 2
  P1IE   &= ~PUSH_BUTTON_2_PIN;
  P4OUT  |= LED_2_PIN;                           //turn on LED2
  TA0CTL |= TASSEL__ACLK|MC__CONTINUOUS;         //timer A0 from ACLK continuous mode about 2 seconds
  TA0CTL &= ~TAIFG;                              //clear flag
  TA0CTL |= TACLR;                               //set clear bit to start timer
  while((TA0CTL & TAIFG) == 0){
    ;
  }
  P4OUT &= ~LED_2_PIN;                           //turn off LED1
  P2IE  |= PUSH_BUTTON_1_PIN;                    //enable interrupts on push button 1
  P1IE  |= PUSH_BUTTON_2_PIN;                    //enable interrupts on push button 2
  P2IFG &= ~PUSH_BUTTON_1_PIN;                   //clear flag
  P1IFG &= ~PUSH_BUTTON_2_PIN;
}
//////////////////////////////////////////////////////////////////////////

void gpioInit(void)
{
  P1OUT &= ~LED_1_PIN;                           //led on p1.0 default off
  P1DIR |= LED_1_PIN;
  P4OUT &= ~LED_2_PIN;                           //led on p4.7 default off
  P4DIR |= LED_2_PIN;
  P2REN |= PUSH_BUTTON_1_PIN;                    //push button on p2.1 with pull up resistor
  P2OUT |= PUSH_BUTTON_1_PIN;
  P2IES |= PUSH_BUTTON_1_PIN;                    //falling edge
  P2IE  |= PUSH_BUTTON_1_PIN;                    //enable interrupts
  P2IFG &= ~PUSH_BUTTON_1_PIN;                   //clear interrupt flag
  P1REN |= PUSH_BUTTON_2_PIN;                    //push button on p1.1 with pull up resistor
  P1OUT |= PUSH_BUTTON_2_PIN;
  P1IES |= PUSH_BUTTON_2_PIN;                    //falling edge
  P1IE  |= PUSH_BUTTON_2_PIN;                    //enable interrupts
  P1IFG &= ~PUSH_BUTTON_2_PIN;                   //clear interrupt flag
}
