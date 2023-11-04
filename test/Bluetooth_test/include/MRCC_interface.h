/************************************/
/* Author    : Ahmed Sherif    	    */
/* SWC       : RCC          		*/
/* Layer     : MCAL               	*/
/* Version   : 1.0                	*/
/* Date      : October 19, 2023 	*/
/* Last Edit : N/A			      	*/
/************************************/
#ifndef _MRCC_INTERFACE_H_
#define _MRCC_INTERFACE_H_

void MRCC_voidInit(void);
u8 MRCC_voidEnablePeripheral(u8 ARG_u8CLKBus, u8 ARG_u8Peripheral);
u8 MRCC_voidDisablePeripheral(u8 ARG_u8CLKBus, u8 ARG_u8Peripheral);
#endif /* _MRCC_INTERFACE_H_ */