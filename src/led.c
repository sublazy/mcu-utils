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
enum rcc_periph_clken
rcc_of_gpio (uint32_t gpioport);

/* Private routines
 * --------------------------------------------------------------------------- */
enum rcc_periph_clken
rcc_of_gpio (uint32_t gpioport)
{
	enum rcc_periph_clken rcc = 0;

	switch (gpioport) {
	case GPIOA:
		rcc = RCC_GPIOA;
		break;
	case GPIOB:
		rcc = RCC_GPIOB;
		break;
	case GPIOC:
		rcc = RCC_GPIOC;
		break;
	case GPIOD:
		rcc = RCC_GPIOD;
		break;
	case GPIOE:
		rcc = RCC_GPIOE;
		break;
	case GPIOF:
		rcc = RCC_GPIOF;
		break;
	case GPIOG:
		rcc = RCC_GPIOG;
		break;
	default:
		assert (false); // Unknown GPIO port;
		break;
	}

	return rcc;
}

/* Public routines
 * --------------------------------------------------------------------------- */
led_t*
led_new (int id, uint32_t gpioport, uint16_t gpiobit, bool is_active_low)
{
	assert (leds_in_use < NOF_LEDS);

	uint32_t new_led_idx = leds_in_use;
	led_t *led = &led_pool[new_led_idx];

	led->id = id;
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
	return led;
}

void
led_init(void)
{
	rcc_periph_clock_enable (RCC_GPIOB);

	gpio_set_mode (GPIOB, GPIO_MODE_OUTPUT_2_MHZ, GPIO_CNF_OUTPUT_PUSHPULL,
			GPIO1 | GPIO2);

	gpio_set (GPIOB, GPIO1 | GPIO2);
}

void
led_on (uint32_t id)
{
	(void)id;
	gpio_clear (GPIOB, GPIO1 | GPIO2);
}

void
led_off (uint32_t id)
{
	(void)id;
	gpio_set (GPIOB, GPIO1 | GPIO2);
}

void
led_toggle (uint32_t id)
{
	(void)id;
	gpio_toggle (GPIOB, GPIO1 | GPIO2);
}
