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
	RCC_REG(RCC_USART1) |= RCC_BIT(RCC_USART1);
	RCC_REG(RCC_GPIOA) |= RCC_BIT(RCC_GPIOA);
	RCC_REG(RCC_AFIO) |= RCC_BIT(RCC_AFIO);

	GPIO_CRH(UART_PORT) =
		(GPIO_MODE_OUTPUT_2_MHZ << 4) |
		(GPIO_CNF_OUTPUT_ALTFN_PUSHPULL	<< 6) |
		(GPIO_MODE_OUTPUT_2_MHZ << 8) |
		(GPIO_CNF_OUTPUT_ALTFN_PUSHPULL	<< 10) ;

	USART_CR1(USART1) =
		USART_CR1_RE |
		USART_CR1_TE ;

	USART_CR2(USART1) =
		USART_CR2_STOPBITS_1;

	uint32_t usart_clk = 8000000;
	uint32_t baud = 115200;

	USART_BRR(USART1) = ((2 * usart_clk) + baud) / (2 * baud);

	USART_CR1(USART1) |= USART_CR1_UE;
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
