/**************************************/
/* Author    : Ahmed Elyousfy         */ 
/* SWC       : UART	                  */
/* Layer     : MCAL	                  */
/* Version   : 1.0                    */
/* Date      : 0ctober 02 ,2023	      */
/* Last Edit : N/A                    */
/**************************************/

#ifndef MUART_PRIVATE_H_
#define MUART_PRIVATE_H_

#define STOP_MASK	0xFFFFCFFF


/* UART BASE ADDRESS */
#define USART_BASE_ADDRESS	0x40011000


#define USART_SR	*((volatile u32 *)(USART_BASE_ADDRESS))	     /*USART Status Register	*/
#define USART_DR	*((volatile u32 *)(USART_BASE_ADDRESS+0x04)) /*USART Data Register		*/
#define USART_BRR	*((volatile u32 *)(USART_BASE_ADDRESS+0x08)) /*USART Baud Rate Register	*/
#define USART_CR1	*((volatile u32 *)(USART_BASE_ADDRESS+0x0C)) /*USART Control Register 1	*/
#define CR1_UE		13
#define CR1_M		12
#define CR1_PCE		10
#define CR1_PS		9
#define CR1_PEIE	8
#define CR1_TXEIE	7
#define CR1_TCIE	6
#define CR1_RXNEIE	5
#define CR1_IDLEIE	4
#define CR1_TE		3
#define CR1_RE		2

#define USART_CR2	*((volatile u32 *)(USART_BASE_ADDRESS+0x10)) /*USART Control Register 2	*/
#define CR2_STOP_BIT	12
#define CR2_CPOL		10
#define CR2_CPHA		9

#define USART_CR3	*((volatile u32 *)(USART_BASE_ADDRESS+0x14)) /*USART Control Register 3	*/
#define CR3_EIE		0

#define USART_GTPR	*((volatile u32 *)(USART_BASE_ADDRESS+0x18)) /*USART Guard Time and Prescaler Register*/



#endif
