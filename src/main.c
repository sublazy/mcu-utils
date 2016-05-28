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

static char get_char(void);
static int is_char_incoming(void);

static void uart_init(void)
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

static bool is_uart_tx_busy (uint32_t uart)
{
	if (USART_SR(uart) & USART_SR_TXE)
		return false;
	else
		return true;
}

static char get_char()
{
	return (USART_DR(USART1));
}

static void put_char(char c)
{
	while (is_uart_tx_busy(USART1))
		;
	USART_DR(USART1) = c;
}

static int is_char_incoming()
{
	return (USART_SR(USART1) & USART_SR_RXNE);
}

int main(void)
{
	led_init();
	uart_init();

	for (int i = 0; i < 3; i++) {
		led_on (0);
		tim_delay_soft(50000);
		led_off (0);
		tim_delay_soft(50000);
	}

	while (1) {
		led_off (0);

		if (is_char_incoming()) {
			led_on (0);
			char c = get_char();
			put_char(c);
		}
	}
	return 0;
}
