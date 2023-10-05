/**********************************/
/* Author:Ahmed Samir,FahkerEldin */
/* SWC :TIMER		           	  */
/* Layer :MCAL 		              */
/* Version :1.0                   */
/* Date :Octobar 1,2023		      */
/* Last Edit :N/A                 */
/**********************************/

#ifndef _MTIMER_PRIVATE_H_
#define _MTIMER_PRIVATE_H_

/* Base Address*/
#define MTIMER2_BASE_ADDRESS 			0x40000000
#define MTIMER3_BASE_ADDRESS 			0x40000400
#define MTIMER4_BASE_ADDRESS 			0x40000800
#define MTIMER5_BASE_ADDRESS 			0x40000C00
/* register defintion*/


typedef struct
{
	volatile u32 CR1;
	volatile u32 CR2;
	volatile u32 SMCR;
	volatile u32 DIER;
	volatile u32 SR;
	volatile u32 EGR;
	volatile u32 CCMR1;
	volatile u32 CCMR2;
	volatile u32 CCER;
	volatile u32 CNT;
	volatile u32 PSC;
	volatile u32 ARR;
	volatile u32 RESERVED_1;
	volatile u32 CCR1;
	volatile u32 CCR2;
	volatile u32 CCR3;
	volatile u32 CCR4;
	volatile u32 RESERVED_2;
	volatile u32 DCR;
	volatile u32 DMAR;
	volatile u32 TIM2_TIM5_OR;
	
}TIMER_t;

#define TIMER2 				((volatile TIMER_t*)MTIMER2_BASE_ADDRESS)
#define TIMER3 				((volatile TIMER_t*)MTIMER3_BASE_ADDRESS)
#define TIMER4 				((volatile TIMER_t*)MTIMER4_BASE_ADDRESS)
#define TIMER5 				((volatile TIMER_t*)MTIMER5_BASE_ADDRESS)



/***Pin Macros****/
#define CEN			0

#define CH1_OC1M1		4
#define CH1_OC1M2		5
#define CH1_OC1M3		6

#define CH2_OC2M1		12
#define CH2_OC2M2		13
#define CH2_OC2M3		14

#define CKD1			8
#define CKD2			9

#define CMS1			5
#define CMS2			6	
#define DIR				4

#define CC1E			0
#define CC2E			4
#define CC3E			8
#define CC4E			12

#endif
