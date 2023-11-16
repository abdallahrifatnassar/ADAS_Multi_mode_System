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
/**
 * @brief Initialize the specified MTIMER2 channel.
 *
 * This function configures the MTIMER2 channel in edge-aligned mode with the
 * counter counting up. It also enables both capture edges on the specified
 * channel.
 *
 * @param Copy_u8ChannelId The MTIMER2 channel to initialize.
 *
 * @return None
 */
void MTIMER2_voidInit(u8 Copy_u8ChannelId);

/**
 * @brief Start the MTIMER2 counter.
 *
 * This function enables the MTIMER2 counter.
 *
 * @return None
 */
void MTIMER2_voidStartTimer(void);

/**
 * @brief Stop the MTIMER2 counter.
 *
 * This function disables the MTIMER2 counter.
 *
 * @return None
 */
void MTIMER2_voidStopTimer(void);

/**
 * @brief Get the captured value on the specified MTIMER2 channel.
 *
 * This function returns the captured value on the specified MTIMER2 channel.
 *
 * @param Copy_u8ChannelId The MTIMER2 channel to get the captured value for.
 *
 * @return The captured value on the specified MTIMER2 channel.
 */
u32 MTIMER2_u32CaptureValue(u8 Copy_u8ChannelId);

/**
 * @brief Enable the capture interrupt on the specified MTIMER2 channel.
 *
 * This function enables the capture interrupt on the specified MTIMER2 channel.
 *
 * @return None
 */
void MTIMER2_voidEnableInterrupt(void);

/**
 * @brief Disable the capture interrupt on the specified MTIMER2 channel.
 *
 * This function disables the capture interrupt on the specified MTIMER2 channel.
 *
 * @return None
 */
void MTIMER2_voidDisableInterrupt(void);

/**
 * @brief Set the MTIMER2 prescaler.
 *
 * This function sets the MTIMER2 prescaler.
 *
 * @param Copy_u16PrescalerValue The MTIMER2 prescaler value to set.
 *
 * @return None
 */
void MTIMER2_voidSetPreScaler(u16 Copy_u16PrescalerValue);

/**
 * @brief Clear the MTIMER2 counter.
 *
 * This function clears the MTIMER2 counter.
 *
 * @return None
 */
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

