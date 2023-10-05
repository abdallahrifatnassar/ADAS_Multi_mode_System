/**********************************/
/* Author:Ahmed Samir,FahkerEldin */
/* SWC :TIMER		           	  */
/* Layer :MCAL 		              */
/* Version :1.0                   */
/* Date :Octobar 1,2023		      */
/* Last Edit :N/A                 */
/**********************************/

#include "LSTD_types.h"
#include "LBIT_math.h"
#include "MTIMER_interface.h"
#include "MTIMER_private.h"
#include "MTIMER_config.h"


void MTIMER3_voidPwmModeInit(u8 Copy_u8ChannelId)
{
	/*The clock is equal to Interal clock*/
	CLEAR_BIT(TIMER3->CR1,CKD1);
	CLEAR_BIT(TIMER3->CR1,CKD2);
	/*Edge Aligned Mode*/
	CLEAR_BIT(TIMER3->CR1,CMS1);
	CLEAR_BIT(TIMER3->CR1,CMS2);
	/*The Counter  is Upcounter*/
	CLEAR_BIT(TIMER3->CR1,DIR);

	/*Switch to konw Which channel To work on Pwm Mode1 */
	switch(Copy_u8ChannelId)
	{
		case TIMER3_CHANNEL1:
		{
			/*Set the timer To Pwm Mode1 (110)*/
			CLEAR_BIT(TIMER3->CCMR1,CH1_OC1M1);
			SET_BIT(TIMER3->CCMR1,CH1_OC1M2);
			SET_BIT(TIMER3->CCMR1,CH1_OC1M3);
			/*Enable Channel Output to get pwm signal on pin*/
			SET_BIT(TIMER3->CCER,CC1E);
			break;
		}
		case TIMER3_CHANNEL2:
		{
			/*Set the timer To Pwm Mode1 (110)*/
			CLEAR_BIT(TIMER3->CCMR1,CH2_OC2M1);
			SET_BIT(TIMER3->CCMR1,CH2_OC2M2);
			SET_BIT(TIMER3->CCMR1,CH2_OC2M3);
			SET_BIT(TIMER3->CCER,CC2E);
			break;
		}
		case TIMER3_CHANNEL3:
		{
			/*Note that Ch3 Bits Is the same as Ch1 so i use the same macros*/
			/*Set the timer To Pwm Mode1 (110)*/
			CLEAR_BIT(TIMER3->CCMR2,CH1_OC1M1);
			SET_BIT(TIMER3->CCMR2,CH1_OC1M2);
			SET_BIT(TIMER3->CCMR2,CH1_OC1M3);
			SET_BIT(TIMER3->CCER,CC3E);
			break;
		}
		case TIMER3_CHANNEL4:
		{
			/*Note that Ch3 Bits Is the same as Ch1 so i use the same macros*/
			/*Set the timer To Pwm Mode1 (110)*/
			CLEAR_BIT(TIMER3->CCMR2,CH2_OC2M1);
			SET_BIT(TIMER3->CCMR2,CH2_OC2M2);
			SET_BIT(TIMER3->CCMR2,CH2_OC2M3);
			SET_BIT(TIMER3->CCER,CC4E);
			break;
		}
	}

}

void MTIMER3_voidStartTimer(void)
{
	/*Enable Counter*/
	SET_BIT(TIMER3->CR1,CEN);
}

void MTIMER3_voidStopTimer(void)
{
	/*Disable Counter*/
	CLEAR_BIT(TIMER3->CR1,CEN);
}


void MTIMER3_voidSetCompareValue(u8 Copy_u8ChannelId,u16 Copy_u16CompareValue)
{
	/*Switch to konw Which channel To Set the Compare Match Value */
	switch(Copy_u8ChannelId)
	{
		case TIMER3_CHANNEL1:
		{
			TIMER3->CCR1=Copy_u16CompareValue;
			break;
		}
		case TIMER3_CHANNEL2:
		{
			TIMER3->CCR2=Copy_u16CompareValue;
			break;
		}
		case TIMER3_CHANNEL3:
		{
			TIMER3->CCR3=Copy_u16CompareValue;
			break;
		}
		case TIMER3_CHANNEL4:
		{
			TIMER3->CCR4=Copy_u16CompareValue;
			break;
		}
	}
}

void MTIMER3_voidSetPeriodValue(u16 Copy_u16PeriodValue)
{
	TIMER3->ARR=Copy_u16PeriodValue;
}

void MTIMER3_voidSetPreScaler(u16 Copy_u16PrescalerValue)
{
	TIMER3->PSC=Copy_u16PrescalerValue;
}
