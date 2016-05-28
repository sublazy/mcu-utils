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
