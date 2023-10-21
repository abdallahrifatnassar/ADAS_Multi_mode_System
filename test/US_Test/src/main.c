/**************************************/
/* Author    : Ahmed Elyousfy         */
/* SWC       : UltraSonic Test        */
/* Layer     : APP                    */
/* Version   : 1.0                    */
/* Date      : October 16, 2023       */
/* Last Edit : N/A                    */
/**************************************/

#include <stdio.h>
#include <stdlib.h>

#include "LBIT_math.h"
#include "LSTD_types.h"

#include "MRCC_interface.h"
#include "MGPIO_interface.h"
#include "MTIMER_interface.h"
#include "MTIMER_private.h"
#include "MNVIC_interface.h"
#include "MSYSTICK_interface.h"
#include "USART_interface.h"


#include "HULTRASONIC_interface.h"

u8 Status;

extern u32  Global_u32Distance;
volatile u32 Local_u32initalValue,Local_u32FinalValue;
int main ()
{

	MRCC_voidInit();
	MRCC_voidEnablePeripheral(AHB1_BUS,GPIOAEN);
	MRCC_voidEnablePeripheral(AHB1_BUS,GPIOBEN);
	MRCC_voidEnablePeripheral(APB1_BUS,TIM2EN);
	MRCC_voidEnablePeripheral(APB2_BUS,USART1EN);

	MGPIO_voidSetPinMode(MGPIO_PORTB,MGPIO_PIN0,MGPIO_PIN_OUTPUT);
	MGPIO_voidSetPinMode(MGPIO_PORTB,MGPIO_PIN1,MGPIO_PIN_OUTPUT);
	MGPIO_voidSetPinMode(MGPIO_PORTB,MGPIO_PIN2,MGPIO_PIN_OUTPUT);
	MGPIO_voidSetPinMode(MGPIO_PORTB,MGPIO_PIN3,MGPIO_PIN_OUTPUT);
	MGPIO_voidSetPinMode(MGPIO_PORTB,MGPIO_PIN4,MGPIO_PIN_OUTPUT);
	MGPIO_voidSetPinMode(MGPIO_PORTB,MGPIO_PIN5,MGPIO_PIN_OUTPUT);
	MGPIO_voidSetPinMode(MGPIO_PORTB,MGPIO_PIN6,MGPIO_PIN_OUTPUT);
	MGPIO_voidSetPinMode(MGPIO_PORTB,MGPIO_PIN7,MGPIO_PIN_OUTPUT);

	MGPIO_voidSetPinMode(MGPIO_PORTA,MGPIO_PIN9,MGPIO_PIN_ALTRENATE_FUNCTION);
	MGPIO_voidSetPinMode(MGPIO_PORTA,MGPIO_PIN10,MGPIO_PIN_ALTRENATE_FUNCTION);
	MGPIO_voidSetPinMode(MGPIO_PORTA,MGPIO_PIN5,MGPIO_PIN_INPUT);



	MGPIO_voidSetAlternateFunction(MGPIO_PORTA,MGPIO_PIN9,7);
	MGPIO_voidSetAlternateFunction(MGPIO_PORTA,MGPIO_PIN10,7);




	USART_voidInit();

	MNVIC_voidEnablePeripheralInterrupt(28); /*Enable Timer 2 interrupt*/

	MSYSTICK_voidInit();
	HULTRASONIC_voidInit();


	MTIMER2_voidInit(TIMER2_CHANNEL1);
	MTIMER2_voidSetPreScaler(64);



	MTIMER2_voidEnableInterrupt();




	while (1)
	{

		 char distanceArr[5]={0};

		HULTRASONIC_voidGetDistance();





//		while (!MGPIO_u8GetPinValue(MGPIO_PORTA,MGPIO_PIN5));
//		Local_u32initalValue = TIMER2->CNT;
//		while (MGPIO_u8GetPinValue(MGPIO_PORTA,MGPIO_PIN5));
//		Local_u32FinalValue = TIMER2->CNT;





		itoa(Global_u32Distance, distanceArr, 10);


		USART_voidSend(distanceArr,5);
		USART_voidSend("\n",2);

		MSYSTICK_voidSetDelay(100000);



		if (Global_u32Distance<=10)
		{
			MGPIO_voidSetPinValue(MGPIO_PORTB,MGPIO_PIN0,MGPIO_PIN_HIGH);
			MGPIO_voidSetPinValue(MGPIO_PORTB,MGPIO_PIN1,MGPIO_PIN_LOW);
			MGPIO_voidSetPinValue(MGPIO_PORTB,MGPIO_PIN2,MGPIO_PIN_LOW);
			MGPIO_voidSetPinValue(MGPIO_PORTB,MGPIO_PIN3,MGPIO_PIN_LOW);
			MGPIO_voidSetPinValue(MGPIO_PORTB,MGPIO_PIN4,MGPIO_PIN_LOW);
			MGPIO_voidSetPinValue(MGPIO_PORTB,MGPIO_PIN5,MGPIO_PIN_LOW);
			MGPIO_voidSetPinValue(MGPIO_PORTB,MGPIO_PIN6,MGPIO_PIN_LOW);
			MGPIO_voidSetPinValue(MGPIO_PORTB,MGPIO_PIN7,MGPIO_PIN_LOW);



		}
		else if (Global_u32Distance<=50)
		{
			MGPIO_voidSetPinValue(MGPIO_PORTB,MGPIO_PIN0,MGPIO_PIN_LOW);
			MGPIO_voidSetPinValue(MGPIO_PORTB,MGPIO_PIN1,MGPIO_PIN_HIGH);
			MGPIO_voidSetPinValue(MGPIO_PORTB,MGPIO_PIN2,MGPIO_PIN_LOW);
			MGPIO_voidSetPinValue(MGPIO_PORTB,MGPIO_PIN3,MGPIO_PIN_LOW);
			MGPIO_voidSetPinValue(MGPIO_PORTB,MGPIO_PIN4,MGPIO_PIN_LOW);
			MGPIO_voidSetPinValue(MGPIO_PORTB,MGPIO_PIN5,MGPIO_PIN_LOW);
			MGPIO_voidSetPinValue(MGPIO_PORTB,MGPIO_PIN6,MGPIO_PIN_LOW);
			MGPIO_voidSetPinValue(MGPIO_PORTB,MGPIO_PIN7,MGPIO_PIN_LOW);



		}
		else if (Global_u32Distance<=100)
		{
			MGPIO_voidSetPinValue(MGPIO_PORTB,MGPIO_PIN0,MGPIO_PIN_LOW);
			MGPIO_voidSetPinValue(MGPIO_PORTB,MGPIO_PIN1,MGPIO_PIN_LOW);
			MGPIO_voidSetPinValue(MGPIO_PORTB,MGPIO_PIN2,MGPIO_PIN_HIGH);
			MGPIO_voidSetPinValue(MGPIO_PORTB,MGPIO_PIN3,MGPIO_PIN_LOW);
			MGPIO_voidSetPinValue(MGPIO_PORTB,MGPIO_PIN4,MGPIO_PIN_LOW);
			MGPIO_voidSetPinValue(MGPIO_PORTB,MGPIO_PIN5,MGPIO_PIN_LOW);
			MGPIO_voidSetPinValue(MGPIO_PORTB,MGPIO_PIN6,MGPIO_PIN_LOW);
			MGPIO_voidSetPinValue(MGPIO_PORTB,MGPIO_PIN7,MGPIO_PIN_LOW);

			MSYSTICK_voidSetDelay(30);

		}
		else if (Global_u32Distance<=200)
		{
			MGPIO_voidSetPinValue(MGPIO_PORTB,MGPIO_PIN0,MGPIO_PIN_LOW);
			MGPIO_voidSetPinValue(MGPIO_PORTB,MGPIO_PIN1,MGPIO_PIN_LOW);
			MGPIO_voidSetPinValue(MGPIO_PORTB,MGPIO_PIN2,MGPIO_PIN_LOW);
			MGPIO_voidSetPinValue(MGPIO_PORTB,MGPIO_PIN3,MGPIO_PIN_HIGH);
			MGPIO_voidSetPinValue(MGPIO_PORTB,MGPIO_PIN4,MGPIO_PIN_LOW);
			MGPIO_voidSetPinValue(MGPIO_PORTB,MGPIO_PIN5,MGPIO_PIN_LOW);
			MGPIO_voidSetPinValue(MGPIO_PORTB,MGPIO_PIN6,MGPIO_PIN_LOW);
			MGPIO_voidSetPinValue(MGPIO_PORTB,MGPIO_PIN7,MGPIO_PIN_LOW);

			MSYSTICK_voidSetDelay(30);

		}


	}



}







