/**********************************/
/* Author    : Abdullah Nassar    */
/* SWC       : Bit Math           */
/* Layer     : LIB                */
/* Version   : 1.2                */
/* Date      : August 2, 2023     */
/* Last Edit : September 22, 2023 */
/**********************************/

#ifndef _STD_TYPES_H_
#define _STD_TYPES_H_

typedef unsigned char        u8;
typedef unsigned short int   u16;
typedef unsigned long int    u32;
typedef signed char          s8;
typedef signed short int     s16;
typedef signed long int      s32;
typedef float                f32;
typedef double               f64;

typedef enum
{
	E_OK,
	E_NOK,
	E_NULL_POINTER
}STD_error_t;

#define NULL_POINTER     ((void*)0)            

// Is a macro for defining the initialized value of the variables.

#define Initialized_by_Zero  0


#define RUN  1

#define STOP 0


#define Flag_is_Set 	1

#define Flag_is_Cleared 0


#endif