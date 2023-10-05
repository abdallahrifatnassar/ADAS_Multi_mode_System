/**********************************/
/* Author :Ahmed Samir            */
/* SWC :GPIO		              */
/* Layer :MCAL 		              */
/* Version :1.0                   */
/* Date :September 16,2023        */
/* Last Edit :N/A                 */
/**********************************/

#include "LSTD_types.h"
#include "LBIT_math.h"
#include "MGPIO_interface.h"
#include "MGPIO_config.h"
#include "MGPIO_private.h"



void MGPIO_voidSetPinMode(u8 Copy_u8Port,u8 Copy_u8Pin,u8 Copy_u8Mode)
{
	switch(Copy_u8Port)
	{
		case MGPIO_PORTA:
		{
			/* Clear the pin bits to make sure the mode is applied correctly*/
			GPIOA->MODER&=~(MGPIO_PIN_MASK <<(Copy_u8Pin*2));
			GPIOA->MODER|=(Copy_u8Mode <<(Copy_u8Pin*2));
			break;
		}
		case MGPIO_PORTB:
		{
			/* Clear the pin bits to make sure the mode is applied correctly*/
			GPIOB->MODER&=~(MGPIO_PIN_MASK <<(Copy_u8Pin*2));
			GPIOB->MODER|=(Copy_u8Mode <<(Copy_u8Pin*2));
			break;
		}
		case MGPIO_PORTC:
		{
			/* Clear the pin bits to make sure the mode is applied correctly*/
			GPIOC->MODER&=~(MGPIO_PIN_MASK <<(Copy_u8Pin*2));
			GPIOC->MODER|=(Copy_u8Mode <<(Copy_u8Pin*2));
			break;
		}
		default:break;// error
	}
}

void MGPIO_voidSetOutputPinType(u8 Copy_u8Port,u8 Copy_u8Pin,u8 Copy_u8Type)
{
	switch(Copy_u8Port)
	{
		case MGPIO_PORTA:
		{
			if(MGPIO_PIN_PUSH_PULL==Copy_u8Type)
			{
				CLEAR_BIT(GPIOA->OTYPER,Copy_u8Pin);
			}
			else if(MGPIO_PIN_OPEN_DRAIN==Copy_u8Type)
			{
				SET_BIT(GPIOA->OTYPER,Copy_u8Pin);
			}
			else
			{
				//error
			}
			break;
		}
		case MGPIO_PORTB:
		{
			if(MGPIO_PIN_PUSH_PULL==Copy_u8Type)
			{
				CLEAR_BIT(GPIOB->OTYPER,Copy_u8Pin);
			}
			else if(MGPIO_PIN_OPEN_DRAIN==Copy_u8Type)
			{
				SET_BIT(GPIOB->OTYPER,Copy_u8Pin);
			}
			else
			{
				//error
			}
			break;
		}
		case MGPIO_PORTC:
		{
			if(MGPIO_PIN_PUSH_PULL==Copy_u8Type)
			{
				CLEAR_BIT(GPIOC->OTYPER,Copy_u8Pin);
			}
			else if(MGPIO_PIN_OPEN_DRAIN==Copy_u8Type)
			{
				SET_BIT(GPIOC->OTYPER,Copy_u8Pin);
			}
			else
			{
				//error
			}
			break;
		}
		default:break;// error
	}
}
void MGPIO_voidSetOutputPinSpeed(u8 Copy_u8Port,u8 Copy_u8Pin,u8 Copy_u8Speed)
{
	switch(Copy_u8Port)
	{
		case MGPIO_PORTA:
		{
			GPIOA->OSPEEDR&=~(MGPIO_PIN_MASK <<(Copy_u8Pin*2));
			GPIOA->OSPEEDR|=(Copy_u8Speed <<(Copy_u8Pin*2));
			break;
		}
		case MGPIO_PORTB:
		{
			GPIOB->OSPEEDR&=~(MGPIO_PIN_MASK <<(Copy_u8Pin*2));
			GPIOB->OSPEEDR|=(Copy_u8Speed <<(Copy_u8Pin*2));
			break;
		}
		case MGPIO_PORTC:
		{
			GPIOC->OSPEEDR&=~(MGPIO_PIN_MASK <<(Copy_u8Pin*2));
			GPIOC->OSPEEDR|=(Copy_u8Speed <<(Copy_u8Pin*2));
			break;
		}
		default:break;// error
	}
}
void MGPIO_voidSetPinPullType(u8 Copy_u8Port,u8 Copy_u8Pin,u8 Copy_u8PullType)
{
	switch(Copy_u8Port)
	{
		case MGPIO_PORTA:
		{
			GPIOA->PURDR&=~(MGPIO_PIN_MASK <<(Copy_u8Pin*2));
			GPIOA->PURDR|=(Copy_u8PullType <<(Copy_u8Pin*2));
			break;
		}
		case MGPIO_PORTB:
		{
			GPIOB->PURDR&=~(MGPIO_PIN_MASK <<(Copy_u8Pin*2));
			GPIOB->PURDR|=(Copy_u8PullType <<(Copy_u8Pin*2));
			break;
		}
		case MGPIO_PORTC:
		{
			GPIOC->PURDR&=~(MGPIO_PIN_MASK <<(Copy_u8Pin*2));
			GPIOC->PURDR|=(Copy_u8PullType <<(Copy_u8Pin*2));
			break;
		}
		default:break;// error
	}	
}

