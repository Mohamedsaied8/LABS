/*
 * ADC_Test.c
 *
 * Created: 6/6/2020 1:41:46 PM
 * Author : Mohamed
 * ADC-> Free Running Mode
 * No left Adjust 
 * Channel A1 --> POT
 * Vref = 2.56v Internal
 * Prescaler /128
 */ 
#define F_CPU	16000000
#include <util/delay.h>
#include <avr/io.h>
#include "lcd.h"
char temperature[20]="";
void ADC_Init(){
	//ADMUX=(1<<MUX0); //ADC1
	ADMUX|=(1<<REFS0) | (1<<REFS1);//Reference voltage is internal 2.56v
	//prescaler16/128 , Auto Trigger , ADC Enable
	ADCSRA|=(1<<ADEN)| (1<<ADATE) | (1<<ADPS0)|(1<<ADPS1)|(1<<ADPS2);	
	
}

unsigned int ADC_read(unsigned char channel){
	unsigned int result =0;
	ADMUX|=((1<<REFS0)|(1<<REFS1)) | (channel & 0x07);
	//start conversion
	ADCSRA|=(1<<ADSC);
	//check on ADIF flag 
	while(!(ADCSRA&(1<<ADIF)));
	ADCSRA|=(1<<ADIF);
	//Get Results
	result = ADCL;
	result|=(ADCH<<8); // ADCH(2 bits) | ADCL (8 bits) [ 1011011011]
	return result;
}
int main(void)
{
	DDRA&=~(1<<1);
	//LED0
	DDRC=0xFF;
	//ADC Init
	ADC_Init();	
	LCD_Init();	
   while (1) 
    {
	unsigned int adc_value =ADC_read(1);
	
	//eduation to convert volt readings into temperature in celisius
	//temp_celisius=adc_value*(stepsize/10mv)
	 //vref/no.levels=step size => 2.56/1024=2.5~  10 bits resolution 2^10=1024
	float cel = adc_value /4;
	//cel=cel/10;
	LCD_Clear();
	sprintf(temperature,"Temperature=%d",(unsigned int )cel);
	LCD_Command(0x80);
	LCD_String(temperature);
	if (cel>=38)
	{
		LCD_Command(0xC0);
		LCD_String("Beware Infection");
	}
	else{
		
	//LCD_Command(0xC0);
	//LCD_String("");
	}
	_delay_ms(3000);
	memset(temperature,0,20);
	}
}

