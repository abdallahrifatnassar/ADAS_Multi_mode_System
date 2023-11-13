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
#include "AALC_interface.h"
#include "HLDR_interface.h"


u32	G_u32Read = 0;
void func(void);
int main ()
{

	MRCC_voidInit();
	MRCC_voidEnablePeripheral(AHB1_BUS,GPIOAEN);
	MRCC_voidEnablePeripheral(AHB1_BUS,GPIOBEN);
	MRCC_voidEnablePeripheral(APB1_BUS,TIM2EN);
	MRCC_voidEnablePeripheral(APB1_BUS,TIM3EN);
	MRCC_voidEnablePeripheral(APB2_BUS,USART1EN);


	MNVIC_voidEnablePeripheralInterrupt(28); /*Enable Timer 2 interrupt*/
	MNVIC_voidEnablePeripheralInterrupt(37); /*Enable USART 1 interrupt*/
	MNVIC_voidSetGroupMode(MNVIC_GROUP2_SUB8);
	MNVIC_voidSetPeripheralPriority(28,0,0);
	MNVIC_voidSetPeripheralPriority(37,1,0);
	CallBack(func);

	/*Set UART1 Pin */
	MGPIO_voidSetPinMode(MGPIO_PORTA,MGPIO_PIN9,MGPIO_PIN_ALTRENATE_FUNCTION);
	MGPIO_voidSetOutputPinType(MGPIO_PORTA,MGPIO_PIN9,MGPIO_PIN_PUSH_PULL);
	MGPIO_voidSetPinPullType(MGPIO_PORTA,MGPIO_PIN9,MGPIO_PULL_UP);
	MGPIO_voidSetAlternateFunction(MGPIO_PORTA,MGPIO_PIN9,7);

	MGPIO_voidSetPinMode(MGPIO_PORTA,MGPIO_PIN10,MGPIO_PIN_ALTRENATE_FUNCTION);
	MGPIO_voidSetOutputPinType(MGPIO_PORTA,MGPIO_PIN10,MGPIO_PIN_PUSH_PULL);
	MGPIO_voidSetPinPullType(MGPIO_PORTA,MGPIO_PIN10,MGPIO_PULL_UP);
	MGPIO_voidSetAlternateFunction(MGPIO_PORTA,MGPIO_PIN10,7);


	/* LDR Pin Values */
	HLDR_SetPin(MGPIO_PORTA,MGPIO_PIN12);
	MGPIO_voidSetPinMode(MGPIO_PORTA,MGPIO_PIN15,MGPIO_PIN_OUTPUT);
	MGPIO_voidSetOutputPinType(MGPIO_PORTA,MGPIO_PIN15,MGPIO_PIN_PUSH_PULL);
	MGPIO_voidSetPinPullType(MGPIO_PORTA,MGPIO_PIN15,MGPIO_PULL_UP);

	/*UART1	Enable*/
	MUSART_voidInit(833);
	MUSART_voidEnableInterrupt();
	MUSART_voidEnableRX();
	MUSART_voidEnableTX();
	MUSART_voidEnableUART();

	/*Test */
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

	}
}

void func(void)
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
		/*ACC	With	AEB*/
		HMOTOR_voidMoveForward();
		while(G_u32Read != 'w')
		{
			G_u32Read = MUSART_voidReadData();
			AALC_voidMode();
			ACC_voidMode();
			MSYSTICK_voidSetDelay(25000);
		}
		break;
	}
	case	'U'	:
	{
		/*LKA	With	LDW*/
		while(G_u32Read != 'u')
		{
			G_u32Read = MUSART_voidReadData();
			APP_LKA();
		}
		break;
	}
	default:HMOTOR_voidStop();break;
	}
}
