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

static void stdio_init(void)
{
	// TODO Give each module a 'required_clocks' parameter.
	// E.g. tty_required_clocks = RCC_USART1 | RCC_GPIOA | RCC_AFIO;
	rcc_periph_clock_enable(RCC_USART1);
	rcc_periph_clock_enable(RCC_GPIOA);
	rcc_periph_clock_enable(RCC_AFIO);

	gpio_set_mode(UART_PORT,
		      GPIO_MODE_OUTPUT_2_MHZ,
		      GPIO_CNF_OUTPUT_ALTFN_PUSHPULL,
		      UART_PIN_TX | UART_PIN_RX);

	uint32_t mode = USART_MODE_TX_RX;
	uint32_t baud = 115200;
	uint32_t nof_stopbits = 1;

	usart_set_mode(USART1, mode);
	usart_set_baudrate(USART1, baud);
	usart_set_stopbits(USART1, nof_stopbits);
	usart_enable(USART1);
}

/* Main program
 * --------------------------------------------------------------------------- */
int main(void)
{
	stdio_init();
	printf ("\r\nReset ****************\r\n");

	//led_t *led1 = led_new(GPIOB, GPIO1, true);
	led_t *led2 = led_new(GPIOB, GPIO2, true);

	for (int i = 0; i < 10; i++) {
		led_toggle (led2);
		printf ("blink %d\r\n", i);
		tim_delay_soft(500000);
	}

	while (1) {
		static int i = -100000;
		printf ("%d\r\n", i++);
		tim_delay_soft(50000);
	}
	return 0;
}
