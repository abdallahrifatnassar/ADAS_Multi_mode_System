/***********************************************/
/* Author       : Ahmed Sherif                 */
/* SWC          : NVIC                         */
/* Layer        : MCAL                         */
/* Version      : 1.0                          */
/* Date         : September 17, 2023           */
/* Last Edited  : N/A		            	   */
/***********************************************/

#ifndef _MNVIC_CONFIG_H_
#define _MNVIC_CONFIG_H_

typedef enum
{
    SEXTEEN_GRPOUP = 0,
    EIGHT_GRPOUP = 4,
    FOUR_GRPOUP = 5,
    TWO_GROUP = 6,
    NO_GROUP = 7
} MNVIC_GroupPriority_t;

#endif /* _MNVIC_CONFIG_H_ */