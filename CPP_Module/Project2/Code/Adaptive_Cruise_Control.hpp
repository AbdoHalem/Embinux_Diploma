#ifndef __ADAPTIVE_CRUISE_CONTROL__H__
#define __ADAPTIVE_CRUISE_CONTROL__H__

/**
 * @file Adaptive_Cruise_Control.hpp
 * @author Abdelrahman Abdelhalem (abdohalem305@gmail.com)
 * @brief This is a header file for Adaptive_Cruise_Control class
 * @details This class is for controlling the car if unexpected event occured
 * @version 0.1
 * @date 2024-09-27
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "Speed_Sensor.hpp"
#include "Temp_Sensor.hpp"
#include "Radar_Sensor.hpp"
#include "Logger.hpp"

/**
 * @brief Macros for Adaptive_Cruise_Control orders
 * 
 */
#define SLOW_CAR                (unsigned int)50
#define STOP_CAR                (unsigned int)0

/**
 * @brief This class is for Adaptive_Cruise_Control
 * @details It controls the speed or brake when the car temperature is high or an obstacale detection happened
 * 
 */
class Adaptive_Cruise_Control
{
private:
    Speed_Sensor *speed_sensor;
    Radar_Sensor *radar_sensor;
    Temp_Sensor *temp_sensor;
    Logger *logger;
public:
    /* Parameterized Constructor */
    Adaptive_Cruise_Control(Speed_Sensor *speed_sensor, Radar_Sensor *radar_sensor, Temp_Sensor *temp_sensor) ;
    /* Default Destructor */
    ~Adaptive_Cruise_Control();
    /* Methods */
    void cruiseControl();
};


#endif  //!__ADAPTIVE_CRUISE_CONTROL__H__