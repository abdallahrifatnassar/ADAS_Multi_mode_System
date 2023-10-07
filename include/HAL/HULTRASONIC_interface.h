/**********************************/
/* Author:Gp Group 				  */
/* SWC :UltraSonic Sensor		  */
/* Layer :HAL 		              */
/* Version :1.0                   */
/* Date :Octobar 7,2023		      */
/* Last Edit :N/A                 */
/**********************************/

#ifndef _HULTRASONIC_INTERFACE_H_
#define _HULTRASONIC_INTERFACE_H_


/*---------------------------------------------------------------------
|  Method [HULTRASONIC_voidInit]
|
|  Purpose: [This function responsible for init PWM Signal on choosen Channel
|			 PWM Siganl->Edge aligned PWM With frequency=(Comparetime/PeriodValue)
|			 As long as Compare Value >timer Couner The output is high (Pwm Mode 1)
|			 Ton=CompareValue]
|
|  Pre-condition:N/A
|
|  Post-condition: N/A
|
|  Parameters:N/A
|
|  Returns:  N/A
-------------------------------------------------------------------*/
void HULTRASONIC_voidInit(void);

/*---------------------------------------------------------------------
|  Method [HULTRASONIC_voidGetDistance]
|
|  Purpose: [This function responsible for Sending Trigger Pulse]
|
|  Pre-condition:N/A
|
|  Post-condition: N/A
|
|  Parameters:N/A
|
|  Returns:  N/A
-------------------------------------------------------------------*/

void HULTRASONIC_voidGetDistance(void);


/*---------------------------------------------------------------------
|  Method [HULTRASONIC_u32Distance]
|
|  Purpose: [This function is used For returning Distance]
|
|  Pre-condition:N/A
|
|  Post-condition: N/A
|
|  Parameters:N/A
|
|  Returns:  u32
-------------------------------------------------------------------*/
u32 HULTRASONIC_u32Distance(void);




#endif