/*
 * gpio.h
 *
 *  Created on: 11 Apr 2017
 *      Author: aevans
 */

#ifndef INCLUDE_GPIO_H_
#define INCLUDE_GPIO_H_

#include "project.h"

#define GPIO_PORT_1_INPUT                 (*((uint8_t const volatile *)0x200))
#define GPIO_PORT_2_INPUT                 (*((uint8_t const volatile *)0x201))
#define GPIO_PORT_1_OUTPUT                (*((uint8_t volatile *)0x202))
#define GPIO_PORT_2_OUTPUT                (*((uint8_t volatile *)0x203))
#define GPIO_PORT_1_DIRECTION             (*((uint8_t volatile *)0x204))
#define GPIO_PORT_2_DIRECTION             (*((uint8_t volatile *)0x205))
#define GPIO_PORT_1_RESISTOR_ENABLE       (*((uint8_t volatile *)0x206))
#define GPIO_PORT_2_RESISTOR_ENABLE       (*((uint8_t volatile *)0x207))
#define GPIO_PORT_1_DRIVE_STRENGTH        (*((uint8_t volatile *)0x208))
#define GPIO_PORT_2_DRIVE_STRENGTH        (*((uint8_t volatile *)0x209))
#define GPIO_PORT_1_FUNCTION_SELECT       (*((uint8_t volatile *)0x20A))
#define GPIO_PORT_2_FUNCTION_SELECT       (*((uint8_t volatile *)0x20B))
#define GPIO_PORT_1_INTERRUPT_VECTOR      (*((uint16_t const volatile *)0x20E))
#define GPIO_PORT_1_INTERRUPT_EDGE_SELECT (*((uint8_t volatile *)0x218))
#define GPIO_PORT_2_INTERRUPT_EDGE_SELECT (*((uint8_t volatile *)0x219))
#define GPIO_PORT_1_INTERRUPT_ENABLE      (*((uint8_t volatile *)0x21A))
#define GPIO_PORT_2_INTERRUPT_ENABLE      (*((uint8_t volatile *)0x21B))
#define GPIO_PORT_1_INTERRUPT_FLAG        (*((uint8_t volatile *)0x21C))
#define GPIO_PORT_2_INTERRUPT_FLAG        (*((uint8_t volatile *)0x21D))
#define GPIO_PORT_2_INTERRUPT_VECTOR      (*((uint16_t const volatile *)0x21E))

#define LED_PIN (0x01)
#define PUSH_BUTTON_PIN (0x02)





#endif /* INCLUDE_GPIO_H_ */
