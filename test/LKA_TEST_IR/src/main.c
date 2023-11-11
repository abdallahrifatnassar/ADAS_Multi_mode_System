/*
 * main.c
 *
 *  Created on: Sep 27, 2023
 *      Author: Ahmed Samir
 */




#include "LSTD_types.h"
#include "LBIT_math.h"
#include "MRCC_interface.h"
#include "MGPIO_interface.h"
#include "MTIMER_interface.h"
#include "HMOTORS_interface.h"
#include "ALKA_IR_interface.h"

u16 Global_u16Data=0;

int main (void)
{
	/*Clock Init*/
sz	MRCC_voidInit();
	/*Peripherals Enables*/
	MRCC_voidEnablePeripheral(AHB1_BUS,GPIOAEN);
	MRCC_voidEnablePeripheral(AHB1_BUS,GPIOBEN);

	/*Enable Timer 3 Peripheral*/
	MRCC_voidEnablePeripheral(APB1_BUS,TIM3EN);
	/*Setup Altrenate Function */
	/*Timer 3 Channel 2 at-> PORTB,Pin5*/
	MGPIO_voidSetPinMode(MGPIO_PORTB,MGPIO_PIN5,MGPIO_PIN_ALTRENATE_FUNCTION);
	MGPIO_voidSetAlternateFunction(MGPIO_PORTB,MGPIO_PIN5,2);



	MTIMER3_voidPwmModeInit(TIMER3_CHANNEL2);
	MTIMER3_voidSetPeriodValue(1000);
	MTIMER3_voidSetPreScaler(160);
	MTIMER3_voidStartTimer();

    /*Motor	init*/

	HMOTOR_voidInit();
	HMOTOR_voidSetSpeed(500);
	//HMOTOR_voidMoveForward();

	ALKA_IR_Init();

	while (1)
	{
		APP_LKA();
	}
	return 0;
}

