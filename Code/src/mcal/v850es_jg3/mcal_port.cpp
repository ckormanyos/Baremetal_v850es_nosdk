///////////////////////////////////////////////////////////////////////////////
//  Copyright Christopher Kormanyos 2026.
//  Distributed under the Boost Software License,
//  Version 1.0. (See accompanying file LICENSE_1_0.txt
//  or copy at http://www.boost.org/LICENSE_1_0.txt)
//

#include <mcal_port.h>

#include <cstdint>

#define PM3L (*(volatile uint8_t*)(0xFFFFF426ul))
#define P3L  (*(volatile uint8_t*)(0xFFFFF406ul))

auto mcal::port::init(const config_type*) -> void
{
  /* set P36 as output low (LED ON) */
  PM3L &= (uint8_t)~(1u << 6);
  P3L  &= (uint8_t)~(1u << 6);
}
