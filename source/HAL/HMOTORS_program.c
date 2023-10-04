/**********************************/
/* Author:Ahmed Samir,FahkerEldin */
/* SWC :MOTOR		           	  */
/* Layer :HAL 		              */
/* Version :1.0                   */
/* Date :Octobar 4,2023		      */
/* Last Edit :N/A                 */
/**********************************/

#include "LSTD_types.h"
#include "LBIT_math.h"
#include "MGPIO_interface.h"
#include "MTIMER_interface.h"
#include "HMOTOR_interface.h"
#include "HMOTOR_private.h"
#include "HMOTOR_config.h"


void HMOTOR_voidInit(void)
{
	/*Set Motor control Direction pins to output Pushpull (IN1->4) */
	
	MGPIO_voidSetPinMode(MOTOR_IN1_PORT,MOTOR_IN1_PIN,MGPIO_PIN_OUPUT);
	MGPIO_voidSetOutputPinType(MOTOR_IN1_PORT,MOTOR_IN1_PIN,MGPIO_PIN_PUSH_PULL);
	MGPIO_voidSetOutputPinSpeed(MOTOR_IN1_PORT,MOTOR_IN1_PIN,MGPIO_MEDIUMSPEED);
													 
	MGPIO_voidSetPinMode(MOTOR_IN2_PORT,MOTOR_IN2_PIN,MGPIO_PIN_OUPUT);
	MGPIO_voidSetOutputPinType(MOTOR_IN2_PORT,MOTOR_IN2_PIN,MGPIO_PIN_PUSH_PULL);
	MGPIO_voidSetOutputPinSpeed(MOTOR_IN2_PORT,MOTOR_IN2_PIN,MGPIO_MEDIUMSPEED);
													 
	MGPIO_voidSetPinMode(MOTOR_IN3_PORT,MOTOR_IN3_PIN,MGPIO_PIN_OUPUT);
	MGPIO_voidSetOutputPinType(MOTOR_IN3_PORT,MOTOR_IN3_PIN,MGPIO_PIN_PUSH_PULL);
	MGPIO_voidSetOutputPinSpeed(MOTOR_IN3_PORT,MOTOR_IN3_PIN,MGPIO_MEDIUMSPEED);
													 
	MGPIO_voidSetPinMode(MOTOR_IN4_PORT,MOTOR_IN4_PIN,MGPIO_PIN_OUPUT);
	MGPIO_voidSetOutputPinType(MOTOR_IN4_PORT,MOTOR_IN4_PIN,MGPIO_PIN_PUSH_PULL);
	MGPIO_voidSetOutputPinSpeed(MOTOR_IN4_PORT,MOTOR_IN4_PIN,MGPIO_MEDIUMSPEED);
	
}

void HMOTOR_voidMoveForward(void)
{
	
}

void HMOTOR_voidMoveBackward(void)
{
	
}

void HMOTOR_voidStop(void)
{
	
}

void HMOTOR_voidMoveRight(void)
{
	
}

void HMOTOR_voidMoveLeft(void)
{
	
}

void HMOTOR_voidSetSpeed(u16 Copy_u16Speed)
{
	
}