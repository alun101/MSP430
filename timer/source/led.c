/*
 * led.c
 *
 *  Created on: 24 Feb 2017
 *      Author: aevans
 */

#include "project.h"

void led1Init(){
   P1OUT  &= ~LED_1_PIN;                                   //clear pin 1.0 output register
   P1DIR  |=  LED_1_PIN;                                   //set pin 1.0 as output
}

void led2Init(){
    P4OUT |= LED_2_PIN;                                    //set pin 4.7 output register
    P4DIR |= LED_2_PIN;                                    //set pin 4.7 as output
}
