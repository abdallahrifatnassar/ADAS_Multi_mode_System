/*
  * File:  USART_Program.c 
 *	SWC:    USART
 *	Version: 1.0 
 *  Created on: 19-06-2023 
 *  Author: Abdallah Ragab 
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "USART_Interface.h"
#include "USART_Private.h"
#include "USART_Config.h"


void USART_voidInit(void){
	/*1- Enable Rx and Tx*/
	SET_BIT(USART1->USART_CR1,3);
	SET_BIT(USART1->USART_CR1,2);
	/*USART1 is connected to APB2,8MHZ*/
	USART1->USART_BRR=0x341;
	/*USART1 is connected to APB2,8MHZ*/
	SET_BIT(USART1->USART_CR1,13);




}

void USART_voidSend(char* Datau8TransData,u8 Copy_u8Length){
	u8 local_u8Counter=0;
	while(local_u8Counter<Copy_u8Length){
		USART1->USART_DR=Datau8TransData[local_u8Counter];
		while(GET_BIT(USART1->USART_SR,6)==0);
		local_u8Counter++;

	}

}

void USART_voidReceive(u8* Datau8ReceData){
	while(GET_BIT(USART1->USART_SR,5)==0);
	*Datau8ReceData=USART1->USART_DR;
}

