///////////////////////////////////////////////////////////////////////////////
//  Copyright Christopher Kormanyos 2026.
//  Distributed under the Boost Software License,
//  Version 1.0. (See accompanying file LICENSE_1_0.txt
//  or copy at http://www.boost.org/LICENSE_1_0.txt)
//

#include <mcal_led.h>
#include <mcal_led/mcal_led_boolean_state_base.h>

class led_v850es_jg3_starter : public mcal::led::led_boolean_state_base
{
private:
  using base_class_type = mcal::led::led_boolean_state_base;

public:
  led_v850es_jg3_starter() noexcept
  {
    // TBD: Initialize the LED port pin to output low.
  }

  auto toggle() noexcept -> void override
  {
    // TBD: Toggle the LED port pin.

    base_class_type::toggle();
  }
};

mcal::led::led_base& mcal::led::led0()
{
  using led0_led_type = led_v850es_jg3_starter;

  static led0_led_type l0;

  return l0;
}
