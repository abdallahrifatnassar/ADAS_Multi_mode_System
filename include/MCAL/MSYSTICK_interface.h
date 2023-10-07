/**********************************/
/* Author :Ahmed Samir            */
/* SWC :SYSTICK		              */
/* Layer :MCAL 		              */
/* Version :1.0                   */
/* Date :September 18,2023        */
/* Last Edit :N/A                 */
/**********************************/

#ifndef _MSYSTICK_INTERFACE_H_
#define _MSYSTICK_INTERFACE_H_

/*******APIS******/

/*--------------------------------------------------------------------------------------------------------------------
*[Function Name]: MEXTI_voidEnableExtiInterrupt
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
void MSYSTICK_voidInit(void);

void MSYSTICK_voidSelectClock(u8 Copy_u8SystickClock);

void MSYSTICK_voidEnable(void);

void MSYSTICK_voidDisable(void);

void MSYSTICK_voidEnableInterrupt(void);

void MSYSTICK_voidDisableInterrupt(void);

void MSYSTICK_voidReloadValue(u32 Copy_u32ReloadValue);

void MSYSTICK_voidClearTimer(void);

u32 MSYSTICK_u32GetElaspedTime(void);

u32 MSYSTICK_u32GetRemainingTime(void);

void MSYSTICK_voidSetCallBack(void (*Copy_pvUserFunc)(void));

void MSYSTICK_voidSetDelay(u32 Copy_u32DelayTicks);
/*****************/

/***Clock Macros**/

#define AHB					1
#define AHB_DIV_BY8			2

/*****************/
#endif 

