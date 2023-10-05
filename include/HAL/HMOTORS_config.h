/**********************************/
/* Author:Ahmed Samir,FahkerEldin */
/* SWC :MOTOR		           	  */
/* Layer :HAL 		              */
/* Version :1.0                   */
/* Date :Octobar 4,2023		      */
/* Last Edit :N/A                 */
/**********************************/

#ifndef _HMOTOR_CONFIG_H_
#define _HMOTOR_CONFIG_H_


/************************/
/*Motor 1 Direction Pins Write it in Pair (PORT,PIN)*/
#define MOTOR_IN1_PORT_PIN					/*MGPIO_PORTA,MGPIO_PORTB,MGPIO_PORTC,MGPIO_PIN(0->15)Except Portc*/

#define MOTOR_IN2_PORT_PIN					/*MGPIO_PORTA,MGPIO_PORTB,MGPIO_PORTC,MGPIO_PIN(0->15)Except Portc*/

/************************/


/*Motor 2 Direction Pins Write it in Pair (PORT,PIN)*/
#define MOTOR_IN3_PORT_PIN					/*MGPIO_PORTA,MGPIO_PORTB,MGPIO_PORTC,MGPIO_PIN(0->15)Except Portc*/

#define MOTOR_IN4_PORT_PIN					/*MGPIO_PORTA,MGPIO_PORTB,MGPIO_PORTC,MGPIO_PIN(0->15)Except Portc*/

/************************/
/*Motors Speed Pins in Pair(PORT,PIN),Note that it Must be one of Timer3 Channels
(PB0,PB1,PB4,PB5,PA6,PA7) */
#define MOTOR_EN_PORT_PIN

#endif