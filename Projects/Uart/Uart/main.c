/*
 * Uart.c
 *
 * Created: 5/1/2020 12:47:02 PM
 * Author : infin
 */ 

#define F_CPU	16000000
#include <avr/io.h>
#include <util/delay.h>

#define BAUD   9600
#define BAUD_EQ		((F_CPU/(BAUD*16UL))-1)
char uartReceive();
void uartInit();
void uartSend(char data);

int main(void)
{
	
	uartInit();
	while (1)
	{
		
		uart_sendString("Mohamed\r\n");
		_delay_ms(1000);
	}
}

void uartInit(){
	//Select Baud Rate
	UBRRL=BAUD_EQ;
	//Enable RX and TX
	UCSRB =(1<<RXEN)|(1<<TXEN);
	//select frame size and number of stop bits
	UCSRC=(1<<7)|(1<<1) | (1<<2);
}

void uartSend(char data){
	
	while( !(UCSRA & (1<<UDRE)));
	UDR=data;
}

char uartReceive(){
	while( !(UCSRA & (1<<RXC)));
	return UDR;
}
void uart_sendString(char *str){
	char i=0;
	while(str[i]!='\0'){
		uartSend(str[i]);
		i++;
	}
}