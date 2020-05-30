/*
 * dio_cfg.h
 *
 * Created: 5/29/2020 1:41:43 PM
 *  Author: infin
 */ 


#ifndef DIO_CFG_H_
#define DIO_CFG_H_
#include "STD_Types.h"
#include "dio_types.h"
#define PINCOUNT 32

typedef struct{
	Dio_DirType pinDirection;
	STD_LevelType pinLevel;//TODO
}Dio_PinType;

extern const Dio_PinType pin_cfg[PINCOUNT];
void Dio_Init();
#endif /* DIO_CFG_H_ */