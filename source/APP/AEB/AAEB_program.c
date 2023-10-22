/***********************************************/
/* Author       : Ahmed Sherif                 */
/* SWC          : AEB                          */
/* Layer        : APP                          */
/* Version      : 1.0                          */
/* Date         : October 21, 2023             */
/* Last Edited  : N/A                          */
/***********************************************/

/*-------------------------------------------------- Including Files ------------------------------------------------- */
#include "LBIT_math.h"
#include "LSTD_types.h"
#include "d:\Embedded Systems required\ARM\ARM-Hackers\Graduation Project\ADAS\ADAS_Multi_mode_System\include\HAL\HMOTORS\HMOTORS_interface.h"
#include "d:\Embedded Systems required\ARM\ARM-Hackers\Graduation Project\ADAS\ADAS_Multi_mode_System\include\HAL\HULTRASONIC\HULTRASONIC_interface.h"

/*-------------------------------------------------- Global Variables ------------------------------------------------*/
u32 G_u32ReadDistance = 0;

int main(void)
{
    /* Initializing the UltraSonic*/
    HULTRASONIC_voidInit();
    /* Initializing the Motor And Moving Forward in a speed of 100rpm */
    HMOTOR_voidInit();
    HMOTOR_voidMoveForward();
    HMOTOR_voidSetSpeed(1000);
    /* Infinity Loop */
    while (1)
    {
        /* Reading the distance between the two cars */
        G_u32ReadDistance = HULTRASONIC_u32Distance();

        if (G_u32ReadDistance < 50 && G_u32ReadDistance > 10)
        {
            /* Decreasing the speed to the half */
            HMOTOR_voidSetSpeed(500);
        }
        else if (G_u32ReadDistance <= 10)
        {
            /* urgent Brake to stop the car avoiding very possible accident */
            HMOTOR_voidStop();
        }
        else
        {
            /* Keep On your Speed */
            HMOTOR_voidSetSpeed(1000);
        }
    }
    return 0;
}