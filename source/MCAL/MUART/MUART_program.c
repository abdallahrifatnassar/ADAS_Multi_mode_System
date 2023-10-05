/**************************************/
/* Author    : Ahmed Elyousfy         */ 
/* SWC       : UART	                  */
/* Layer     : MCAL	                  */
/* Version   : 1.0                    */
/* Date      : 0ctober 02 ,2023	      */
/* Last Edit : N/A                    */
/**************************************/

#include "LBIT_math.h"
#include "LSTD_types.h"

#include "MUART_config.h"
#include "MUART_private.h"
#include "MUART_interface.h"

void MUART_voidInit (void)
{
	/* ENABLE UART */
	SET_BIT(USART_CR1,CR1_UE);
	
	/* WORD LENGTH SET TO 8 BIT */
	CLEAR_BIT(USART_CR1,CR1_M);
	
	/* SET BAUD RATE TO A PRE CONFIGURED VALUE */
	USART_BRR = (UART_BAUD_RATE << 4);
	
	/* SET STOP BIT NUMBER */
	USART_CR2 |= (USART_CR2 & (STOP_MASK)) | (STOP_BIT_VALUE<<CR2_STOP_BIT);
	
	/* NO PARITY NEEDED*/
	CLEAR_BIT(USART_CR1,CR1_PCE);
}