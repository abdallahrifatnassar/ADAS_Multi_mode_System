/**********************************/
/* Author :Ahmed Samir            */
/* SWC :RCC		                  */
/* Layer :MCAL 		              */
/* Version :1.0                   */
/* Date :September 12,2023        */
/* Last Edit :N/A                 */
/**********************************/

#include "LSTD_types.h"
#include "LBIT_math.h"
#include "MRCC_interface.h"
#include "MRCC_private.h"
#include "MRCC_config.h"
/*--------------------------------------------------------------------------------------------------------------------
*[Function Name]: MRCC_voidInit
*
*[Description]: This function is responsible for Init the RCC(reset and clock contorl)
*				There are 3 options(HSI,HSE,PLL)and the prescaler of the buses(AHB1,AHB2,APB1,APB2) 
*
*[Arguments]:
*
*[in]:  N/A
*
*[out]: N/A
*
*[Returns]: N/A
--------------------------------------------------------------------------------------------------------------------*/
void MRCC_voidInit(void)
{
	/* System clock Selection*/
	#if SYSTEM_CLOCK==HSI
		/* Internal high-speed clock enable*/
		SET_BIT(MRCC->CR,HSION);
		/* Poll the ready flag*/
		while(!GET_BIT(MRCC->CR,HSIRDY));
		/* SET System clock To HSI */
		CLEAR_BIT(MRCC->CFGR,0);
		CLEAR_BIT(MRCC->CFGR,1);
		
	#elif SYSTEM_CLOCK==HSE
			/* Check if Bypass Or Not*/
			#if	HSE_TYPE==HSE_BYPASS
				/* External By pass high-speed clock enable*/
				SET_BIT(MRCC->CR,HSEBYP);
				/* External high-speed clock enable*/
				SET_BIT(MRCC->CR,HSEON);
				/* Poll the ready flag*/
				while(!GET_BIT(MRCC->CR,HSERDY));
				/* SET System clock To HSE */
				SET_BIT(MRCC->CFGR,0);
				CLEAR_BIT(MRCC->CFGR,1);
			#elif HSE_TYPE==HSE_NOTBYPASS
				/* External By pass high-speed clock disable*/
				CLEAR_BIT(MRCC->CR,HSEBYP);
				/* External high-speed clock enable*/
				SET_BIT(MRCC->CR,HSEON);
				/* Poll the ready flag*/
				while(!GET_BIT(MRCC->CR,HSERDY));
				/* SET System clock To HSE */
				SET_BIT(MRCC->CFGR,0);
				CLEAR_BIT(MRCC->CFGR,1);
			#else 
				#error "Wrong HSE Clock ";	
			#endif
			
	#elif SYSTEM_CLOCK==PLL
		#if PLL_SOURCE==HSI
			/* Internal high-speed clock enable*/
			SET_BIT(MRCC->CR,HSION);
			/* Poll the ready flag*/
			while(!GET_BIT(MRCC->CR,HSIRDY));
			/*Main PLL clock source*/
			CLEAR_BIT(MRCC->PLLCFGR,PLLSRC);
			/* Main PLL (PLL) enable*/
			SET_BIT(MRCC->CR,PLLON);
			/* Poll the ready flag*/
			while(!GET_BIT(MRCC->CR,PLLRDY));
			/* SET System clock To PLL */
			CLEAR_BIT(MRCC->CFGR,0);
			SET_BIT(MRCC->CFGR,1);
		#elif PLL_SOURCE==HSE 
			/* Check if Bypass Or Not*/
			#if	HSE_TYPE==HSE_BYPASS
				/* External By pass high-speed clock enable*/
				SET_BIT(MRCC->CR,HSEBYP);
				/* External high-speed clock enable*/
				SET_BIT(MRCC->CR,HSEON);
				/* Poll the ready flag*/
				while(!GET_BIT(MRCC->CR,HSERDY));
				/*Main PLL clock source*/
				SET_BIT(MRCC->PLLCFGR,PLLSRC);
				/* Main PLL (PLL) enable*/
				SET_BIT(MRCC->CR,PLLON);
				/* Poll the ready flag*/
				while(!GET_BIT(MRCC->CR,PLLRDY));
				/* SET System clock To PLL */
				CLEAR_BIT(MRCC->CFGR,0);
				SET_BIT(MRCC->CFGR,1);
			#elif HSE_TYPE==HSE_NOTBYPASS
				/* External By pass high-speed clock Disable*/
				CLEAR_BIT(MRCC->CR,HSEBYP);
				/* External high-speed clock enable*/
				SET_BIT(MRCC->CR,HSEON);
				/* Poll the ready flag*/
				while(!GET_BIT(MRCC->CR,HSERDY));
				/*Main PLL clock source*/
				SET_BIT(MRCC->PLLCFGR,PLLSRC);
				/* Main PLL (PLL) enable*/
				SET_BIT(MRCC->CR,PLLON);
				/* Poll the ready flag*/
				while(!GET_BIT(MRCC->CR,PLLRDY));
				/* SET System clock To PLL */
				CLEAR_BIT(MRCC->CFGR,0);
				SET_BIT(MRCC->CFGR,1);
			#else 
				#error "wrong PLL Source"
			#endif
		
		#endif
	
	#else 
		#error "Wrong System Clock ";
	#endif
	/* Buses Prescaler Selection*/
	/*AHB Prescaler*/
	#if AHB_BUS_PRESCALER==SYSTEM_CLOCK_NO_DIV
		MRCC->CFGR=(((MRCC->CFGR)&AHB_PRESCALER_MASK)|(SYSTEM_CLOCK<<4));
	#elif AHB_BUS_PRESCALER==SYSTEM_CLOCK_DIV_BY_2
		MRCC->CFGR=(((MRCC->CFGR)&AHB_PRESCALER_MASK)|(SYSTEM_CLOCK_DIV_BY_2<<4));
		
	#elif AHB_BUS_PRESCALER==SYSTEM_CLOCK_DIV_BY_4
		MRCC->CFGR=(((MRCC->CFGR)&AHB_PRESCALER_MASK)|(SYSTEM_CLOCK_DIV_BY_4<<4));
		
	#elif AHB_BUS_PRESCALER==SYSTEM_CLOCK_DIV_BY_8
		MRCC->CFGR=(((MRCC->CFGR)&AHB_PRESCALER_MASK)|(SYSTEM_CLOCK_DIV_BY_8<<4));
		
	#elif AHB_BUS_PRESCALER==SYSTEM_CLOCK_DIV_BY_16
		MRCC->CFGR=(((MRCC->CFGR)&AHB_PRESCALER_MASK)|(SYSTEM_CLOCK_DIV_BY_16<<4));
		
	#elif AHB_BUS_PRESCALER==SYSTEM_CLOCK_DIV_BY_64
		MRCC->CFGR=(((MRCC->CFGR)&AHB_PRESCALER_MASK)|(SYSTEM_CLOCK_DIV_BY_64<<4));
		
	#elif AHB_BUS_PRESCALER==SYSTEM_CLOCK_DIV_BY_128
		MRCC->CFGR=(((MRCC->CFGR)&AHB_PRESCALER_MASK)|(SYSTEM_CLOCK_DIV_BY_128<<4));
		
	#elif AHB_BUS_PRESCALER==SYSTEM_CLOCK_DIV_BY_256
		MRCC->CFGR=(((MRCC->CFGR)&AHB_PRESCALER_MASK)|(SYSTEM_CLOCK_DIV_BY_256<<4));
		
	#elif AHB_BUS_PRESCALER==SYSTEM_CLOCK_DIV_BY_512
		MRCC->CFGR=(((MRCC->CFGR)&AHB_PRESCALER_MASK)|(SYSTEM_CLOCK_DIV_BY_512<<4));
		
	#else
		#error "Wrong AHB Prescaler";
	#endif
	
	/*APB1 Prescaler*/
	#if APB1_BUS_PRESCALER==AHB_CLOCK
		MRCC->CFGR=(((MRCC->CFGR)&APB1_PRESCALER_MASK)|(AHB_CLOCK<<10));
	#elif APB1_BUS_PRESCALER==AHB_CLOCK_DIV_BY_2
		MRCC->CFGR=(((MRCC->CFGR)&APB1_PRESCALER_MASK)|(AHB_CLOCK_DIV_BY_2<<10));
		
	#elif APB1_BUS_PRESCALER==AHB_CLOCK_DIV_BY_4
		MRCC->CFGR=(((MRCC->CFGR)&APB1_PRESCALER_MASK)|(AHB_CLOCK_DIV_BY_4<<10));
		
	#elif APB1_BUS_PRESCALER==AHB_CLOCK_DIV_BY_8
		MRCC->CFGR=(((MRCC->CFGR)&APB1_PRESCALER_MASK)|(AHB_CLOCK_DIV_BY_8<<10));
		
	#elif APB1_BUS_PRESCALER==AHB_CLOCK_DIV_BY_16
		MRCC->CFGR=(((MRCC->CFGR)&APB1_PRESCALER_MASK)|(AHB_CLOCK_DIV_BY_16<<10));
		
		
	#else
		#error "Wrong APB1 Prescaler";
	#endif
	
	/*APB2 Prescaler*/
	#if APB2_BUS_PRESCALER==AHB_CLOCK
		MRCC->CFGR=(((MRCC->CFGR)&APB2_PRESCALER_MASK)|(AHB_CLOCK<<13));
	#elif APB2_BUS_PRESCALER==AHB_CLOCK_DIV_BY_2
		MRCC->CFGR=(((MRCC->CFGR)&APB2_PRESCALER_MASK)|(AHB_CLOCK_DIV_BY_2<<13));
		
	#elif APB2_BUS_PRESCALER==AHB_CLOCK_DIV_BY_4
		MRCC->CFGR=(((MRCC->CFGR)&APB2_PRESCALER_MASK)|(AHB_CLOCK_DIV_BY_4<<13));
		
	#elif APB2_BUS_PRESCALER==AHB_CLOCK_DIV_BY_8
		MRCC->CFGR=(((MRCC->CFGR)&APB2_PRESCALER_MASK)|(AHB_CLOCK_DIV_BY_8<<13));
		
	#elif APB2_BUS_PRESCALER==AHB_CLOCK_DIV_BY_16
		MRCC->CFGR=(((MRCC->CFGR)&APB2_PRESCALER_MASK)|(AHB_CLOCK_DIV_BY_16<<13));
		
		
	#else
		#error "Wrong APB1 Prescaler";
	#endif
	
}
/*--------------------------------------------------------------------------------------------------------------------
*[Function Name]: MRCC_voidEnablePeripheral
*
*[Description]: This function is responsible for Enabling the clock for peripherals
*				There are 3 options(HSI,HSE,PLL)and the prescaler of the buses(AHB1,AHB2,APB1,APB2) 
*
*[Arguments]:
*
*[in]: u8 Copy_u8Bus: This Argument indicates the bus of the peripheral(AHB1,AHB2,APB1,APB2) 
*	   u8 Copy_u8Peripheral	: This Argument indicates the peripheral 
*
*[out]: N/A
*
*[Returns]: N/A
--------------------------------------------------------------------------------------------------------------------*/
void MRCC_voidEnablePeripheral(u8 Copy_u8Bus,u8 Copy_u8Peripheral)
{
	switch(Copy_u8Bus)
	{
		case AHB1_BUS :SET_BIT(MRCC->AHB1ENR,Copy_u8Peripheral);break;
		case AHB2_BUS :SET_BIT(MRCC->AHB2ENR,Copy_u8Peripheral);break;
		case APB1_BUS :SET_BIT(MRCC->APB1ENR,Copy_u8Peripheral);break;
		case APB2_BUS :SET_BIT(MRCC->APB2ENR,Copy_u8Peripheral);break;
		default:break;// for error handling 
	}
}
/*--------------------------------------------------------------------------------------------------------------------
*[Function Name]: MRCC_voidDisablePeripheral
*
*[Description]: This function is responsible for Disabling the clock for peripherals
*				There are 3 options(HSI,HSE,PLL)and the prescaler of the buses(AHB1,AHB2,APB1,APB2) 
*
*[Arguments]:
*
*[in]: u8 Copy_u8Bus: This Argument indicates the bus of the peripheral(AHB1,AHB2,APB1,APB2) 
*	   u8 Copy_u8Peripheral	: This Argument indicates the peripheral 
*
*[out]: N/A
*
*[Returns]: N/A
--------------------------------------------------------------------------------------------------------------------*/
void MRCC_voidDisablePeripheral(u8 Copy_u8Bus,u8 Copy_u8Peripheral)
{
	switch(Copy_u8Bus)
	{
		case AHB1_BUS :CLEAR_BIT(MRCC->AHB1ENR,Copy_u8Peripheral);break;
		case AHB2_BUS :CLEAR_BIT(MRCC->AHB2ENR,Copy_u8Peripheral);break;
		case APB1_BUS :CLEAR_BIT(MRCC->APB1ENR,Copy_u8Peripheral);break;
		case APB2_BUS :CLEAR_BIT(MRCC->APB2ENR,Copy_u8Peripheral);break;
		default:break;// for error handling 
	}
}
/*--------------------------------------------------------------------------------------------------------------------
*[Function Name]: MRCC_voidEnableClockSecurity
*
*[Description]: This function is responsible for Enabling System clock securtiy (in case of clock failing the hsi will be system clock) 
*
*[Arguments]:
*
*[in]: N/A 
*
*[out]: N/A
*
*[Returns]: N/A
--------------------------------------------------------------------------------------------------------------------*/
void MRCC_voidEnableClockSecurity(void)
{
	SET_BIT(MRCC->CR,CSSON);
}
/*--------------------------------------------------------------------------------------------------------------------
*[Function Name]: MRCC_voidDisableClockSecurity
*
*[Description]: This function is responsible for Disabling System clock securtiy (in case of clock failing the hsi will be system clock) 
*
*[Arguments]:
*
*[in]: N/A 
*
*[out]: N/A
*
*[Returns]: N/A
--------------------------------------------------------------------------------------------------------------------*/
void MRCC_voidDisableClockSecurity(void)
{
	CLEAR_BIT(MRCC->CR,CSSON);
}

