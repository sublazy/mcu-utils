/*
 * Copyright (c) 2016 Cezary Sałbut
 *
 * This file is subject to the terms of the MIT license. If a copy of
 * the MIT license was not distributed with this file, You can obtain
 * one at https://opensource.org/licenses/MIT.
 */

#ifndef LED_H
#define LED_H

#include "headers_all.h"

enum led_id {
	LED_ID_STATUS,
	LED_ID_COMM,
	LED_ID_LAST,
};

void led_init(void);
void led_on (uint32_t id);
void led_off (uint32_t id);
void led_toggle (uint32_t id);


#endif // LED_H
