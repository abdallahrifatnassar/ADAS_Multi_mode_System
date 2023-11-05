/***********************************************/
/* Author       : Ahmed Sherif                 */
/* SWC          : MGPIO                        */
/* Layer        : MCAL                         */
/* Version      : 1.0                          */
/* Date         : October 21, 2023             */
/* Last Edited  : N/A                          */
/***********************************************/

#ifndef _MGPIO_PRIVATE_H_
#define _MGPIO_PRIVATE_H_

/* Definition of private variables */
#define MGPIOA_BASE_ADDRESS (0x40020000UL)
#define MGPIOB_BASE_ADDRESS (0x40020400UL)
#define MGPIOC_BASE_ADDRESS (0x40020800UL)

typedef struct
{
    volatile u32 GPIOx_Moder;
    volatile u32 GPIOx_OTYPER;
    volatile u32 GPIOx_OSPEEDR;
    volatile u32 GPIOx_PUPDR;
    volatile u32 GPIOx_IDR;
    volatile u32 GPIOx_ODR;
    volatile u32 GPIOx_BSRR;
    volatile u32 GPIOx_LCKR;
    volatile u32 GPIOx_AFRL;
    volatile u32 GPIOx_AFRH;
} MGPIO_t;

#define GPIOA ((volatile MGPIO_t *)MGPIOA_BASE_ADDRESS)
#define GPIOB ((volatile MGPIO_t *)MGPIOB_BASE_ADDRESS)
#define GPIOC ((volatile MGPIO_t *)MGPIOC_BASE_ADDRESS)

#endif /* _MGPIO_PRIVATE_H_ */