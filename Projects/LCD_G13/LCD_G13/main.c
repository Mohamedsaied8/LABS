/*
 * LCD_G13.c
 *
 * Created: 5/30/2020 1:25:07 PM
 * Author : Mohamed
 
 *LCD Driver:
 *initialize lcd in 4 bits mode
 *function for sending command to LCD
 *function send one Character to LCD
 *function send String
 
 lcd.c
 lcd.h
 */ 

#include <avr/io.h>
#include "lcd.h"

int main(void)
{
	LCD_Init();
	LCD_Command(0x80);
    LCD_String("Amit-Learning");
    while (1) 
    {
    }
}

