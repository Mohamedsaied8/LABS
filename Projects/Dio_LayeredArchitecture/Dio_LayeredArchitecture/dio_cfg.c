/*
 * dio_cfg.c
 *
 * Created: 5/29/2020 1:41:28 PM
 *  Author: infin
 */ 
#include "dio_cfg.h"
#include "bit_math.h"
#include "dio_hw.h"

const Dio_PinType pin_cfg[PINCOUNT]={
/*PA0*/	{Input,STD_HIGH},
/*PA1*/	{Input,STD_HIGH}, //input with pull-up
/*PA2*/	{Output,STD_LOW},
/*PA3*/	{Output,STD_LOW},
/*PA4*/	{Output,STD_LOW},
/*PA5*/	{Output,STD_HIGH}, //input with pull-up
/*PA6*/	{Output,STD_LOW},
/*PA7*/	{Output,STD_LOW},
/*PB0*/	{Output,STD_LOW},
/*PB1*/	{Output,STD_HIGH}, 
/*PB2*/	{Output,STD_LOW},
/*PB3*/	{Output,STD_LOW},
/*PB4*/	{Output,STD_LOW},
/*PB5*/	{Input,STD_HIGH}, //input with pull-up
/*PB6*/	{Output,STD_LOW},
/*PB7*/	{Output,STD_LOW},	
/*PC0*/	{Output,STD_LOW},
/*PC1*/	{Input,STD_HIGH}, //input with pull-up
/*PC2*/	{Output,STD_LOW},
/*PC3*/	{Output,STD_LOW},
/*PC4*/	{Output,STD_LOW},
/*PC5*/	{Input,STD_HIGH}, //input with pull-up
/*PC6*/	{Output,STD_LOW},
/*PC7*/	{Output,STD_LOW},
/*PD0*/	{Output,STD_LOW},
/*PD1*/	{Output,STD_HIGH}, //input with pull-up
/*PD2*/	{Output,STD_LOW},
/*PD3*/	{Output,STD_LOW},
/*PD4*/	{Output,STD_LOW},
/*PD5*/	{Output,STD_HIGH}, //input with pull-up
/*PD6*/	{Output,STD_LOW},
/*PD7*/	{Output,STD_LOW}
	
	
};

void Dio_Init(){
	
	//loop on all pins , set DDR 
	uint8 counter;
	for(counter=Dio_Channel_A0;counter<PINCOUNT;counter++){
		Dio_PortType portx=counter/8;
		Dio_ChannelType pos=counter % 8;
		if (pin_cfg[counter].pinDirection==Output)
		{
			switch (portx)
			{
				case Dio_PortA:
						SET_BIT(DDRA_REG,pos);
						break;
				case Dio_PortB:
						SET_BIT(DDRB_REG,pos);
						break;
				case Dio_PortC:
						SET_BIT(DDRC_REG,pos);
						break;
				case Dio_PortD:
						SET_BIT(DDRD_REG,pos);
						break;
			}//switch
		}//if
		else{
			switch (portx)
			{
				case Dio_PortA:
					CLEAR_BIT(DDRA_REG,pos);
					break;
				case Dio_PortB:
					CLEAR_BIT(DDRB_REG,pos);
					break;
				case Dio_PortC:
					CLEAR_BIT(DDRC_REG,pos);
					break;
				case Dio_PortD:
					CLEAR_BIT(DDRD_REG,pos);
					break;
			}
		}
		
}//for loop
	
}//function