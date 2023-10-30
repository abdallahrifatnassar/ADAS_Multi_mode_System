/**********************************************************************
* Author  : Abdelrahman Osam Khaled
* Date 	  : 22 March,2023
* SWC	  : Bit Math
* Version : 1.0
* Layer	  : Library
*********************************************************************/

#ifndef BIT_MATH_H
#define BIT_MATH_H

/**********Functions like nacro to manipulate over specific bit ***********/

#define	SET_BIT(REG_NAME,Bit_no)		(REG_NAME |= (1<<Bit_no))

#define CLEAR_BIT(REG_NAME,Bit_no)		(REG_NAME &= ~(1<<Bit_no))

#define GET_BIT(REG_NAME,Bit_no)		((REG_NAME >> Bit_no) & 1)

#define TOGGLE_BIT(REG_NAME,Bit_no)		(REG_NAME ^= (1<<Bit_no))

 #define Clr_BITS(REG,MSK)			(REG) &= ~(MSK)
#define Set_ALL_BITS(REG)			(REG) =  (0xFFFFFFFF)
 #define Clr_ALL_BITS(REG)			(REG) =  (0x00000000)

/******** Functions like macro to manipulate over specific register *********/

#define SET_REG(REG_NAME,VALUE)		(REG_NAME=VALUE)

#define GET_REG(REG_NAME)			(REG_NAME)

#define CLEAR_REG(REG_NAME)			(REG_NAME= 0x00)

#define TOGGLE_REG(REG_NAME)		(REG_NAME ^= 0xFF)

#define Assign_Bit(REG_NAME,Bit_No,VALUE) do{if(Value == 1) SET_BIT(REG_NAME,Bit_No); \
										else CLEAR_BIT(REG_NAME,Bit_No);}while(0)




#endif
