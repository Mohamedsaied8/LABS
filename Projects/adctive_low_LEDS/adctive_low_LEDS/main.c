/*
 * adctive_low_LEDS.c
 *
 * Created: 5/22/2020 3:48:43 PM
 * Author : Mohamed
 */ 
#define F_CPU	16000000
#include <avr/io.h>
#include <util/delay.h>

int main(void)
{

	DDRD|=(1<<3);
    while (1) 
    {
		//ON Active Low LED
		PORTD&=~(1<<3);
		_delay_ms(100);
    }
}

