/*
 * Dio_LayeredArchitecture.c
 *
 * Created: 5/29/2020 11:12:07 AM
 * Author : infin
 */ 

#define F_CPU 16000000
#include <util/delay.h>
#include "dio.h"
#include "dio_cfg.h"
#include "STD_Types.h"

int main(void)
{
  Dio_Init();
 // Dio_WriteChannel(Dio_Channel_A0,STD_HIGH);//activate pull-up
    while (1) 
    {
		//7 segment Enable
	 Dio_WriteChannel(Dio_Channel_B1,STD_HIGH);
	 Dio_WriteChannel(Dio_Channel_B2,STD_HIGH);
	//Display 1
	for(uint8 num=0;num<10;num++){
		Dio_WritePort(Dio_PortA,(num<<4));// PA7 PA6 PA5 PA4
		_delay_ms(1000);
	}
	
	
		
		
	}
}

