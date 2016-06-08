/*
 * Copyright (c) 2016 Cezary Sałbut
 *
 * This file is subject to the terms of the MIT license. If a copy of
 * the MIT license was not distributed with this file, You can obtain
 * one at https://opensource.org/licenses/MIT.
 */

/*
 * This file contains project-wide configuration settings.
 */

#ifndef CONFIG_H
#define CONFIG_H

// Do you want to use printf from standard library, or your own?
#define PROJ_CFG_STD_PRINTF     0
#define PROJ_CFG_OWN_PRINTF     (!PROJ_CFG_STD_PRINTF)

// Have you already activated hardware timers on your platform?
#define PROJ_CFG_SYSTICK        0
#define PROJ_CFG_HW_TIMERS      0

#endif // CONFIG_H
