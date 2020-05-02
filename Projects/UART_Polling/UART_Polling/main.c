/*
 * UART_Polling.c
 *
 * Created: 5/1/2020 3:33:32 PM
 * Author : Mohamed
 
 Requirements:
	Application to communicate with Bluetooth
	UART interface
	Baud Rate 9600bps
	No party
	One stop bit
	Frame size of 8 bits
 */ 

#define F_CPU	16000000
#include <util/delay.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#define BAUD 9600
#define BAUD_EQ		((F_CPU/(BAUD*16UL))-1)

 void uart_Init();
 void uartSend(char data);
 void uartSendString(char *str);
 unsigned char uartReceive();
/*
typedef struct{

	unsigned short int baud_rate;
	unsigned char parity;
	unsigned char frame_size;
	unsigned char stop_bits;
		
	
}uart_cfg;
typedef enum{
	NO_PARITY,
	ODD_PARITY,
	EVEN_PARITY
}parity_type;
typedef enum{
	5_BITS,
	6_BITS,
	7_BITS,
	8_BITS,
	9_BITS
}framesize_type;
	uart_cfg uart_config={9600,NO_PARITY,8_BITS,1}
*/
 void uart_Init(){
	  //Initialize Baud rate
	  UBRRL=BAUD_EQ;
	  //TXEN and Receive
	  UCSRB=(1<<RXCIE)|(1<<TXEN)|(1<<RXEN);
	  //frame size 8 bis , no parity , one stop bit
	  UCSRC=(1<<URSEL)|(1<<UCSZ0)|(1<<UCSZ1);
 }
 //uart send char
 void uartSend(char data){
	 //Send data
	 while(!(UCSRA&(1<<UDRE)));//polling
	 UDR=data;
 }
 //uart receive
 unsigned char uartReceive(){
	 //
	 while(!(UCSRA&(1<<RXC)));
	 return UDR;
 }
 //uart send string
void uartSendString(char *str){
	
	unsigned char i=0;
	while(str[i]!='\0'){
		uartSend(str[i]);	
		i++; 
	 }//while
}
volatile char recv_buf,recv_flag,recv_byte;
int main(void)
{

	
   uart_Init();
	 sei();
	uartSendString("Welcome to Interfacing\r\n");	
	 char i=0;
    while (1) 
    {
		
		if(recv_flag!=0){
			
			i++;
			recv_buf[i]=recv_byte;
			recv_flag=0;
		}
		
//	unsigned char cmd = uartReceive();
	uartSendString("Robot Command\r\n");	
	
	_delay_ms(1000);
    }//while
}//main


ISR(USART_RXC_vect){
	
	recv_flag=1;
	recv_byte=UDR;
	
}
