/*
 * timerA0.c
 *
 *  Created on: 15 May 2017
 *      Author: aevans
 */
//////////////////////// Private Includes ////////////////////////////////
#include "project.h"
//////////////////////////////////////////////////////////////////////////
void timerA0Init(void){
  TA0CCR0 = 65535;                               //compare register, should be .5 seconds from default speed of fdcoclkdiv
  TA0CCTL0 |= CCIE;                              //enable interrupts for compare register 0
  TA0CTL |= MC__UP|ID__8|TASSEL__SMCLK|TACLR;       //up mode, clock /8, sourced from SMCLK, start timer
}
