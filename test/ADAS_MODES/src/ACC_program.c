/**********************************/
/* Author :Ahmed Samir            */
/* SWC :ACC		                  */
/* Layer :APP 		              */
/* Version :1.0                   */
/* Date :October 21,2023          */
/* Last Edit :N/A                 */
/**********************************/

#include "LSTD_types.h"
#include "LBIT_math.h"
#include "HULTRASONIC_interface.h"
#include "HMOTORS_interface.h"
#include "ACC_interface.h"
#include "ACC_private.h"
#include "ACC_config.h"

/*Global Variable used to get distance*/
extern u32  Global_u32Distance;
void ACC_voidMode(void)
{
	static u16 Local_u16Speed=ACC_MIN_SPEED;
	/*First Calculate The Distace */
	HULTRASONIC_voidGetDistance();
	
	/*Second Set the Speed according to Distance*/
	
	if(Global_u32Distance>=ACC_MAX_DISTANCE)
	{
		/*The Distance is larger than Max Distance So Increase the Speed */
		Local_u16Speed+=ACC_SPEED_RATE;
	}
	else if(Global_u32Distance>=ACC_MIN_DISTANCE)
	{
		/*The Distance is less than Max Distance and higher than min Distance So maintain the Speed */
		/*Dont change any thing*/
	}
	else if(Global_u32Distance>=ACC_SAFE_DISTANCE)
	{
		/*The Distance is less than min Distance and higher than safe Distance So Decrease the Speed */
		Local_u16Speed-=ACC_SPEED_RATE;
	}
	else
	{
		/*The Distance is less than  safe Distance So Stop the Car */
		Local_u16Speed=ACC_MIN_SPEED;
	}
	
	
	/*Third Check if the calculated speed is less than max Speed*/
	if(Local_u16Speed>=ACC_MAX_SPEED)
	{
		Local_u16Speed=ACC_MAX_SPEED;
	}
	else if(Local_u16Speed<ACC_MIN_SPEED)
	{
		Local_u16Speed=ACC_MIN_SPEED;
	}
	else
	{
		/*Speed is Correct and within the range*/
	}
	
	/*Fourth Apply The New Speed To Motor*/
	HMOTOR_voidSetSpeed(Local_u16Speed);
}