u8 MGPIO_u8GetPinValue(u8 Copy_u8Port,u8 Copy_u8Pin)
{
	u8 Local_u8Return=0;
	switch(Copy_u8Port)
	{
		case MGPIO_PORTA:
		{
			Local_u8Return=GET_BIT(GPIOA->IDR,Copy_u8Pin);
			break;
		}
		case MGPIO_PORTB:
		{
			Local_u8Return=GET_BIT(GPIOB->IDR,Copy_u8Pin);
			break;
		}
		case MGPIO_PORTC:
		{
			Local_u8Return=GET_BIT(GPIOC->IDR,Copy_u8Pin);
			break;
		}
		default:break;// error
	}
	return Local_u8Return;
}
void MGPIO_voidSetPinValue(u8 Copy_u8Port,u8 Copy_u8Pin,u8 Copy_u8Value)
{
	switch(Copy_u8Port)
	{
		case MGPIO_PORTA:
		{
			if(MGPIO_PIN_LOW==Copy_u8Value)
			{
				// set the pin to clear value(LOW)
				CLEAR_BIT(GPIOA->ODR,Copy_u8Pin);
			}
			else if(MGPIO_PIN_HIGH==Copy_u8Value)
			{
				// set the pin to clear value(High)
				SET_BIT(GPIOA->ODR,Copy_u8Pin);
			}
			else
			{
				//error
			}
			break;
		}
		case MGPIO_PORTB:
		{
			if(MGPIO_PIN_LOW==Copy_u8Value)
			{
				CLEAR_BIT(GPIOB->ODR,Copy_u8Pin);
			}
			else if(MGPIO_PIN_HIGH==Copy_u8Value)
			{
				SET_BIT(GPIOB->ODR,Copy_u8Pin);
			}
			else
			{
				//error
			}
			break;
		}
		case MGPIO_PORTC:
		{
			if(MGPIO_PIN_LOW)
			{
				CLEAR_BIT(GPIOC->ODR,Copy_u8Pin);
			}
			else if(MGPIO_PIN_HIGH==Copy_u8Value)
			{

				SET_BIT(GPIOC->ODR,Copy_u8Pin);
			}
			else
			{
				//error
			}
			break;
		}
		default:break;// error
	}
}

