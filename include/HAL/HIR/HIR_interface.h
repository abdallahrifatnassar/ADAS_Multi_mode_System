/************************************/
/* Author    : Abdullah Nassar    	*/
/* SWC       : INFRARED SENSOR		*/
/* Layer     : HAL               	*/
/* Version   : 1.0                	*/
/* Date      : October 5, 2023 		*/
/* Last Edit : N/A			      	*/
/************************************/

#ifndef _HIR_INTERFACE_H_
#define _HIR_INTERFACE_H_

/****** Port Macros*******/
#define HIR_PORTA 1
#define HIR_PORTB 2
#define HIR_PORTC 3
/************************/

/********Pins Macros*****/
#define HIR_PIN0 0
#define HIR_PIN1 1
#define HIR_PIN2 2
#define HIR_PIN3 3
#define HIR_PIN4 4
#define HIR_PIN5 5
#define HIR_PIN6 6
#define HIR_PIN7 7
#define HIR_PIN8 8
#define HIR_PIN9 9
#define HIR_PIN10 10
#define HIR_PIN11 11
#define HIR_PIN12 12
#define HIR_PIN13 13
#define HIR_PIN14 14
#define HIR_PIN15 15
/************************/

void HIR_voidInit(u8 Copy_u8Port, u8 Copy_u8Pin);

u8 HIR_u8ReadIR(u8 Copy_u8Port, u8 Copy_u8Pin);

#endif
