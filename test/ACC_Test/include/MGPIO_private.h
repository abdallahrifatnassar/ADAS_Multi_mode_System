/**********************************/
/* Author :Ahmed Samir            */
/* SWC :GPIO		              */
/* Layer :MCAL 		              */
/* Version :1.0                   */
/* Date :September 16,2023        */
/* Last Edit :N/A                 */
/**********************************/

#ifndef _MGPIO_PRIVATE_H_
#define _MGPIO_PRIVATE_H_

/* Base Address*/
#define MGPIOA_BASE_ADDRESS 	0x40020000
#define MGPIOB_BASE_ADDRESS 	0x40020400
#define MGPIOC_BASE_ADDRESS 	0x40020800

/* register defintion*/
typedef struct
{
	volatile u32 MODER;
	volatile u32 OTYPER;
	volatile u32 OSPEEDR;
	volatile u32 PURDR;
	volatile u32 IDR;
	volatile u32 ODR;
	volatile u32 BSRR;
	volatile u32 LCKR;
	volatile u32 AFRL;
	volatile u32 AFRH;
}GPIO_t;

#define GPIOA 				((volatile GPIO_t*)MGPIOA_BASE_ADDRESS)
#define GPIOB 				((volatile GPIO_t*)MGPIOB_BASE_ADDRESS)
#define GPIOC 				((volatile GPIO_t*)MGPIOC_BASE_ADDRESS)




#define MGPIO_PIN_MASK				3
#define MGPIO_ALTFUNCTION_MASK		15





#endif