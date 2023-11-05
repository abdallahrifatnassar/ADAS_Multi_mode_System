/***********************************************/
/* Author       : Ahmed Sherif                 */
/* SWC          : USART                        */
/* Layer        : MCAL                         */
/* Version      : 1.0                          */
/* Date         : OCTOBER 7, 2023              */
/* Last Edited  : N/A                          */
/***********************************************/

#ifndef _MUSART_INTERFACE_H_
#define _MUSART_INTERFACE_H_

void MUSART_voidInit(u32 ARG_u32BaudRate);
void MUSART_voidEnableUART(void);

void MUSART_voidEnableTX(void);
void MUSART_voidDisableTX(void);

void MUSART_voidEnableRX(void);
void MUSART_voidDisableRX(void);

void MUSART_voidSendData(u8 ARG_u8Data);
u8 MUSART_voidReadData(void);

void MUSART_voidEnableInterrupt(void);
void MUSART_voidDisableInterrupt(void);

#endif //  _MUSART_INTERFACE_H_