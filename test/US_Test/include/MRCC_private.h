/**********************************/
/* Author :Ahmed Samir            */
/* SWC :RCC		                  */
/* Layer :MCAL 		              */
/* Version :1.0                   */
/* Date :September 12,2023        */
/* Last Edit :N/A                 */
/**********************************/

#ifndef _MRCC_PRIVATE_H_
#define _MRCC_PRIVATE_H_


/* Base Address*/
#define MRCC_BASE_ADDRESS 	0x40023800
/* register defintion*/
typedef struct
{
	volatile u32 CR;
	volatile u32 PLLCFGR;
	volatile u32 CFGR;
	volatile u32 CIR;
	volatile u32 AHB1RSRT;
	volatile u32 AHB2RSRT;
	volatile u32 Reserved0[2];
	volatile u32 APB1RSRT;
	volatile u32 APB2RSRT;
	volatile u32 Reserved1[2];
	volatile u32 AHB1ENR;
	volatile u32 AHB2ENR;
	volatile u32 Reserved2[2];
	volatile u32 APB1ENR;
	volatile u32 APB2ENR;
	volatile u32 Reserved3[2];
	volatile u32 AHB1LPENR;
	volatile u32 AHB2LPENR;
	volatile u32 Reserved4[2];
	volatile u32 APB1LPENR;
	volatile u32 APB2LPENR;
	volatile u32 Reserved5[2];
	volatile u32 BDCR;
	volatile u32 CSR;
	volatile u32 Reserved6[2];
	volatile u32 SSCGR;
	volatile u32 PLLI2SCFGR;
	volatile u32 Reserved7;
	volatile u32 DCKCFGR;	
}MRCC_t;

#define MRCC 				((volatile MRCC_t*)MRCC_BASE_ADDRESS)



/* Register  Bits*/
#define PLLON 		24
#define CSSON 		19
#define HSEBYP 		18
#define HSEON		16
#define	HSION		0
#define PLLSRC		22
#define HSERDY 		17
#define HSIRDY		1
#define PLLRDY		25



/***** AHB_BUS PreScaler******/

#define SYSTEM_CLOCK_NO_DIV			1
#define SYSTEM_CLOCK_DIV_BY_2	8
#define SYSTEM_CLOCK_DIV_BY_4	9
#define SYSTEM_CLOCK_DIV_BY_8	10
#define SYSTEM_CLOCK_DIV_BY_16	11
#define SYSTEM_CLOCK_DIV_BY_64	12
#define SYSTEM_CLOCK_DIV_BY_128	13
#define SYSTEM_CLOCK_DIV_BY_256	14
#define SYSTEM_CLOCK_DIV_BY_512	15
#define AHB_PRESCALER_MASK 		0xFFFFFF0F
/********************************/


/***** APB_BUS PreScaler******/

#define AHB_CLOCK 				1
#define AHB_CLOCK_DIV_BY_2		4
#define AHB_CLOCK_DIV_BY_4		5
#define AHB_CLOCK_DIV_BY_8		6
#define AHB_CLOCK_DIV_BY_16		7
#define APB1_PRESCALER_MASK    0xFFFFE3FF
#define APB2_PRESCALER_MASK    0xFFFF1FFF
/********************************/



#endif
