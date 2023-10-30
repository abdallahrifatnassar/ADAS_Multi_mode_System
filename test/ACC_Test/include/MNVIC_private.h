/**********************************/
/* Author :Ahmed Samir            */
/* SWC :NVIC		              */
/* Layer :MCAL 		              */
/* Version :1.0                   */
/* Date :September 17,2023        */
/* Last Edit :N/A                 */
/**********************************/

#ifndef _MNVIC_PRIVATE_H_
#define _MNVIC_PRIVATE_H_

/* Base Address*/
#define MNVIC_BASE_ADDRESS 		0xE000E100

/* register defintion*/
typedef struct
{
	volatile u32 ISER[8];
	volatile u32 RESERVED1[24];
	volatile u32 ICER[8];
	volatile u32 RESERVED2[24];
	volatile u32 ISPR[8];
	volatile u32 RESERVED3[24];
	volatile u32 ICPR[8];
	volatile u32 RESERVED4[24];
	volatile u32 IABR[8];
	volatile u32 RESERVED5[56];
	volatile u8 IPR[240];
	volatile u32 RESERVED6[580];
	u32 STIR;
	
}NVIC_t;

#define NVIC 				((volatile NVIC_t*)MNVIC_BASE_ADDRESS)
#define AIRCR 				*((volatile u32*)0xE000ED0C)

#define VECTKEY				0x05FA0000
#define REGISTER_WIDTH		32






#endif
