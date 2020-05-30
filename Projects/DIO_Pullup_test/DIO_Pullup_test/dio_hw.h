/*
 * dio_hw.h
 *
 * Created: 5/23/2020 2:55:12 PM
 *  Author: Mohamed
 */ 


#ifndef DIO_HW_H_
#define DIO_HW_H_
#include "STD_Types.h"

#define PINA_REG	*((volatile const uint8*)0x39)  //read only
#define DDRA_REG   *((volatile uint8 *) 0x3A)
#define PORTA_REG    *((volatile uint8*)0x3B)

#define PINB_REG	*((volatile const uint8*)0x36)  //read only
#define DDRB_REG    *((volatile uint8 *) 0x37)
#define PORTB_REG    *((volatile uint8*)0x38)


#define PINC_REG	*((volatile const uint8*)0x33)  //read only
#define DDRC_REG    *((volatile uint8 *) 0x34)
#define PORTC_REG    *((volatile uint8*)0x35)


#define PIND_REG	*((volatile const uint8*)0x30)  //read only
#define DDRD_REG    *((volatile uint8 *) 0x31)
#define PORTD_REG    *((volatile uint8*)0x32)



#endif /* DIO_HW_H_ */