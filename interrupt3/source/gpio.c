/*
 * gpio.c
 *
 *  Created on: 15 May 2017
 *      Author: aevans
 */
 //////////////////////// Private Includes ////////////////////////////////
#include "project.h"
//////////////////////////////////////////////////////////////////////////
void gpioInit(void){
  P1OUT &= ~LED1_PIN;                                      // LED on p1.0 default off
  P1DIR |= LED1_PIN;
  P4OUT |= LED2_PIN;                                       // LED on p4.7 default on
  P4DIR |= LED2_PIN;
}
