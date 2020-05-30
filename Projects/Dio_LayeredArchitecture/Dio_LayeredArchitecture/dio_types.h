/*
 * dio_types.h
 *
 * Created: 5/29/2020 11:18:42 AM
 *  Author: infin
 */ 
//Channel Type
//PORT Type

#ifndef DIO_TYPES_H_
#define DIO_TYPES_H_

//
typedef enum{
	Dio_Channel_A0, //0
	Dio_Channel_A1,
	Dio_Channel_A2,
	Dio_Channel_A3,
	Dio_Channel_A4,
	Dio_Channel_A5,
	Dio_Channel_A6,
	Dio_Channel_A7,
	Dio_Channel_B0,
	Dio_Channel_B1,
	Dio_Channel_B2, 
	Dio_Channel_B3,
	Dio_Channel_B4,
	Dio_Channel_B5,
	Dio_Channel_B6,
	Dio_Channel_B7,
	Dio_Channel_C0,
	Dio_Channel_C1,
	Dio_Channel_C2,
	Dio_Channel_C3,
	Dio_Channel_C4,
	Dio_Channel_C5,
	Dio_Channel_C6,
	Dio_Channel_C7,	
	Dio_Channel_D0,	
	Dio_Channel_D1,
	Dio_Channel_D2,
	Dio_Channel_D3,
	Dio_Channel_D4,
	Dio_Channel_D5,
	Dio_Channel_D6,
	Dio_Channel_D7,//31
}Dio_ChannelType;

typedef enum{
	Dio_PortA, //0
	Dio_PortB,
	Dio_PortC,
	Dio_PortD//3
	
}Dio_PortType;

typedef enum{
	Input,
	Output
}Dio_DirType;

#endif /* DIO_TYPES_H_ */