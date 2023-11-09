/**********************************/
/* Author :Ahmed Samir            */
/* SWC :LKS With Camera		      */
/* Layer :APP 		              */
/* Version :1.0                   */
/* Date :October 30,2023          */
/* Last Edit :N/A                 */
/**********************************/

#ifndef _LKS_CAMERA_INTERFACE_H_
#define _LKS_CAMERA_INTERFACE_H_





/*--------------------------------------------------------------------------------------------------------------------
 *
 * @brief Initialize the Inputs Pins for Camera Output.
 *
 * This function initializes the peripherals for the Output Camera and sets the pins as input mode with pull-up resistors.
 *
 * @return None
 *
/--------------------------------------------------------------------------------------------------------------------*/
void LKS_Camera_App_Init();

/**
 * @brief Read the camera sensor on the right side of the car.
 *
 * This function reads the output of the camera sensor on the right side of the car and returns a value of 1 if the sensor is detecting a Lane, and 0 otherwise.
 *
 * @return A value of 1 if the camera sensor is detecting a Lane , and 0 otherwise.
 */
u8  LKS_Camera_Read_Right();

/**
 * @brief Read the camera sensor on the Left side of the car.
 *
 * This function reads the output of the camera sensor on the right side of the car and returns a value of 1 if the sensor is detecting a Lane, and 0 otherwise.
 *
 * @return A value of 1 if the camera sensor is detecting a Lane , and 0 otherwise.
 */
u8  LKS_Camera_Read_Left();

/**
 * @brief This function is the main application loop for the LKS Camera.
 *
 * This function first initializes the LKS Camera, then reads the left and right camera sensors.
 * Depending on the values read from the camera sensors, the function will move the robot forward, stop the robot, or turn the robot left or right.
 *
 * @return None
 */
void LKS_Camera_App(void);


















#endif 
