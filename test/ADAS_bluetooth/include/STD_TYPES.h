/**********************************************************************
* Author  : Abdelrahman Osam Khaled
* Date 	  : 11 March,2023
* SWC	  : STD TYPES
* Version : 1.0
* Layer	  : Library
*********************************************************************/
#ifndef	STD_TYPES_H
#define STD_TYPES_H

typedef	unsigned char			u8;
typedef unsigned short int		u16;
typedef unsigned long int		u32;

typedef signed char				s8;
typedef signed short int		s16;
typedef signed long int			s32;

typedef float					f32;
typedef double					f64;

/* Mavros for error state */
#define STD_TYPES_OK				1
#define STD_TYPES_NOK				0
/* Macros for TRUE & FALSE values */
#define STD_TYPES_TRUE				1
#define STD_TYPES_FALSE				0

#define NULL   ((void*)0)


#endif