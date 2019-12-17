

# Digital meters for measuring electrical and physical quantities
#### Table of Contents

1. [Introduction](#introduction)
2. [Schematic](#Schematic)
2. [Hardware](#hardware)
3. [Software](#software)
4. [References](#references)


## Introduction

Our objective is to program meters that will measure electrical and physical quantities with the possibility of repeated measurement and data logging so that the data can be later exported to a computer. In this project, we managed to program meters that measure  voltage, Resistance and Light intensity. A simple Voltage divider was used to obtain a voltage(which corresponds to the measured quantity) that is converted by the ADC to digital form.The obtained value is then recalculated to obtain a data representation of the actual value of the measured quantity that is sent  to the LCD for display and through UART to PuTTY SSH Client for logging.

## Schematic

![](https://github.com/EvansLiyambo/Digital-electronics-2/blob/master/projects/project/voltage_divider.jpg)


## Hardware

Arduino UNO board 
Arduino LCD keypad shield



## Software

Microsoft Visual studio
PuTTY SSH Client

## Schematic



## References

1. Microchip, [AVR 8-bit Toolchain for Windows, Linux, Mac OS X](https://www.microchip.com/mplab/avr-support/avr-and-arm-toolchains-c-compilers)
2. UART library developed by Peter Fleury,http://homepage.hispeed.ch/peterfleury/avr-software.html

