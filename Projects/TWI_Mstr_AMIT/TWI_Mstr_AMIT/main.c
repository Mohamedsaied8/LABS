/*
 * TWI_Mstr_AMIT.c
 *
 * Created: 5/8/2020 4:18:42 PM
 * Author : Mohamed
 Requirements:
 TWI communication bit rate 100khz 
 Master Mode : 'M'
 */ 
#include <math.h>
#define F_CPU 16000000UL
#define SCL_FRE100K	100000L
#define BIT_RATE(TWSR)			((F_CPU/SCL_FRE100K)/(16+2*pow(4,(TWSR&((1<<TWPS0)|(1<<TWPS1))))))
#include <avr/io.h>
#include <util/delay.h>

void TWI_Init(){
	TWBR=BIT_RATE(0x00);
	
}
void TWI_Start(){
	//send start
	TWCR=(1<<TWINT)|(1<<TWSTA) |(1<<TWEN);
	//check on the TWINT flag
	while(!(TWCR & (1<<TWINT)));
	//7:3=0xF8 1111 1 000
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
void  TWI_stop(){
	//stop condition
	TWCR=(1<<TWINT)|(1<<TWSTO)|(1<<TWEN);
	while(!(TWCR&(1<<TWINT)));
}
int main(void)
{
   TWI_Init();
    while (1) 
    {
		//start
		 TWI_Start();
		 _delay_ms(100);
		 //SLA+w
		 TWI_addr(0x30);
		 _delay_ms(100);
		 //data
		 TWI_write('M');
		 _delay_ms(100);
		 TWI_stop();	
    }
}

