/*
 * spi_types.h
 *
 * Created: 5/2/2020 4:43:09 PM
 *  Author: infin
 */ 


#ifndef SPI_TYPES_H_
#define SPI_TYPES_H_

typedef enum{
	SLAVE=0,
	MASTER
}DeviceMode_Type;


typedef enum{
	MODE0=0,
	MODE1,
	MODE2,
	MODE3
}ClokMode_Type;

typedef enum{
	MSB=0,
	LSB
}DataOrder_Type;

typedef enum{
	FOSC_DIV4=0,
	FOSC_DIV16 //0000 00001
}SpeedRate_Type;

typedef enum{
POLLING,
INTERRUPT_EN
}InterruptMode_Type;
typedef enum{
DISABLED,	
ENABLED
}SPI_EN_Type;

#endif /* SPI_TYPES_H_ */