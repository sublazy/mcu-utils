/*
 * Copyright (c) 2016 Cezary Sałbut
 *
 * This file is subject to the terms of the MIT license. If a copy of
 * the MIT license was not distributed with this file, You can obtain
 * one at https://opensource.org/licenses/MIT.
 */

#ifndef TTY_H
#define TTY_H

#include "headers_all.h"

/* Configuration
 * --------------------------------------------------------------------------- */
#define TTY_CLK_GPIO  RCC_GPIOA
#define TTY_CLK_USART RCC_USART1
#define TTY_BAUDRATE  115200
#define UART_PORT_TX  GPIOA
#define UART_PORT_RX  GPIOA
#define UART_PIN_TX   GPIO9
#define UART_PIN_RX   GPIO10

/* Routines
 * --------------------------------------------------------------------------- */
void tty_init(void);

#endif // TTY_H
