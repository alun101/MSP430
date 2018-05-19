/*
 * alun_gpio.c
 *
 *  Created on: 15 Aug 2017
 *      Author: aevans
 */
#include "alun_gpio.h"

gpio_register_t *const port_1 = (gpio_register_t *)0x0200;
gpio_register_t *const port_2 = (gpio_register_t *)0x0201;
gpio_register_t *const port_3 = (gpio_register_t *)0x0220;
gpio_register_t *const port_4 = (gpio_register_t *)0x0221;
gpio_register_t *const port_5 = (gpio_register_t *)0x0240;
gpio_register_t *const port_6 = (gpio_register_t *)0x0241;
gpio_register_t *const port_7 = (gpio_register_t *)0x0260;
gpio_register_t *const port_8 = (gpio_register_t *)0x0261;

gpio_register_interrupt_t *const port_1_interrupt = (gpio_register_interrupt_t *)0x0218;
gpio_register_interrupt_t *const port_2_interrupt = (gpio_register_interrupt_t *)0x0219;


gpio_pin_state_t gpioPinRead(gpio_register_t* gpio_port, uint8_t gpio_pin){
  gpio_pin_state_t pin_state;
  if((gpio_port->input_register & gpio_pin) == 0){
      pin_state = low;
  }
  else if((gpio_port->input_register & gpio_pin) != 0){
      pin_state = high;
  }
  return(pin_state);
}

void gpioPinStateSet(gpio_register_t* gpio_port, uint8_t gpio_pin, gpio_pin_state_t pin_state){
  if(pin_state == low){
    gpio_port->output_register &= ~gpio_pin;
  }
  else if(pin_state == high){
    gpio_port->output_register |= gpio_pin;
  }
}

void gpioPinDirectionSet(gpio_register_t* gpio_port, uint8_t gpio_pin, gpio_pin_direction_t pin_direction){
  if(pin_direction == input){
    gpio_port->direction_register &= ~gpio_pin;
  }
  if(pin_direction == output){
    gpio_port->direction_register |= gpio_pin;
  }
}

void gpioPinResistorEnableSet(gpio_register_t* gpio_port, uint8_t gpio_pin, gpio_pin_resistor_t resistor_enable){
 if(resistor_enable == disable){
   gpio_port->resistor_enable_register &= ~gpio_pin;
 }
 if(resistor_enable == enable){
   gpio_port->resistor_enable_register |= gpio_pin;
 }
}

void gpioPinResistorFunctionSet(gpio_register_t* gpio_port, uint8_t gpio_pin, gpio_pin_resistor_function_t resistor_function){
  if(resistor_function == pull_down){
    gpio_port->output_register &= ~gpio_pin;
  }
  else if(resistor_function == pull_up){
    gpio_port->output_register |= ~gpio_pin;
  }
}

void gpioPinDriveStrength(gpio_register_t* gpio_port, uint8_t gpio_pin, gpio_pin_drive_strength_t drive_strength){
  if(drive_strength == reduced){
    gpio_port->drive_strength_register &= ~gpio_pin;
  }
  else if(drive_strength == full){
    gpio_port->drive_strength_register |= gpio_pin;
  }
}

void gpioPinFunctionSelect(gpio_register_t* gpio_port, uint8_t gpio_pin, gpio_pin_function_select_t function_select){
  if(function_select == gpio){
    gpio_port->function_select_register &= ~gpio_pin;
  }
  else if(function_select == peripheral){
    gpio_port->function_select_register |= gpio_pin;
  }
}

void gpioPinToggle(gpio_register_t* gpio_port, uint8_t gpio_pin){
  gpio_port->output_register ^= gpio_pin;
}
