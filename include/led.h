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

typedef struct led_t led_t;

#define NOF_LEDS  2

led_t* led_new (uint32_t gpioport, uint16_t gpiobit, int id, bool is_active_low);
led_t* led_get (int led_id);

void led_init (void);
void led_on (uint32_t id);
void led_off (uint32_t id);
void led_toggle (uint32_t id);


#endif // LED_H
