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
	RCC_REG(RCC_GPIOB) |= RCC_BIT(RCC_GPIOB);

	GPIO_CRL(GPIOB) &= ~0xFF0;
	GPIO_CRL(GPIOB) |=
		(GPIO_MODE_OUTPUT_2_MHZ << 8) |
		(GPIO_MODE_OUTPUT_2_MHZ << 4);

	GPIO_BSRR(GPIOB) |= 0x6;
}

void
led_on (uint32_t id)
{
	(void)id;
	GPIO_BRR(GPIOB) |= 0x6;
}

void
led_off (uint32_t id)
{
	(void)id;
	GPIO_BSRR(GPIOB) |= 0x6;
}

void
led_toggle (uint32_t id)
{
	(void)id;
}
