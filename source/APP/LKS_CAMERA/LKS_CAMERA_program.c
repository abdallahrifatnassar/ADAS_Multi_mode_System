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
#include "MUART_interface.h"
#include "HMOTORS_interface.h"
#include "LKS_CAMERA_interface.h"
#include "LKS_CAMERA_config.h"
#include "LKS_CAMERA_private.h"

void LKS_CAMERA_voidMode(void)
{
	/*1- Get Data From Uart */
	u8 Local_u8UartData;
	Local_u8UartData=MUSART_voidReadData
	/*2- Take Descision according to this data*/
	
	if(Local_u8UartData<LKS_CAMERA_MIN_LEFT_ANGLE)
	{
		/*Data is Lower than 8(min angle) then this is left angle command so motors move left*/
		HMOTOR_voidMoveLeft();
	}
	else if(Local_u8UartData>LKS_CAMERA_MIN_RIGHT_ANGLE)
	{
		/*Data is higher than 12(min angle) then this is right angle command so motors move right*/
		HMOTOR_voidMoveRight();
	}
	else
	{
		/*Data is between 8,12 then motor move forward*/
		HMOTOR_voidMoveForward();
	}
}


