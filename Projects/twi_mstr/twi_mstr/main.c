/*
 * twi_mstr.c
 *
 * Created: 5/8/2020 12:34:55 PM
 * Author : infin
 */ 
#include <avr/io.h>
#include <math.h>
#define F_CPU	16000000UL
#define SCL_FREQ100K	100000L
#define BITRATE(TWSR)	((F_CPU/SCL_FREQ100K)-16)/(2*pow(4,(TWSR&((1<<TWPS0)|(1<<TWPS1))))) /* Define bit rate */

#include <util/delay.h>

void TWI_Init(){
	
	TWBR=0x00; //clear bit rate register
	TWBR=BITRATE(TWSR=0x00); //no prescale
	
}
void TWI_Start(){
	TWCR=(1<<TWINT)|(1<<TWEN)|(1<<TWSTA);
	while(!(TWCR&(1<<TWINT)));
	while((TWSR&0xF8)!=0x08);
}
void TWI_addr(unsigned char addr){
	TWDR=addr;
	TWCR=(1<<TWINT)|(1<<TWEN);
	while(!(TWCR&(1<<TWINT)));
	while((TWSR&0xF8)!=0x18);
}
void TWI_write(unsigned char data){
	TWDR=data;
	TWCR=(1<<TWINT)|(1<<TWEN);
	while(!(TWCR&(1<<TWINT)));
	while((TWSR&0xF8)!=0x28);
}
int main(void)
{
    /* Replace with your application code */
    while (1) 
    {
    }
}

