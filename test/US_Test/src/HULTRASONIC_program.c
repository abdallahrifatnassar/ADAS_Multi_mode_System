/**********************************/
/* Author:Gp Group 				  */
/* SWC :UltraSonic Sensor		  */
/* Layer :HAL 		              */
/* Version :1.0                   */
/* Date :Octobar 7,2023		      */
/* Last Edit :N/A                 */
/**********************************/


#include "LSTD_types.h"
#include "LBIT_math.h"
#include "MGPIO_interface.h"
#include "MSYSTICK_interface.h"
#include "MTIMER_interface.h"
#include "HULTRASONIC_interface.h"
#include "HULTRASONIC_private.h"
#include "HULTRASONIC_config.h"

u32 Global_u32Distance;
static u32 Local_u32initalValue=0;
static u32 Local_u32FinalValue=0;

<<<<<<< HEAD
static volatile u32 Local_u32initalValue=0;
static volatile u32 Local_u32FinalValue=0;
volatile u32 Global_u32Distance;
=======
>>>>>>> 4d5cc6ad828be424b38bb5022df8ed67e134bb4e
void HULTRASONIC_voidInit(void)
{
	/* Set Trigger Pin to output */
	MGPIO_voidSetPinMode(ULTRASONIC_TRIGGER_PORT_PIN,MGPIO_PIN_OUPUT);
	MGPIO_voidSetOutputPinType(ULTRASONIC_TRIGGER_PORT_PIN,MGPIO_PIN_PUSH_PULL);
	MGPIO_voidSetOutputPinSpeed(ULTRASONIC_TRIGGER_PORT_PIN,MGPIO_MEDIUMSPEED);
	
	/* Set Echo Pin to altrenate function of timer2 */
//	MGPIO_voidSetPinMode(ULTRASONIC_ECHO_PORT_PIN,MGPIO_PIN_ALTRENATE_FUNCTION);
//	MGPIO_voidSetAlternateFunction(ULTRASONIC_ECHO_PORT_PIN,1);
}

void HULTRASONIC_voidGetDistance(void)
{
<<<<<<< HEAD
	/*Make Trigger Pin to High for 10us the Low*/
	/*Make Timer 2 Count From Zero*/
	MTIMER2_voidClearCount();
=======
	/* Make Trigger Pin to High for 10us the Low*/
	/* Make Timer 2 Count From Zero*/
	//MTIMER2_voidClearCount();
	MGPIO_voidSetPinValue(ULTRASONIC_TRIGGER_PORT_PIN,MGPIO_PIN_LOW);
>>>>>>> 4d5cc6ad828be424b38bb5022df8ed67e134bb4e
	MGPIO_voidSetPinValue(ULTRASONIC_TRIGGER_PORT_PIN,MGPIO_PIN_HIGH);
	MSYSTICK_voidSetDelay(100);
	MGPIO_voidSetPinValue(ULTRASONIC_TRIGGER_PORT_PIN,MGPIO_PIN_LOW);
}

void TIM2_IRQHandler(void)
{
<<<<<<< HEAD

=======
>>>>>>> 4d5cc6ad828be424b38bb5022df8ed67e134bb4e
	volatile static u8 Local_u8Flag=0;
	
	if(0==Local_u8Flag)
	{
		MTIMER2_voidStartTimer();
		/* First time Echo high */
		Local_u32initalValue = MTIMER2_u32CaptureValue(ULTRASONIC_ECHO_CHANNEL);
		Local_u8Flag = 1;
	}
	else
	{
		/* Second time Echo Low */
		Local_u32FinalValue = MTIMER2_u32CaptureValue(ULTRASONIC_ECHO_CHANNEL);
		Local_u8Flag = 0;
		MTIMER2_voidStopTimer();
<<<<<<< HEAD
=======
		MTIMER2_voidClearCount();
>>>>>>> 4d5cc6ad828be424b38bb5022df8ed67e134bb4e
	}
	
	/* 34 is speed of sound 34cm/ms=0.034 cm/us */
	/* Distance=SpeedofSound*Time)/2 */
	/* for ex: Timer 2 freq =8MHZ ,PreScaler=64,TickTime=64/8=8  MicroSeconnd */
	/* Global_u32Distance=(((0.034 * (Local_u32FinalValue-Local_u32initalValue)*8))/2);	*/
	Global_u32Distance=(0.136 * (Local_u32FinalValue-Local_u32initalValue));
}


/*in case of you dont want to use extern */
u32 HULTRASONIC_u32Distance(void)
{
	return Global_u32Distance;
} 












