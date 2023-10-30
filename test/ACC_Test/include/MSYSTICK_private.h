/**********************************/
/* Author :Ahmed Samir            */
/* SWC :SYSTICK		              */
/* Layer :MCAL 		              */
/* Version :1.0                   */
/* Date :September 18,2023        */
/* Last Edit :N/A                 */
/**********************************/

#ifndef _MSYSTICK_PRIVATE_H_
#define _MSYSTICK_PRIVATE_H_

/* Base Address*/
#define MSYSTICK_BASE_ADDRESS 		0xE000E010

/* register defintion*/

typedef struct
{
	volatile u32 CTRL;
	volatile u32 LOAD;
	volatile u32 VAL;
	volatile u32 CALIB;
	
}SYSTICK_t;

#define SYSTICK 				((volatile SYSTICK_t*)MSYSTICK_BASE_ADDRESS)

/****Pin Macros******/
#define SYSTICK_COUNT_FLAG				16
#define SYSTICK_CLK_SOURCE				2
#define SYSTICK_INT_ENABLE				1
#define SYSTICK_ENABLE					0

/********************/

/***Config Macros****/
#define AHB_CLOCK						1
#define AHB_CLOCK_DIV_BY_8				2

#define SYSTICK_INTERRUPT_ENABLE		3
#define SYSTICK_INTERRUPT_DISABLE		4

#define ENABLED							5
#define DISABLED						6

/********************/

#endif