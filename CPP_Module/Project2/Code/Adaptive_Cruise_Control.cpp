/**
 * @file Adaptive_Cruise_Control.cpp
 * @author Abdelrahman Abdelhalem (abdohalem305@gmail.com)
 * @brief This is a cpp file for Adaptive_Cruise_Control class
 * @details This class is for controlling the car if unexpected event occured
 * @version 0.1
 * @date 2024-09-27
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include "Adaptive_Cruise_Control.hpp"

/**
 * @brief Construct a new Adaptive_Cruise_Control::Adaptive_Cruise_Control object
 * @details Parameterized Constructor
 * 
 * @param speed_sensor 
 * @param radar_sensor 
 * @param temp_sensor 
 */
Adaptive_Cruise_Control::Adaptive_Cruise_Control(Speed_Sensor *speed_sensor, Radar_Sensor *radar_sensor, Temp_Sensor *temp_sensor){
    this->speed_sensor = speed_sensor;
    this->radar_sensor = radar_sensor;
    this->temp_sensor = temp_sensor;
    logger = Logger::getInstance();     /*!< Assign object of the singleton logger */ 
}

/**
 * @brief Destroy the Adaptive_Cruise_Control::Adaptive_Cruise_Control object
 * @details Default Destructor 
 * 
 */
Adaptive_Cruise_Control::~Adaptive_Cruise_Control() {}

/**
 * @brief Function to control the car
 * @details This function automatically brake the car if an object is
 * detected at a distance smaller than the SAFE_DISTANCE.
 * Slow down the speed if its temperature is higher than SAFE_TEMPERATURE.
 * Stop the car if its temperature is higher than THRESHOLD_TEMPERATURE
 * 
 */
void Adaptive_Cruise_Control::cruiseControl() {
    unsigned int speed = speed_sensor->getValue();
    unsigned int temperature = temp_sensor->getValue();
    unsigned int distance = radar_sensor->getValue();

    if(distance <= SAFE_DISTANCE){
        speed_sensor->controlSpeed(STOP_CAR);
        logger->log("AdaptiveCruiseControl: Automatic brake activated... An object is infront of you!", CRITICAL, BOTH);
    }
    else if(temperature >= SAFE_TEMPERATURE && temperature < THRESHOLD_TEMPERATURE){
        speed_sensor->controlSpeed(SLOW_CAR);
        logger->log("AdaptiveCruiseControl: Automatic decelerating activated... Car temperature is high!", WARNING, BOTH);
    }
    else if(temperature >= THRESHOLD_TEMPERATURE){
        while(speed_sensor->getValue() > 0){       // Decelerating the speed until stop the car
            speed_sensor->controlSpeed(speed_sensor->getValue() - 10);
        }
        speed_sensor->controlSpeed(STOP_CAR);
        logger->log("AdaptiveCruiseControl: Automatic parking activated... Car temperature is very high!", CRITICAL, BOTH);
    }
}