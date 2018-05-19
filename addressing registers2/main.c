

//project includes
#include "project.h"


void main(void)
{
  WDTCTL = WDTPW | WDTHOLD;	                               // Stop watchdog timer

  //initialise gpio pins
  GPIO_PORT_1_OUTPUT |= LED_PIN;                           //led on p1.0 default on
  GPIO_PORT_1_DIRECTION |= LED_PIN;
  GPIO_PORT_2_RESISTOR_ENABLE |= PUSH_BUTTON_PIN;          //push button on p2.1 with pullup resistor
  GPIO_PORT_2_OUTPUT |= PUSH_BUTTON_PIN;

  for(;;){
    while((GPIO_PORT_2_INPUT & PUSH_BUTTON_PIN) != 0){
      GPIO_PORT_1_OUTPUT |= LED_PIN;
    }
    GPIO_PORT_1_OUTPUT &= ~LED_PIN;
  }	
}
