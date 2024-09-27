/**
 * @file Radar_Sensor.cpp
 * @author Abdelrahman Abdelhalem (abdohalem305@gmail.com)
 * @brief This is a cpp file for Radar_Sensor class
 * @details This class provides the main functionality of a sensor 
 * that measure the distance between the car and front object
 * @version 0.1
 * @date 2024-09-27
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include "Radar_Sensor.hpp"

/**
 * @brief Construct a new Radar_Sensor::Radar_Sensor object and initializes the distance value with zero
 * @details Member Intialize Constructor
 * 
 */
Radar_Sensor::Radar_Sensor() : distance_(0) {}

/**
 * @brief Destroy the Radar_Sensor::Radar_Sensor object
 * @details Default Destructor
 * 
 */
Radar_Sensor::~Radar_Sensor(){}

/**
 * @brief Virtual function to get the distance between the car and front object
 * 
 * @return unsigned int: The distance between the car and front object 
 */
unsigned int Radar_Sensor::getValue() const {
    return distance_;
}

/**
 * @brief Virtual function to update the distance value
 * 
 */
void Radar_Sensor::update() {
    distance_ = rand() % 40;
}