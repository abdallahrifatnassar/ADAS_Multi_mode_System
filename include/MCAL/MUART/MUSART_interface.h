/***********************************************/
/* Author       : Ahmed Sherif                 */
/* SWC          : USART                        */
/* Layer        : MCAL                         */
/* Version      : 1.0                          */
/* Date         : November 4, 2023             */
/* Last Edited  : OCTOBER 7, 2023              */
/***********************************************/

#ifndef _MUSART_INTERFACE_H_
#define _MUSART_INTERFACE_H_

/*--------------------------------------------------------------------------------------------------------------------
*[Function Name]: MUSART_voidInit
*
*[Description]: This function is responsible for Configuring the USART protocol and its initialization
*
*[Arguments]:
*
*[in]: u32 ARG_u32BaudRate: It takes the value of baud rate as an argument according to the equation: RX/TX Baud = (F_CPU)/(8 * (2 - OVER8) * USARTDIV)
*
*[out]: N/A
*
*[Returns]: N/A
--------------------------------------------------------------------------------------------------------------------*/
void MUSART_voidInit(u32 ARG_u32BaudRate);
/*--------------------------------------------------------------------------------------------------------------------
*[Function Name]: MUSART_voidEnableUART
*
*[Description]: This function is responsible for Enabling the USART communication
*
*[Arguments]:
*
*[in]: N/A
*
*[out]: N/A
*
*[Returns]: N/A
--------------------------------------------------------------------------------------------------------------------*/
void MUSART_voidEnableUART(void);
/*--------------------------------------------------------------------------------------------------------------------
*[Function Name]: MUSART_voidEnableTX
*
*[Description]: This function is responsible for Enabling the Transmitting pin TX
*
*[Arguments]:
*
*[in]: N/A
*
*[out]: N/A
*
*[Returns]: N/A
--------------------------------------------------------------------------------------------------------------------*/
void MUSART_voidEnableTX(void);
/*--------------------------------------------------------------------------------------------------------------------
*[Function Name]: MUSART_voidDisableTX
*
*[Description]: This function is responsible for Disabling the Transmitting pin TX
*
*[Arguments]:
*
*[in]: N/A
*
*[out]: N/A
*
*[Returns]: N/A
--------------------------------------------------------------------------------------------------------------------*/
void MUSART_voidDisableTX(void);
/*--------------------------------------------------------------------------------------------------------------------
*[Function Name]: MUSART_voidEnableRX
*
*[Description]: This function is responsible for Enabling the Receiving pin RX
*
*[Arguments]:
*
*[in]: N/A
*
*[out]: N/A
*
*[Returns]: N/A
--------------------------------------------------------------------------------------------------------------------*/
void MUSART_voidEnableRX(void);
/*--------------------------------------------------------------------------------------------------------------------
*[Function Name]: MUSART_voidDisableUART
*
*[Description]: This function is responsible for Disabling the Receiving pin RX
*
*[Arguments]:
*
*[in]: N/A
*
*[out]: N/A
*
*[Returns]: N/A
--------------------------------------------------------------------------------------------------------------------*/
void MUSART_voidDisableRX(void);
/*--------------------------------------------------------------------------------------------------------------------
*[Function Name]: MUSART_voidSendData
*
*[Description]: This function is responsible for Sending data character by character
*
*[Arguments]:
*
*[in]: u8 ARG_u8Data: It takes the character tha you want to send and put into the Data_Register.
*
*[out]: N/A
*
*[Returns]: N/A
--------------------------------------------------------------------------------------------------------------------*/
void MUSART_voidSendData(u8 ARG_u8Data);
/*--------------------------------------------------------------------------------------------------------------------
*[Function Name]: MUSART_voidReadData
*
*[Description]: This function is responsible for Receiving data charater by character from other devices.
*
*[Arguments]:
*
*[in]: N/A
*
*[out]: N/A
*
*[Returns]: It returns the data that has been sent in type of (u8)
--------------------------------------------------------------------------------------------------------------------*/
u8 MUSART_voidReadData(void);
/*--------------------------------------------------------------------------------------------------------------------
*[Function Name]: MUSART_voidEnableInterrupt
*
*[Description]: This function is responsible for Enabling interrupt to indicate that data has been sent.
*
*[Arguments]:
*
*[in]: N/A
*
*[out]: N/A
*
*[Returns]: N/A
--------------------------------------------------------------------------------------------------------------------*/
void MUSART_voidEnableInterrupt(void);
/*--------------------------------------------------------------------------------------------------------------------
*[Function Name]: MUSART_voidEnableInterrupt
*
*[Description]: This function is responsible for Disabling interrupt.
*
*[Arguments]:
*
*[in]: N/A
*
*[out]: N/A
*
*[Returns]: N/A
--------------------------------------------------------------------------------------------------------------------*/
void MUSART_voidDisableInterrupt(void);

#endif /* _MUSART_INTERFACE_H_ */