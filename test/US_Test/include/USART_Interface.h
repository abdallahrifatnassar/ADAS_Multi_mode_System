/*
  * File:  USART_Interface.h 
 *	SWC:    USART
 *	Version: 1.0 
 *  Created on: 19-06-2023 
 *  Author: Abdallah Ragab 
 */
#ifndef USART_INTERFACE
#define USART_INTERFACE

void USART_voidInit(void);

void USART_voidSend(char* Datau8TransData,u8 Copy_u8Length);

void USART_voidReceive(u8* Datau8ReceData);


#endif // USART_INTERFACE
