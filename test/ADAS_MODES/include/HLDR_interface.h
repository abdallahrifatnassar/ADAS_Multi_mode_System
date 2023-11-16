/************************************/
/* Author    : Abdullah Nassar    	*/
/* SWC       : LDR					*/
/* Layer     : HAL               	*/
/* Version   : 1.0                	*/
/* Date      : October 31, 2023 	*/
/* Last Edit : N/A			      	*/
/************************************/

#ifndef _HLDR_INTERFACE_H_
#define _HLDR_INTERFACE_H_

/****** Port Macros*******/
#define HLDR_PORTA 1
#define HLDR_PORTB 2
#define HLDR_PORTC 3
/************************/

/********Pins Macros*****/
#define HLDR_PIN0 0
#define HLDR_PIN1 1
#define HLDR_PIN2 2
#define HLDR_PIN3 3
#define HLDR_PIN4 4
#define HLDR_PIN5 5
#define HLDR_PIN6 6
#define HLDR_PIN7 7
#define HLDR_PIN8 8
#define HLDR_PIN9 9
#define HLDR_PIN10 10
#define HLDR_PIN11 11
#define HLDR_PIN12 12
#define HLDR_PIN13 13
#define HLDR_PIN14 14
#define HLDR_PIN15 15
/************************/

void HLDR_voidInit(u8 Copy_u8Port);

void HLDR_SetPin(u8 Copy_u8Port, u8 Copy_u8Pin);

u8 HLDR_u8ReadLDR(u8 Copy_u8Port, u8 Copy_u8Pin);

#endif