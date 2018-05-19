/*
 * main.c
 */
 //To flash leds on p1.0 and p4.7 for a duration of half a second. Using TimerA0.

#include "project.h"

void main(void)
{
    WDTCTL = WDTPW | WDTHOLD;	                             //Stop watchdog timer

    led1Init();                                            //initialise led 1 on p1.0
    led2Init();                                            //initialise led 2 on p4.7

    timerA0Init();                                         //initialise timerA0

    for(;;){

      while((TA0CTL & TIMER_A0_INTERRUPT_FLAG)==0){        //while timer counts do nothing
        ;                                                  //once flag is set exit loop
      }
      TA0CTL &= TIMER_A0_CLEAR_INTERRUPT_FLAG;             //clear flag
      P1OUT  ^= LED_1_PIN;                                 //toggle led on pin 1.0
      P4OUT  ^= LED_2_PIN;                                 //toggle led on pin 4.7
    }

}
