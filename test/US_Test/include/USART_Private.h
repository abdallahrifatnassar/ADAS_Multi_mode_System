/*
  * File:  USART_Private.h 
 *	SWC:    USART
 *	Version: 1.0 
 *  Created on: 19-06-2023 
 *  Author: Abdallah Ragab 
 */
#ifndef USART_PRIVATE
#define USART_PRIVATE

typedef struct{
	volatile u32 USART_SR  ;
	volatile u32 USART_DR  ;
	volatile u32 USART_BRR ;
	volatile u32 USART_CR1 ;
	volatile u32 USART_CR2 ;
	volatile u32 USART_CR3 ;
	volatile u32 USART_GTPR;

}USART_t;

#define USART1 			((volatile USART_t*)(0x40011000))
#define USART6 			((volatile USART_t*)(0x40011400))
#define USART2 			((volatile USART_t*)(0x40014400))


#endif // USART_PRIVATE
