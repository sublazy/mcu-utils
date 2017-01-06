/* Copyright (c) 2016-2017 Cezary Salbut                              */
/*                                                                    */
/* This file is subject to the terms of the MIT license. If a copy of */
/* the MIT license was not distributed with this file, You can obtain */
/* one at https://opensource.org/licenses/MIT.                        */
/*                                                                    */

/* ********************** AUTO-GENERATED CODE **********************  */
/* NOTE: This file has been generated automatically. To re-generate   */
/* it, run 'make code'. You can edit this file manually to try out    */
/* things quickly; for permanent changes the following files should   */
/* be modified:                                                       */
// TODO: List the files used for generation.

#include "headers_all.h"

void led_platform_init(void)
{
        bool active_low;
        led_new(GPIOB, GPIO1, active_low = true);
        led_new(GPIOB, GPIO2, active_low = true);
}
