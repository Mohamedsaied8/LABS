/*
 * lcd.h
 *
 * Created: 5/30/2020 1:26:44 PM
 *  Author: infin
 */ 


#ifndef LCD_H_
#define LCD_H_
#define F_CPU 16000000
#include <avr/io.h>
#include <util/delay.h>


#define LCD_PORT		PORTA
#define LCD_CTRL		PORTB
#define LCD_Dir			DDRA
#define LCD_CTRL_Dir	DDRB
#define RS				1 //PB1
#define RW				2 //PB2
#define E				3 //PB3


//function prototypes
void LCD_Init();
void LCD_Command(char cmd);
void LCD_Char(char data);
void LCD_String(char* str);

//
void LCD_Clear();



#endif /* LCD_H_ */