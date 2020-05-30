/*
 * spi_cfg.c
 *
 * Created: 5/2/2020 4:40:32 PM
 *  Author: infin
 */ 
#include "spi_cfg.h"
#include "SPI_HW.h"
#include "spi_types.h"
#define  MSTR   4
	

const SPI_TYPE_CFG spi_cfg={
	MASTER,MODE0,FOSC_DIV16,MSB,POLLING,ENABLED
};

void SPI_Init(){
	
	if (spi_cfg.device_mode==MASTER)
	{
		SPI->SPCR_REG|=(1<<MSTR);
	}
	if(spi_cfg.clock_mode==MODE0){
		SPI->SPCR_REG&=~(1<<2);
		SPI->SPCR_REG&=~(1<<3);
	}
	
}