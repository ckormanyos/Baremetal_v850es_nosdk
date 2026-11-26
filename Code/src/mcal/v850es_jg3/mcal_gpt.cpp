///////////////////////////////////////////////////////////////////////////////
//  Copyright Christopher Kormanyos 2026.
//  Distributed under the Boost Software License,
//  Version 1.0. (See accompanying file LICENSE_1_0.txt
//  or copy at http://www.boost.org/LICENSE_1_0.txt)
//

#include <mcal_gpt.h>

#include <cstdint>

#define TM0CTL0  (*(volatile uint8_t*)0xFFFFF690ul)
#define TM0CMP0  (*(volatile uint16_t*)0xFFFFF694ul)
#define TM0EQIC0 (*(volatile uint8_t*)0xFFFFF150ul)

#define PM3L (*(volatile uint8_t*)(0xFFFFF426ul))
#define P3L  (*(volatile uint8_t*)(0xFFFFF406ul))

auto mcal::gpt::init(const config_type*) -> void
{
  /* configure the TMM0 timer */
  TM0CTL0 = 0;
  TM0CMP0 = 19999; //1ms interrupt
  TM0EQIC0 = 7;
  TM0CTL0 = 0x80;
}

auto mcal::gpt::secure::get_time_elapsed() -> value_type
{
  return value_type { };
}

volatile uint32_t x;

extern "C"
__attribute__((interrupt)) void timer_isr(void);

extern "C"
__attribute__((interrupt)) void timer_isr(void)
{
  x = static_cast<std::uint32_t>(x + 1U);

  if(x >= 500)
  {
    P3L ^= (1u << 6);
    x = 0;
  }
}
