# Overview

This repo contains experiments using the Digispark ATTINY85 development board.

## Dependencies

- Micronucleus bootloader and command line tool
- `gcc-avr`, `avr-libc`, `avr-binutils`
- Digispark ATTINY85 Development board

## Micronucleus

This document is going to skim over the details of building/flashing an updated Micronucleus bootloader. It's assumed you've already done this step.

## Building the Experiments

Each folder has a Makefile that will build the project and flash it to the Digispark. This development board is a little different from other boards to program. The basic workflow is to run the command to upload the new firmware and then plug in the board (`micronucleus` will wait). Check the Makefiles for details.


