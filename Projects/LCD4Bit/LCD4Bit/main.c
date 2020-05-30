/*
 * GccApplication1.c
 *
 * Created: 5/19/2019 11:12:00 AM
 * Author : Mohamed
 */ 

#include <avr/io.h>
#include "lcd.h"




int main(void)
{
   LCD_Init();			/* Initialization of LCD*/

   LCD_String("El hamdulelah");	/* Write string on 1st line of LCD*/
   LCD_Command(0xC0);		/* Go to 2nd line*/
   LCD_String("AMIT-Learning");	/* Write string on 2nd line*/
   while(1);
}

