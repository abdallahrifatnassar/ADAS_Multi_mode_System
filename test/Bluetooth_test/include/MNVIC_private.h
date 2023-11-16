/***********************************************/
/* Author       : Ahmed Sherif                 */
/* SWC          : NVIC                         */
/* Layer        : MCAL                         */
/* Version      : 1.0                          */
/* Date         : September 17, 2023           */
/* Last Edited  : N/A		            	   */
/***********************************************/

#ifndef _MNVIC_PRIVATE_H_
#define _MNVIC_PRIVATE_H_

#include "LSTD_types.h"
#include "LBIT_math.h"

/* This is STM32F4*/

#define MNVIC_BASE_ADDRESS (0xE000E100UL) /* Start Address of NVIC_ISER0 */

/*************************Structure of the NVIC registers********************************/
typedef struct
{
    volatile u32 NVIC_ISERx[8U]; /* Interrupt set-enable register x*/
    volatile u32 RESERVED0[24U];  /* Reserved for future use*/
    volatile u32 NVIC_ICERx[8U]; /*Interrupt clear-enable register x*/
    volatile u32 RESERVED1[24U];  /* Reserved for future use*/
    volatile u32 NVIC_ISPRx[8U]; /*Interrupt set-pending register x*/
    volatile u32 RESERVED2[24U];  /* Reserved for future use*/
    volatile u32 NVIC_ICPRx[8U]; /* Interrupt clear-pending register x*/
    volatile u32 RESERVED3[24U];  /* Reserved for future use*/
    volatile u32 NVIC_IABRx[8U]; /* Interrupt active bit register x */
    volatile u32 RESERVED4[56U];  /* Reserved for future use*/
    volatile u8 NVIC_IPRx[240U]; /* Interrupt priority register x*/
    volatile u32 RESERVED5[581];  /* Reserved for future use*/
} MNVIC_t;


typedef enum
{
    /* Non-Handled Exceptions Requests*/
    RESET_IRQn = -15,       /* Reset */
    NMI_IRQn = -14,         /* Non maskable interrupt, Clock Security System */
    HARDFAULT_IRQn = -13,   /* All class of fault */
    MEMFAULT_IRQn = -12,    /* Memory management */
    BUSFAULT_IRQn = -11,    /* Pre-fetch fault, memory access fault */
    USAGEFAULT_IRQn = -10,  /* Undefined instruction or illegal state */
    SVCALL_IRQn = -5,       /* System Service call via SWI instruction */
    DEBUGMONITOR_IRQn = -4, /* Debug Monitor */
    PENDSV_IRQn = -2,       /* Pendable request for system service */
    SYSTICK_IRQn = -1,      /* System tick timer */

    /* External Interrupts Requests */
    WWDG_IRQn = 0, /* Watch-Dog Timer */
    EXTI16_PVD_IRQn = 1,
    EXTI21_TAMP_STAMP_IRQn = 2,
    EXTI22_RTC_WKUP_IRQn = 3,
    FLASH_IRQn = 4,
    RCC_IRQn = 5,
    EXTI0_IRQn = 6,
    EXTI1_IRQn = 7,
    EXTI2_IRQn = 8,
    EXTI3_IRQn = 9,
    EXTI4_IRQn = 10,
    DMA1_STREAM0_IRQn = 11,
    DMA1_STREAM1_IRQn = 12,
    DMA1_STREAM2_IRQn = 13,
    DMA1_STREAM3_IRQn = 14,
    DMA1_STREAM4_IRQn = 15,
    DMA1_STREAM5_IRQn = 16,
    DMA1_STREAM6_IRQn = 17,
    ADC_IRQn = 18,
    EXTI9_5_IRQn = 23,
    TIM1_BRK_TIM9_IRQn = 24,
    TIM1_UP_TIM10_IRQn = 25,
    TIM1_TRG_COM_TIM11_IRQn = 26, // STM32F4 only
    TIM1_CC_IRQn = 27,
    TIM2 = 28
} IRQn_Type;

#define NVIC ((volatile MNVIC_t *)MNVIC_BASE_ADDRESS)

#endif /* _MNVIC_PRIVATE_H_ */
