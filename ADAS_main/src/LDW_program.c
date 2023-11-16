/**********************************/
/* Author:Fakhr Eldin    		  */
/* SWC :LKA             		  */
/* Layer :APP 		              */
/* Version :1.0                   */
/* Date :Octobar 21,2023		  */
/* Last Edit :N/A                 */
/**********************************/
#include "LSTD_types.h"
#include "LBIT_math.h"
#include "MGPIO_interface.h"
#include "HIR_interface.h"
#include "HMOTORS_interface.h"
#include "LDW_interface.h"

/*LANE DEPATURE	WRANING MODE*/

u8 L_u8Right_IR = 0;
u8 L_u8Left_IR = 0;
/*Set both to intial 0 to stop */

void LDW_voidMode(void)
{   
	L_u8Right_IR =LDW_Read_IR_Right();
	L_u8Left_IR  = LDW_Read_IR_Right();

	if((L_u8Left_IR==1)&&(L_u8Right_IR==1))
	{
		/*buzeer on you	on lane */
		MGPIO_voidSetPinValue(MGPIO_PORTB, MGPIO_PIN10,MGPIO_PIN_LOW);
	}
	else if((L_u8Left_IR==0)&&(L_u8Right_IR==0))
	{
		MGPIO_voidSetPinValue(MGPIO_PORTB, MGPIO_PIN10,MGPIO_PIN_LOW);
	}
	else if((L_u8Left_IR==1)&&(L_u8Right_IR==0))
	{
		/*buzeer on out of lane */
		MGPIO_voidSetPinValue(MGPIO_PORTB, MGPIO_PIN10,MGPIO_PIN_HIGH);
	}
	else if((L_u8Left_IR==0)&&(L_u8Right_IR==1))
	{
		/*buzeer on out of lane */
		MGPIO_voidSetPinValue(MGPIO_PORTB, MGPIO_PIN10,MGPIO_PIN_HIGH);
	}
	else
	{

	}
}

void LDW_voidInit(void)
{
	HIR_voidInit(MGPIO_PORTB);
	HIR_SetPin(MGPIO_PORTB, MGPIO_PIN12);   /*portb pin 12 for Right ir*/
	HIR_SetPin(MGPIO_PORTB, MGPIO_PIN13);  /*portb pin 13 for Left ir*/
}

u8  LDW_Read_IR_Right(void)
{
	u8 L_u8Read = 0;
	L_u8Read= HIR_u8ReadIR(MGPIO_PORTB, MGPIO_PIN12);
	return L_u8Read;
}

u8  LDW_Read_IR_Left(void)
{
	u8 L_u8Read = 0;
	L_u8Read=HIR_u8ReadIR(MGPIO_PORTB, MGPIO_PIN13);
	return L_u8Read;
}





