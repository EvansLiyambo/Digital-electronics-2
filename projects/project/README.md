

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

![voltage divider](https://github.com/EvansLiyambo/Digital-electronics-2/blob/master/projects/project/voltage_divider.png)

calcuations to obtain actual level of the measured quantity:
   𝑉out= (𝐴𝐷𝐶 ∗𝑉𝑟𝑒𝑓)/1023
   where V ref if the reference voltage of the ADC. 
 
 1.Voltage  is then calculated as follows
   Vin = Vout(R1+R2)/R2               
   
   Where R1 and R2 have known resistance.
 
 2.Resistance is caculated as follows
   R2=(R1*Vout)/(V_in-Vout)
   
   where R1 is known resistance.
    
 3.LDR resistance.
    LDR = ldr = (R1*V_out)/(V_in-V_out)
    where R1 is the known resistance .

## Hardware

Arduino UNO board ,
Arduino LCD keypad shield



## Software

Microsoft Visual studio,
PuTTY SSH Client

## Schematic



## References

1. Microchip, [AVR 8-bit Toolchain for Windows, Linux, Mac OS X](https://www.microchip.com/mplab/avr-support/avr-and-arm-toolchains-c-compilers)
2. UART library developed by Peter Fleury,http://homepage.hispeed.ch/peterfleury/avr-software.html

