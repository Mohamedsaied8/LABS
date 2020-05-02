/*
 * SPI_Mstr.c
 *
 * Created: 5/2/2020 10:36:27 AM
 * Author : infin
 */ 
#define CS		0
#define MOSI	5
#define SCK		7
#define LED0	2
#define F_CPU		16000000

#include "SPI.h"
#include <util/delay.h>
#include <avr/io.h>


unsigned char SPI_Transfer(unsigned char sendByte){
	
	//PORTB&=~(1<<4);
	SPDR=sendByte;
	while(!(SPSR&(1<<SPIF)));
	return SPDR;
}

int main(void)
{ 
	SPI_Init();
		// Set MOSI, SCK as Output
		DDRB=(1<<MOSI)|(1<<SCK);
		DDRB|=(1<<CS);
	//LED0
	DDRC|=(1<<LED0)|(1<<CS);
	//PORTB|=(1<<CS);
	PORTC&=~(1<<CS);

    while (1) 
    {
		
		
		 //slave select
		  PORTC&=~(1<<CS);
		char recvByte=SPI_Transfer('1');
		//slave select Disable
		PORTC|=(1<<CS);
		if (recvByte=='2')
		{
		 	PORTC^=(1<<LED0);//PC2
			_delay_ms(1000);
		}
		 
    }//while
}//main

