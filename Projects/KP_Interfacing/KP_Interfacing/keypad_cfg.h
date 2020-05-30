/*
 * keypad_cfg.h
 *
 * Created: 5/30/2020 4:00:34 PM
 *  Author: infin
 */ 


#ifndef KEYPAD_CFG_H_
#define KEYPAD_CFG_H_
#include "dio_types.h"


#define COL_NUM 4
#define ROW_NUM	4

#define ROW0	Dio_Channel_B5
#define ROW1	Dio_Channel_B6
#define ROW2	Dio_Channel_B7
#define ROW3	Dio_Channel_A0

#define COL0	Dio_Channel_C3
#define COL1	Dio_Channel_C4
#define COL2	Dio_Channel_C5
#define COL3	Dio_Channel_C6






//define key map
const uint8 Keypad_Map[16] =
{
	'1','2','3','A',
	'4','5','6','B',
	'7','8','9','C',
	'*','0','#','D'
};


#endif /* KEYPAD_CFG_H_ */