void MRCC_voidSetSystemClock(u8 Copy_u8ClockSource,u8 Copy_u8HSEMode,u8 Copy_u8PLLSource)
{
	switch(Copy_u8ClockSource)
	{
		case HSI:
		{
			/* Internal high-speed clock enable*/
			SET_BIT(MRCC->CR,HSION);
			/* Poll the ready flag*/
			while(!GET_BIT(MRCC->CR,HSIRDY));
			/* SET System clock To HSI */
			CLEAR_BIT(MRCC->CFGR,0);
			CLEAR_BIT(MRCC->CFGR,1);
			break;
		}
		case HSE :
		{
			switch(Copy_u8HSEMode)
			{
				case HSE_BYPASS:
				{
					/* External By pass high-speed clock enable*/
					SET_BIT(MRCC->CR,HSEBYP);
					/* External high-speed clock enable*/
					SET_BIT(MRCC->CR,HSEON);
					/* Poll the ready flag*/
					while(!GET_BIT(MRCC->CR,HSERDY));
					/* SET System clock To HSE */
					SET_BIT(MRCC->CFGR,0);
					CLEAR_BIT(MRCC->CFGR,1);
					break;
				}
				case HSE_NOTBYPASS:
				{
					/* External By pass high-speed clock disable*/
					CLEAR_BIT(MRCC->CR,HSEBYP);					
					/* External high-speed clock enable*/
					SET_BIT(MRCC->CR,HSEON);
					/* Poll the ready flag*/
					while(!GET_BIT(MRCC->CR,HSERDY));
					/* SET System clock To HSE */
					SET_BIT(MRCC->CFGR,0);
					CLEAR_BIT(MRCC->CFGR,1);
					break;
				}
				default:break;//error handling
			}
			break;
		}
		case PLL:
		{
				switch(Copy_u8PLLSource)
				{
					case HSI:
					{
						/* Internal high-speed clock enable*/
						SET_BIT(MRCC->CR,HSION);
						/* Poll the ready flag*/
						while(!GET_BIT(MRCC->CR,HSIRDY));
						/*Main PLL clock source*/
						CLEAR_BIT(MRCC->PLLCFGR,PLLSRC);
						/* Main PLL (PLL) enable*/
						SET_BIT(MRCC->CR,PLLON);
						/* Poll the ready flag*/
						while(!GET_BIT(MRCC->CR,PLLRDY));
						/* SET System clock To PLL */
						CLEAR_BIT(MRCC->CFGR,0);
						SET_BIT(MRCC->CFGR,1);
						break;
					}
					case HSE :
					{
						switch(Copy_u8HSEMode)
						{
							case HSE_BYPASS:
							{
								/* External By pass high-speed clock enable*/
								SET_BIT(MRCC->CR,HSEBYP);
								/* External high-speed clock enable*/
								SET_BIT(MRCC->CR,HSEON);
								/* Poll the ready flag*/
								while(!GET_BIT(MRCC->CR,HSERDY));
								/*Main PLL clock source*/
								SET_BIT(MRCC->PLLCFGR,PLLSRC);
								/* Main PLL (PLL) enable*/
								SET_BIT(MRCC->CR,PLLON);
								/* Poll the ready flag*/
								while(!GET_BIT(MRCC->CR,PLLRDY));
								/* SET System clock To PLL */
								CLEAR_BIT(MRCC->CFGR,0);
								SET_BIT(MRCC->CFGR,1);
								break;
							}
							case HSE_NOTBYPASS:
							{
								/* External By pass high-speed clock Disable*/
								CLEAR_BIT(MRCC->CR,HSEBYP);
								/* External high-speed clock enable*/
								SET_BIT(MRCC->CR,HSEON);
								/* Poll the ready flag*/
								while(!GET_BIT(MRCC->CR,HSERDY));
								/*Main PLL clock source*/
								SET_BIT(MRCC->PLLCFGR,PLLSRC);
								/* Main PLL (PLL) enable*/
								SET_BIT(MRCC->CR,PLLON);
								/* Poll the ready flag*/
								while(!GET_BIT(MRCC->CR,PLLRDY));
								/* SET System clock To PLL */
								CLEAR_BIT(MRCC->CFGR,0);
								SET_BIT(MRCC->CFGR,1);
								break;
							}
							default:break;//error
						}
						break;
					}
					default:break;//error
				}
			break;
		}
		default:break;//error
	}
}
/* another function using error handling 
STD_error_t MRCC_stderrEnablePeripheral(u8 Copy_u8Bus,u8 Copy_u8Peripheral)
{
	STD_error_t Local_stderrState=E_OK:
	switch(Copy_u8Bus)
	{
		case AHB1_BUS :SET_BIT(MRCC->AHB1ENR,Copy_u8Peripheral);break;
		case AHB2_BUS :SET_BIT(MRCC->AHB2ENR,Copy_u8Peripheral);break;
		case APB1_BUS :SET_BIT(MRCC->APB1ENR,Copy_u8Peripheral);break;
		case APB2_BUS :SET_BIT(MRCC->APB2ENR,Copy_u8Peripheral);break;
		default:Local_stderrState=E_NOK;break; 
	}
	return Local_stderrState;
}
STD_error_t MRCC_stderrDisablePeripheral(u8 Copy_u8Bus,u8 Copy_u8Peripheral)
{
	STD_error_t Local_stderrState=E_OK:
	switch(Copy_u8Bus)
	{
		case AHB1_BUS :CLEAR_BIT(MRCC->AHB1ENR,Copy_u8Peripheral);break;
		case AHB2_BUS :CLEAR_BIT(MRCC->AHB2ENR,Copy_u8Peripheral);break;
		case APB1_BUS :CLEAR_BIT(MRCC->APB1ENR,Copy_u8Peripheral);break;
		case APB2_BUS :CLEAR_BIT(MRCC->APB2ENR,Copy_u8Peripheral);break;
		default:Local_stderrState=E_NOK;break;
	}
	return Local_stderrState;
}*/
