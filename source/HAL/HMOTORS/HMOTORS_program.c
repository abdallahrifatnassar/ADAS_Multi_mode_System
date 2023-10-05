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
	
	MGPIO_voidSetPinMode(MOTOR_IN1_PORT_PIN,MGPIO_PIN_OUPUT);
	MGPIO_voidSetOutputPinType(MOTOR_IN1_PORT_PIN,MGPIO_PIN_PUSH_PULL);
	MGPIO_voidSetOutputPinSpeed(MOTOR_IN1_PORT_PIN,MGPIO_MEDIUMSPEED);
													 
	MGPIO_voidSetPinMode(MOTOR_IN2_PORT_PIN,MGPIO_PIN_OUPUT);
	MGPIO_voidSetOutputPinType(MOTOR_IN2_PORT_PIN,MGPIO_PIN_PUSH_PULL);
	MGPIO_voidSetOutputPinSpeed(MOTOR_IN2_PORT_PIN,MGPIO_MEDIUMSPEED);
													 
	MGPIO_voidSetPinMode(MOTOR_IN3_PORT_PIN,MGPIO_PIN_OUPUT);
	MGPIO_voidSetOutputPinType(MOTOR_IN3_PORT_PIN,MGPIO_PIN_PUSH_PULL);
	MGPIO_voidSetOutputPinSpeed(MOTOR_IN3_PORT_PIN,MGPIO_MEDIUMSPEED);
													 
	MGPIO_voidSetPinMode(MOTOR_IN4_PORT_PIN,MGPIO_PIN_OUPUT);
	MGPIO_voidSetOutputPinType(MOTOR_IN4_PORT_PIN,MGPIO_PIN_PUSH_PULL);
	MGPIO_voidSetOutputPinSpeed(MOTOR_IN4_PORT_PIN,MGPIO_MEDIUMSPEED);
	
}

void HMOTOR_voidMoveForward(void)
{
	/*Motor 1 control pins (IN1,IN2) 
	to move forward Make IN1 High and IN2 Low 
	and reverse if backward and so is on motor 2 (IN3,IN4)*/
	
	/*Motor 1*/
	MGPIO_voidSetPinValue(MOTOR_IN1_PORT_PIN,MGPIO_PIN_HIGH);
	MGPIO_voidSetPinValue(MOTOR_IN2_PORT_PIN,MGPIO_PIN_LOW);
	
	/*Motor 2*/
	MGPIO_voidSetPinValue(MOTOR_IN3_PORT_PIN,MGPIO_PIN_HIGH);
	MGPIO_voidSetPinValue(MOTOR_IN4_PORT_PIN,MGPIO_PIN_LOW);
}

void HMOTOR_voidMoveBackward(void)
{
	/*Motor 1 control pins (IN1,IN2) 
	to move forward Make IN1 High and IN2 Low 
	and reverse if backward and so is on motor 2 (IN3,IN4)*/
	
	/*Motor 1*/
	MGPIO_voidSetPinValue(MOTOR_IN1_PORT_PIN,MGPIO_PIN_LOW);
	MGPIO_voidSetPinValue(MOTOR_IN2_PORT_PIN,MGPIO_PIN_HIGH);
	
	/*Motor 2*/
	MGPIO_voidSetPinValue(MOTOR_IN3_PORT_PIN,MGPIO_PIN_LOW);
	MGPIO_voidSetPinValue(MOTOR_IN4_PORT_PIN,MGPIO_PIN_HIGH);
}

void HMOTOR_voidStop(void)
{
	/*STOP All Motors*/
	MGPIO_voidSetPinValue(MOTOR_IN1_PORT_PIN,MGPIO_PIN_LOW);
	MGPIO_voidSetPinValue(MOTOR_IN2_PORT_PIN,MGPIO_PIN_LOW);
	MGPIO_voidSetPinValue(MOTOR_IN3_PORT_PIN,MGPIO_PIN_LOW);
	MGPIO_voidSetPinValue(MOTOR_IN4_PORT_PIN,MGPIO_PIN_LOW);
	
}

void HMOTOR_voidMoveRight(void)
{
	/*Move Motors in the right (m1) Stop Motors in the left(m2)*/
	
	MGPIO_voidSetPinValue(MOTOR_IN1_PORT_PIN,MGPIO_PIN_HIGH);
	MGPIO_voidSetPinValue(MOTOR_IN2_PORT_PIN,MGPIO_PIN_LOW);
	
	MGPIO_voidSetPinValue(MOTOR_IN3_PORT_PIN,MGPIO_PIN_LOW);
	MGPIO_voidSetPinValue(MOTOR_IN4_PORT_PIN,MGPIO_PIN_LOW);
}

void HMOTOR_voidMoveLeft(void)
{
	/*Stop Motors in the right (m1) Move Motors in the left(m2)*/
	
	MGPIO_voidSetPinValue(MOTOR_IN1_PORT_PIN,MGPIO_PIN_LOW);
	MGPIO_voidSetPinValue(MOTOR_IN2_PORT_PIN,MGPIO_PIN_LOW);
	
	MGPIO_voidSetPinValue(MOTOR_IN3_PORT_PIN,MGPIO_PIN_HIGH);
	MGPIO_voidSetPinValue(MOTOR_IN4_PORT_PIN,MGPIO_PIN_LOW);
}

void HMOTOR_voidSetSpeed(u16 Copy_u16Speed)
{
	/*Set Compare Match Value to adjust Pwm(SPeed)*/
	
	MTIMER3_voidSetCompareValue(MOTOR_EN_CHANNEL,Copy_u16Speed);
}