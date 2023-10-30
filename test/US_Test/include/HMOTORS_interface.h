/**********************************/
/* Author:Ahmed Samir,FahkerEldin */
/* SWC :MOTOR		           	  */
/* Layer :HAL 		              */
/* Version :1.0                   */
/* Date :Octobar 4,2023		      */
/* Last Edit :N/A                 */
/**********************************/

#ifndef _HMOTOR_INTERFACE_H_
#define _HMOTOR_INTERFACE_H_


/*****************APIS Made By Ahmed Samir ********************/

/*---------------------------------------------------------------------
|  Method [HMOTOR_voidInit]
|
|  Purpose: [This function responsible for init The direction of motor control pins]
|
|  Pre-condition:setup pins in config file first
|
|  Post-condition: N/A
|
|  Parameters:N/A
|
|  Returns:  N/A
-------------------------------------------------------------------*/
void HMOTOR_voidInit(void);


/*---------------------------------------------------------------------
|  Method [HMOTOR_voidMoveForward]
|
|  Purpose: [This function Will Make motor to move in forward direction]
|
|  Pre-condition:N/A
|
|  Post-condition: N/A
|
|  Parameters: N/A
|
|  Returns:  N/A
-------------------------------------------------------------------*/
void HMOTOR_voidMoveForward(void);

/*---------------------------------------------------------------------
|  Method [HMOTOR_voidMoveBackward]
|
|  Purpose: [This function Will Make motor to move in backward direction]
|
|  Pre-condition:N/A
|
|  Post-condition: N/A
|
|  Parameters: N/A
|
|  Returns:  N/A
-------------------------------------------------------------------*/		   
void HMOTOR_voidMoveBackward(void);

/*---------------------------------------------------------------------
|  Method [HMOTOR_voidStop]
|
|  Purpose: [This function Will Stop motor]
|
|  Pre-condition:N/A
|
|  Post-condition: N/A
|
|  Parameters:N/A
|
|  Returns:  N/A
-------------------------------------------------------------------*/
		   
void HMOTOR_voidStop(void);

/*---------------------------------------------------------------------
|  Method [HMOTOR_voidMoveRight]
|
|  Purpose: [This function Will Make motor to move in Right direction]
|
|  Pre-condition:N/A
|
|  Post-condition: N/A
|
|  Parameters: N/A
|
|  Returns:  N/A
-------------------------------------------------------------------*/		   
void HMOTOR_voidMoveRight(void);

/*---------------------------------------------------------------------
|  Method [HMOTOR_voidMoveLeft]
|
|  Purpose: [This function Will Make motor to move in Left direction]
|
|  Pre-condition:N/A
|
|  Post-condition: N/A
|
|  Parameters: N/A
|
|  Returns:  N/A
-------------------------------------------------------------------*/		   
void HMOTOR_voidMoveLeft(void);

/*---------------------------------------------------------------------
|  Method [HMOTOR_voidSetSpeed]
|
|  Purpose: [This function responsible For setting the motor Speed of rotation]
|
|  Pre-condition:N/A
|
|  Post-condition: N/A
|
|  Parameters:
|	Copy_u16Speed -- [Motor Speed Value] 
|
|  Returns:  N/A
-------------------------------------------------------------------*/	
void HMOTOR_voidSetSpeed(u16 Copy_u16Speed);

/**********************************************************/
#endif


