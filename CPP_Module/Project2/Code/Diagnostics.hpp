#ifndef __DIAGNOSTICS__H__
#define __DIAGNOSTICS__H__

/**
 * @file Diagnostics.hpp
 * @author Abdelrahman Abdelhalem (abdohalem305@gmail.com)
 * @brief This is a header file for Diagnostics class
 * @details This class is for running and checking all the car diagnostics
 * @version 0.1
 * @date 2024-09-27
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "Speed_Sensor.hpp"
#include "Radar_Sensor.hpp"
#include "Temp_Sensor.hpp"
#include "Battery_Sensor.hpp"
#include "Logger.hpp"

/**
 * @brief This class is for car diagnostics
 * @details It runs car diagnostics which checks car speed, temperature, 
 * safe distance, and battery level
 */
class Diagnostics
{
private:
    /* Pointers to sensors for monitoring */
    /**
     * @brief Pointer to speed sensor
     * @details private member
     * 
     */
    Speed_Sensor* speedSensor;
    /**
     * @brief Pointer to radar sensor
     * @details private member
     * 
     */
    Radar_Sensor* radarSensor;
    /**
     * @brief Pointer to temperature sensor
     * @details private member
     * 
     */
    Temp_Sensor* tempSensor;
    /**
     * @brief Pointer to battery sensor
     * @details private member
     * 
     */
    Battery_Sensor* battery;
    /**
     * @brief Pointer to logger sensor
     * @details Private member
     * 
     */
    Logger* logger;     /* Singleton logger */ 
public:
    /* Parameterized Constructor */
    Diagnostics(Speed_Sensor* speed, Radar_Sensor* radar, Temp_Sensor* temp, Battery_Sensor* batt);
    /* Default Destructor */
    ~Diagnostics();
    /* Method to run car diagnostics */
    void runDiagnostics();
    /* Check Speed */
    bool checkSpeed();
    /* Check Distance */
    bool checkDistance();
    /* Check Temperature */
    bool checkTemperature();
    /* Check Battery */
    bool checkBattery();
};

#endif  //!__DIAGNOSTICS__H__


