/***********************************************/
/* Author       : Ahmed Sherif                 */
/* SWC          : NVIC                         */
/* Layer        : MCAL                         */
/* Version      : 1.0                          */
/* Date         : September 17, 2023           */
/* Last Edited  : N/A		            	   */
/***********************************************/
#include "LSTD_types.h"
#include "LBIT_math.h"
#include "MNVIC_interface.h"
#include "MNVIC_config.h"

void MNVIC_voidEnableIRQ(IRQn_Type IRQn)
{
	if ((u32)IRQn > 0)
	{
		u32 L_u32RegNum = ((u32)IRQn >> 5); // EQUIV. :IRQn / 32;
		SET_BIT(NVIC->NVIC_ISERx[L_u32RegNum], (((u32)IRQn) & 0x1F)); /*  1 << (((u32)IRQn) - (32 * L_u32RegNum)); */
	}
	else
	{
		// Do Nothing
	}
}
void MNVIC_voidDisableIRQ(IRQn_Type IRQn)
{
	if ((u32)IRQn > 0)
	{
		u32 L_u32RegNum = ((u32)IRQn >> 5);
		SET_BIT(NVIC->NVIC_ICERx[L_u32RegNum], (((u32)IRQn) & (u32)0x1F)); /* 1 << (((u32)IRQn) - (32 * L_u32RegNum)); */
	}
	else
	{
		// Do Nothing
	}
}

void MNVIC_voidSetPendingIRQ(IRQn_Type IRQn)
{
	if ((u32)IRQn > 0)
	{
		u32 L_u32RegNum = ((u32)IRQn >> 5);
		SET_BIT(NVIC->NVIC_ISPRx[L_u32RegNum], (((u32)IRQn) & 0x1F)); /* 1 << (((u32)IRQn) - (32 * L_u32RegNum)); */
	}
	else
	{
		// Do Nothing
	}
}
void MNVIC_voidClearPendingIRQ(IRQn_Type IRQn)
{
	if ((u32)IRQn > 0)
	{
		u32 L_u32RegNum = (((u32)(IRQn)) >> 5);
		SET_BIT(NVIC->NVIC_ICPRx[L_u32RegNum], (((u32)IRQn) & 0x1F)); /* 1 << (((u32)IRQn) - (32 * L_u32RegNum)) */
	}
	else
	{
		// Do Nothing
	}
}
u32 MNVIC_u32GetPendingIRQ(IRQn_Type IRQn)
{
	u32 L_u32RegNum = (((u32)(IRQn)) >> 5);
	return GET_BIT(NVIC->NVIC_ISPRx[L_u32RegNum], (((u32)IRQn) & 0x1F)); /* 1 << (((u32)IRQn) - (32 * L_u32RegNum)) */
}

u32 MNVIC_u32GetActive(IRQn_Type IRQn)
{
	u32 L_u32RegNum = (((u32)(IRQn)) >> 5);
	return GET_BIT(NVIC->NVIC_IABRx[L_u32RegNum], (((u32)IRQn) & 0x1F)); /* 1 << (((u32)IRQn) - (32 * L_u32RegNum)) */
}

void MNVIC_voidSetPriority(IRQn_Type IRQn, u32 priority)
{
	if ((u32)IRQn > 0)
	{
		NVIC->NVIC_IPRx[(u32)IRQn] = (u8) priority << 4;
	}
	else
	{
		// Do Nothing
	}
}
u8 	 MNVIC_u8GetPriority(IRQn_Type IRQn)
{
	return ((NVIC->NVIC_IPRx[(u32)IRQn] >> 4));
}

void MNVIC_voidSetPriorityGrouping(MNVIC_GroupPriority_t ARG_u8PriorityGroupLevel)
{
	/* To make sure that the value of Group Level is in range between 0 & 7 */
	u32 L_u32PriorityGroupNumTemp = ((u32)ARG_u8PriorityGroupLevel & (u32)0x07);
	u32 L_u32Value = SCB->SCB_AIRCR;
	L_u32Value &= (u32)(0XF8FF);
	L_u32Value |= (((u32)0x05FA) << 16) | ((L_u32PriorityGroupNumTemp) << 8);

	SCB->SCB_AIRCR = L_u32Value;
}
u8 MNVIC_u8GetPriorityLevel(void)
{
	return ((u32)SCB->SCB_AIRCR & (u32)0x0700);
}
