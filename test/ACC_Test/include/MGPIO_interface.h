/**********************************/
/* Author :Ahmed Samir            */
/* SWC :GPIO		              */
/* Layer :MCAL 		              */
/* Version :1.0                   */
/* Date :September 16,2023        */
/* Last Edit :N/A                 */
/**********************************/

#ifndef _MGPIO_INTERFACE_H_
#define _MGPIO_INTERFACE_H_


/****** Port Macros*******/
#define MGPIO_PORTA							1
#define MGPIO_PORTB							2
#define MGPIO_PORTC							3
/************************/

/********Pins Macros******/
#define MGPIO_PIN0							0
#define MGPIO_PIN1							1
#define MGPIO_PIN2							2
#define MGPIO_PIN3							3
#define MGPIO_PIN4							4
#define MGPIO_PIN5							5
#define MGPIO_PIN6							6
#define MGPIO_PIN7							7
#define MGPIO_PIN8							8
#define MGPIO_PIN9							9
#define MGPIO_PIN10							10
#define MGPIO_PIN11							11
#define MGPIO_PIN12							12
#define MGPIO_PIN13							13
#define MGPIO_PIN14							14
#define MGPIO_PIN15							15
/************************/

/********Pins Modes******/
#define MGPIO_PIN_INPUT						0
#define MGPIO_PIN_OUTPUT					1
#define MGPIO_PIN_ALTRENATE_FUNCTION		2
#define MGPIO_PIN_ANALOG					3
/************************/


/***Output pins Modes***/
#define MGPIO_PIN_PUSH_PULL					1
#define MGPIO_PIN_OPEN_DRAIN				2
/************************/

/****Output Pins Speed***/ 
#define MGPIO_LOWSPEED						0
#define MGPIO_MEDIUMSPEED					1
#define MGPIO_HIGHSPEED						2
#define MGPIO_VERYHIGHSPEED					3
/************************/

/****Pins Pull Types***/ 
#define MGPIO_NO_PULL						0
#define MGPIO_PULL_UP						1
#define MGPIO_PULL_DOWN						2
/************************/
/****Pins Values***/ 
#define MGPIO_PIN_LOW						0
#define MGPIO_PIN_HIGH						1
/************************/




/************ APIS*******/
/*--------------------------------------------------------------------------------------------------------------------
*[Function Name]: MGPIO_voidSetPinMode
*
*[Description]: This function is responsible for Setting pin mode at certain port 
*				There are 4 options(MGPIO_PIN_INPUT,MGPIO_PIN_OUPUT,MGPIO_PIN_ALTRENATE_FUNCTION,MGPIO_PIN_ANALOG)
*
*[Arguments]:
*
*[in]: u8 Copy_u8Port: This Argument indicates the PORT (MGPIO_PORTA,MGPIO_PORTB,MGPIO_PORTC) 
* 	   u8 Copy_u8Pin: This Argument indicates the Pin (0->15)
*      u8 Copy_u8Mode:This Argument indicates the Mode(MGPIO_PIN_INPUT,MGPIO_PIN_OUPUT,MGPIO_PIN_ALTRENATE_FUNCTION,MGPIO_PIN_ANALOG)
*
*[out]: N/A
*
*[Returns]: N/A
--------------------------------------------------------------------------------------------------------------------*/
void MGPIO_voidSetPinMode(u8 Copy_u8Port,u8 Copy_u8Pin,u8 Copy_u8Mode);


/*--------------------------------------------------------------------------------------------------------------------
*[Function Name]: MGPIO_voidSetOutputPinType
*
*[Description]: This function is responsible for Setting the type of pin  at certain port
*				There are 2 options(MGPIO_PIN_PUSH_PULL,MGPIO_PIN_OPEN_DRAIN)
*
*[Arguments]:
*
*[in]: u8 Copy_u8Port: This Argument indicates the PORT (MGPIO_PORTA,MGPIO_PORTB,MGPIO_PORTC) 
* 	   u8 Copy_u8Pin: This Argument indicates the Pin (0->15)
*      u8 Copy_u8Type:This Argument indicates the Type(MGPIO_PIN_PUSH_PULL,MGPIO_PIN_OPEN_DRAIN)
*
*[out]: N/A
*
*[Returns]: N/A
--------------------------------------------------------------------------------------------------------------------*/
void MGPIO_voidSetOutputPinType(u8 Copy_u8Port,u8 Copy_u8Pin,u8 Copy_u8Type);


/*--------------------------------------------------------------------------------------------------------------------
*[Function Name]: MGPIO_voidSetOutputPinSpeed
*
*[Description]: This function is responsible for Setting the Speed of pin  at certain port
*				There are 4 options(MGPIO_LOWSPEED,MGPIO_MEDIUMSPEED,MGPIO_HIGHSPEED,MGPIO_VERYHIGHSPEED)
*
*[Arguments]:
*
*[in]: u8 Copy_u8Port: This Argument indicates the PORT (MGPIO_PORTA,MGPIO_PORTB,MGPIO_PORTC) 
* 	   u8 Copy_u8Pin: This Argument indicates the Pin (0->15)
*      u8 Copy_u8Speed:This Argument indicates the Speed(MGPIO_LOWSPEED,MGPIO_MEDIUMSPEED,MGPIO_HIGHSPEED,MGPIO_VERYHIGHSPEED)
*
*[out]: N/A
*
*[Returns]: N/A
--------------------------------------------------------------------------------------------------------------------*/
void MGPIO_voidSetOutputPinSpeed(u8 Copy_u8Port,u8 Copy_u8Pin,u8 Copy_u8Speed);


