/*
 * Copyright (c) 2016 Cezary Sałbut
 *
 * This file is subject to the terms of the MIT license. If a copy of
 * the MIT license was not distributed with this file, You can obtain
 * one at https://opensource.org/licenses/MIT.
 */

#include "headers_all.h"

typedef struct led_class {
	uint32_t gpio;
	bool is_on;
	bool is_active_low;
} led_class_t;

/* Public routines
 * --------------------------------------------------------------------------- */
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
