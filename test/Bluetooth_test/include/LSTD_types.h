/***********************************************/
/* Author       : Ahmed Sherif                 */
/* SWC          : Standard Types               */
/* Layer        : LIB                          */
/* Version      : 1.1                          */
/* Date         : August 3, 2023               */
/* Last Edited  : August 2, 2023               */
/***********************************************/

#ifndef _LSTD_TYPES_H_
#define _LSTD_TYPES_H_

#include <stdio.h>

typedef unsigned char u8;
typedef unsigned short int u16;
typedef unsigned long int u32;

typedef signed char s8;
typedef signed short int s16;
typedef signed long int s32;

typedef float f32;
typedef double u64;

typedef enum
{
	E_OK,
	E_NOK,
	E_NULLPOINTER,
}STD_error_t;

#define NULL_POINTER	((void*)0)

#endif
