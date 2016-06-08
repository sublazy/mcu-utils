/*
 * Copyright (c) 2016 Cezary Sałbut
 *
 * This file is subject to the terms of the MIT license. If a copy of
 * the MIT license was not distributed with this file, You can obtain
 * one at https://opensource.org/licenses/MIT.
 */

#include "headers_all.h"

/* Module configuration
 * --------------------------------------------------------------------------- */
#define UART  USART1

/* Prototypes
 * --------------------------------------------------------------------------- */
static bool is_uart_tx_busy (uint32_t uart);
size_t _write (int fd, const void *buf, size_t count);

/* Private routines
 * --------------------------------------------------------------------------- */
#if 0 // will be needed for _read()
static char get_char()
{
	return (USART_DR(UART));
}
#endif

static bool is_uart_tx_busy (uint32_t uart)
{
	if (USART_SR(uart) & USART_SR_TXE)
		return false;
	else
		return true;
}

void put_char(unsigned char c)
{
	while (is_uart_tx_busy(UART))
		;
	USART_DR(UART) = c;
}

/* Public routines
 * --------------------------------------------------------------------------- */
size_t _write (int fd, const void *buf, size_t count)
{
	(void) fd;
	const char *c = buf;
	size_t i = 0;

	for (i = 0; i < count; i++) {
		put_char (*c);
		c++;
	}

	return i;
}
