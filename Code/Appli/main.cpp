///////////////////////////////////////////////////////////////////////////////
//  Copyright Christopher Kormanyos 2026.
//  Distributed under the Boost Software License,
//  Version 1.0. (See accompanying file LICENSE_1_0.txt
//  or copy at http://www.boost.org/LICENSE_1_0.txt)
//

// Originally from
/******************************************************************************************
  Filename    : main.cpp

  Core        : V850ES/JG3-L

  Mcu         : μPD70F3793

  Author      : Chalandi Amine

  Owner       : Chalandi Amine

  Date        : 28.10.2026

  Description : Application main function

******************************************************************************************/

// Get and extract the compiler.
// cd /mnt/c/Users/ckorm/Documents/Ks/uC_Software/Boards/chalandi/Baremetal_v850es_nosdk/Build/tools
// tar -xf gcc-16.2.0-v850-unknown-elf.tar.gz

// Add the compiler path.
// cd /mnt/c/Users/ckorm/Documents/Ks/uC_Software/Boards/chalandi/Baremetal_v850es_nosdk/Build
// export PATH="$PATH:/mnt/c/Users/ckorm/Documents/Ks/uC_Software/Boards/chalandi/Baremetal_v850es_nosdk/Build/tools/gcc-16.2.0-v850-unknown-elf/bin"

#include "uart.h"
#include "printf.h"

#include <mcal_gpt.h>
#include <mcal_irq.h>
#include <mcal_port.h>

#include <os/os.h>

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

  // Start the multitasking scheduler. This does not return.
  // Handle an unexpected return from main() in the startup code.
  os::start_os();
}
