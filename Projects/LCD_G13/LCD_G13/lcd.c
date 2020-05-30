/*
 * lcd.c
 *
 * Created: 5/30/2020 1:26:32 PM
 *  Author: infin
 */ 
#include "lcd.h"

void LCD_Init(){
	//Direction of Data pins
	LCD_Dir|=0xF0; //A4 to A7 are output
	//Direction of Control Pins
	LCD_CTRL_Dir|=(1<<RS)|(1<<RW)|(1<<E);
	LCD_CTRL&=~(1<<RW);//Write mode
	_delay_ms(20); 
	//initialize procedure
	LCD_Command(0x33);
	LCD_Command(0x32);
	LCD_Command(0x28);
	LCD_Command(0x0C);//Display on , cursor off
	LCD_Command(0x06);//Entry Mode
	LCD_Command(0x01);

}
void LCD_Command(char cmd){
	
	//A4 to A7 data pins 
	LCD_PORT = (LCD_PORT & 0x0F) | (cmd & 0xF0);
	
	//RS PB1 RW PB2 E PB3
	LCD_CTRL&=~(1<<RS);
	LCD_CTRL|=(1<<E);
	_delay_us(10); //micro seconds
	LCD_CTRL&=~(1<<E);
	
	_delay_us(2000);
	
	LCD_PORT= (LCD_PORT & 0x0F) | (cmd << 4);
	LCD_CTRL|=(1<<E);
	_delay_us(10); //micro seconds
	LCD_CTRL&=~(1<<E);
	
	//execution time LCD command
	_delay_ms(10);
}

void LCD_Char(char data){
	
	LCD_PORT=(LCD_PORT & 0x0F) | (data & 0xF0);
	LCD_CTRL|=(1<<RS); //data register
	LCD_CTRL|=(1<<E);
	_delay_us(10);
	LCD_CTRL&=~(1<<E);
	_delay_us(2000);
	LCD_PORT=(LCD_PORT & 0x0F)|(data<<4);
	LCD_CTRL|=(1<<E);
	_delay_us(10);
	LCD_CTRL&=~(1<<E);
	_delay_ms(2);
}
//LCD_String("hello");
void LCD_String(char* str){

char i=0;
while(str[i]!='\0'){
	LCD_Char(str[i]);
	i++;
  }
}