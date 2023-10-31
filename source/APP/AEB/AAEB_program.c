/***********************************************/
/* Author       : Ahmed Sherif                 */
/* SWC          : AEB                          */
/* Layer        : APP                          */
/* Version      : 1.1                          */
/* Date         : October 30, 2023             */
/* Last Edited  : October 21, 2023             */
/***********************************************/

/*-------------------------------------------------- Including Files ------------------------------------------------- */
#include "LBIT_math.h"
#include "LSTD_types.h"
#include "MSYSTICK_interface.h"
#include "HULTRASONIC_interface.h"
#include "HMOTORS_interface.h"
#include "AAEB_interface.h"

/*-------------------------------------------------- Global Variables ------------------------------------------------*/
/*Global Variable used to get distance*/
extern u32  Global_u32Distance;;

void AAEB_voidMode(void)
{
    /* Update the distance */
    HULTRASONIC_voidGetDistance();

    /* Keeping the brakes active until the distance between the two cars increases */
    while (G_u32ReadDistance < 10)
    {
        /* urgent Brake to stop the car avoiding very possible accident */
        HMOTOR_voidStop();
        /* Update the distance */
        HULTRASONIC_voidGetDistance();
        MSYSTICK_voidSetDelay(40000); // Delay 10 seconds*/
    }
}