void MGPIO_voidSetPinValueAtomic(u8 Copy_u8Port,u8 Copy_u8Pin,u8 Copy_u8Value)
{
	switch(Copy_u8Port)
	{
		case MGPIO_PORTA:
		{
			if(MGPIO_PIN_LOW==Copy_u8Value)
			{
				// set the pin to the correct postion in reset registe(higher 16)
				Copy_u8Pin+=16;
				// set the pin to clear value(low)
				GPIOA->BSRR=(1<<Copy_u8Pin);
			}
			else if(MGPIO_PIN_HIGH==Copy_u8Value)
			{
				// set the pin to clear value(High)
				GPIOA->BSRR=(1<<Copy_u8Pin);
			}
			else
			{
				//error
			}
			break;
		}
		case MGPIO_PORTB:
		{
			if(MGPIO_PIN_LOW==Copy_u8Value)
			{
				Copy_u8Pin+=16;
				GPIOB->BSRR=(1<<Copy_u8Pin);
			}
			else if(MGPIO_PIN_HIGH==Copy_u8Value)
			{
				// set the pin to clear value(High)
				GPIOB->BSRR=(1<<Copy_u8Pin);
			}
			else
			{
				//error
			}
			break;
		}
		case MGPIO_PORTC:
		{
			if(MGPIO_PIN_LOW)
			{
				Copy_u8Pin+=16;
				GPIOC->BSRR=(1<<Copy_u8Pin);
			}
			else if(MGPIO_PIN_HIGH==Copy_u8Value)
			{
				GPIOC->BSRR=(1<<Copy_u8Pin);
			}
			else
			{
				//error
			}
			break;
		}
		default:break;// error
	}	
}
void MGPIO_voidSetAlternateFunction(u8 Copy_u8Port,u8 Copy_u8Pin,u8 Copy_u8AltFunction)
{
	switch(Copy_u8Port)
	{
		case MGPIO_PORTA:
		{
			// check the number of pin to choose which register
			if(Copy_u8AltFunction<8)
			{
				// clear the value of the location first
				GPIOA->AFRL&=~(MGPIO_ALTFUNCTION_MASK<<(Copy_u8Pin*4));
				// set the value of the alternate function
				GPIOA->AFRL|=(Copy_u8AltFunction<<(Copy_u8Pin*4));
			}
			else if(Copy_u8AltFunction<16)
			{
				// clear the value of the location first
				GPIOA->AFRH&=~(MGPIO_ALTFUNCTION_MASK<<(Copy_u8Pin*4));
				// set the value of the alternate function
				GPIOA->AFRH=(Copy_u8AltFunction<<(Copy_u8Pin*4));
			}
			else
			{
				//error
			}
			break;
		}
		case MGPIO_PORTB:
		{
			if(Copy_u8AltFunction<8)
			{
				// clear the value of the location first
				GPIOB->AFRL&=~(MGPIO_ALTFUNCTION_MASK<<(Copy_u8Pin*4));
				// set the value of the alternate function
				GPIOB->AFRL|=(Copy_u8AltFunction<<(Copy_u8Pin*4));
			}
			else if(Copy_u8AltFunction<16)
			{
				// clear the value of the location first
				GPIOB->AFRH&=~(MGPIO_ALTFUNCTION_MASK<<(Copy_u8Pin*4));
				// set the value of the alternate function
				GPIOB->AFRH=(Copy_u8AltFunction<<(Copy_u8Pin*4));
			}
			else
			{
				//error
			}
			break;
		}
		case MGPIO_PORTC:
		{
			if(Copy_u8AltFunction<8)
			{
				// clear the value of the location first
				GPIOC->AFRL&=~(MGPIO_ALTFUNCTION_MASK<<(Copy_u8Pin*4));
				// set the value of the alternate function
				GPIOC->AFRL|=(Copy_u8AltFunction<<(Copy_u8Pin*4));
			}
			else if(Copy_u8AltFunction<16)
			{
				// clear the value of the location first
				GPIOC->AFRH&=~(MGPIO_ALTFUNCTION_MASK<<(Copy_u8Pin*4));
				// set the value of the alternate function
				GPIOC->AFRH=(Copy_u8AltFunction<<(Copy_u8Pin*4));
			}
			else
			{
				//error
			}
			break;
		}
		default:break;// error
	}	
}
