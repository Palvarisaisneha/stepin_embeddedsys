/**
 * @file main.c
 * @author SAISNEHA
 * @brief embeddedsys project
 * @copyright Copyright (c) 2021
 * 
 */

#include <avr/io.h>
#include<util/delay.h>
 int main(void)
{
    SEAT_CHECKING(); //Initializing Drivers seat
    ADC_INITIALIZATION(); //Initializing ADC to accept temperature values
    TIMER_INITIALIZATION(); //Initializing Timer by dividing clock with 64 prescale
    LCD_INITIALIZATION(); //Initializing LCD

    uint16_t read;

	while(1)
    {
        if(SEAT_CHECK)
        {
            PORTD|=(1<<PD2);
            if(HEATER_ON){
                LED_ON;
                _delay_ms(200);
                CLEAR_LCD();
                read=SENSE_ADC(0);
                PWM_OUPUT(read);

            }
            else
                {
                    LED_OFF;
                     _delay_ms(200);
                    HEATER_OFF;
                    _delay_ms(200);
                    CLEAR_LCD();
                }
        }
        else{
            LED_OFF;
            _delay_ms(200);
            HEATER_OFF;
            _delay_ms(200);
            CLEAR_LCD();
        }
    }
    return 0;
}
