/*
 * gpio_functions.c
 *
 *  Created on: 9 Mar 2017
 *      Author: aevans
 */

 #include "project.h"

 void gpioPinSetOutput(SFR_8BIT port, uint16_t pin, OUTPUT_PIN_DRIVE_STRENGTH DRIVE_STRENGTH, OUTPUT_PIN_ACTIVE_STATE ACTIVE_STATE){
   switch(port){
     case P1OUT:
       if(ACTIVE_STATE==ACTIVE_LOW){
         P1OUT |= pin;
       }
       else if(ACTIVE_STATE==ACTIVE_HIGH){
         P1OUT &= ~pin;
       }
       P1DIR |= pin;
       if(DRIVE_STRENGTH==REDUCED){
         P1DS &= ~pin;
       }
       else if(DRIVE_STRENGTH==FULL){
         P1DS |= pin;
       }
       break;
     case P2OUT:
       if(ACTIVE_STATE==ACTIVE_LOW){
         P2OUT |= pin;
       }
       else if(ACTIVE_STATE==ACTIVE_HIGH){
         P2OUT &= ~pin;
       }
       P2DIR |= pin;
       if(DRIVE_STRENGTH==REDUCED){
         P2DS &= ~pin;
       }
       else if(DRIVE_STRENGTH==FULL){
         P2DS |= pin;
       }
       break;
     case P3OUT:
       if(ACTIVE_STATE==ACTIVE_LOW){
         P3OUT |= pin;
       }
       else if(ACTIVE_STATE==ACTIVE_HIGH){
         P3OUT &= ~pin;
       }
       P3DIR |= pin;
       if(DRIVE_STRENGTH==REDUCED){
         P3DS &= ~pin;
       }
       else if(DRIVE_STRENGTH==FULL){
         P3DS |= pin;
       }
       break;
     case P4OUT:
       if(ACTIVE_STATE==ACTIVE_LOW){
         P4OUT |= pin;
       }
       else if(ACTIVE_STATE==ACTIVE_HIGH){
         P4OUT &= ~pin;
       }
       P4DIR |= pin;
       if(DRIVE_STRENGTH==REDUCED){
         P4DS &= ~pin;
       }
       else if(DRIVE_STRENGTH==FULL){
         P4DS |= pin;
       }
       break;
     default:
     ;
   }
 }

 void gpioOutputPinWrite(SFR_8BIT port, uint16_t pin, GPIO_PIN_STATE PIN_STATE){
   if(PIN_STATE==LOW){
     port &= ~pin;
   }
   else if(PIN_STATE==HIGH){
     port |= pin;
   }
 }

 void gpioOutputPinToggle(SFR_8BIT port, uint16_t pin){
   port ^= pin;
 }

 void gpioPinSetInput(SFR_8BIT port, uint16_t pin, INPUT_PULL_RESISTOR INPUT_RESISTOR){
   switch(port){
     case P1IN:
       P1DIR &= ~pin;
       if(INPUT_RESISTOR==NO_RESISTOR){
         P1REN &= ~pin;
       }
       else if(INPUT_RESISTOR==PULL_DOWN){
         P1REN |= pin;
         P1OUT &= ~pin;
       }
       else if(INPUT_RESISTOR==PULL_UP){
         P1REN |= pin;
         P1OUT |= pin;
       }
       break;
     case P2IN:
       P2DIR &= ~pin;
       if(INPUT_RESISTOR==NO_RESISTOR){
         P2REN &= ~pin;
       }
       else if(INPUT_RESISTOR==PULL_DOWN){
         P2REN |= pin;
         P2OUT &= ~pin;
       }
       else if(INPUT_RESISTOR==PULL_UP){
         P2REN |= pin;
         P2OUT |= pin;
       }
       break;
     case P3IN:
       P3DIR &= ~pin;
       if(INPUT_RESISTOR==NO_RESISTOR){
         P3REN &= ~pin;
       }
       else if(INPUT_RESISTOR==PULL_DOWN){
         P3REN |= pin;
         P3OUT &= ~pin;
       }
       else if(INPUT_RESISTOR==PULL_UP){
         P3REN |= pin;
         P3OUT |= pin;
       }
       break;
     case P4IN:
       P4DIR &= ~pin;
       if(INPUT_RESISTOR==NO_RESISTOR){
         P4REN &= ~pin;
       }
       else if(INPUT_RESISTOR==PULL_DOWN){
         P4REN |= pin;
         P4OUT &= ~pin;
       }
       else if(INPUT_RESISTOR==PULL_UP){
         P4REN |= pin;
         P4OUT |= pin;
       }
       break;
     default:
     ;
   }
 }

 GPIO_PIN_STATE gpioInputReadPin(SFR_8BIT port, uint16_t pin){
   GPIO_PIN_STATE BIT_STATE;
   if((port & pin)==0){
     BIT_STATE = LOW;
   }
   else if((port & pin)!=0){
     BIT_STATE = HIGH;
   }
   return(BIT_STATE);
 }
