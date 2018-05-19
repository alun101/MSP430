#include <msp430.h>

/*
 * main.c
 */

#include "project.h"

void main(void)
{
  WDTCTL = WDTPW | WDTHOLD;	                                                     // Stop watchdog timer

  typedef uint8_t volatile read_write_byte_register_t;
  typedef uint8_t const volatile read_only_byte_register_t;
  typedef uint16_t const volatile read_only_word_register_t;

  typedef struct gpio_register gpio_register_t;
  struct gpio_register{
    read_only_byte_register_t  port_1_in;                                        //@0200
    read_only_byte_register_t  port_2_in;                                        //@0201
    read_write_byte_register_t port_1_out;                                       //@0202
    read_write_byte_register_t port_2_out;                                       //@0203
    read_write_byte_register_t port_1_direction;                                 //@0204
    read_write_byte_register_t port_2_direction;                                 //@0205
    read_write_byte_register_t port_1_resistor_enable;                           //@0206
    read_write_byte_register_t port_2_resistor_enable;                           //@0207
    read_write_byte_register_t port_1_drive_strenght;                            //@0208
    read_write_byte_register_t port_2_drive_strength;                            //@0209
    read_write_byte_register_t port_1_function_select;                           //@020A
    read_write_byte_register_t port_2_function_select;                           //@020B
    uint8_t                    padding1[2];                                      //@020C-020D
    read_only_word_register_t  port_1_interrupt_vector;                          //@020E-020F
    uint8_t                    padding2[8];                                      //@0210-0217
    read_write_byte_register_t port_1_interrupt_edge_select;                     //@0218
    read_write_byte_register_t port_2_interrupt_edge_select;                     //@0219
    read_write_byte_register_t port_1_interrupt_enable;                          //@021A
    read_write_byte_register_t port_2_interrupt_enable;                          //@021B
    read_write_byte_register_t port_1_interrupt_flag;                            //@021C
    read_write_byte_register_t port_2_interrupt_flag;                            //@021D
    read_only_word_register_t  port_2_interrupt_vector;                          //@021E-021F
  };

  gpio_register_t *const gpio_port_1_2 = (gpio_register_t *)0x0200;
  enum{
    led_pin = 0x01,
    push_button_pin = 0x02
  };

  gpio_port_1_2->port_1_out |= led_pin;                                          //initialise led on p1.0
  gpio_port_1_2->port_1_direction |= led_pin;
  gpio_port_1_2->port_2_resistor_enable |= push_button_pin;                      //initialise push button on p2.1 with pullup resistor
  gpio_port_1_2->port_2_out |= push_button_pin;

  for(;;){
    while((gpio_port_1_2->port_2_in & push_button_pin) != 0){
      gpio_port_1_2->port_1_out |= led_pin;
    }
    gpio_port_1_2->port_1_out &= ~led_pin;
  }
}
