/**********************************/
/* Author :Ahmed Samir            */
/* SWC :RCC		                  */
/* Layer :MCAL 		              */
/* Version :1.0                   */
/* Date :September 12,2023        */
/* Last Edit :N/A                 */
/**********************************/

#ifndef _MRCC_INTERFACE_H_
#define _MRCC_INTERFACE_H_

/***** APIS******/
/*--------------------------------------------------------------------------------------------------------------------
*[Function Name]: MRCC_voidInit
*
*[Description]: This function is responsible for Init the RCC(reset and clock contorl)
*				There are 3 options(HSI,HSE,PLL)and the prescaler of the buses(AHB1,AHB2,APB1,APB2) 
*
*[Arguments]:
*
*[in]:  N/A
*
*[out]: N/A
*
*[Returns]: N/A
--------------------------------------------------------------------------------------------------------------------*/
void MRCC_voidInit(void);

/*--------------------------------------------------------------------------------------------------------------------
*[Function Name]: MRCC_voidEnablePeripheral
*
*[Description]: This function is responsible for Enabling the clock for peripherals
*				There are 3 options(HSI,HSE,PLL)and the prescaler of the buses(AHB1,AHB2,APB1,APB2) 
*
*[Arguments]:
*
*[in]: u8 Copy_u8Bus: This Argument indicates the bus of the peripheral(AHB1,AHB2,APB1,APB2) 
*	   u8 Copy_u8Peripheral	: This Argument indicates the peripheral 
*
*[out]: N/A
*
*[Returns]: N/A
--------------------------------------------------------------------------------------------------------------------*/
void MRCC_voidEnablePeripheral(u8 Copy_u8Bus,u8 Copy_u8Peripheral);

/*--------------------------------------------------------------------------------------------------------------------
*[Function Name]: MRCC_voidDisablePeripheral
*
*[Description]: This function is responsible for Disabling the clock for peripherals
*				There are 3 options(HSI,HSE,PLL)and the prescaler of the buses(AHB1,AHB2,APB1,APB2) 
*
*[Arguments]:
*
*[in]: u8 Copy_u8Bus: This Argument indicates the bus of the peripheral(AHB1,AHB2,APB1,APB2) 
*	   u8 Copy_u8Peripheral	: This Argument indicates the peripheral 
*
*[out]: N/A
*
*[Returns]: N/A
--------------------------------------------------------------------------------------------------------------------*/
void MRCC_voidDisablePeripheral(u8 Copy_u8Bus,u8 Copy_u8Peripheral);
/*--------------------------------------------------------------------------------------------------------------------
*[Function Name]: MRCC_voidEnableClockSecurity
*
*[Description]: This function is responsible for Enabling System clock securtiy (in case of clock failing the hsi will be system clock) 
*
*[Arguments]:
*
*[in]: N/A 
*
*[out]: N/A
*
*[Returns]: N/A
--------------------------------------------------------------------------------------------------------------------*/
void MRCC_voidEnableClockSecurity(void);

/*--------------------------------------------------------------------------------------------------------------------
*[Function Name]: MRCC_voidDisableClockSecurity
*
*[Description]: This function is responsible for Disabling System clock securtiy (in case of clock failing the hsi will be system clock) 
*
*[Arguments]:
*
*[in]: N/A 
*
*[out]: N/A
*
*[Returns]: N/A
--------------------------------------------------------------------------------------------------------------------*/
void MRCC_voidDisableClockSecurity(void);

/*--------------------------------------------------------------------------------------------------------------------
*[Function Name]: MRCC_voidSetSystemClock
*
*[Description]: This function is responsible for Setting the System clock 
*				There are 3 options for clock source(HSI,HSE,PLL)
*				and 2 options for hse mood(HSE_BYPASS,HSE_NOTBYPASS) can pass any thing here if you choose hsi as clock source
* 				and 2 options for pll(HSI,HSE)and 
*				if HSE is selected you must choose which mode the cyrstal is connected with(HSE_BYPASS,HSE_NOTBYPASS).
*
*[Arguments]:
*
*[in]: u8 Copy_u8Bus: This Argument indicates the bus of the peripheral(AHB1,AHB2,APB1,APB2) 
*	   u8 Copy_u8Peripheral	: This Argument indicates the peripheral 
*
*[out]: N/A
*
*[Returns]: N/A
--------------------------------------------------------------------------------------------------------------------*/
void MRCC_voidSetSystemClock(u8 Copy_u8ClockSource,u8 Copy_u8HSEMode,u8 Copy_u8PLLSource);

/* another function using error handling 
STD_error_t MRCC_stderrEnablePeripheral(u8 Copy_u8Bus,u8 Copy_u8Peripheral);
STD_error_t MRCC_stderrDisablePeripheral(u8 Copy_u8Bus,u8 Copy_u8Peripheral);*/
/****************/

/*******macros********/

#define HSI  			1
#define HSE  			2
#define PLL 			3

#define HSE_BYPASS		1
#define HSE_NOTBYPASS	2
/*********************/

/***** Bus definition******/
#define AHB1_BUS	1
#define AHB2_BUS	2
#define APB1_BUS	3
#define APB2_BUS	4
/*************************/

/***** AHB1_BUS Peripherals******/
#define DMA2EN		22		/*DMA2 clock enable*/
#define DMA1EN		21		/*DMA1 clock enable*/
#define CRCEN		12		/*CRC clock enable*/
#define GPIOHEN		7		/*I/O PORTH clock enable*/
#define GPIOEEN		4		/*I/O PORTE clock enable*/
#define GPIODEN		3		/*I/O PORTD clock enable*/
#define GPIOCEN		2		/*I/O PORTC clock enable*/
#define GPIOBEN		1		/*I/O PORTB clock enable*/
#define GPIOAEN		0		/*I/O PORTA clock enable*/
/********************************/

/***** AHB2_BUS Peripherals******/
#define OTGFSEN		7		/*USB OTG FS clock enable */
/********************************/

/***** APB1_BUS Peripherals******/
#define PWREN		28		/*Power Interface clock enable*/
#define I2C3EN		23		/*I2C3 clock enable*/
#define I2C2EN		22		/*I2C2 clock enable*/
#define I2C1EN		21		/*I2C1 clock enable*/
#define USART2EN	17		/*USART2 clock enable*/
#define SPI3EN		15		/*SPI3 clock enable*/
#define SPI2EN		14		/*SPI2 clock enable*/
#define WWDGEN		11		/*Window Watchdog clock enable*/
#define TIM5EN		3		/*TIM5 clock enable*/
#define TIM4EN		2		/*TIM4 clock enable*/
#define TIM3EN		1		/*TIM3 clock enable*/
#define TIM2EN		0		/*TIM2 clock enable*/
/********************************/

/***** APB2_BUS Peripherals******/
#define TIM11EN		18		/*TIM11 clock enable*/
#define TIM10EN		17		/*TIM10 clock enable*/
#define TIM9EN		16		/*TIM9 clock enable*/
#define SYSCFGEN	14		/*System configuration controller clock enable*/
#define SPI4EN		13		/*SPI4 clock enable*/
#define SPI1EN		12		/*SPI1 clock enable*/
#define SDIOEN		11		/*SDIO clock enable*/
#define ADC1EN		8		/*ADC1 clock enable*/
#define USART6EN	5		/*USART6 clock enable*/
#define USART1EN	4		/*USART1 clock enable*/
#define TIM1EN		0		/*TIM1 clock enable*/
/********************************/



#endif 