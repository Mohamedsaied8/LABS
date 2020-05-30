/*
 * dio.h
 *
 * Created: 5/29/2020 11:43:50 AM
 *  Author: infin
 */ 


#ifndef DIO_H_
#define DIO_H_
#include "STD_Types.h"
#include "dio_types.h"
//prototypes
void Dio_WriteChannel(Dio_ChannelType channelId,STD_LevelType Level);
STD_LevelType Dio_ReadChannel(Dio_ChannelType channelId);
void Dio_WritePort(Dio_PortType,uint8 value);
//TODO : Read PORT

#endif /* DIO_H_ */