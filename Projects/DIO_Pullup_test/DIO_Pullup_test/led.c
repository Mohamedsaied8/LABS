/*
 * led.c
 *
 * Created: 5/23/2020 3:44:03 PM
 *  Author: Mohamed
 * LED Driver
 */ 

#include "bit_math.h"
#include "dio_hw.h"
#include "app_cfg.h"

void LED_ON(){
	
	SET_BIT(LED_PORT,LED);
}
void LED_OFF(){
	
}
void LED_Init(){
	
}