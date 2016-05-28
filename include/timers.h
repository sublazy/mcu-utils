/*
 * Copyright (c) 2016 Cezary Sałbut
 *
 * This file is subject to the terms of the MIT license. If a copy of
 * the MIT license was not distributed with this file, You can obtain
 * one at https://opensource.org/licenses/MIT.
 */

#ifndef TIMERS_H
#define TIMERS_H

// Have you already activated hardware timers on your platform?
// If the macros below are '0', most of this module's functions will
// be compiled to nothing. They won't trigger any compilation errors though.
#define CFG_SYSTICK    0
#define CFG_HW_TIMERS  0

// Inaccurate, blocking, dumb delay, based on core clocking.
void tim_delay_soft(uint32_t nof_cycles);

// Accurate blocking delay.
// Needs CFG_SYSTICK = 1
void tim_delay_ms(uint32_t milliseconds);

#endif // TIMERS_H
