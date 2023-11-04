/*
 * MSCB_private.h
 *
 *  Created on: 6 Oct 2023
 *      Author: DELL
 */

#ifndef MSCB_PRIVATE_H_
#define MSCB_PRIVATE_H_

#include "LSTD_types.h"
#include "LBIT_math.h"

#define SCB_BASE_ADDRESS (0xE000ED00UL)   /* Start Address of SCB*/


typedef struct
{
    volatile u32 SCB_CPUID;
    volatile u32 SCB_ICSR;
    volatile u32 SCB_VTOR;
    volatile u32 SCB_AIRCR;
    volatile u32 SCB_SCR;
    volatile u32 SCB_CCR;
    volatile u32 SCB_SHPR1;
    volatile u32 SCB_SHPR2;
    volatile u32 SCB_SHPR3;
    volatile u32 SCB_SHCSR;
    volatile u32 SCB_CFSR;
    volatile u32 SCB_HFSR[2];
    volatile u32 SCB_MMAR;
    volatile u32 SCB_BFAR;
    volatile u32 SCB_AFSR;
} SCB_t;

#define SCB ((volatile SCB_t *)SCB_BASE_ADDRESS)

#endif /* MSCB_PRIVATE_H_ */
