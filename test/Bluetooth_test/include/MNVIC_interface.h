/***********************************************/
/* Author       : Ahmed Sherif                 */
/* SWC          : NVIC                         */
/* Layer        : MCAL                         */
/* Version      : 1.0                          */
/* Date         : September 17, 2023           */
/* Last Edited  : N/A		            	   */
/***********************************************/

#ifndef _MNVIC_INTERFACE_H_
#define _MNVIC_INTERFACE_H_

#include "LSTD_types.h"
#include "MNVIC_config.h"
#include "MNVIC_private.h"
#include "MSCB_private.h"
/*Enables an interrupt or exception
[NAME]: void MNVIC_voidEnableIRQ(IRQn_Type IRQn)
[IN]: The argument of the function which indicates which interrupt is desired
[OUT]: N/A
[DES]: The function is meant to be called to enable the interrupt or exception being chosen.
*/
void MNVIC_voidEnableIRQ(IRQn_Type IRQn);
/*---------------------------------------------------------------------------------------------*/

/*Disables a previously enabled interrupt*/
void MNVIC_voidDisableIRQ(IRQn_Type IRQn);
/*---------------------------------------------------------------------------------------------*/
/*Setting the priority of a given interrupt*/
void MNVIC_voidSetPriority(IRQn_Type IRQn, u32 priority);
u8 	 MNVIC_u8GetPriority(IRQn_Type IRQn);
/*---------------------------------------------------------------------------------------------*/
/*Setting the Interrupt priority grouping field
This field determines the split of group priority from subpriority */
void MNVIC_voidSetPriorityGrouping(MNVIC_GroupPriority_t ARG_u8PriorityGroupLevel);
u8 MNVIC_u8GetPriorityLevel(void);

/*Testing the code*/

/* Set the pending status of an interrupt */
void MNVIC_voidSetPendingIRQ(IRQn_Type IRQn);
/* Clear the pending status of an interrupt*/
void MNVIC_voidClearPendingIRQ(IRQn_Type IRQn);
/* Get the pending status of an interrupt */
u32 MNVIC_u32GetPendingIRQ(IRQn_Type IRQn);
/*Get the Active status of the interrupt */
u32 MNVIC_u32GetActive(IRQn_Type IRQn);

#endif /* _MNVIC_INTERFCAE_H_ */
