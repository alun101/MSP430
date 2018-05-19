//////////////////////////////////////////////////////////////////////////
#include <msp430.h>
#include <stdbool.h>
#include <stdint.h>
#include <intrinsics.h>
//////////////////////////////////////////////////////////////////////////
bool isButton2Pushed(void);                                 //prototype
bool isButton1Released(void);
bool isButton1Pushed(void);
//////////////////////////////////////////////////////////////////////////
#define LED_1_PIN 0x01
#define BUTTON_1_PIN 0x02
#define LED_2_PIN 0x80
#define BUTTON_2_PIN 0x02
//////////////////////////////////////////////////////////////////////////
void main(void) {
  bool static button_state;
  bool *button_1_pushed;
  button_1_pushed = &button_state;

  WDTCTL = WDTPW | WDTHOLD;	                               //Stop watchdog timer

  P1OUT &= ~LED_1_PIN;                                     //led on p1.0 default off             button 1 on p1.1 controls led 2 on p4.7
  P1DIR |=  LED_1_PIN;                                     //led output                          button 2 on p2.1 controls led 1 on p1.0
  P1REN |=  BUTTON_1_PIN;                                  //push button on p1.1
  P1OUT |=  BUTTON_1_PIN;                                  //push button with pullup resistor
  P2REN |=  BUTTON_2_PIN;                                  //push button on p2.1
  P2OUT |=  BUTTON_2_PIN;                                  //push button with pullup resistor
  P4OUT &= ~LED_2_PIN;                                     //led on p4.7 default off
  P4DIR |=  LED_2_PIN;                                     //led output


  TA0CCR0 = 4361;                                          //compare register, should be about 4.16ms, 0.00416s, from default speed of SMCLK
  TA0CCTL0 |= CCIE;                                        //enable interrupts for compare register 0
  TA0CTL |= MC__UP|ID__1|TASSEL__SMCLK|TACLR;              //up mode, clock /1, sourced from SMCLK, start timer

  _enable_interrupt();                                     //enable all interrupts from intrinsics.h

  while(1){
    LPM3;
    if(isButton2Pushed() == true){
      P1OUT ^= LED_1_PIN;
    }
    if(*button_1_pushed == true){
      if(isButton1Released() == true){
        P4OUT ^= LED_2_PIN;
        *button_1_pushed = false;
      }
    }
    if(*button_1_pushed == false){
      if(isButton1Pushed() == true){
        *button_1_pushed = true;
      }
    }
  }
}
//////////////////////////////////////////////////////////////////////////
//ISR for timer A0
//------------------------------------------------------------------------
#pragma vector = TIMER0_A0_VECTOR
__interrupt void T0AO_ISR(void)
{
  LPM3_EXIT;
}
//////////////////////////////////////////////////////////////////////////
bool isButton2Pushed(){
  uint16_t volatile static  switch_state = 0;
  switch_state = (switch_state<<1)|(P2IN & BUTTON_2_PIN)|(0xe000); //needs 12 consecutive closed button reads
  if(switch_state==0xf000){
    return true;
  }
  return false;
}

bool isButton1Released(){
  uint16_t volatile static switch_state = 0;
  switch_state = (switch_state<<1)|(P1IN & BUTTON_1_PIN);
  if(switch_state==0x00fe){
    return true;
  }
  return false;
}

bool isButton1Pushed(){
  uint16_t volatile static  switch_state = 0;
  switch_state = (switch_state<<1)|(P1IN & BUTTON_1_PIN)|(0xfe00); //needs 12 consecutive closed button reads
  if(switch_state==0xff00){
    return true;
  }
  return false;
}
