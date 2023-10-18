/************************************/
/* Author    : Abdullah Nassar    	*/
/* SWC       : INFRARED SENSOR		*/
/* Layer     : HAL               	*/
/* Version   : 1.0                	*/
/* Date      : October 5, 2023 		*/
/* Last Edit : N/A			      	*/
/************************************/

#include "LBIT_math.h"
#include "LSTD_types.h"

/* MCAL INCLUDES */
#include "MGPIO_interface.h"

/* HAL INCLUDES */
#include "HIR_config.h"
#include "HIR_private.h"
#include "HIR_interface.h"

void HIR_voidInit(u8 Copy_u8Port)
{
    MRCC_voidInit();
    
	MRCC_voidEnablePeripheral(AHB1_BUS,Copy_u8Port-1);
}

void HIR_SetPin(u8 Copy_u8Port, u8 Copy_u8Pin)
{
    MGPIO_voidSetPinMode(Copy_u8Port, Copy_u8Pin, MGPIO_PIN_INPUT);
    MGPIO_voidSetPinPullType(Copy_u8Port, Copy_u8Pin, MGPIO_PULL_UP);
}

u8 HIR_u8ReadIR(u8 Copy_u8Port, u8 Copy_u8Pin)
{
    u8 L_u8Read = 0;
    L_u8Read = MGPIO_u8GetPinValue(Copy_u8Port, Copy_u8Pin);
    return L_u8Read;
}


