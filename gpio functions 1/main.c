#include <msp430.h>
#include "alun_gpio.h"
/*
 * main.c
 */
void main(void)
{
  WDTCTL = WDTPW | WDTHOLD;	// Stop watchdog timer

  gpioPinStateSet(port_1, PIN_0, high);                              //led p1.0 default on
  gpioPinDirectionSet(port_1, PIN_0, output);                        //led p1.0 output
  gpioPinStateSet(port_4, PIN_7, high);                              //led p4.7 default on
  gpioPinDirectionSet(port_4, PIN_7, output);                        //led p4.7 output
  gpioPinResistorEnableSet(port_2, PIN_1, enable);                   //push button p2.1 with pull up resistor
  gpioPinResistorFunctionSet(port_2, PIN_1, pull_up);

  while(1){
    while((gpioPinRead(port_2, PIN_1))==0){                          //button 2.1 pushed (held) turn off led
        gpioPinStateSet(port_1, PIN_0, low);
    }
    gpioPinStateSet(port_1, PIN_0, high);                            //button released turn on led
  }
}
