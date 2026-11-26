/******************************************************************************************
  Filename    : main.c

  Core        : V850ES/JG3-L

  Mcu         : μPD70F3793

  Author      : Chalandi Amine

  Owner       : Chalandi Amine

  Date        : 28.10.2026

  Description : Application main function

******************************************************************************************/
#include "uart.h"
#include "printf.h"

#include <mcal_gpt.h>
#include <mcal_irq.h>
#include <mcal_port.h>

#include <cstdint>

auto main(void) -> int;

auto main(void) -> int
{
  mcal::port::init(nullptr);
  mcal::gpt::init(nullptr);

  mcal::irq::enable_all();

  /* initilize uart */
  uart_init(115200);
  printf("Hello from V850ES!\n");

  for(;;);
}
