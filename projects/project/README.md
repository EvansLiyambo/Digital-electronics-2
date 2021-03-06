

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
    V_out = (ADC*Vref)/1023
 
 1.Voltage  is then calculated as follows:
 
    V_in = V_out(R1+R2)/R2    
   
    Where R1 and R2 have known resistance.
 
 2.Resistance is caculated as follows:
 
    R2 = (R1*V_out)/(V_in-V_out)
   
    Where R1 is a known resistance.
    
 3.LDR resistance is calculated as follows:
   
    LDR = (R1*V_out)/(V_in-V_out)
  
    Where R1 is a known resistance

## Hardware

Arduino UNO board ,
Arduino LCD keypad shield

## Software

Microsoft Visual studio,
PuTTY SSH Client

## References

1. Microchip, [AVR 8-bit Toolchain for Windows, Linux, Mac OS X](https://www.microchip.com/mplab/avr-support/avr-and-arm-toolchains-c-compilers)
2. UART library developed by Peter Fleury,http://homepage.hispeed.ch/peterfleury/avr-software.html
3. Video - https://www.youtube.com/watch?v=jFEycrZ0ezA&fbclid=IwAR0YLZLkZ3AY4rmHj69GYbvOjTtShyFzoAgjNzxsEtYiQ4EieZ8vyoofHTg
