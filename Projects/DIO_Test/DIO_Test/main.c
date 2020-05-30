/*
 * DIO_Test.c
 *
 * Created: 5/22/2020 12:43:41 PM
 * Author : Mohamed
 *Interface LED PC2 -- Active High
 * 1) Data Direction of PC2 to be output =1
 * 2)Output Register PORT PC2 =1
 */ 
//Internal OSC 1 ~ Mhz 
//Ext 16Mhz << for Atmega32
#define F_CPU 16000000
#include <avr/io.h>//address of all registers
#include <util/delay.h>
#include "bit_math.h"
#include "STD_Types.h"


#define  BUZZER  3 //PA3
#define BUTTON2  2// PD2
#define BUTTON0  0//PB0
#define LED0     2//PC2
#define LED2	 3//PD3

#define Buzzer_DDR	DDRA

#define Buzzer_Port	PORTA
	
#define LED0_DDR	DDRC


void Initialize_modules(){
		//PA3
		SET_BIT(Buzzer_DDR,BUZZER);
		//Data Direction of PC2 to be output
		SET_BIT(LED0_DDR,LED0);
		//Data Direct for Button at B0 to be input pin
		//  DDRB&=~(1<<0);
		CLEAR_BIT(DDRB,BUTTON0);
		//LED2 on PD3 to be output pin
		SET_BIT(DDRD,LED2);
		//button2 PD2
		CLEAR_BIT(DDRD,BUTTON2);
		
		//relay PA2 as output
		SET_BIT(DDRA,2);
}
int main(void)
{	
	Initialize_modules();
    while (1) 
    {
		SET_BIT(PORTA,2);
		_delay_ms(1000);
		CLEAR_BIT(PORTD,LED2);
		_delay_ms(1000);


		SET_BIT(PORTD,LED2);
		_delay_ms(50);
		CLEAR_BIT(PORTD,LED2);
		_delay_ms(50);
		
	//check if button is pressed on PD2
	if(GET_BIT(PIND,BUTTON2)==HIGH){	//get_bit???
		_delay_ms(30); //debounce time 
		//provide output =1
		//TOGGLE_BIT(Buzzer_Port,BUZZER); //xor? 
		
	}
	else{
		//CLEAR_BIT(PORTC,2);
		//CLEAR_BIT(PORTD,3);
	}//else
    }//while
	
}//main

