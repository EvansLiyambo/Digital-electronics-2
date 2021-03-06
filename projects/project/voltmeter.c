
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
 *  Brief: Timer1 overflow interrupt routine. Start ADC conversion.
 */
ISR(TIMER1_OVF_vect)
{
    //  Start ADC conversion

     ADCSRA |= _BV(ADSC);
}

/**
 *   ADC complete interrupt routine. Update LCD and UART 
 *         transmiter.
 */
    // Function for measuring Voltage.


//Voltmeter
    void Voltmeter(void)
{
    float V_out = 0;
    float V_in ;
    uint16_t R1 = 470;
    uint16_t R2 = 470;
    char uart_string[4];

	// Read 10-bit ACD value and converting it to voltage (ADC*5/1023)
     V_out = ADC*0.004888;

    // Calculating the input voltage
     V_in = (V_out*(R1+R2))/R2;

    // Update LCD and UART transmiter
       
    uart_puts("Voltage = ");
    dtostrf(V_in, 5, 3, uart_string);
     
    uart_puts(uart_string); 
    uart_puts(" V\r\n");

    lcd_puts("Voltmeter");
    lcd_gotoxy(0,1);
    lcd_puts(uart_string); 
    lcd_gotoxy(8,1);
    lcd_puts("V        ");
}

ISR(ADC_vect)
{
  
         Voltmeter();

}