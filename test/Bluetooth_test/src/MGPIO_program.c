/***********************************************/
/* Author       : Ahmed Sherif                 */
/* SWC          : MGPIO                        */
/* Layer        : MCAL                         */
/* Version      : 1.0                          */
/* Date         : October 21, 2023             */
/* Last Edited  : N/A                          */
/***********************************************/

#include "LSTD_types.h"
#include "LBIT_math.h"
#include "MGPIO_interface.h"
#include "MGPIO_config.h"
#include "MGPIO_private.h"

void MGPIO_voidSetPinDirection(u8 ARG_u8GPIOPort, MGPIO_Pin_t ARG_u8GPIOPin, MGPIO_Mode_t ARG_u8GPIODirection)
{
    u8 L_u8ErrorState = 0;

    switch (ARG_u8GPIOPort)
    {
    case MGPIOA:
    {
        switch (ARG_u8GPIODirection)
        {
        case INPUT_MODE:
            CLEAR_BIT(GPIOA->GPIOx_Moder, (ARG_u8GPIOPin * 2));
            CLEAR_BIT(GPIOA->GPIOx_Moder, ((ARG_u8GPIOPin * 2) + 1));
            break;
        case OUTPUT_MODE:
            SET_BIT(GPIOA->GPIOx_Moder, (ARG_u8GPIOPin * 2));
            CLEAR_BIT(GPIOA->GPIOx_Moder, ((ARG_u8GPIOPin * 2) + 1));
            break;
        case ALTERNATE_FUNCTION:
            CLEAR_BIT(GPIOA->GPIOx_Moder, (ARG_u8GPIOPin * 2));
            SET_BIT(GPIOA->GPIOx_Moder, ((ARG_u8GPIOPin * 2) + 1));
            break;
        case ANALOG_MODE:
            SET_BIT(GPIOA->GPIOx_Moder, (ARG_u8GPIOPin * 2));
            SET_BIT(GPIOA->GPIOx_Moder, ((ARG_u8GPIOPin * 2) + 1));
            break;
        default:
            break;
        }
    }
    break;
    case MGPIOB:
    {
        switch (ARG_u8GPIODirection)
        {
        case INPUT_MODE:
            CLEAR_BIT(GPIOB->GPIOx_Moder, (ARG_u8GPIOPin * 2));
            CLEAR_BIT(GPIOB->GPIOx_Moder, ((ARG_u8GPIOPin * 2) + 1));
            break;
        case OUTPUT_MODE:
            SET_BIT(GPIOB->GPIOx_Moder, (ARG_u8GPIOPin * 2));
            CLEAR_BIT(GPIOB->GPIOx_Moder, ((ARG_u8GPIOPin * 2) + 1));
            break;
        case ALTERNATE_FUNCTION:
            CLEAR_BIT(GPIOB->GPIOx_Moder, (ARG_u8GPIOPin * 2));
            SET_BIT(GPIOB->GPIOx_Moder, ((ARG_u8GPIOPin * 2) + 1));
            break;
        case ANALOG_MODE:
            SET_BIT(GPIOB->GPIOx_Moder, (ARG_u8GPIOPin * 2));
            SET_BIT(GPIOB->GPIOx_Moder, ((ARG_u8GPIOPin * 2) + 1));
            break;
        default:
            break;
        }
    }
    break;
    case MGPIOC:
    {
        switch (ARG_u8GPIODirection)
        {
        case INPUT_MODE:
            CLEAR_BIT(GPIOC->GPIOx_Moder, (ARG_u8GPIOPin * 2));
            CLEAR_BIT(GPIOC->GPIOx_Moder, ((ARG_u8GPIOPin * 2) + 1));
            break;
        case OUTPUT_MODE:
            SET_BIT(GPIOC->GPIOx_Moder, (ARG_u8GPIOPin * 2));
            CLEAR_BIT(GPIOC->GPIOx_Moder, ((ARG_u8GPIOPin * 2) + 1));
            break;
        case ALTERNATE_FUNCTION:
            CLEAR_BIT(GPIOC->GPIOx_Moder, (ARG_u8GPIOPin * 2));
            SET_BIT(GPIOC->GPIOx_Moder, ((ARG_u8GPIOPin * 2) + 1));
            break;
        case ANALOG_MODE:
            SET_BIT(GPIOC->GPIOx_Moder, (ARG_u8GPIOPin * 2));
            SET_BIT(GPIOC->GPIOx_Moder, ((ARG_u8GPIOPin * 2) + 1));
            break;
        default:
            break;
        }
    }
    break;
    default:
        L_u8ErrorState = 1;
        break;
    }
}
void MGPIO_voidSetPinOutput(u8 ARG_u8GPIOPort, MGPIO_Pin_t ARG_u8GPIOPin, MGPIO_OutPut_t ARG_u8GPIOOutPutMode)
{
    switch (ARG_u8GPIOPort)
    {
    case MGPIOA:
    {
        switch (ARG_u8GPIOOutPutMode)
        {
        case PUSH_PULL:
            CLEAR_BIT(GPIOA->GPIOx_OTYPER, ARG_u8GPIOPin);
            break;
        case OPEN_DRAIN:
            SET_BIT(GPIOA->GPIOx_OTYPER, ARG_u8GPIOPin);
            break;
        default:
            break;
        }
    }
    break;
    case MGPIOB:
    {
        switch (ARG_u8GPIOOutPutMode)
        {
        case PUSH_PULL:
            CLEAR_BIT(GPIOB->GPIOx_OTYPER, ARG_u8GPIOPin);
            break;
        case OPEN_DRAIN:
            SET_BIT(GPIOB->GPIOx_OTYPER, ARG_u8GPIOPin);
            break;
        default:
            break;
        }
    }
    break;
    case MGPIOC:
    {
        switch (ARG_u8GPIOOutPutMode)
        {
        case PUSH_PULL:
            CLEAR_BIT(GPIOC->GPIOx_OTYPER, ARG_u8GPIOPin);
            break;
        case OPEN_DRAIN:
            SET_BIT(GPIOC->GPIOx_OTYPER, ARG_u8GPIOPin);
            break;
        default:
            break;
        }
    }
    break;
    default:
        break;
    }
}
void MGPIO_voidSetSpeed(u8 ARG_u8GPIOPort, MGPIO_Pin_t ARG_u8GPIOPin, MGPIO_OutPut_t ARG_u8GPIOSpeed)
{
    switch (ARG_u8GPIOPort)
    {
    case MGPIOA:
    {
        switch (ARG_u8GPIOSpeed)
        {
        case LOW_SPEED:
            CLEAR_BIT(GPIOA->GPIOx_OSPEEDR, (ARG_u8GPIOPin * 2));
            CLEAR_BIT(GPIOA->GPIOx_OSPEEDR, ((ARG_u8GPIOPin * 2) + 1));
            break;
        case MEDIUM_SPEED:
            SET_BIT(GPIOA->GPIOx_OSPEEDR, (ARG_u8GPIOPin * 2));
            CLEAR_BIT(GPIOA->GPIOx_OSPEEDR, ((ARG_u8GPIOPin * 2) + 1));
            break;
        default:
            break;
        }
    }
    break;
    case MGPIOB:
    {
        switch (ARG_u8GPIOSpeed)
        {
        case LOW_SPEED:
            CLEAR_BIT(GPIOB->GPIOx_OSPEEDR, (ARG_u8GPIOPin * 2));
            CLEAR_BIT(GPIOB->GPIOx_OSPEEDR, ((ARG_u8GPIOPin * 2) + 1));
            break;
        case MEDIUM_SPEED:
            SET_BIT(GPIOB->GPIOx_OSPEEDR, (ARG_u8GPIOPin * 2));
            CLEAR_BIT(GPIOB->GPIOx_OSPEEDR, ((ARG_u8GPIOPin * 2) + 1));
            break;
        default:
            break;
        }
    }
    break;
    case MGPIOC:
    {
        switch (ARG_u8GPIOSpeed)
        {
        case LOW_SPEED:
            CLEAR_BIT(GPIOC->GPIOx_OSPEEDR, (ARG_u8GPIOPin * 2));
            CLEAR_BIT(GPIOC->GPIOx_OSPEEDR, ((ARG_u8GPIOPin * 2) + 1));
            break;
        case MEDIUM_SPEED:
            SET_BIT(GPIOC->GPIOx_OSPEEDR, (ARG_u8GPIOPin * 2));
            CLEAR_BIT(GPIOC->GPIOx_OSPEEDR, ((ARG_u8GPIOPin * 2) + 1));
            break;
        default:
            break;
        }
    }
    break;
    default:
        break;
    }
}
void MGPIO_voidSetPinInPut(u8 ARG_u8GPIOPort, MGPIO_Pin_t ARG_u8GPIOPin, MGPIO_InputMode_t ARG_u8GPIOInPutMode)
{
    switch (ARG_u8GPIOPort)
    {
    case MGPIOA:
    {
        switch (ARG_u8GPIOInPutMode)
        {
        case PULLDOWN_MODE:
            CLEAR_BIT(GPIOA->GPIOx_PUPDR, (ARG_u8GPIOPin * 2));
            SET_BIT(GPIOA->GPIOx_PUPDR, ((ARG_u8GPIOPin * 2) + 1));
            break;
        case PULLUP_MODE:
            SET_BIT(GPIOA->GPIOx_PUPDR, (ARG_u8GPIOPin * 2));
            CLEAR_BIT(GPIOA->GPIOx_PUPDR, ((ARG_u8GPIOPin * 2) + 1));
            break;
        }
    }
    break;
    case MGPIOB:
    {
        switch (ARG_u8GPIOInPutMode)
        {
        case PULLDOWN_MODE:
            CLEAR_BIT(GPIOB->GPIOx_PUPDR, (ARG_u8GPIOPin * 2));
            SET_BIT(GPIOB->GPIOx_PUPDR, ((ARG_u8GPIOPin * 2) + 1));
            break;
        case PULLUP_MODE:
            SET_BIT(GPIOB->GPIOx_PUPDR, (ARG_u8GPIOPin * 2));
            CLEAR_BIT(GPIOB->GPIOx_PUPDR, ((ARG_u8GPIOPin * 2) + 1));
            break;
        }
    }
    break;
    case MGPIOC:
    {
        switch (ARG_u8GPIOInPutMode)
        {
        case PULLDOWN_MODE:
            CLEAR_BIT(GPIOC->GPIOx_PUPDR, (ARG_u8GPIOPin * 2));
            SET_BIT(GPIOC->GPIOx_PUPDR, ((ARG_u8GPIOPin * 2) + 1));
            break;
        case PULLUP_MODE:
            SET_BIT(GPIOC->GPIOx_PUPDR, (ARG_u8GPIOPin * 2));
            CLEAR_BIT(GPIOC->GPIOx_PUPDR, ((ARG_u8GPIOPin * 2) + 1));
            break;
        }
    }
    break;
    default:
        break;
    }
}
void MGPIO_voidSetPinValue(u8 ARG_u8GPIOPort, MGPIO_Pin_t ARG_u8GPIOPin, MGPIO_Value_t ARG_u8GPIOPinValue)
{
    switch (ARG_u8GPIOPort)
    {
    case MGPIOA:
    {
        switch (ARG_u8GPIOPinValue)
        {
        case HIGH:
            GPIOA->GPIOx_BSRR = 1 << ARG_u8GPIOPin;
            break;
        case LOW:
            GPIOA->GPIOx_BSRR = (1 << (ARG_u8GPIOPin + 16));
            break;
        default:
            break;
        }
    }
    break;
    case MGPIOB:
    {
        switch (ARG_u8GPIOPinValue)
        {
        case HIGH:
            GPIOB->GPIOx_BSRR = 1 << ARG_u8GPIOPin;
            break;
        case LOW:
            GPIOB->GPIOx_BSRR = (1 << (ARG_u8GPIOPin + 16));
            break;
        default:
            break;
        }
    }
    break;
    case MGPIOC:
    {
        switch (ARG_u8GPIOPinValue)
        {
        case HIGH:
            GPIOC->GPIOx_BSRR = 1 << ARG_u8GPIOPin;
            break;
        case LOW:
            GPIOC->GPIOx_BSRR = (1 << (ARG_u8GPIOPin + 16));
            break;
        default:
            break;
        }
    }
    break;

    default:
        break;
    }
}
void MGPIO_voidGetPinValue(u8 ARG_u8GPIOPort, MGPIO_Pin_t ARG_u8GPIOPin, u8 *ARG_u8ReadValue)
{
    switch (ARG_u8GPIOPort)
    {
    case MGPIOA:
    {
        *ARG_u8ReadValue = GET_BIT(GPIOA->GPIOx_IDR, ARG_u8GPIOPin);
    }
    break;
    case MGPIOB:
    {
        *ARG_u8ReadValue = GET_BIT(GPIOB->GPIOx_IDR, ARG_u8GPIOPin);
    }
    break;
    case MGPIOC:
    {
        *ARG_u8ReadValue = GET_BIT(GPIOC->GPIOx_IDR, ARG_u8GPIOPin);
    }
    break;
    }
}
void MGPIO_voidSetAlternative(u8 ARG_u8GPIOPort, MGPIO_Pin_t ARG_u8GPIOPin, u8 Copy_u8AltFunction)
{
    switch (ARG_u8GPIOPort)
    {
    case MGPIOA:
    {
        if (ARG_u8GPIOPin < 8)
        {
            GPIOA->GPIOx_AFRL &= ~((u32)0x0000000F << (ARG_u8GPIOPin * 4));
            GPIOA->GPIOx_AFRL |= (Copy_u8AltFunction << (ARG_u8GPIOPin * 4));
        }
        else if (ARG_u8GPIOPin >= 8 && ARG_u8GPIOPin < 16)
        {
            GPIOA->GPIOx_AFRH &= ~((u32)0x0000000F << ((ARG_u8GPIOPin % 8) * 4));
            GPIOA->GPIOx_AFRH |= (Copy_u8AltFunction << ((ARG_u8GPIOPin % 8) * 4));
        }
        else
        {
            /* Error */
        }
    }
    break;
    case MGPIOB:
    {
        if (ARG_u8GPIOPin < 8)
        {
            GPIOB->GPIOx_AFRL &= ~((u32)0x0000000F << (ARG_u8GPIOPin * 4));
            GPIOB->GPIOx_AFRL |= (Copy_u8AltFunction << (ARG_u8GPIOPin * 4));
        }
        else if (ARG_u8GPIOPin > 8 && ARG_u8GPIOPin < 16)
        {
            GPIOB->GPIOx_AFRH &= ~((u32)0x0000000F << (ARG_u8GPIOPin * 4));
            GPIOB->GPIOx_AFRH |= (Copy_u8AltFunction << (ARG_u8GPIOPin * 4));
        }
        else
        {
            /* Error */
        }
    }
    break;
    case MGPIOC:
    {
        if (ARG_u8GPIOPin < 8)
        {
            GPIOC->GPIOx_AFRL &= ~((u32)0x0000000F << (ARG_u8GPIOPin * 4));
            GPIOC->GPIOx_AFRL |= (Copy_u8AltFunction << (ARG_u8GPIOPin * 4));
        }
        else if (ARG_u8GPIOPin > 8 && ARG_u8GPIOPin < 16)
        {
            GPIOC->GPIOx_AFRH &= ~((u32)0x0000000F << (ARG_u8GPIOPin * 4));
            GPIOC->GPIOx_AFRH |= (Copy_u8AltFunction << (ARG_u8GPIOPin * 4));
        }
        else
        {
            /* Error */
        }
    }
    break;
    default:
        /* Do Nothing */
        break;
    }
}