/*--------------------------------------------------------------------------------------------------------------------
*[Function Name]: MGPIO_voidSetOutputPinSpeed
*
*[Description]: This function is responsible for Setting the Inter conncetion of pin  at certain port
*				There are 3 options(MGPIO_NO_PULL,MGPIO_PULL_UP,MGPIO_PULL_DOWN)
*
*[Arguments]:
*
*[in]: u8 Copy_u8Port: This Argument indicates the PORT (MGPIO_PORTA,MGPIO_PORTB,MGPIO_PORTC) 
* 	   u8 Copy_u8Pin: This Argument indicates the Pin (0->15)
*      u8 Copy_u8PullType:This Argument indicates the Connection(MGPIO_NO_PULL,MGPIO_PULL_UP,MGPIO_PULL_DOWN)
*
*[out]: N/A
*
*[Returns]: N/A
--------------------------------------------------------------------------------------------------------------------*/
void MGPIO_voidSetPinPullType(u8 Copy_u8Port,u8 Copy_u8Pin,u8 Copy_u8PullType);

/*--------------------------------------------------------------------------------------------------------------------
*[Function Name]: MGPIO_u8GetPinValue
*
*[Description]: This function is responsible for Getting the value  of pin  at certain port
*
*[Arguments]:
*
*[in]: u8 Copy_u8Port: This Argument indicates the PORT (MGPIO_PORTA,MGPIO_PORTB,MGPIO_PORTC) 
* 	   u8 Copy_u8Pin: This Argument indicates the Pin (0->15)
*
*[out]: N/A
*
*[Returns]: u8 : the value of the pin(1,0)
--------------------------------------------------------------------------------------------------------------------*/
u8 MGPIO_u8GetPinValue(u8 Copy_u8Port,u8 Copy_u8Pin);

/*--------------------------------------------------------------------------------------------------------------------
*[Function Name]: MGPIO_voidSetPinValue
*
*[Description]: This function is responsible for Setting  value to a pin  at certain port
*
*[Arguments]:
*
*[in]: u8 Copy_u8Port: This Argument indicates the PORT (MGPIO_PORTA,MGPIO_PORTB,MGPIO_PORTC) 
* 	   u8 Copy_u8Pin: This Argument indicates the Pin (0->15)
*	   u8 Copy_u8Value: This Argument indicates the Value to be written (MGPIO_PIN_LOW,MGPIO_PIN_HIGH)
*
*[out]: N/A
*
*[Returns]: N/A
--------------------------------------------------------------------------------------------------------------------*/
void MGPIO_voidSetPinValue(u8 Copy_u8Port,u8 Copy_u8Pin,u8 Copy_u8Value);


/*--------------------------------------------------------------------------------------------------------------------
*[Function Name]: MGPIO_voidSetPinValueAtomic
*
*[Description]: This function is responsible for Setting  value to a pin  at certain port atomicaly(one clock cycle)
*
*[Arguments]:
*
*[in]: u8 Copy_u8Port: This Argument indicates the PORT (MGPIO_PORTA,MGPIO_PORTB,MGPIO_PORTC) 
* 	   u8 Copy_u8Pin: This Argument indicates the Pin (0->15)
*	   u8 Copy_u8Value: This Argument indicates the Value to be written (MGPIO_PIN_LOW,MGPIO_PIN_HIGH)
*
*[out]: N/A
*
*[Returns]: N/A
--------------------------------------------------------------------------------------------------------------------*/
void MGPIO_voidSetPinValueAtomic(u8 Copy_u8Port,u8 Copy_u8Pin,u8 Copy_u8Value);

/*--------------------------------------------------------------------------------------------------------------------
*[Function Name]: MGPIO_voidSetAltrenateFunction
*
*[Description]: This function is responsible for Setting  the Alternate function of a pin  at certain port
*
*[Arguments]:
*
*[in]: u8 Copy_u8Port: This Argument indicates the PORT (MGPIO_PORTA,MGPIO_PORTB,MGPIO_PORTC) 
* 	   u8 Copy_u8Pin: This Argument indicates the Pin (0->15)
*	   u8 Copy_u8AltFunction: This Argument indicates the requried Alternate function to be written
*
*[out]: N/A
*
*[Returns]: N/A
--------------------------------------------------------------------------------------------------------------------*/
void MGPIO_voidSetAlternateFunction(u8 Copy_u8Port,u8 Copy_u8Pin,u8 Copy_u8AltFunction);
/************************/




#endif 
