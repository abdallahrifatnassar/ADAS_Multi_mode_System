/****************************************************/
/* Author 	: Abdullah Nassar & Ahmed ELyousfy     	*/
/* SWC 		: ALC		                  			*/
/* Layer 	: APP 		              				*/
/* Version 	: 1.0                   				*/
/* Date 	: October 31,2023          				*/
/* Last Edit: N/A                 					*/
/****************************************************/

#ifndef _AALC_CONFIG_H_
#define _AALC_CONFIG_H_

/*
/////Port Macros////
#define HLDR_PORTA 1
#define HLDR_PORTB 2
#define HLDR_PORTC 3

////Pins Macros////
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
*/

/*	Change this part		*/
/*Set pin and port for LDR sensor*/
#define	LDR_PORT	HLDR_PORTC
#define	LDR_PIN		HLDR_PIN0

#define	OP_PORT		HLDR_PORTC
#define	OP_PIN		HLDR_PIN1

/*	Do not change this part	*/
#define	LDR_PORTPIN		LDR_PORT,LDR_PIN
#define	OP_PORTPIN		OP_PORT,OP_PIN


#endif