void MGPIO_voidSetPortValue(u8 ARG_u8GPIOPort, u8 ARG_u8Value)
{
    for (size_t i = 0; i < 8; i++)
    {
        MGPIO_voidSetPinDirection(ARG_u8GPIOPort, i, OUTPUT_MODE);
        MGPIO_voidSetPinOutput(ARG_u8GPIOPort, i, PUSH_PULL);
        MGPIO_voidSetPinValue(ARG_u8GPIOPort, i, (ARG_u8Value & 1));
        if (ARG_u8Value != 0)
        {
            ARG_u8Value >>= 1;
        }
    }
    return;
}

void MGPIO_voidLEDMatrix(u8 arr[], u8 ARG_u8Size)
{
    u8 L_u8RowShift = 0xFF;
    for (size_t i = 0; i < ARG_u8Size; i++)
    {
        MGPIO_voidSetPortValue(MGPIOA, arr[i]);
        MGPIO_voidSetPortValue(MGPIOB, L_u8RowShift - (1 << i));
    }

    for (size_t i = 0; i < 65500; i++)
    {
        // wait
    }
}

/*void MGPIO_voidSetPinAltFun(u8 Copy_u8PortName, u8 Copy_u8PinNum, u8 Copy_u8AlFun)
{
    if (Copy_u8PinNum <= 7U)
    {
        switch (Copy_u8PortName)
        {
        case MGPIOA_PORT:
            GPIOA->AFRL |= (u32)(Copy_u8AlFun << (4U * Copy_u8PinNum));
            break;
        case MGPIOB_PORT:
            GPIOB->AFRL |= (u32)(Copy_u8AlFun << (4U * Copy_u8PinNum));
            break;
        case MGPIOC:
            MPIOC->AFRL |= (u32)(Copy_u8AlFun << (4U * Copy_u8PinNum));
            break;
        default:
            break;
        }
    }
    else
    {
        switch (Copy_u8PortName)
        {
        case MGPIOA:
            GPIOA->AFRH |= (u32)(Copy_u8AlFun << (4U * (Copy_u8PinNum % 8)));
            break;
        case MGPIOB:
            GPIOB->AFRH |= (u32)(Copy_u8AlFun << (4U * (Copy_u8PinNum % 8)));
            break;
        case MGPIOC:
            GPIOC->AFRH |= (u32)(Copy_u8AlFun << (4U * (Copy_u8PinNum % 8)));
            break;
        default:
            break ;
        }
    }
}*/
