/***********************************************/
/* Author       : Ahmed Sherif                 */
/* SWC          : USART                        */
/* Layer        : MCAL                         */
/* Version      : 1.0                          */
/* Date         : OCTOBER 7, 2023              */
/* Last Edited  : N/A                          */
/***********************************************/

#include "LSTD_types.h"
#include "LBIT_math.h"
#include "MUSART_private.h"
#include "MUSART_config.h"
#include "MUSART_interface.h"

void (*ptrvoid)(void) = NULL_POINTER;

void MUSART_voidInit(u32 ARG_u32BaudRate)
{
	/* Defining the baud rate to the register */
	USART1->USART_BRR = ARG_u32BaudRate;
	/* Defining the OverSamoling mode by 16 */
	CLEAR_BIT(USART1->USART_CR1, 15);
	/* Defining the WordLength of the data to be written */
	CLEAR_BIT(USART1->USART_CR1, 12);
	/* Defining the Number of STOP bits to be One Stop bit*/
	CLEAR_BIT(USART1->USART_CR2, 12);
	CLEAR_BIT(USART1->USART_CR2, 13);
}

void MUSART_voidEnableUART(void)
{
	SET_BIT(USART1->USART_CR1, 13);
}

void MUSART_voidEnableTX(void)
{
	SET_BIT(USART1->USART_CR1, 3);
}
void MUSART_voidDisableTX(void)
{
	CLEAR_BIT(USART1->USART_CR1, 3);
}

void MUSART_voidEnableRX(void)
{
	SET_BIT(USART1->USART_CR1, 2);
}
void MUSART_voidDisableRX(void)
{
	CLEAR_BIT(USART1->USART_CR1, 3);
}

void MUSART_voidSendData(u8 ARG_u8Data)
{
	while (!(GET_BIT(USART1->USART_SR, 7)));
	USART1->USART_DR = ARG_u8Data;
}
u8 MUSART_voidReadData(void)
{
	//while (!(GET_BIT(USART1->USART_SR, 5)));
	return (USART1->USART_DR);
}

void MUSART_voidEnableInterrupt(void)
{
	SET_BIT(USART1->USART_CR1,5);
}
void MUSART_voidDisableInterrupt(void)
{
	CLEAR_BIT(USART1->USART_CR1,5);
}

void CallBack(void (*ptr)(void))
{
	ptrvoid = ptr;
}

void USART1_IRQHandler(void)
{
	if(NULL_POINTER != ptrvoid)
	{
		(*ptrvoid)();
	}
	else
	{
		// Do Nothing
	}
}
