/**********************************/
/* Author :Ahmed Samir            */
/* SWC :NVIC		              */
/* Layer :MCAL 		              */
/* Version :1.0                   */
/* Date :September 17,2023        */
/* Last Edit :N/A                 */
/**********************************/

#ifndef _MNVIC_INTERFACE_H_
#define _MNVIC_INTERFACE_H_



/*****Priority Enum****/

typedef enum
{
	MNVIC_GROUP16_SUB0=3,
	MNVIC_GROUP8_SUB2,
	MNVIC_GROUP4_SUB4,
	MNVIC_GROUP2_SUB8,
	MNVIC_GROUP0_SUB16,

}GroupMode_t;
/**********************/

/*******APIS******/

/*--------------------------------------------------------------------------------------------------------------------
*[Function Name]: MNVIC_voidEnablePeripheralInterrupt
*
*[Description]: This function is responsible for Enabling peripheral Interrupt  
*
*[Arguments]:
*
*[in]: u8 Copy_u8InterruptId: This Argument indicates the id of the interrupt 
*
*[out]: N/A
*
*[Returns]: N/A
--------------------------------------------------------------------------------------------------------------------*/
void MNVIC_voidEnablePeripheralInterrupt(u8 Copy_u8InterruptId);

/*--------------------------------------------------------------------------------------------------------------------
*[Function Name]: MNVIC_voidDisablePeripheralInterrupt
*
*[Description]: This function is responsible for Disabling peripheral Interrupt  
*
*[Arguments]:
*
*[in]: u8 Copy_u8InterruptId: This Argument indicates the id of the interrupt 
*
*[out]: N/A
*
*[Returns]: N/A
--------------------------------------------------------------------------------------------------------------------*/
void MNVIC_voidDisablePeripheralInterrupt(u8 Copy_u8InterruptId);

/*--------------------------------------------------------------------------------------------------------------------
*[Function Name]: MNVIC_voidSetPeripheralPendingFlag
*
*[Description]: This function is responsible for Setting peripheral pending flag (to test software) 
*
*[Arguments]:
*
*[in]: u8 Copy_u8InterruptId: This Argument indicates the id of the interrupt 
*
*[out]: N/A
*
*[Returns]: N/A
--------------------------------------------------------------------------------------------------------------------*/
void MNVIC_voidSetPeripheralPendingFlag(u8 Copy_u8InterruptId);

/*--------------------------------------------------------------------------------------------------------------------
*[Function Name]: MNVIC_voidSetPeripheralPendingFlag
*
*[Description]: This function is responsible for Clearing peripheral pending flag  
*
*[Arguments]:
*
*[in]: u8 Copy_u8InterruptId: This Argument indicates the id of the interrupt 
*
*[out]: N/A
*
*[Returns]: N/A
--------------------------------------------------------------------------------------------------------------------*/
void MNVIC_voidClearPeripheralPendingFlag(u8 Copy_u8InterruptId);

/*--------------------------------------------------------------------------------------------------------------------
*[Function Name]: MNVIC_voidSetGroupMode
*
*[Description]: This function is responsible for Setting software priority (group and sub ) 
*
*[Arguments]:
*
*[in]: GroupMode_t Copy_enGroupMode: This Argument indicates the (group and sub ) of the System 
*
*[out]: N/A
*
*[Returns]: N/A
--------------------------------------------------------------------------------------------------------------------*/
void MNVIC_voidSetGroupMode(GroupMode_t Copy_enGroupMode);

/*--------------------------------------------------------------------------------------------------------------------
*[Function Name]: MNVIC_voidSetPeripheralPriority
*
*[Description]: This function is responsible for Setting software priority for every peripheral (group and sub ) 
*
*[Arguments]:
*
*[in]: u8 Copy_u8InterruptId: This Argument indicates the id of interrupt (no of interrupt at vector table)
*	   u8 Copy_u8GroupId: This Argument indicates the Group priority of interrupt (lower value Higher priority)
*	   u8 Copy_u8SubGroupId: This Argument indicates the sub group priority  of interrupt (lower value Higher priority)
*
*[out]: N/A
*
*[Returns]: N/A
--------------------------------------------------------------------------------------------------------------------*/
void MNVIC_voidSetPeripheralPriority(u8 Copy_u8InterruptId,u8 Copy_u8GroupId,u8 Copy_u8SubGroupId);



/*****************/




#endif 
