/************************************/
/* Author    : Ahmed Sherif    	    */
/* SWC       : RCC          		*/
/* Layer     : MCAL               	*/
/* Version   : 1.0                	*/
/* Date      : October 19, 2023 	*/
/* Last Edit : N/A			      	*/
/************************************/

#ifndef _MRCC_CONFIG_H_
#define _MRCC_CONFIG_H_

// Define the three Clock Sources of STM32F401 --------------------------------
#define HSI (0UL) // Internal High Speed Clock
#define HSE (1UL) // External High Speed Clock
#define PLL (2UL) // Phase Locked Loop
#define LSI (3UL) // Low Speed Clock
#define LSE (4UL) // External Low Speed Clock

// Define the clock source for system clock ----------------------------------
#define AHB1_BUS (1UL)
#define AHB2_BUS (2UL)
#define APB1_BUS (3UL)
#define APB2_BUS (4UL)

// Define the Peripherals of AHB1 -------------------------------------
#define GPIO_PORTA_ENABLE (0UL)
#define GPIO_PORTB_ENABLE (1UL)
#define GPIO_PORTC_ENABLE (2UL)
#define DMA1_ENABLE (21UL)
#define DMA2_ENABLE (22UL)

// Define the Peripherals of APB1 --------------------------------
#define TIM2_ENABLE (0UL)
#define TIM3_ENABLE (1UL)
#define TIM4_ENABLE (2UL)
#define TIM5_ENABLE (3UL)
#define WWDG_ENABLE (11UL)
#define SPI2_ENABLE (14UL)
#define SPI3_ENABLE (15UL)
#define USART2_ENABLE (17UL)
#define I2C1_ENABLE (21UL)
#define I2C2_ENABLE (22UL)
#define I2C3_ENABLE (23UL)
#define PWR_ENABLE (28UL)

// Define the Peripherals of APB2 --------------------------------
// Define the the connection of the HSE clk whither it's bypassed or Oscillator
#define HSE_Oscillator (2UL) // HSE oscillator
#define HSE_BYPASS (1UL)     // HSE bypass

// AHB PreScalar of the clk source
#define AHB_DIV1 (0UL)    // Divide the clk by 1
#define AHB_DIV2 (8UL)    // Divide the clk by 2
#define AHB_DIV4 (9UL)    // Divide the clk by 4
#define AHB_DIV8 (10UL)   // Divide the clk by 8
#define AHB_DIV16 (11UL)  // Divide the clk by 16
#define AHB_DIV64 (12UL)  // Divide the clk by 64
#define AHB_DIV128 (13UL) // Divide the clk by 128
#define AHB_DIV256 (14UL) // Divide the clk by 256
#define AHB_DIV512 (15UL) // Divide the clk by 512

// APB1 PreSacler Divider
#define APB1_DIV1 (0UL)  // Divide the clk by 1
#define APB1_DIV2 (4UL)  // Divide the clk by 2
#define APB1_DIV4 (5UL)  // Divide the clk by 4
#define APB1_DIV8 (6UL)  // Divide the clk by 8
#define APB1_DIV16 (7UL) // Divide the clk by 16

// APB2 PreSacler Divider
#define APB2_DIV1 (0UL)  // Divide the clk by 1
#define APB2_DIV2 (4UL)  // Divide the clk by 2
#define APB2_DIV4 (5UL)  // Divide the clk by 4
#define APB2_DIV8 (6UL)  // Divide the clk by 8
#define APB2_DIV16 (7UL) // Divide the clk by 16

// Define the Prescaler for AHB and APB buses
#define AHB_PRESCALER (1UL << 4)
#define APB1_PRESCALER (1UL << 3)
#define APB2_PRESCALER (1UL << 2)

// Define the The clk sources to operate the system with --------------------------------
#define RCC_CLK_SOURCE HSI
#define HSE_SOURCE_TYPE HSE_Oscillator
#define SYSTEM_CLK_AHB_DIVIDER DIV2
#define APB1_CLK_DIVIDER APB1_DIV1
#define APB2_CLK_DIVIDER APB2_DIV1

#endif /* _MRCC_CONFIG_H_ */
