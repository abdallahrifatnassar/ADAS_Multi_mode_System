/************************************/
/* Author    : Ahmed Sherif    	    */
/* SWC       : RCC          		*/
/* Layer     : MCAL               	*/
/* Version   : 1.0                	*/
/* Date      : October 19, 2023 	*/
/* Last Edit : N/A			      	*/
/************************************/

// Include files ------------------------------
#include "LBIT_math.h"
#include "LSTD_types.h"
#include "MRCC_Config.h"
#include "MRCC_private.h"
#include "MRCC_interface.h"

// Preprocessor -----------------------------------
#define MRCC_CR_HSION (0UL)
#define MRCC_CR_HSIRDY (1UL)

#define RCC_CR_HSEON (16UL)
#define RCC_CR_HSERDY (17UL)
#define RCC_CR_HSEBYP (18UL)
#define RCC_CR_CSSON (19UL)

#define RCC_CR_PLLON (24UL)
#define RCC_CR_PLLRDY (25UL)
// Functions Interface ----------------------------

void MRCC_voidInit(void)
{
#if (RCC_CLK_SOURCE == HSI)
    // Enable the High Speed internal clock
    SET_BIT(RCC->RCC_CR, MRCC_CR_HSION);
    while (!GET_BIT(RCC->RCC_CR, MRCC_CR_HSIRDY))
        ;
    // Select the HSI as a System Clock
    CLEAR_BIT(RCC->RCC_CFGR, 0);
    CLEAR_BIT(RCC->RCC_CFGR, 1);
#elif (RCC_CLK_SOURCE == HSE)
    // Enable the external high speed oscillator
    if (HSE_SOURCE_TYPE == HSE_Oscillator)
    {
        CLEAR_BIT(RCC->RCC_CR, RCC_CR_HSEBYP);
        SET_BIT(RCC->RCC_CR, RCC_CR_HSEON);
        while (!GET_BIT(RCC->RCC_CR, RCC_CR_HSERDY))
            ;
        // Select the HSE as a System Clock
        SET_BIT(RCC->RCC_CFGR, 0);
        CLEAR_BIT(RCC->RCC_CFGR, 1);
        // Enabling Clk Security system
        SET_BIT(RCC->RCC_CR, RCC_CR_CSSON);
    }
    else
    {
        SET_BIT(RCC->RCC_CR, RCC_CR_HSEBYP);
        SET_BIT(RCC->RCC_CR, RCC_CR_HSEON);
        while (!GET_BIT(RCC->RCC_CR, RCC_CR_HSERDY))
            ;
        // Select the HSE as a System Clock
        SET_BIT(RCC->RCC_CFGR, 0);
        CLEAR_BIT(RCC->RCC_CFGR, 1);
        // Enabling Clk Security system
        SET_BIT(RCC->RCC_CR, RCC_CR_CSSON);
    }
#elif (RCC_CLK_SOURCE == PLL)
    // Enable the phase-locked loop
    SET_BIT(RCC->RCC_CR, RCC_CR_PLLON);
    while (!GET_BIT(RCC->RCC_CR, RCC_CR_PLLRDY))
        ;
    // Select the PLL as a System Clock
    CLEAR_BIT(RCC->RCC_CFGR, 0);
    SET_BIT(RCC->RCC_CFGR, 1);
#else
#error "Wrong System Clock ";
#endif

    /*------------------------------------ Defining AHB PreScaler ------------------------------------------------ */

#if (SYSTEM_CLK_AHB_DIVIDER == AHB_DIV1)
    RCC->RCC_CFGR = (((RCC->RCC_CFGR & (u32)0XFFFFFF0F)) | (AHB_DIV1 << 4));
#elif (SYSTEM_CLK_AHB_AHB_DIVIDER == AHB_DIV2)
    RCC->RCC_CFGR = (((RCC->RCC_CFGR & (u32)0XFFFFFF0F)) | (AHB_DIV2 << 4));
#elif (SYSTEM_CLK_AHB_DIVIDER == AHB_DIV4)
    RCC->RCC_CFGR = (((RCC->RCC_CFGR & (u32)0XFFFFFF0F)) | (AHB_DIV4 << 4));
#elif (SYSTEM_CLK_AHB_DIVIDER == AHB_DIV8)
    RCC->RCC_CFGR = (((RCC->RCC_CFGR & (u32)0XFFFFFF0F)) | (AHB_DIV8 << 4));
#elif (SYSTEM_CLK_AHB_DIVIDER == AHB_DIV16)
    RCC->RCC_CFGR = (((RCC->RCC_CFGR & (u32)0XFFFFFF0F)) | (AHB_DIV16 << 4));
#elif (SYSTEM_CLK_AHB_DIVIDER == AHB_DIV64)
    RCC->RCC_CFGR = (((RCC->RCC_CFGR & (u32)0XFFFFFF0F)) | (AHB_DIV64 << 4));
#elif (SYSTEM_CLK_AHB_DIVIDER == AHB_DIV128)
    RCC->RCC_CFGR = (((RCC->RCC_CFGR & (u32)0XFFFFFF0F)) | (AHB_DIV128 << 4));
#elif (SYSTEM_CLK_AHB_DIVIDER == AHB_DIV256)
    RCC->RCC_CFGR = (((RCC->RCC_CFGR & (u32)0XFFFFFF0F)) | (AHB_DIV256 << 4));
#elif (SYSTEM_CLK_AHB_DIVIDER == AHB_DIV512)
    RCC->RCC_CFGR = (((RCC->RCC_CFGR & (u32)0XFFFFFF0F)) | (AHB_DIV512 << 4));
#else
#error "Unknown system clock AHB_Divider"
#endif

    /*------------------------------------ Defining APB1 PreScaler -------------------------------------------- */

#if (APB1_CLK_DIVIDER == APB1_DIV1)
    RCC->RCC_CFGR = (((RCC->RCC_CFGR & (u32)0XFFFFE3FF)) | (APB1_DIV1 << 10));
#elif (APB1_CLK_DIVIDER == APB1_DIV2)
    RCC->RCC_CFGR = (((RCC->RCC_CFGR & (u32)0XFFFFE3FF)) | (APB1_DIV2 << 10));
#elif (APB1_CLK_DIVIDER == APB1_DIV4)
    RCC->RCC_CFGR = (((RCC->RCC_CFGR & (u32)0XFFFFE3FF)) | (APB1_DIV4 << 10));
#elif (APB1_CLK_DIVIDER == APB1_DIV8)
    RCC->RCC_CFGR = (((RCC->RCC_CFGR & (u32)0XFFFFE3FF)) | (APB1_DIV8 << 10));
#elif (APB1_CLK_DIVIDER == APB1_DIV16)
    RCC->RCC_CFGR = (((RCC->RCC_CFGR & (u32)0XFFFFE3FF)) | (APB1_DIV16 << 10));
#else
#error "Unknown system clock APB1_Divider"
#endif

#if (APB2_CLK_DIVIDER == APB2_DIV1)
    RCC->RCC_CFGR = (((RCC->RCC_CFGR & (u32)0XFFFF1FFF)) | (APB2_DIV1 << 13));
#elif (APB2_CLK_DIVIDER == APB2_DIV2)
    RCC->RCC_CFGR = (((RCC->RCC_CFGR & (u32)0XFFFF1FFF)) | (APB2_DIV2 << 13));
#elif (APB2_CLK_DIVIDER == APB2_DIV4)
    RCC->RCC_CFGR = (((RCC->RCC_CFGR & (u32)0XFFFF1FFF)) | (APB2_DIV4 << 13));
#elif (APB2_CLK_DIVIDER == APB2_DIV8)
    RCC->RCC_CFGR = (((RCC->RCC_CFGR & (u32)0XFFFF1FFF)) | (APB2_DIV8 << 13));
#elif (APB2_CLK_DIVIDER == APB2_DIV16)
    RCC->RCC_CFGR = (((RCC->RCC_CFGR & (u32)0XFFFF1FFF)) | (APB2_DIV16 << 13));
#else
#error "Unknown system clock APB2_Divider"
#endif
}
u8 MRCC_voidEnablePeripheral(u8 ARG_u8CLKBus, u8 ARG_u8Peripheral)
{
    u8 L_u8ErrState = 0;

    switch (ARG_u8CLKBus)
    {
    case AHB1_BUS:
        SET_BIT(RCC->RCC_AHB1ENR, ARG_u8Peripheral);
        break;
    case AHB2_BUS:
        SET_BIT(RCC->RCC_AHB2ENR, ARG_u8Peripheral);
        break;
    case APB1_BUS:
        SET_BIT(RCC->RCC_APB1ENR, ARG_u8Peripheral);
        break;
    case APB2_BUS:
        SET_BIT(RCC->RCC_APB2ENR, ARG_u8Peripheral);
        break;
    default:
        L_u8ErrState = 1;
        break;
    }
    return L_u8ErrState;
}
u8 MRCC_voidDisablePeripheral(u8 ARG_u8CLKBus, u8 ARG_u8Peripheral)
{
    u8 L_u8ErrState = 0;

    switch (ARG_u8CLKBus)
    {
    case AHB1_BUS:
        CLEAR_BIT(RCC->RCC_AHB1ENR, ARG_u8Peripheral);
        break;
    case AHB2_BUS:
        CLEAR_BIT(RCC->RCC_AHB2ENR, ARG_u8Peripheral);
        break;
    case APB1_BUS:
        CLEAR_BIT(RCC->RCC_APB1ENR, ARG_u8Peripheral);
        break;
    case APB2_BUS:
        CLEAR_BIT(RCC->RCC_APB2ENR, ARG_u8Peripheral);
        break;
    default:
        L_u8ErrState = 1;
        break;
    }
    return L_u8ErrState;
}
