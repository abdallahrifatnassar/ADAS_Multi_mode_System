/**********************************/
/* Author:Gp Group 				  */
/* SWC :UltraSonic Sensor		  */
/* Layer :HAL 		              */
/* Version :1.0                   */
/* Date :Octobar 7,2023		      */
/* Last Edit :N/A                 */
/**********************************/

#ifndef _HULTRASONIC_CONFIG_H_
#define _HULTRASONIC_CONFIG_H_

/************************/
/*UltraSonic Trigger Pins Write it in Pair (PORT,PIN)*/
#define ULTRASONIC_TRIGGER_PORT_PIN MGPIO_PORTA, MGPIO_PIN1 /*MGPIO_PORTA,MGPIO_PORTB,MGPIO_PORTC,MGPIO_PIN(0->15)Except Portc*/

/*UltraSonic Echo Pins Write it in Pair (PORT,PIN)*,Note that it Must be one of Timer2 Channels
(PA0,PA1,PA2,PA3,PA15,PB3,PB10) */
#define ULTRASONIC_ECHO_PORT_PIN MGPIO_PORTA, MGPIO_PIN5

/*TIMER2_CHANNEL1->4*/
#define ULTRASONIC_ECHO_CHANNEL TIMER2_CHANNEL1

#endif
