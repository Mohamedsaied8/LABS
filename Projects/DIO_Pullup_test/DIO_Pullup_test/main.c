/*
 * DIO_Pullup_test.c
 *
 * Created: 5/23/2020 12:50:11 PM
 * Author : Mohamed
 */ 





#define F_CPU 16000000
//#include <avr/io.h>
#include <util/delay.h>

#include "bit_math.h"
#include "STD_Types.h"
#include "app_cfg.h" //config your app pins


int main(void)
{
	//const int x=5;
//	DDRC=0x00;//all pins are inputs
	//PA0 -active low button
	CLEAR_BIT(BUTTON_DDR,BUTTON);
	SET_BIT(Button_PORT,BUTTON); //enable pull-up
	//CLEAR_BIT(SFIOR,PUD); //PUD=0
	SET_BIT(LED_DDR,LED);//LED
	
    while (1) 
    {
		if (GET_BIT(Button_PIN,BUTTON)==LOW)
		{ _delay_ms(30);
			//LED ON
			LED_ON();
			//SET_BIT(LED_PORT,LED);
			_delay_ms(100);
		}
		else
		CLEAR_BIT(LED_PORT,LED);
    }
}

