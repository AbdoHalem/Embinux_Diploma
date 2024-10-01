/**
 * @file Temp_Sensor.cpp
 * @author Abdelrahman Abdelhalem (abdohalem305@gmail.com)
 * @brief This is a cpp file for Temp_Sensor class
 * @details This class provides the main functionality of a temperature sensor
 * @version 0.1
 * @date 2024-09-27
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include "Temp_Sensor.hpp"

/**
 * @brief Construct a new Temp_Sensor::Temp_Sensor object and initializes the temperature value with 12 celisius
 * @details Member Initialize Constructor
 * 
 */
Temp_Sensor::Temp_Sensor() : temperature_(12) {}

/**
 * @brief Destroy the Temp_Sensor::Temp_Sensor object
 * @details Default Destructor
 * 
 */
Temp_Sensor::~Temp_Sensor() {}

/**
 * @brief Virtual function to get the temperature value
 * 
 * @return unsigned int : The car temperature
 */
unsigned int Temp_Sensor::getValue() const {
    return temperature_;
}

/**
 * @brief Virtual function to update the temperature value
 * 
 */
void Temp_Sensor::update() {
    temperature_ = rand() % 100;
}