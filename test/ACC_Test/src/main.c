/**************************************/
/* Author    : Ahmed Samir         	  */
/* SWC       : ACC Test        		  */
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
#include "HMOTORS_interface.h"
#include "HULTRASONIC_interface.h"
#include "ACC_interface.h"

int main ()
{

	MRCC_voidInit();
	MRCC_voidEnablePeripheral(AHB1_BUS,GPIOAEN);
	MRCC_voidEnablePeripheral(AHB1_BUS,GPIOBEN);
	MRCC_voidEnablePeripheral(APB1_BUS,TIM2EN);
	MRCC_voidEnablePeripheral(APB1_BUS,TIM3EN);



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
	HMOTOR_voidMoveForward();

	while (1)
	{
		ACC_voidMode();
		/*Wait for 15ms to make sure that the trigger pulses isn't too fast and the distance is calculated correctly */
		MSYSTICK_voidSetDelay(15000);
	}


}







