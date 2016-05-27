# Microcontroller utilities

## What is it?

This software is a collection of software utilities useful in every
bare-metal microcontroller application. The utilities include:

 - LED driver
 - Hardware-based software timers
 - Command shell, accessible over serial port
 - Multi-level debugging macros
 - Bit manipulation macros
 - State machine engine
 - Button driver
 - Human interface thread template
 - Program tracing and profiling engine
 - Lightweight task scheduler
 - Test support utilities


## Requirements and dependencies

 - libopencm3
 - arm-none-eabi gcc toolchain


## What platforms is it for?

In the initial phase, the project is targeted at STM32 family. STM32F103
is the MCU of choice for initial development.
