
#include <stdlib.h>             
#include <avr/io.h>
#include <avr/interrupt.h>
#include "timer.h"
#include "lcd.h"
#include "uart.h"
#include "stdio.h"

/* Typedef -----------------------------------------------------------*/
/* Define ------------------------------------------------------------*/
#define UART_BAUD_RATE 9600

/* Variables ---------------------------------------------------------*/
/* Function prototypes -----------------------------------------------*/

/* Functions ---------------------------------------------------------*/
/**
 *  Brief:  Main program. Read ADC result and transmit via UART.
 *  Input:  None
 *  Return: None
 */
int main(void)
{
    // LCD display
    lcd_init(LCD_DISP_ON);

    /* ADC
     * Configuring ADC reference, clock source, enable ADC module, 
     *       and enable conversion complete interrupt */
        ADMUX |=  _BV(REFS0);
        ADMUX &= ~_BV(REFS1);

        ADMUX |=  _BV(MUX0);
        ADMUX &= ~_BV(MUX1);
        ADMUX &= ~_BV(MUX2);
        ADMUX &= ~_BV(MUX3);                              // activating pin A1 

        ADCSRA |= _BV(ADPS0);
        ADCSRA |= _BV(ADPS1);
        ADCSRA |= _BV(ADPS2);
        
        ADCSRA |= _BV(ADEN);

        ADCSRA |= _BV(ADIE);
    
     
     
       
    /* Timer1
     *  ConfigurIing Timer1 clock source and enabling overflow 
     *       interrupt */
    TIM_config_prescaler(TIM1, TIM_PRESC_64);
    TIM_config_interrupt(TIM1, TIM_OVERFLOW_ENABLE);

    // UART: asynchronous, 8-bit data, no parity, 1-bit stop
    uart_init(UART_BAUD_SELECT(UART_BAUD_RATE, F_CPU));

    // Enables interrupts by setting the global interrupt mask
    sei();

    // Put string to ringbuffer for transmitting via UART.
    //uart_puts("UART testing\r\n");

    // Infinite loop
    for (;;) {
    

    }

    
    return (0);
}

/**
 * Timer1 overflow interrupt routine. Start ADC conversion.
 */
    ISR(TIMER1_OVF_vect)
{
    //  Start ADC conversion

     ADCSRA |= _BV(ADSC);
}

/**
 *  ADC complete interrupt routine. Update LCD and UART 
 *         transmiter.
 */
    // Function for measuring Resistance

//Ohmmeter
 void Ohmmeter(void)
{
     float V_out = 0;
     float V_in = 5;
     float R1 = 10000;
     float R2;
     char uart_string[10];

	// Reading 10-bit ACD value and converting it to voltage (ADC*5/1023)
    V_out = ADC*0.004888;

    // Calculating the input voltage
    R2 = (R1*V_out)/(V_in-V_out);

    // Updating LCD and UART transmiter
    if(R2<1000){
    uart_puts("Ohmmeter");
    dtostrf(R2, 5, 3, uart_string);
    
    uart_puts(uart_string); 
    uart_puts(" Ohms\r\n");

    lcd_puts("Ohmmeter");
    lcd_gotoxy(0,1);
    lcd_puts(uart_string); 
    lcd_gotoxy(7,1);
    lcd_puts("Ohms       ");
    }
    else{
    R2 = R2/1000;
    uart_puts("Ohmmeter\n\r");
    dtostrf(R2, 5, 3, uart_string);

    uart_puts(uart_string); 
    uart_puts(" Kilo Ohms\r\n");

    lcd_puts("Ohmmeter");
    lcd_gotoxy(0,1);
    lcd_puts(uart_string); 
    lcd_gotoxy(7,1);
    lcd_puts("Kilo Ohms       ");
    }
   
}



ISR(ADC_vect)
{
    //calling the functions
      Ohmmeter();

}