/*
 * Copyright (c) 2016 Cezary Sałbut
 *
 * This file is subject to the terms of the MIT license. If a copy of
 * the MIT license was not distributed with this file, You can obtain
 * one at https://opensource.org/licenses/MIT.
 */

#include "headers_all.h"

void
tim_delay_soft(uint32_t nof_cycles)
{
	volatile uint32_t cnt = nof_cycles;

	while (cnt--)
		;
}

#if IS_ENABLED (CFG_SYSTICK)
void
tim_delay_ms(uint32_t milliseconds)
{
	(void) milliseconds;
}
#else
void
tim_delay_ms(uint32_t milliseconds)
{
	(void) milliseconds;
}
#endif

