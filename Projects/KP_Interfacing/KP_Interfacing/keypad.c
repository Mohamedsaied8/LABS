/*
 * keypad.c
 *
 * Created: 5/30/2020 4:00:09 PM
 *  Author: infin
 */ 
#include "keypad.h"

#include "keypad_cfg.h"

#define KEY_RELEASE	255

uint8 keypressed=KEY_RELEASE;

static void checkcol(uint8 row){
	
	if (Dio_ReadChannel(COL0)==STD_low)
	{
		keypressed=row*COL_NUM+0;
		
	}
	else if (Dio_ReadChannel(COL1)==STD_low)
	{
		keypressed=row*COL_NUM+1;
			
	}
	else if (Dio_ReadChannel(COL2)==STD_low)
	{
		keypressed=row*COL_NUM+2;
		
	}
	else if (Dio_ReadChannel(COL3)==STD_low)
	{
		keypressed=row*COL_NUM+3;
		
	}
}
uint8 GetKeypressed(){
	
	//row0 = Low , the rest of rows are high
	Dio_WriteChannel(ROW0,STD_low);
	Dio_WriteChannel(ROW1,STD_high);
	Dio_WriteChannel(ROW2,STD_high);
	Dio_WriteChannel(ROW3,STD_high);
	checkcol(0);
	
	Dio_WriteChannel(ROW0,STD_high);
	Dio_WriteChannel(ROW1,STD_low);
	Dio_WriteChannel(ROW2,STD_high);
	Dio_WriteChannel(ROW3,STD_high);
	checkcol(1);
	
	Dio_WriteChannel(ROW0,STD_high);
	Dio_WriteChannel(ROW1,STD_high);
	Dio_WriteChannel(ROW2,STD_low);
	Dio_WriteChannel(ROW3,STD_high);
	checkcol(2);
	
	Dio_WriteChannel(ROW0,STD_high);
	Dio_WriteChannel(ROW1,STD_high);
	Dio_WriteChannel(ROW2,STD_high);
	Dio_WriteChannel(ROW3,STD_low);
	checkcol(3);
	
return keypressed==KEY_RELEASE? KEY_RELEASE: Keypad_Map[keypressed];	
}