/**********************************/
/* Author:Fakhr Eldin    		  */
/* SWC :LKA             		  */
/* Layer :APP 		              */
/* Version :1.0                   */
/* Date :Octobar 21,2023		  */
/* Last Edit :N/A                 */
/**********************************/
#include "LSTD_types.h"
#include "LBIT_math.h"
#include "MGPIO_interface.h"
#include "HIR_interface.h"
#include "HMOTORS_interface.h"
#include "ALKA_IR_interface.h"

/*LANE KEEPING ASSIST MODE*/

 u8 L_u8Right_Read = 0;
 u8 L_u8Left_Read = 0;
/*Set both to intial 0 to stop */





void APP_LKA(void)
{   
    ALKA_IR_Init();     
    L_u8Right_Read =ALKA_Read_IR_Right();
    L_u8Left_Read  = ALKA_Read_IR_Left();

       if((L_u8Left_Read==1)&&(L_u8Right_Read==1)) /*(Both BLACK)-> MOVEFORWARD*/
       {
           HMOTOR_voidMoveForward();
       }
      else if((L_u8Left_Read==0)&&(L_u8Right_Read==0)) /*(Both WHITE)-> STOP*/
      {
          HMOTOR_voidStop();
      }
      else if((L_u8Left_Read==1)&&(L_u8Right_Read==0)) /*(Right ir  WHITE)->TURNRIGHT*/
      {
          HMOTOR_voidMoveRight();
      }
      else if((L_u8Left_Read==0)&&(L_u8Right_Read==1)) /*(Left ir  WHITE)->TURNLEFT*/
      {
          HMOTOR_voidMoveLeft();
      }
      else 
      {
        
      }
}

void ALKA_IR_Init()
    {
        HIR_voidInit(MGPIO_PORTB);
        HIR_SetPin(MGPIO_PORTB, MGPIO_PIN12)    /*portb pin 12 for Right ir*/
        HIR_SetPin(MGPIO_PORTB, MGPIO_PIN13)    /*portb pin 13 for Left ir*/
    }

u8  ALKA_Read_IR_Right()
    {   u8 L_u8Read = 0;
        L_u8Read= HIR_u8ReadIR(MGPIO_PORTB, MGPIO_PIN12);
        return L_u8Read;
    }

u8  ALKA_Read_IR_Left()
    {
        u8 L_u8Read = 0;
        L_u8Read=HIR_u8ReadIR(MGPIO_PORTB, MGPIO_PIN13);
        return L_u8Read;
    }





