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



void MTIMER2_voidInit(u8 Copy_u8ChannelId)
{
	// Edge-aligned mode. The counter counts up or down depending on the direction bit
	CLEAR_BIT(TIMER2->CR1,CMS1);
	CLEAR_BIT(TIMER2->CR1,1<<CMS1);  
	//Counter used as upcounter
	CLEAR_BIT(TIMER2->CR1,DIR);		
	switch(Copy_u8ChannelId)
	{
		case TIMER2_CHANNEL1:
		{
			//01: CC1 channel is configured as input, IC1 is mapped on TI1
			SET_BIT(TIMER2->CCMR1,CC1S0);			
			CLEAR_BIT(TIMER2->CCMR1,CC1S1);	
			/*00: no prescaler, capture is done each time an edge is detected on the  
			capture inpuT*/		
			CLEAR_BIT(TIMER2->CCMR1,IC1PSC0);
			CLEAR_BIT(TIMER2->CCMR1,IC1PSC1);
			//11: noninverted/both edges
			SET_BIT(TIMER2->CCER,CC1P);	
			SET_BIT(TIMER2->CCER,CC1NP);
			//Enable Capture
			SET_BIT(TIMER2->CCER,CC1E);
		}break;
		case TIMER2_CHANNEL2:
		{
			//01: CC1 channel is configured as input, IC2 is mapped on TI2
			SET_BIT(TIMER2->CCMR1,CC2S8);			
			CLEAR_BIT(TIMER2->CCMR1,CC2S9);	
			/*00: no prescaler, capture is done each time an edge is detected on the 
			capture inpuT*/		
			CLEAR_BIT(TIMER2->CCMR1,IC2PSC10);
			CLEAR_BIT(TIMER2->CCMR1,IC2PSC10);
			//11: noninverted/both edges
			SET_BIT(TIMER2->CCER,CC2P);	
			SET_BIT(TIMER2->CCER,CC2NP);
			//Enable Capture
			SET_BIT(TIMER2->CCER,CC2E);			
		}break;
		
		case TIMER2_CHANNEL3:
		{
			//01: CC1 channel is configured as input, IC2 is mapped on TI2
			SET_BIT(TIMER2->CCMR2,CC3S0);			
			CLEAR_BIT(TIMER2->CCMR2,CC3S1);	
			/*00: no prescaler, capture is done each time an edge is detected on the 
			capture inpuT*/		
			CLEAR_BIT(TIMER2->CCMR2,IC2PSC10);
			CLEAR_BIT(TIMER2->CCMR2,IC2PSC10);
			//11: noninverted/both edges
			SET_BIT(TIMER2->CCER,CC3P);	
			SET_BIT(TIMER2->CCER,CC3NP);
			//Enable Capture
			SET_BIT(TIMER2->CCER,CC3E);
		}break;
		case TIMER2_CHANNEL4:
		{
			//01: CC1 channel is configured as input, IC2 is mapped on TI2
			SET_BIT(TIMER2->CCMR2,CC4S8);			
			CLEAR_BIT(TIMER2->CCMR2,CC4S9);	
			/*00: no prescaler, capture is done each time an edge is detected on the 
			capture inpuT*/		
			CLEAR_BIT(TIMER2->CCMR2,IC4PSC10);
			CLEAR_BIT(TIMER2->CCMR2,IC4PSC11);
			//11: noninverted/both edges
			SET_BIT(TIMER2->CCER,CC4P);	
			SET_BIT(TIMER2->CCER,CC4NP);
			//Enable Capture
			SET_BIT(TIMER2->CCER,CC4E);			
		}break;
	}
}
void MTIMER2_voidStartTimer(void)
{
	/*Enable Counter*/
	CLEAR_BIT(TIMER2->CR1,CEN);	
}
void MTIMER2_voidStopTimer(void)
{
	/*Disable Counter*/
	CLEAR_BIT(TIMER2->CR1,CEN);
}

u32	 MTIMER2_u32CaptureValue(u8 Copy_u8ChannelId)
{
	u32 Local_u32CaptureValue=0;
	switch(Copy_u8ChannelId)
	{
		case TIMER2_CHANNEL1:
		{
			Local_u32CaptureValue=TIMER2->CCR1;
		}break;
		case TIMER2_CHANNEL2:
		{
			Local_u32CaptureValue=TIMER2->CCR2;
		}break;
		case TIMER2_CHANNEL3:
		{
			Local_u32CaptureValue=TIMER2->CCR3;
		}break;
		case TIMER2_CHANNEL4:
		{
			Local_u32CaptureValue=TIMER2->CCR4;	
		}break;
	}
	return	Local_u32CaptureValue;	
}
void MTIMER2_voidEnableInterrupt(void)
{
	/*Enable interrupt*/
	SET_BIT(TIMER2->DIER,CC1IE);
}
void MTIMER2_voidDisableInterrupt(void)
{
	/*Disable interrupt*/
	CLEAR_BIT(TIMER2->DIER,CC1IE);
}

void MTIMER2_voidSetPreScaler(u16 Copy_u16PrescalerValue)
{
	TIMER2->PSC=Copy_u16PrescalerValue;
}

void MTIMER2_voidClearCount(void)
{
	TIMER2->CNT=0;
}