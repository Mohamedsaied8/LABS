/*
 * STD_Types.h
 *
 * Created: 5/29/2020 11:18:22 AM
 *  Author: infin
 */ 


#ifndef STD_TYPES_H_
#define STD_TYPES_H_
//unsigned
typedef unsigned char uint8; //data type
typedef unsigned int uint16;
typedef unsigned long int uint32;
//signed
typedef signed char sint8; 
typedef signed int sint16;
typedef signed long int sint32;


typedef float float16;
typedef double float32;


typedef enum{
	STD_LOW,//0
	STD_HIGH //1
}STD_LevelType;



#endif /* STD_TYPES_H_ */