/*
 * dio.c
 *
 * Created: 5/29/2020 11:47:52 AM
 *  Author: Mohamed
 */ 
#include "dio_types.h"
#include "dio_hw.h"
#include "dio.h"
#include "bit_math.h"


STD_LevelType Dio_ReadChannel(Dio_ChannelType ChannelId){
	
	STD_LevelType ret=STD_LOW;
	//which port?
	Dio_PortType portx=ChannelId/8;
	
	//position inside port?
	Dio_ChannelType pos=ChannelId % 8;
	switch (portx)
	{
		case Dio_PortA:
				ret= GET_BIT(PINA_REG,pos);
				break;
	    case Dio_PortB:
				ret= GET_BIT(PINB_REG,pos);
				break;
		case Dio_PortC:
				ret= GET_BIT(PINC_REG,pos);
				break;
		case Dio_PortD:
				ret= GET_BIT(PIND_REG,pos);
				break;	
		default:
		    break;		
				
	}
	return ret;
}
 
	 
void Dio_WriteChannel(Dio_ChannelType channelId,STD_LevelType Level){
	//port of the channel? 4 ports 0 ~ 3 
	
	 Dio_PortType portx=channelId/8; // 1/8=0 , 0~ 3
	 
	 //position of the channel inside the port 0~7
	 Dio_ChannelType pos= channelId % 8; //7
	 
	 switch(portx){
		 case Dio_PortA:
			
					if (Level==STD_HIGH)
					{
						SET_BIT(PORTA_REG,pos); // PORTA_REG |=(1<<1)
					}
					else{
						CLEAR_BIT(PORTA_REG,pos);
					}
					break;
					
		 case Dio_PortB:
		 	if (Level==STD_HIGH)
		 	{
			 	SET_BIT(PORTB_REG,pos); // PORTA_REG |=(1<<pos)
		 	}
		 	else{
			 	CLEAR_BIT(PORTB_REG,pos);
		 	}
		 	break;
		 case Dio_PortC:
			 if (Level==STD_HIGH)
			 {
				 SET_BIT(PORTC_REG,pos); // PORTA_REG |=(1<<pos)
			 }
			else{
				 CLEAR_BIT(PORTC_REG,pos);
			 }
			break;
		 case Dio_PortD:
			if (Level==STD_HIGH)
			{
				 SET_BIT(PORTD_REG,pos); // PORTA_REG |=(1<<pos)
			}
			else{
				 CLEAR_BIT(PORTD_REG,pos);
			}
			break;
		 
		default: break; 
	 }
	
	
}

void Dio_WritePort(Dio_PortType port,uint8 value){
	
	switch(port){
		case Dio_PortA:
				PORTA_REG=value;
				break;
		case Dio_PortB:
				PORTB_REG=value;
				break;
		case Dio_PortC:
				PORTC_REG=value;
				break;
		case Dio_PortD:
			PORTD_REG=value;
			break;
									
		default: break;
		
	}
	
}