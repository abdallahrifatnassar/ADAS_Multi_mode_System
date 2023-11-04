/***********************************************/
/* Author       : Ahmed Sherif                 */
/* SWC          : MGPIO                        */
/* Layer        : MCAL                         */
/* Version      : 1.0                          */
/* Date         : October 21, 2023             */
/* Last Edited  : N/A                          */
/***********************************************/
#ifndef MGPIO_CONFIG_H_
#define MGPIO_CONFIG_H_

#define MGPIOA 1
#define MGPIOB 2
#define MGPIOC 3
#define MGPIOD 4
#define MGPIOE 5
#define MGPIOH 6

typedef enum
{
    MGPIO_PIN0 = 0,
    MGPIO_PIN1,
    MGPIO_PIN2,
    MGPIO_PIN3,
    MGPIO_PIN4,
    MGPIO_PIN5,
    MGPIO_PIN6,
    MGPIO_PIN7,
    MGPIO_PIN8,
    MGPIO_PIN9,
    MGPIO_PIN10,
    MGPIO_PIN11,
    MGPIO_PIN12,
    MGPIO_PIN13,
    MGPIO_PIN14,
    MGPIO_PIN15
} MGPIO_Pin_t;

typedef enum
{
    LOW_SPEED = 0,
    MEDIUM_SPEED,
    HIGH_SPEED,     /* Not supported on all MCUs*/
    VERY_HIGH_SPEED /* Not supported on all MCUs*/
} MGPIO_speed_t;

typedef enum
{
    OPEN_DRAIN = 0,
    PUSH_PULL
} MGPIO_OutPut_t;

typedef enum
{
    INPUT_MODE = 0,
    OUTPUT_MODE,
    ALTERNATE_FUNCTION,
    ANALOG_MODE
} MGPIO_Mode_t;

typedef enum
{
    PULLUP_MODE = 0,
    PULLDOWN_MODE
} MGPIO_InputMode_t;

typedef enum
{
    HIGH,
    LOW
} MGPIO_Value_t;
#endif /* MGPIO_CONFIG_H_ */