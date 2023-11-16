/************************************/
/* Author    : Abdullah Nassar    	*/
/* SWC       : INFRARED SENSOR		*/
/* Layer     : HAL               	*/
/* Version   : 1.0                	*/
/* Date      : October 5, 2023 		*/
/* Last Edit : N/A			      	*/
/************************************/

#ifndef _HIR_INTERFACE_H_
#define _HIR_INTERFACE_H_

/****** Port Macros*******/
#define HIR_PORTA 1
#define HIR_PORTB 2
#define HIR_PORTC 3
/************************/

/********Pins Macros*****/
#define HIR_PIN0 0
#define HIR_PIN1 1
#define HIR_PIN2 2
#define HIR_PIN3 3
#define HIR_PIN4 4
#define HIR_PIN5 5
#define HIR_PIN6 6
#define HIR_PIN7 7
#define HIR_PIN8 8
#define HIR_PIN9 9
#define HIR_PIN10 10
#define HIR_PIN11 11
#define HIR_PIN12 12
#define HIR_PIN13 13
#define HIR_PIN14 14
#define HIR_PIN15 15
/************************/

/*--------------------------------------------------------------------------------------------------------------------
 * @brief Initialize the specified HIR peripheral.
 *
 * This function first initializes the MRCC, then enables the peripheral clock.
 *
 * @param Copy_u8Port The port number of the HIR peripheral to initialize.
 *
 * @return None
 *
/*--------------------------------------------------------------------------------------------------------------------*/
void HIR_voidInit(u8 Copy_u8Port);


/*--------------------------------------------------------------------------------------------------------------------
/**
 * @brief Sets the specified pin of the HIR peripheral as input with pull-up resistor.
 *
 * @param Copy_u8Port The port number of the HIR peripheral to set the pin for.
 * @param Copy_u8Pin The pin number to set.
 *
 * @return None
 */
/*--------------------------------------------------------------------------------------------------------------------*/
void HIR_SetPin(u8 Copy_u8Port, u8 Copy_u8Pin);


/*--------------------------------------------------------------------------------------------------------------------
/**
 /**
 * @brief Read the value of the specified HIR pin.
 *
 * This function reads the value of the specified pin of the HIR peripheral.
 *
 * @param Copy_u8Port The port number of the HIR peripheral to read the pin for.
 * @param Copy_u8Pin The pin number to read.
 *
 * @return The value of the pin.
 */
/*--------------------------------------------------------------------------------------------------------------------*/
u8 HIR_u8ReadIR(u8 Copy_u8Port, u8 Copy_u8Pin);

#endif