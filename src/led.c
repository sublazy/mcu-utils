/*
 * Copyright (c) 2016 Cezary Sałbut
 *
 * This file is subject to the terms of the MIT license. If a copy of
 * the MIT license was not distributed with this file, You can obtain
 * one at https://opensource.org/licenses/MIT.
 */

#include "headers_all.h"

// Assert handler not implemented yet in this project.
#ifdef assert
#undef assert
#define assert(condition) do { } while (0)
#endif

/* Private types
 * --------------------------------------------------------------------------- */
typedef struct led_t {
	uint32_t gpio;
	uint16_t gpiobit;
	bool is_on;
	bool is_active_low;
	enum rcc_periph_clken rcc; // e.g. RCC_GPIOA
} led_t;

/* Private data
 * --------------------------------------------------------------------------- */
static led_t led_pool[NOF_LEDS];
static uint32_t leds_in_use = 0;

/* Private prototypes
 * --------------------------------------------------------------------------- */

/* Private routines
 * --------------------------------------------------------------------------- */

/* Public routines
 * --------------------------------------------------------------------------- */
led_t*
led_new (uint32_t gpioport, uint16_t gpiobit, bool is_active_low)
{
	assert (leds_in_use < NOF_LEDS);

	uint32_t new_led_idx = leds_in_use;
	led_t *led = &led_pool[new_led_idx];

	led->gpio = gpioport;
	led->gpiobit = gpiobit;
	led->is_active_low = is_active_low;
	led->rcc = rcc_of_gpio(gpioport);
	led->is_on = false;

	rcc_periph_clock_enable (led->rcc);
	gpio_set_mode (led->gpio,
		       GPIO_MODE_OUTPUT_2_MHZ,
		       GPIO_CNF_OUTPUT_PUSHPULL,
		       led->gpiobit);

	leds_in_use++;
	assert (led);
	led_off (led);
	return led;
}

void
led_on (led_t *led)
{
	if (!led->is_active_low) {
		gpio_set (led->gpio, led->gpiobit);
	} else {
		gpio_clear (led->gpio, led->gpiobit);
	}

	led->is_on = true;
}

void
led_off (led_t *led)
{
	if (!led->is_active_low) {
		gpio_clear (led->gpio, led->gpiobit);
	} else {
		gpio_set (led->gpio, led->gpiobit);
	}

	led->is_on = false;
}

void
led_toggle (led_t *led)
{
	gpio_toggle (led->gpio, led->gpiobit);
	led->is_on = !led->is_on;
}
