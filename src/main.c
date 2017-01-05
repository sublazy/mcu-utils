/*
 * Copyright (c) 2016 Cezary Sałbut
 *
 * This file is subject to the terms of the MIT license. If a copy of
 * the MIT license was not distributed with this file, You can obtain
 * one at https://opensource.org/licenses/MIT.
 */

#include "headers_all.h"

#define UART_PORT     GPIOA
#define UART_PIN_TX   GPIO9
#define UART_PIN_RX   GPIO10

int main(void)
{
	tty_init();
	led_platform_init();

	printf ("\r\nReset ****************\r\n");

	led_t *led1 = led_get_obj(LED1);
	led_t *led2 = led_get_obj(LED2);
	led_on(led1);

	for (int i = 0; i < 12; i++) {
		led_toggle(led1);
		led_toggle(led2);
		printf ("blink %d\r\n", i);
		tim_delay_soft(50000);
	}
	led_off(led1);
	led_off(led2);

	while (1) {
		static int i = -100000;
		printf ("%d\r\n", i++);
		tim_delay_soft(50000);
	}
	return 0;
}
