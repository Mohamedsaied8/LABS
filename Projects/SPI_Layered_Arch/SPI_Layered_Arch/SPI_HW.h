/*
 * SPI_HW.h
 *
 * Created: 5/2/2020 4:31:02 PM
 *  Author: infin
 */ 


#ifndef SPI_HW_H_
#define SPI_HW_H_
#include "STD_Types.h"
//#define SPCR_REG	*((volatile uint8*)0x2D)
typedef struct  
{
	uint8 SPCR_REG; //0x2D
	uint8 SPSR_REG;
	uint8 SPDR_REG;
}SPI_Type;


#define SPI ((volatile SPI_Type*)0x2D)


#endif /* SPI_HW_H_ */