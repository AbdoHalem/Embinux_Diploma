/**
 * @file Battery_Sensor.cpp
 * @author Abdelrahman Abdelhalem (abdohalem305@gmail.com)
 * @brief This is a cpp file for Battery_Sensor class
 * @details This class provides the main functionality of the car battery
 * @version 0.1
 * @date 2024-09-27
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include "Battery_Sensor.hpp"

/**
 * @brief Virtual function to get the temperature value
 * 
 * @return unsigned int: The battery-charge level
 */
unsigned int Battery_Sensor::getValue() const {
    return charge_;
}

/**
 * @brief Virtual function to update the temperature value
 * 
 */
void Battery_Sensor::update() {
    temperature_ = rand() % 51;
    charge_ = rand() % 101;
}

/**
 * @brief Virtual function to get the charge value
 * 
 * @return unsigned int: The battery's temperature
 */
unsigned int Battery_Sensor::getBatteryTemp() const {
    return temperature_;
}
