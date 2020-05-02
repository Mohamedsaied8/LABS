/*
 * SPI.c
 *
 * Created: 5/2/2020 12:44:53 PM
 *  Author: infin
 */ 
#include "SPI.h"
#include <avr/io.h>


void SPI_Init(){
	
	//Master Mode CLK/16
	SPI->SPCR_REG=(1<<MSTR)|(1<<SPE)|(1<<SPR0);

}