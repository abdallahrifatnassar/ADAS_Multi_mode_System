/***********************************************/
/* Author       : Ahmed Sherif                 */
/* SWC          : USART                        */
/* Layer        : MCAL                         */
/* Version      : 1.0                          */
/* Date         : OCTOBER 7, 2023              */
/* Last Edited  : N/A                          */
/***********************************************/

#ifndef _MUSART_PRIVATE_H_
#define _MUSART_PRIVATE_H_

#include "LSTD_types.h"

#define MUSART1_BASE_ADDRESS    (0x40011000UL)
#define MUSART2_BASE_ADDRESS    (0x40004400UL)
#define MUSART6_BASE_ADDRESS    (0x40014400UL)

typedef struct
{
    volatile u32 USART_SR;
    volatile u32 USART_DR;
    volatile u32 USART_BRR;
    volatile u32 USART_CR1;
    volatile u32 USART_CR2;
    volatile u32 USART_CR3;
    volatile u32 USART_GTPR;
}MUSART_t;

#define USART1   ((volatile MUSART_t*) MUSART1_BASE_ADDRESS)
#define USART2   ((volatile MUSART_t*) MUSART2_BASE_ADDRESS)
#define USART6   ((volatile MUSART_t*) MUSART6_BASE_ADDRESS)

#endif /* _MUSART_PRIVATE_H_ */
