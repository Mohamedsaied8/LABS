/*
 * SPI.h
 *
 * Created: 5/2/2020 12:45:08 PM
 *  Author: infin
 */ 


#ifndef SPI_H_
#define SPI_H_


typedef struct{
unsigned char SPCR_REG;
unsigned char SPSR_REG;
unsigned char SPDR_REG;
}SPI_Type;

#define SPI ((volatile SPI_Type*)0x2D)
#endif /* SPI_H_ */