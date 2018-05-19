/*
 * alun_gpio.h
 *
 *  Created on: 15 Aug 2017
 *      Author: aevans
 */

#ifndef INCLUDE_ALUN_GPIO_H_
#define INCLUDE_ALUN_GPIO_H_
////////////////////////Library Includes //////////////////////////////////////
#include <stdint.h>
////////////////////////Project Includes //////////////////////////////////////
////////////////////////Defines and typedefs //////////////////////////////////
#define PIN_0 (0x01)
#define PIN_1 (0x02)
#define PIN_2 (0x04)
#define PIN_3 (0x08)
#define PIN_4 (0x10)
#define PIN_5 (0x20)
#define PIN_6 (0x40)
#define PIN_7 (0x80)


typedef uint8_t volatile read_write_byte_register_t;
typedef uint8_t const volatile read_only_byte_register_t;
typedef uint16_t const volatile read_only_word_register_t;

typedef struct gpio_register gpio_register_t;
struct gpio_register{
  read_only_byte_register_t  input_register;
  uint8_t                    padding1;
  read_write_byte_register_t output_register;
  uint8_t                    padding2;
  read_write_byte_register_t direction_register;
  uint8_t                    padding3;
  read_write_byte_register_t resistor_enable_register;
  uint8_t                    padding4;
  read_write_byte_register_t drive_strength_register;
  uint8_t                    padding5;
  read_write_byte_register_t function_select_register;
};

typedef struct gpio_register_interrupt gpio_register_interrupt_t;
struct gpio_register_interrupt{
  read_write_byte_register_t interrupt_edge_select_register;
  uint8_t                    padding6;
  read_write_byte_register_t interrupt_enable_register;
  uint8_t                    padding7;
  read_write_byte_register_t interrupt_flag_register;
};

typedef enum{
  low = 0,
  high = 1
}gpio_pin_state_t;

typedef enum{
  input = 0,
  output =1
}gpio_pin_direction_t;

typedef enum{
  disable = 0,
  enable = 1
}gpio_pin_resistor_t;

typedef enum{
  pull_down = 0,
  pull_up = 1
}gpio_pin_resistor_function_t;

typedef enum{
  reduced = 0,
  full = 1
}gpio_pin_drive_strength_t;

typedef enum{
  gpio = 0,
  peripheral = 1
}gpio_pin_function_select_t;

extern gpio_register_t *const port_1;
extern gpio_register_t *const port_2;
extern gpio_register_t *const port_3;
extern gpio_register_t *const port_4;
extern gpio_register_t *const port_5;
extern gpio_register_t *const port_6;
extern gpio_register_t *const port_7;
extern gpio_register_t *const port_8;

///////////////////////////////////////////////////////////////////////////////
//////////////////////// Function Prototypes //////////////////////////////////
gpio_pin_state_t gpioPinRead(gpio_register_t* gpio_port, uint8_t gpio_pin);
void gpioPinStateSet(gpio_register_t* gpio_port, uint8_t gpio_pin, gpio_pin_state_t pin_state);
void gpioPinDirectionSet(gpio_register_t* gpio_port, uint8_t gpio_pin, gpio_pin_direction_t pin_direction);
void gpioPinResistorEnableSet(gpio_register_t* gpio_port, uint8_t gpio_pin, gpio_pin_resistor_t resistor_enable);
void gpioPinResistorFunctionSet(gpio_register_t* gpio_port, uint8_t gpio_pin, gpio_pin_resistor_function_t resistor_function);
void gpioPinDriveStrength(gpio_register_t* gpio_port, uint8_t gpio_pin, gpio_pin_drive_strength_t drive_strength);
void gpioPinFunctionSelect(gpio_register_t* gpio_port, uint8_t gpio_pin, gpio_pin_function_select_t function_select);
void gpioPinToggle(gpio_register_t* gpio_port, uint8_t gpio_pin);



#endif /* INCLUDE_ALUN_GPIO_H_ */
