/**********************************/
/* Author:Ahmed Samir,FahkerEldin */
/* SWC :TIMER		           	  */
/* Layer :MCAL 		              */
/* Version :1.0                   */
/* Date :Octobar 1,2023		      */
/* Last Edit :N/A                 */
/**********************************/

#ifndef _MTIMER_INTERFACE_H_
#define _MTIMER_INTERFACE_H_

/*****************APIS Made By Ahmed Samir ********************/

/*---------------------------------------------------------------------
|  Method [MTIMER3_voidPwmModeInit]
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
|  Parameters:
|      Copy_u8ChannelId -- [Number of channel to output Pwm signal form it]
|
|  Returns:  N/A
-------------------------------------------------------------------*/
void MTIMER3_voidPwmModeInit(u8 Copy_u8ChannelId);


/*---------------------------------------------------------------------
|  Method [MTIMER3_voidStartTimer]
|
|  Purpose: [This function Will Make Timer to Start Counting]
|
|  Pre-condition:N/A
|
|  Post-condition: N/A
|
|  Parameters: N/A
|
|  Returns:  N/A
-------------------------------------------------------------------*/
void MTIMER3_voidStartTimer(void);

/*---------------------------------------------------------------------
|  Method [MTIMER3_voidStopTimer]
|
|  Purpose: [This function Will Make Timer to Stop Counting]
|
|  Pre-condition:N/A
|
|  Post-condition: N/A
|
|  Parameters: N/A
|
|  Returns:  N/A
-------------------------------------------------------------------*/		   
void MTIMER3_voidStopTimer(void);

/*---------------------------------------------------------------------
|  Method [MTIMER3_voidSetCompareValue]
|
|  Purpose: [This function responsible For setting the value to be compared
|			With Timer Counting register ]
|
|  Pre-condition:N/A
|
|  Post-condition: N/A
|
|  Parameters:
|	Copy_u8ChannelId -- [Number of channel to output Pwm signal form it]
|	Copy_u16CompareValue -- [Compare Value] 
|
|  Returns:  N/A
-------------------------------------------------------------------*/
		   
void MTIMER3_voidSetCompareValue(u8 Copy_u8ChannelId,u16 Copy_u16CompareValue);
	

/*---------------------------------------------------------------------
|  Method [MTIMER3_voidSetPeriodValue]
|
|  Purpose: [This function responsible For setting the value That the Timer
|			Will Count to (Timer Over Flow)]
|
|  Pre-condition:N/A
|
|  Post-condition: N/A
|
|  Parameters:
|	MTIMER3_voidSetPeriodValue -- [Period Value] 
|
|  Returns:  N/A
-------------------------------------------------------------------*/	
void MTIMER3_voidSetPeriodValue(u16 Copy_u16PeriodValue);


/*---------------------------------------------------------------------
|  Method [MTIMER3_voidSetPeriodValue]
|
|  Purpose: [This function responsible For setting the Prescaler to 
|			the clock Of the timer (TickTime=(Prescaler/TimerClock))]
|
|  Pre-condition:N/A
|
|  Post-condition: N/A
|
|  Parameters:
|	Copy_u16PrescalerValue -- [Prescaler Value] 
|
|  Returns:  N/A
-------------------------------------------------------------------*/
void MTIMER3_voidSetPreScaler(u16 Copy_u16PrescalerValue);





/*****************APIS Made By FahkerEldin ********************/
void MTIMER2_voidInit(u8 Copy_u8ChannelId);

void MTIMER2_voidStartTimer(void);

void MTIMER2_voidStopTimer(void);

u32	 MTIMER2_u32CaptureValue(u8 Copy_u8ChannelId);

void MTIMER2_voidEnableInterrupt(void);

void MTIMER2_voidDisableInterrupt(void);


void MTIMER2_voidSetPreScaler(u16 Copy_u16PrescalerValue);

void MTIMER2_voidClearCount(void);



/*****Options Macros*****/
#define TIMER3_CHANNEL1			1
#define TIMER3_CHANNEL2			2
#define TIMER3_CHANNEL3			3
#define TIMER3_CHANNEL4			4

#define TIMER2_CHANNEL1			1
#define TIMER2_CHANNEL2			2
#define TIMER2_CHANNEL3			3
#define TIMER2_CHANNEL4			4


/************************/


/**********************************************************/

#endif 

