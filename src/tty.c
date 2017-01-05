/*
 * Copyright (c) 2016 Cezary Sałbut
 *
 * This file is subject to the terms of the MIT license. If a copy of
 * the MIT license was not distributed with this file, You can obtain
 * one at https://opensource.org/licenses/MIT.
 */

#include "headers_all.h"

#ifdef assert
#undef assert
#define assert(condition) do { } while (0)
#endif

/* Private types
 * --------------------------------------------------------------------------- */

/* Private data
 * --------------------------------------------------------------------------- */

/* Private prototypes
 * --------------------------------------------------------------------------- */

/* Private routines
 * --------------------------------------------------------------------------- */

/* Public routines
 * --------------------------------------------------------------------------- */
void tty_init(void)
{
	rcc_periph_clock_enable(TTY_CLK_USART);
	rcc_periph_clock_enable(RCC_AFIO);
	rcc_periph_clock_enable(TTY_CLK_GPIO);

	gpio_set_mode(UART_PORT_TX,
		      GPIO_MODE_OUTPUT_2_MHZ,
		      GPIO_CNF_OUTPUT_ALTFN_PUSHPULL,
		      UART_PIN_TX);

	gpio_set_mode(UART_PORT_RX,
		      GPIO_MODE_OUTPUT_2_MHZ,
		      GPIO_CNF_OUTPUT_ALTFN_PUSHPULL,
		      UART_PIN_RX);

	uint32_t mode = USART_MODE_TX_RX;
	uint32_t baud = TTY_BAUDRATE;
	uint32_t nof_stopbits = 1;

	usart_set_mode(USART1, mode);
	usart_set_baudrate(USART1, baud);
	usart_set_stopbits(USART1, nof_stopbits);
	usart_enable(USART1);
}
