/*
 * Copyright (c) 2016 Cezary Sałbut
 *
 * This file is subject to the terms of the MIT license. If a copy of
 * the MIT license was not distributed with this file, You can obtain
 * one at https://opensource.org/licenses/MIT.
 */

#include "headers_all.h"

#ifdef assert
#undef assert
#define assert(condition) do { } while (0)
#endif

/* Private types
 * --------------------------------------------------------------------------- */

/* Private data
 * --------------------------------------------------------------------------- */

/* Private prototypes
 * --------------------------------------------------------------------------- */

/* Private routines
 * --------------------------------------------------------------------------- */

/* Public routines
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
