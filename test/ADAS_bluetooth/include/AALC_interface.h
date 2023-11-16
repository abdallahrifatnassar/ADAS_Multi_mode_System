/****************************************************/
/* Author 	: Abdullah Nassar & Ahmed ELyousfy     	*/
/* SWC 		: ALC		                  			*/
/* Layer 	: APP 		              				*/
/* Version 	: 1.0                   				*/
/* Date 	: October 31,2023          				*/
/* Last Edit: N/A                 					*/
/****************************************************/

#ifndef _AALC_INTERFACE_H_
#define _AALC_INTERFACE_H_

/*---------------------------------------------------------------------
|  Method [ACC_voidMode]
|
|  Purpose: [This function responsible for Adaptive Light Control Mode and Set The
|			 lights of the vehicle based on the LDR Sensor feedback]
|
|  Pre-condition: config LDR pin and port in config file.h
|
|  Post-condition: N/A
|
|  Parameters:N/A
|
|  Returns:  N/A
-------------------------------------------------------------------*/

void	AALC_voidMode(void);

#endif