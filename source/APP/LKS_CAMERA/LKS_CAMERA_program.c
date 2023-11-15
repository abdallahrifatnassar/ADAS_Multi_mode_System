/**********************************/
/* Author :Ahmed Samir            */
/* SWC :LKS With Camera		      */
/* Layer :APP 		              */
/* Version :1.0                   */
/* Date :October 30,2023          */
/* Last Edit :N/A                 */
/**********************************/

#include "LSTD_types.h"
#include "LBIT_math.h"
#include "MGPIO_interface.h"
#include "HMOTORS_interface.h"
#include "HIR_interface.h"
#include "LKS_CAMERA_interface.h"
#include "LKS_CAMERA_config.h"
#include "LKS_CAMERA_private.h"


/*LANE KEEPING ASSIST MODE with Camera*/

u8 L_u8Right_Read_Cam = 0;
u8 L_u8Left_Read_Cam = 0;
/*Set both to intial 0 to stop */





void LKS_Camera_App(void)
{   
	LKS_Camera_App_Init();
	L_u8Right_Read_Cam =LKS_Camera_Read_Right();
	L_u8Left_Read_Cam  = LKS_Camera_Read_Left();

	if((L_u8Left_Read_Cam==1)&&(L_u8Right_Read_Cam==1)) /*-> MOVEFORWARD*/
	{
		HMOTOR_voidMoveForward();
	}
	else if((L_u8Left_Read_Cam==0)&&(L_u8Right_Read_Cam==0)) /*-> STOP*/
	{
		HMOTOR_voidStop();
	}
	else if((L_u8Left_Read_Cam==1)&&(L_u8Right_Read_Cam==0)) /*(Camera order turn left)->TURNLEFT*/
	{
		HMOTOR_voidMoveLeft();
	}
	else if((L_u8Left_Read_Cam==0)&&(L_u8Right_Read_Cam==1)) /*(Camera order turn left)->TURNRIGHT*/
	{
		HMOTOR_voidMoveRight();
	}
	else
	{

	}
}

void LKS_Camera_App_Init(void)
{
	HIR_voidInit(MGPIO_PORTB);
	HIR_SetPin(MGPIO_PORTB, MGPIO_PIN14);   /*portb pin 14 for Left ir*/
	HIR_SetPin(MGPIO_PORTB, MGPIO_PIN15);   /*portb pin 15 for Right ir*/

}

u8  LKS_Camera_Read_Right(void)
{   u8 L_u8Read = 0;
	L_u8Read= HIR_u8ReadIR(MGPIO_PORTB, MGPIO_PIN15); // read output order of camera if 1 force car to move right
	return L_u8Read;
}

u8  LKS_Camera_Read_Left(void)
{
	u8 L_u8Read = 0;
	L_u8Read=HIR_u8ReadIR(MGPIO_PORTB, MGPIO_PIN14);// read output order of camera if 1 force car to move left
	return L_u8Read;
}






