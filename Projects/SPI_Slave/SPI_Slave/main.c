/*
 * SPI_Mstr.c
 *
 * Created: 5/2/2020 10:36:27 AM
 * Author : infin
 */ 

#define MISO	6
#define SCK		7
#define LED0	2
#define F_CPU		16000000


#include <util/delay.h>
#include <avr/io.h>

void SPI_Init(){
	SPCR=(1<<SPE);
	// Set MOSI, SCK as Output
	DDRB|=(1<<MISO);
	 
}
unsigned char SPI_Transfer(unsigned char sendByte){
	
	 SPDR=sendByte;
	while(!(SPSR&(1<<SPIF)));
 
	return SPDR;
}

int main(void)
{ 
	SPI_Init();
	//LED0
	DDRC|=(1<<LED0);
    while (1) 
    {
	unsigned char recvByte=SPI_Transfer('2');	
		if (recvByte=='1')
		{
			PORTC^=(1<<LED0);//PC2
			_delay_ms(1000);
		}
    }//while
}//main

