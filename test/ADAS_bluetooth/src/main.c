/**************************************/
/* Author    : Ahmed Samir         	  */
/* SWC       : ADAs Test        	  */
/* Layer     : APP                    */
/* Version   : 1.0                    */
/* Date      : October 16, 2023       */
/* Last Edit : N/A                    */
/**************************************/


#include "LBIT_math.h"
#include "LSTD_types.h"
#include "MRCC_interface.h"
#include "MGPIO_interface.h"
#include "MTIMER_interface.h"
#include "MTIMER_private.h"
#include "MNVIC_interface.h"
#include "MSYSTICK_interface.h"
#include "MUSART_interface.h"
#include "HMOTORS_interface.h"
#include "HULTRASONIC_interface.h"
#include "HIR_interface.h"
#include "ACC_interface.h"
#include "ALKA_IR_interface.h"
#include "LDW_interface.h"


u32	G_u32Read;
int main ()
{

	MRCC_voidInit();
	MRCC_voidEnablePeripheral(AHB1_BUS,GPIOAEN);
	MRCC_voidEnablePeripheral(AHB1_BUS,GPIOBEN);
	MRCC_voidEnablePeripheral(APB1_BUS,TIM2EN);
	MRCC_voidEnablePeripheral(APB1_BUS,TIM3EN);
	MRCC_voidEnablePeripheral(APB2_BUS,USART1EN);

	/*Set UART1 Pin */
	MGPIO_voidSetPinMode(MGPIO_PORTA,MGPIO_PIN9,MGPIO_PIN_ALTRENATE_FUNCTION);
	MGPIO_voidSetPinMode(MGPIO_PORTA,MGPIO_PIN10,MGPIO_PIN_ALTRENATE_FUNCTION);
	MGPIO_voidSetAlternateFunction(MGPIO_PORTA,MGPIO_PIN9,7);
	MGPIO_voidSetAlternateFunction(MGPIO_PORTA,MGPIO_PIN10,7);

	/*UART1	Enable*/
	MUSART_voidInit(833);
	MUSART_voidEnableRX();
	MUSART_voidEnableTX();
	MUSART_voidEnableUART();

	/**/
	MGPIO_voidSetPinMode(MGPIO_PORTB, MGPIO_PIN10,MGPIO_PIN_OUTPUT);
	MGPIO_voidSetOutputPinType(MGPIO_PORTB, MGPIO_PIN10,MGPIO_PIN_PUSH_PULL);
	MGPIO_voidSetOutputPinSpeed(MGPIO_PORTB, MGPIO_PIN10,MGPIO_MEDIUMSPEED);

	MNVIC_voidEnablePeripheralInterrupt(28); /*Enable Timer 2 interrupt*/

	MSYSTICK_voidInit();
	HULTRASONIC_voidInit();

	/*Set Timer 3 Channel 2 Altrenative function*/
	MGPIO_voidSetPinMode(MGPIO_PORTB,MGPIO_PIN5,MGPIO_PIN_ALTRENATE_FUNCTION);
	MGPIO_voidSetAlternateFunction(MGPIO_PORTB,MGPIO_PIN5,2);

	/*Timer2 init*/
	MTIMER2_voidInit(TIMER2_CHANNEL1);
	MTIMER2_voidSetPreScaler(64);
	MTIMER2_voidEnableInterrupt();

	/*Timer 3 init*/
	MTIMER3_voidPwmModeInit(TIMER3_CHANNEL2);
	MTIMER3_voidSetPeriodValue(1000);
	MTIMER3_voidSetPreScaler(160);
	MTIMER3_voidStartTimer();



	HMOTOR_voidInit();
	HMOTOR_voidSetSpeed(500);

	ALKA_IR_Init();

	while (1)
	{

		G_u32Read = MUSART_voidReadData();
		switch	(G_u32Read)
		{
		case	'F'	:
		{
			HMOTOR_voidMoveForward();
			break;
		}
		case	'B'	:
		{
			HMOTOR_voidMoveBackward();
			break;
		}
		case	'L'	:
		{
			HMOTOR_voidMoveLeft();
			break;
		}
		case	'R'	:
		{
			HMOTOR_voidMoveRight();
			break;
		}
		case	'W'	:
		{
			/*ACC	With	AE*/

			HMOTOR_voidMoveForward();
			ACC_voidMode();

			break;
		}
		case	'U'	:
		{
			/*LKA	With	LDW*/
			HMOTOR_voidSetSpeed(500);
			APP_LKA();
			break;
		}
		case	'1'	:
		{
			HMOTOR_voidSetSpeed(100);
			break;
		}
		case	'2'	:
		{
			HMOTOR_voidSetSpeed(200);
			break;
		}
		case	'3'	:
		{
			HMOTOR_voidSetSpeed(300);
			break;
		}
		case	'4'	:
		{
			HMOTOR_voidSetSpeed(400);
			break;
		}
		case	'5'	:
		{
			HMOTOR_voidSetSpeed(500);
			break;
		}
		case	'6'	:
		{
			HMOTOR_voidSetSpeed(600);
			break;
		}
		case	'7'	:
		{
			HMOTOR_voidSetSpeed(700);
			break;
		}
		case	'8'	:
		{
			HMOTOR_voidSetSpeed(800);
			break;
		}
		case	'9'	:
		{
			HMOTOR_voidSetSpeed(900);
			break;
		}
		case	'q'	:
		{
			HMOTOR_voidSetSpeed(1000);
			break;
		}
		default:HMOTOR_voidStop();break;
		}

	}


}
