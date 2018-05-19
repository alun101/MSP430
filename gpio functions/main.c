#include "project.h"

#define LED_PORT P1OUT
#define LED_PIN (0x0001U)

/*
 * main.c
 */
void main(void) {
  WDTCTL = WDTPW | WDTHOLD;	                               // Stop watchdog timer

  gpioPinSetOutput(LED_PORT,LED_PIN,REDUCED,ACTIVE_HIGH);  // set P1.0 as output
  gpioOutputPinWrite(LED_PORT,LED_PIN,HIGH);               // turn on led P1.0

  while(1){
    ;
  }

}
