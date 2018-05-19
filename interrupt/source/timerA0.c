/*
 * timerA0.c
 *
 *  Created on: 4 May 2017
 *      Author: aevans
 */
 //////////////////////// includes //////////////////////////////////
 #include "project.h"
 ////////////////////////////////////////////////////////////////////
   
 void timerA0Init(){
   TA0CCR0 = 62499;                                     //set compare register @1MHz to be about 0.5s.
   TA0CCTL0 |= CCIE;                                    //enable interrupts for compare register 0
   TA0CTL |= MC__UP|ID__8|TASSEL__SMCLK|TACLR;          //up mode, clock / 8, sourced from SMCLK, start timer
 }
