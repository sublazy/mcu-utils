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

#ifndef LED_ZL31_H
#define LED_ZL31_H

typedef enum led_id_zl31 {
        LED1,
        LED2,
        NOF_LEDS
} led_id_t;

void led_platform_init(void);

#endif // LED_ZL31_H
