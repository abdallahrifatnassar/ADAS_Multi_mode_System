/**************************************/
/* Author    : Ahmed Elyousfy         */ 
/* SWC       : UART	                  */
/* Layer     : MCAL	                  */
/* Version   : 1.0                    */
/* Date      : 0ctober 02 ,2023	      */
/* Last Edit : N/A                    */
/**************************************/

#ifndef MUART_CONFIG_H_
#define MUART_CONFIG_H_

/*Baud Rate 9600   = 0x682 */
/*Baud Rate 115200 = 0x0811*/
#define UART_BAUD_RATE	0x682

/* 
FOR 2 STOP BITS SET VALUE TO 2
FOR 1 STOP BITS SET VALUE TO 0
*/
#define STOP_BIT_VALUE	2

#endif