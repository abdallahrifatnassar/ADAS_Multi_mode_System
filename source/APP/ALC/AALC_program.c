/****************************************************/
/* Author 	: Abdullah Nassar & Ahmed ELyousfy     	*/
/* SWC 		: ALC		                  			*/
/* Layer 	: APP 		              				*/
/* Version 	: 1.0                   				*/
/* Date 	: October 31,2023          				*/
/* Last Edit: N/A                 					*/
/****************************************************/

/*		Liberaries		*/
#include "LSTD_types.h"
#include "LBIT_math.h"

/*		MCAL Drivers	*/
#include "MGPIO_interface.h"

/*		HAL Drivers		*/
#include "HLDR_interface.h"

/*		APP files		*/
#include "AALC_interface.h"
#include "AALC_config.h"
#include "AALC_private.h"

void	AALC_voidMode(void)
{
	static u8 L_u8ReadLDR;
	
	//Get sensor reading
	L_u8ReadLDR = HLDR_u8ReadLDR();
	
	//Turn lights ON or OFF
	if ( 1 == L_u8ReadLDR)
	{
		MGPIO_voidSetPinValue(OP_PORTPIN,MGPIO_PIN_HIGH);
	}
	else
	{
		MGPIO_voidSetPinValue(OP_PORTPIN,MGPIO_PIN_LOW);
	}
}