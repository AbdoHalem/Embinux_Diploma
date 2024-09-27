#ifndef __VEHICLE__H__
#define __VEHICLE__H__

/**
 * @file Vehicle.hpp
 * @author Abdelrahman Abdelhalem (abdohalem305@gmail.com)
 * @brief This is a header file for Vehicle class
 * @details This class is used in the application to update the sensors values,
 * run diagnostics, control the car, and display the dashboard 
 * @version 0.1
 * @date 2024-09-27
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "Speed_Sensor.hpp"
#include "Temp_Sensor.hpp"
#include "Radar_Sensor.hpp"
#include "Battery_Sensor.hpp"
#include "Adaptive_Cruise_Control.hpp"
#include "Diagnostics.hpp"
#include "Logger.hpp"

/* Vehicle Class */
/**
 * @brief This is the Vehicle Class
 * @details It has all sensors and objects as private members
 * 
 */
class Vehicle {
    /* Sensors */
    /**
     * @brief Object of speed sensor
     * @details Private member
     * 
     */
    Speed_Sensor speed_sensor;
    /**
     * @brief Object of radar sensor
     * @details Private member
     * 
     */
    Radar_Sensor radar_sensor;
    /**
     * @brief Object of speed sensor
     * @details Private member
     * 
     */
    Temp_Sensor temp_sensor;
    /**
     * @brief Object of battery sensor
     * @details Private member
     * 
     */
    Battery_Sensor battery;
    /* ECUs and Diagnostics */
    /**
     * @brief Object of Adaptive_Cruise_Control
     * @details Private member
     * 
     */
    Adaptive_Cruise_Control cruise_control;
    /**
     * @brief Object of Diagnostics
     * @details Private member
     * 
     */
    Diagnostics diagnostics;
    /**
     * @brief Pointer to Logger object
     * @details Private member
     * 
     */
    Logger *logger;
public:
    /* Delegation Constructor */
    Vehicle();
    /* Default Destructor */
    ~Vehicle();
    /* Update sensor readings */
    void updateSensors();
    /* Display the vehicle's current status */
    void displayDashboard();
    /* Run diagnostics to check vehicle status */
    void runDiagnostics();
    /* Control the vehicle behavior (e.g., Adaptive Cruise Control) */
    void controlVehicle();
};

#endif  //!__VEHICLE__H__
