/**********************************/
/* Author :Ahmed Samir            */
/* SWC :NVIC		              */
/* Layer :MCAL 		              */
/* Version :1.0                   */
/* Date :September 17,2023        */
/* Last Edit :N/A                 */
/**********************************/

#include "LSTD_types.h"
#include "LBIT_math.h"
#include "MNVIC_private.h"
#include "MNVIC_config.h"
#include "MNVIC_interface.h"

static GroupMode_t Global_GroupMode;

void MNVIC_voidEnablePeripheralInterrupt(u8 Copy_u8InterruptId)
{
	NVIC->ISER[(Copy_u8InterruptId/REGISTER_WIDTH)]=(1<<(Copy_u8InterruptId%REGISTER_WIDTH));
}
void MNVIC_voidDisablePeripheralInterrupt(u8 Copy_u8InterruptId)
{
	NVIC->ICER[(Copy_u8InterruptId/REGISTER_WIDTH)]=(1<<(Copy_u8InterruptId%REGISTER_WIDTH));
}

void MNVIC_voidSetPeripheralPendingFlag(u8 Copy_u8InterruptId)
{
	NVIC->ISPR[(Copy_u8InterruptId/REGISTER_WIDTH)]=(1<<(Copy_u8InterruptId%REGISTER_WIDTH));
}

void MNVIC_voidClearPeripheralPendingFlag(u8 Copy_u8InterruptId)
{
	NVIC->ICPR[(Copy_u8InterruptId/REGISTER_WIDTH)]=(1<<(Copy_u8InterruptId%REGISTER_WIDTH));
}

void MNVIC_voidSetGroupMode(GroupMode_t Copy_enGroupMode)
{
	Global_GroupMode=Copy_enGroupMode;
	AIRCR |=(VECTKEY|(Copy_enGroupMode<<8));	
}

void MNVIC_voidSetPeripheralPriority(u8 Copy_u8InterruptId,u8 Copy_u8GroupId,u8 Copy_u8SubGroupId)
{
	switch(Global_GroupMode)
	{
		case MNVIC_GROUP16_SUB0:
		{
			// no sub priority only group in the 4 msb bits
			NVIC->IPR[Copy_u8InterruptId]=(Copy_u8GroupId<<4);
			break;
		}
		case MNVIC_GROUP8_SUB2:
		{
			// 8 groups at the 3 msb bits and 1 for sub priority
			NVIC->IPR[Copy_u8InterruptId]=((Copy_u8GroupId<<5)|(Copy_u8SubGroupId<<4));
			break;
		}
		case MNVIC_GROUP4_SUB4:
		{
			// 4 groups at the 2 msb bits and 2 for sub priority
			NVIC->IPR[Copy_u8InterruptId]=((Copy_u8GroupId<<6)|(Copy_u8SubGroupId<<4));
			break;
		}
		case MNVIC_GROUP2_SUB8:
		{
			// 8 groups at the 3 msb bits and ine for sub priority
			NVIC->IPR[Copy_u8InterruptId]=((Copy_u8GroupId<<7)|(Copy_u8SubGroupId<<4));
			break;
		}
		case MNVIC_GROUP0_SUB16:
		{
			// no group 16 sub priority
			NVIC->IPR[Copy_u8InterruptId]=(Copy_u8SubGroupId<<4);
			break;
		}
	}
}
