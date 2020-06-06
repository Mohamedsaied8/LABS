/*
 * External_Interrupt.c
 *
 * Created: 6/5/2020 1:36:49 PM
 * Author : infin
 */ 
#define F_CPU	16000000
#define LED1	7
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

volatile unsigned char flag=0;

int main(void)
{
	//LED1 as an output pin
	DDRC|=(1<<LED1);
   //configuratuon of INT0
   //Enable INT0--> PD2 =BUTTON2
   GICR|=(1<<INT0);
   //Generate Interrupt INT0 at Rising Edge
   MCUCR|=(1<<ISC00)|(1<<ISC01);
   //enable Global Interrupt
   sei();
   
   DDRD &=~(1<<2);
   PORTC&=~(1<<LED1);
   
    while (1) 
    {
		if(flag==1)
		{
			PORTC^=(1<<LED1);
			_delay_ms(100);
			flag=0;
		}
		
    }
}

//called by hardware
ISR(INT0_vect){
	flag=1;
}

