/***********************************************/
/* Author       : Ahmed Sherif                 */
/* SWC          : MGPIO                        */
/* Layer        : MCAL                         */
/* Version      : 1.0                          */
/* Date         : October 21, 2023             */
/* Last Edited  : N/A                          */
/***********************************************/
#ifndef MGPIO_INTERFACE_H_
#define MGPIO_INTERFACE_H_

#include "MGPIO_config.h"

void MGPIO_voidSetPinDirection(u8 ARG_u8GPIOPort, MGPIO_Pin_t ARG_u8GPIOPin, MGPIO_Mode_t ARG_u8GPIODirection);
void MGPIO_voidSetPinOutput(u8 ARG_u8GPIOPort, MGPIO_Pin_t ARG_u8GPIOPin, MGPIO_OutPut_t ARG_u8GPIOOutPutMode);
void MGPIO_voidSetSpeed(u8 ARG_u8GPIOPort, MGPIO_Pin_t ARG_u8GPIOPin, MGPIO_OutPut_t ARG_u8GPIOSpeed);
void MGPIO_voidSetPinInPut(u8 ARG_u8GPIOPort, MGPIO_Pin_t ARG_u8GPIOPin, MGPIO_InputMode_t ARG_u8GPIOInPutMode);
void MGPIO_voidSetPinValue(u8 ARG_u8GPIOPort, MGPIO_Pin_t ARG_u8GPIOPin, MGPIO_Value_t ARG_u8GPIOPinValue);
void MGPIO_voidGetPinValue(u8 ARG_u8GPIOPort, MGPIO_Pin_t ARG_u8GPIOPin, u8 *ARG_u8ReadValue);
void MGPIO_voidSetAlternative(u8 ARG_u8GPIOPort, MGPIO_Pin_t ARG_u8GPIOPin, u8 Copy_u8AltFunction);

void MGPIO_voidSetPortValue(u8 ARG_u8GPIOPort, u8 ARG_u8Value);

/* Application of Matrix */
void MGPIO_voidLEDMatrix(u8 arr[], u8 ARG_u8Size);
void MGPIO_voidSetPinAltFun(u8 Copy_u8PortName, u8 Copy_u8PinNum, u8 Copy_u8AlFun);
#endif /* MGPIO_INTERFACE_H_ */
