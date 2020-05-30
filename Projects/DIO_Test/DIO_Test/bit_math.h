/*
 * bit_math.h
 *
 * Created: 5/22/2020 2:16:07 PM
 *  Author: Mohamed
 */ 


#ifndef BIT_MATH_H_
#define BIT_MATH_H_

#define SET_BIT(var,bit)	var|=(1<<bit)
#define CLEAR_BIT(var,bit)	var&=~(1<<bit)
#define GET_BIT(var,bit)	((var>>bit)&1)
#define TOGGLE_BIT(var,bit)	var^=(1<<bit)

#endif /* BIT_MATH_H_ */