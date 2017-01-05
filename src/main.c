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
	printf ("\r\nReset ****************\r\n");

	//led_t *led1 = led_new(GPIOB, GPIO1, true);
	led_t *led2 = led_new(GPIOB, GPIO2, true);

	for (int i = 0; i < 12; i++) {
		led_toggle (led2);
		printf ("blink %d\r\n", i);
		tim_delay_soft(50000);
	}

	while (1) {
		static int i = -100000;
		printf ("%d\r\n", i++);
		tim_delay_soft(50000);
	}
	return 0;
}
