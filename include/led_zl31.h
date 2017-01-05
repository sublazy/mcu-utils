/*
 * Copyright (c) 2016, 2017 Cezary Sałbut
 *
 * This file is subject to the terms of the MIT license. If a copy of
 * the MIT license was not distributed with this file, You can obtain
 * one at https://opensource.org/licenses/MIT.
 */

#ifndef LED_ZL31_H
#define LED_ZL31_H

typedef enum led_id_zl31 {
	LED1,
	LED2,
	NOF_LEDS
}led_id_t;

void led_platform_init(void);

#endif // LED_ZL31_H
