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
  Dio_WriteChannel(Dio_Channel_A0,STD_HIGH);//activate pull-up
    while (1) 
    {
		if(Dio_ReadChannel(Dio_Channel_A0)==STD_LOW){
			_delay_ms(30);
			Dio_WritePort(Dio_PortD,0xFF);
			//Dio_WriteChannel(Dio_Channel_D3,STD_HIGH);
			_delay_ms(100);
		}
		else{
		    Dio_WritePort(Dio_PortD,0x00);
		//	Dio_WriteChannel(Dio_Channel_D3,STD_LOW);
			_delay_ms(100);
		}
		
		
	}
}

