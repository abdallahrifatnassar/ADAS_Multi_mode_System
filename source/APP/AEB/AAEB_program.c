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
#include "d:\Embedded Systems required\ARM\ARM-Hackers\Graduation Project\ADAS\ADAS_Multi_mode_System\include\HAL\HMOTORS\HMOTORS_interface.h"
#include "d:\Embedded Systems required\ARM\ARM-Hackers\Graduation Project\ADAS\ADAS_Multi_mode_System\include\HAL\HULTRASONIC\HULTRASONIC_interface.h"
#include "D:\Embedded Systems required\ARM\ARM-Hackers\Graduation Project\ADAS\ADAS_Multi_mode_System\include\APP\AEB\AAEB_interface.h"
#include "d:\Embedded Systems required\ARM\ARM-Hackers\Graduation Project\ADAS\ADAS_Multi_mode_System\include\MCAL\MSYSTICK\MSYSTICK_interface.h"
/*-------------------------------------------------- Global Variables ------------------------------------------------*/
u32 G_u32ReadDistance = 0;

void AAEB_void_init(void)
{
    /* Initializing the UltraSonic*/
    HULTRASONIC_voidInit();
    /* Initializing the Motor And Moving Forward in a speed of 100rpm */
    HMOTOR_voidInit();
    HMOTOR_voidMoveForward();
    HMOTOR_voidSetSpeed(1000);
}

void AAEB_voidMode(void)
{
    /* Update the distance */
    HULTRASONIC_voidGetDistance();
    MSYSTICK_voidSetDelay(10000000); // Delay 10 seconds*/
    /* Reading the distance between the two cars */
    G_u32ReadDistance = HULTRASONIC_u32Distance();

    /* Keeping the brakes active until the distance between the two cars increases */
    while (G_u32ReadDistance < 10)
    {
        /* urgent Brake to stop the car avoiding very possible accident */
        HMOTOR_voidStop();

        /* Update the distance */
        HULTRASONIC_voidGetDistance();
        MSYSTICK_voidSetDelay(5000000); // Delay 10 seconds*/
        G_u32ReadDistance = HULTRASONIC_u32Distance();
    }
}