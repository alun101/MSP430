/*
 * timerA0.c
 *
 *  Created on: 24 Feb 2017
 *      Author: aevans
 */

#include "project.h"

void timerA0Init(){
  TA0CCR0 = HALF_SECOND_DELAY;                             //set compare register to 16384(65536/4)-1
  TA0CTL &= RESET_16BIT_REGISTER;                          //clear TA0CTL ready for configuration
  TA0CTL |= TASSEL_ACLK;                                   //set source as ACLK, 32768Hz default
  TA0CTL &= ID_NO_DIVIDE;                                  //set ID divider to /1
  TA0EX0 &= IDEX_NO_DIVIDE;                                //set IDEX divider to /1
  TA0CTL |= MODE_CONTROL_UP;                               //set MC to up mode at 32768Hz this is 0.5seconds
  TA0CTL &= TIMER_A0_INTERRUPT_DISABLE;                    //disable Timer A0 interrupts
  TA0CTL &= TIMER_A0_CLEAR_INTERRUPT_FLAG;                 //clear interrupt flag
  TA0CTL |= TIMER_A0_START_TIMER;                          //start timer
}
