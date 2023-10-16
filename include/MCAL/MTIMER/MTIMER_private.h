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



#define	CC1S0			0
#define	CC1S1			1
#define	CC2S8			8
#define	CC2S9			9
#define	CC3S0			0
#define	CC3S1			1
#define	CC4S8			8
#define	CC4S9			9

#define IC1PSC0			0
#define IC1PSC1			1
#define	IC2PSC10		10
#define	IC2PSC11		11
#define	IC31PSC0		0	
#define	IC31PSC1        1
#define	IC4PSC10        10
#define	IC4PSC11        11
/*EDGES configration*/
#define	CC1P			1
#define	CC1NP			3
#define	CC2P			5
#define	CC2NP			7
#define	CC3P			9
#define	CC3NP			11
#define	CC4P			13
#define	CC4NP			15
/*Interrupt bits enable in DIER*/
#define CC1IE			1
#define CC2IE			2
#define CC3IE			3
#define CC4IE			4

#endif
