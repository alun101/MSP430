/*
 * gpio_functions.h
 *
 *  Created on: 9 Mar 2017
 *      Author: aevans
 */

#ifndef INCLUDE_GPIO_FUNCTIONS_H_
#define INCLUDE_GPIO_FUNCTIONS_H_


//includes

#include "project.h"

//defines

typedef enum{
  REDUCED = 0,
  FULL = 1
}OUTPUT_PIN_DRIVE_STRENGTH;

typedef enum{
  LOW = 0,
  HIGH = 1
}GPIO_PIN_STATE;

typedef enum{
  ACTIVE_LOW = 0,
  ACTIVE_HIGH = 1
}OUTPUT_PIN_ACTIVE_STATE;

typedef enum{
  NO_RESISTOR = 0,
  PULL_DOWN = 1,
  PULL_UP = 2
}INPUT_PULL_RESISTOR;


//function prototypes

void gpioPinSetOutput(SFR_8BIT port, uint16_t pin, OUTPUT_PIN_DRIVE_STRENGTH DRIVE_STRENGTH, OUTPUT_PIN_ACTIVE_STATE ACTIVE_STATE);
void gpioOutputPinWrite(SFR_8BIT port, uint16_t pin, GPIO_PIN_STATE PIN_STATE);
void gpioOutputPinToggle(SFR_8BIT port, uint16_t pin);
void gpioPinSetInput(SFR_8BIT port, uint16_t pin, INPUT_PULL_RESISTOR INPUT_RESISTOR);
GPIO_PIN_STATE gpioInputReadPin(SFR_8BIT port, uint16_t pin);




#endif /* INCLUDE_GPIO_FUNCTIONS_H_ */
