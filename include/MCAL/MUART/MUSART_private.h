/***********************************************/
/* Author       : Ahmed Sherif                 */
/* SWC          : USART                        */
/* Layer        : MCAL                         */
/* Version      : 1.0                          */
/* Date         : November 4, 2023             */
/* Last Edited  : OCTOBER 7, 2023              */
/***********************************************/

#ifndef _MUSART_PRIVATE_H_
#define _MUSART_PRIVATE_H_

#include "LSTD_types.h"

/* The Base Addresses of USARTs to start counting from */
#define MUSART1_BASE_ADDRESS (0x40011000UL)
#define MUSART2_BASE_ADDRESS (0x40004400UL)
#define MUSART6_BASE_ADDRESS (0x40014400UL)

/* Struct that contains the Registers of USARTs */
typedef struct
{
    volatile u32 USART_SR;   // Status Register
    volatile u32 USART_DR;   // Data Register
    volatile u32 USART_BRR;  // Baud-rate register
    volatile u32 USART_CR1;  // Control Register 1
    volatile u32 USART_CR2;  // Control Register 2
    volatile u32 USART_CR3;  // Control Register 3
    volatile u32 USART_GTPR; // Guard Time and PreScaler Register
} MUSART_t;

/* A pointers of type MSUART_t to access the registers used by the peripheral */
#define USART1 ((volatile MUSART_t *)MUSART1_BASE_ADDRESS)
#define USART2 ((volatile MUSART_t *)MUSART2_BASE_ADDRESS)
#define USART6 ((volatile MUSART_t *)MUSART6_BASE_ADDRESS)

#endif /* _MUSART_PRIVATE_H_ */
