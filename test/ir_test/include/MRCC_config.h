/**********************************/
/* Author :Ahmed Samir            */
/* SWC :RCC		                  */
/* Layer :MCAL 		              */
/* Version :1.0                   */
/* Date :September 12,2023        */
/* Last Edit :N/A                 */
/**********************************/

#ifndef _MRCC_CONFIG_H_
#define _MRCC_CONFIG_H_

/*
Options:1-HSI
		2-HSE
		3-PLL
*/
#define SYSTEM_CLOCK	HSI


/*
Options:1-HSE_BYPASS
		2-HSE_NOTBYPASS
*/
#define HSE_TYPE	HSE_BYPASS

/*
Options:1-HSI
		2-HSE
*/
#define PLL_SOURCE	HSI

/*
options:
1- SYSTEM_CLOCK_NO_DIV
2- SYSTEM_CLOCK_DIV_BY_2	
3- SYSTEM_CLOCK_DIV_BY_4	
4- SYSTEM_CLOCK_DIV_BY_8	
5- SYSTEM_CLOCK_DIV_BY_16
6- SYSTEM_CLOCK_DIV_BY_64
7- SYSTEM_CLOCK_DIV_BY_128
8- SYSTEM_CLOCK_DIV_BY_256
9- SYSTEM_CLOCK_DIV_BY_512
*/
#define AHB_BUS_PRESCALER	SYSTEM_CLOCK_DIV_BY_2

/*
options:
1- AHB_CLOCK			
2- AHB_CLOCK_DIV_BY_2	
3- AHB_CLOCK_DIV_BY_4	
4- AHB_CLOCK_DIV_BY_8	
5- AHB_CLOCK_DIV_BY_16
*/

#define	APB1_BUS_PRESCALER	AHB_CLOCK
#define	APB2_BUS_PRESCALER	AHB_CLOCK

#endif
