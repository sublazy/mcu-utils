/*
 * Copyright (c) 2016 Cezary Sałbut
 *
 * This file is subject to the terms of the MIT license. If a copy of
 * the MIT license was not distributed with this file, You can obtain
 * one at https://opensource.org/licenses/MIT.
 */


/*
 * This file contains various items that do not (yet) belong to any
 * specific category.
 */

#ifndef MISC_H
#define MISC_H

// Macros from libopencm3, not shared via public headers.
#define RCC_REG(i)  MMIO32(RCC_BASE + ((i) >> 5))
#define RCC_BIT(i)  (1 << ((i) & 0x1f))

// Syntactic sugar for conditional compilation.
// Inspired by linux kernel and Kconfig.
#define IS_ENABLED(tok_1_or_0)  (tok_1_or_0)

#endif // MISC_H
