/************************************/
/* Author    : Ahmed Sherif    	    */
/* SWC       : RCC          		*/
/* Layer     : MCAL               	*/
/* Version   : 1.0                	*/
/* Date      : October 19, 2023 	*/
/* Last Edit : N/A			      	*/
/************************************/
#ifndef _MRCC_PRIVATE_H_
#define _MRCC_PRIVATE_H_

// Preprocessor Files ------------------------------
#define RCC_BASE_ADDRESS (0x40023800UL)
// Registers Definitions ----------------------------
typedef struct
{
    volatile u32 RCC_CR;        // Clock control register
    volatile u32 RCC_PLLCFGR;   // PLL configuration register
    volatile u32 RCC_CFGR;      // Clock configuration register
    volatile u32 RCC_CIR;       // Clock interrupt register
    volatile u32 RCC_AHB1RSTR;  // AHB1 peripheral reset register
    volatile u32 RCC_AHB2RSTR;  // AHB2 peripheral reset register
    volatile u32 RESERVED0[2];   // Reserved
    volatile u32 RCC_APB1RSTR;  // APB1 peripheral reset register
    volatile u32 RCC_APB2RSTR;  // APB2 peripheral reset register
    volatile u32 RESERVED1[2];   // Reserved
    volatile u32 RCC_AHB1ENR;   // AHB1 peripheral clock enable register
    volatile u32 RCC_AHB2ENR;   // AHB2 peripheral clock enable register
    volatile u32 RESERVED2[2];   // Reserved
    volatile u32 RCC_APB1ENR;   // APB1 peripheral clock enable register
    volatile u32 RCC_APB2ENR;   // APB2 peripheral clock enable register
    volatile u32 RESERVED3[2];   // Reserved
    volatile u32 RCC_AHB1LPENR; // AHB1 peripheral clock enable in low power
    volatile u32 RCC_AHB2LPENR; // AHB2 peripheral clock enable in low power
    volatile u32 RESERVED4[2];   // Reserved
    volatile u32 RCC_APB1LPENR; // APB1 peripheral clock enable in low power
    volatile u32 RCC_APB2LPENR; // APB2 peripheral clock enable in low power
    volatile u32 RESERVED5[2];   // Reserved
    volatile u32 RCC_BDCR;      // Backup domain control register
    volatile u32 RCC_CSR;       // Control/status register
    volatile u32 RESERVED6[2];   // Reserved
    volatile u32 RCC_SSCGR;     // Status register
    volatile u32 RCC_PLLI2SCFGR // PLL I2SCFGR register
} MRCC_t;

#define RCC ((volatile MRCC_t *)RCC_BASE_ADDRESS)

#endif /* _MRCC_PRIVATE_H_ */
