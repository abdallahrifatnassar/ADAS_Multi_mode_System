/**********************************/
/* Author :Ahmed Samir            */
/* SWC :SYSTICK		              */
/* Layer :MCAL 		              */
/* Version :1.0                   */
/* Date :September 18,2023        */
/* Last Edit :N/A                 */
/**********************************/

#include "LSTD_types.h"
#include "LBIT_math.h"
#include "MSYSTICK_interface.h"
#include "MSYSTICK_private.h"
#include "MSYSTICK_config.h"

void (*Global_pvSysTickFunc )(void)=NULL;

void MSYSTICK_voidInit(void)
{
	// pre build function of SysTick
	
	//1-Select SysTick Clock
	#if SYSTICK_CLOCK==AHB_CLOCK
		SET_BIT(SYSTICK->CTRL,SYSTICK_CLK_SOURCE);
	#elif SYSTICK_CLOCK==AHB_CLOCK_DIV_BY_8
		CLEAR_BIT(SYSTICK->CTRL,SYSTICK_CLK_SOURCE);	
	#else
		#error "Wrong Systick Clock Config";
	#endif
	// 2- Enable ,Disable SysTick Interrupt
	#if SYSTICK_INTERRUPT==SYSTICK_INTERRUPT_ENABLE
		SET_BIT(SYSTICK->CTRL,SYSTICK_INT_ENABLE);
	#elif SYSTICK_INTERRUPT==SYSTICK_INTERRUPT_DISABLE
		CLEAR_BIT(SYSTICK->CTRL,SYSTICK_INT_ENABLE);
	#else
		#error "Wrong Systick Interrupt Config";
	#endif
	//3- Set the pre load Value
	SYSTICK->LOAD=LOAD_VALUE;
	
	//4- Enable,disable Systick(to start or stop timer)
	#if SYSTICK_MODE==ENABLED
		SET_BIT(SYSTICK->CTRL,SYSTICK_ENABLE);
	#elif SYSTICK_MODE==DISABLED
		CLEAR_BIT(SYSTICK->CTRL,SYSTICK_ENABLE);
	#else
		#error "Wrong Systick Enable Config";
	#endif
}

void MSYSTICK_voidSelectClock(u8 Copy_u8SystickClock)
{
	switch(Copy_u8SystickClock)
	{
		case AHB:SET_BIT(SYSTICK->CTRL,SYSTICK_CLK_SOURCE);break;
		case AHB_DIV_BY8:CLEAR_BIT(SYSTICK->CTRL,SYSTICK_CLK_SOURCE);break;
		default:break;//error
	}
}
void MSYSTICK_voidEnable(void)
{
	// Enable SysTick To start Timer
	SET_BIT(SYSTICK->CTRL,SYSTICK_ENABLE);
}

void MSYSTICK_voidDisable(void)
{
	// Disable SysTick To Stop Timer
	CLEAR_BIT(SYSTICK->CTRL,SYSTICK_ENABLE);
}

void MSYSTICK_voidEnableInterrupt(void)
{
	SET_BIT(SYSTICK->CTRL,SYSTICK_INT_ENABLE);
}

void MSYSTICK_voidDisableInterrupt(void)
{
	CLEAR_BIT(SYSTICK->CTRL,SYSTICK_INT_ENABLE);
}
void MSYSTICK_voidReloadValue(u32 Copy_u32ReloadValue)
{
	// load the value in reload register
	SYSTICK->LOAD=Copy_u32ReloadValue;
}
void MSYSTICK_voidClearTimer(void)
{
	// set 0 or any number to value register clears it
	SYSTICK->VAL=0;
}

u32 MSYSTICK_u32GetElaspedTime(void)
{
	u8 Local_u8Return;
	Local_u8Return=(SYSTICK->LOAD-SYSTICK->VAL);
	return Local_u8Return;
}
u32 MSYSTICK_u32GetRemainingTime(void)
{
	return(SYSTICK->VAL);
}
void MSYSTICK_voidSetCallBack(void (*Copy_pvUserFunc)(void))
{
	if(Copy_pvUserFunc!=NULL)
	{
		Global_pvSysTickFunc=Copy_pvUserFunc;
	}
	else
	{
		//error
	}
}
void SysTick_Handler(void)
{
	volatile u8 Local_u8FlagClear;
	if(Global_pvSysTickFunc!=NULL)
	{
		Global_pvSysTickFunc();
	}
	else
	{
		
	}
	// read the flag to clear it
	Local_u8FlagClear=GET_BIT(SYSTICK->CTRL,SYSTICK_COUNT_FLAG);
}


void MSYSTICK_voidSetDelay(u32 Copy_u32DelayTicks)
{
	//Load The Value to be waited
	MSYSTICK_voidReloadValue(Copy_u32DelayTicks);
	//Enable Systick To start
	MSYSTICK_voidEnable();
	//wait For the flag to be 1
	while(!GET_BIT(SYSTICK->CTRL,SYSTICK_COUNT_FLAG));
	//Stop systick
	MSYSTICK_voidDisable();
}
