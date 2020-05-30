/*
 * spi_cfg.h
 *
 * Created: 5/2/2020 4:36:38 PM
 *  Author: infin
 */ 


#ifndef SPI_CFG_H_
#define SPI_CFG_H_
#include "STD_Types.h"

typedef struct{
	//mstr or salve
	uint8 device_mode;
	//cpol cpha mode
	uint8 clock_mode;
	//speed
   uint8 speed;
	//dord
	uint8 data_order;
	//interrupt or polling
	uint8 interrupt_mode;
	//enable or disable
	uint8 spi_enable;

}SPI_TYPE_CFG;


extern const SPI_TYPE_CFG spi_cfg;

#endif /* SPI_CFG_H_ */