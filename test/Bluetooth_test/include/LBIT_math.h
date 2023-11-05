/***********************************************/
/* Author       : Ahmed Sherif                 */
/* SWC          : Math BIT                     */
/* Layer        : LIB                          */
/* Version      : 1.0                          */
/* Date         : August 2, 2023               */
/* Last Edited  : N/A                          */
/***********************************************/

#ifndef _BIT_MATH_
#define _BIT_MATH_

#define SET_BIT(reg, bit) reg |= (1 << bit)
#define CLEAR_BIT(reg, bit) reg &= ~(1 << bit)
#define TOGGLE_BIT(reg, bit) reg ^= (1 << bit)
#define GET_BIT(reg, bit) ((reg >> bit) & 1)

#endif
