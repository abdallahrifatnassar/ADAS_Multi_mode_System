/**********************************/
/* Author :Ahmed Samir            */
/* SWC :SYSTICK		              */
/* Layer :MCAL 		              */
/* Version :1.0                   */
/* Date :September 18,2023        */
/* Last Edit :N/A                 */
/**********************************/

#ifndef _MSYSTICK_CONFIG_H_
#define _MSYSTICK_CONFIG_H_


/*
Options:
1-AHB_CLOCK
2-AHB_CLOCK_DIV_BY_8
*/
#define SYSTICK_CLOCK	AHB_CLOCK_DIV_BY_8

/*
Options:
1-SYSTICK_INTERRUPT_ENABLE
2-SYSTICK_INTERRUPT_DISABLE
*/
#define SYSTICK_INTERRUPT	SYSTICK_INTERRUPT_DISABLE

/*
Options: Any value from(0x00000001-0x00FFFFFF)(zero has no effect)
*/
#define LOAD_VALUE			0

/*
Options: 
1-ENABLED
2-DISABLED
*/
#define SYSTICK_MODE		DISABLED
#endif
