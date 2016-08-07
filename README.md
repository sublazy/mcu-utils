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

### Goals

The goal of this software is to facilitate creating new bare-metal microcontroller projects, and to free a developer from re-implementing the same basic utilities over and over again. However, I don't intend to create another huge, all-in-one, all-purpose project template monstrosity, as some MCU suppliers tend to do. Within this project, simplicity is placed in front of potential coverage of all use cases.

 - Self-contained, coherent modules
 - Take just one module, or as many as you wish.
 - Don't fight for days trying to carefully dissect from the template only the pieces you need in your project.
 - No support for multiple, slightly differing hardware variants of your target platform.

## Requirements and dependencies

 - libopencm3
 - arm-none-eabi gcc toolchain


## What platforms is it for?

In the initial phase, the project is targeted at STM32 family. STM32F103 is the MCU of choice for initial development.

