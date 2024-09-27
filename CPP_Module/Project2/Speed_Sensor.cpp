/**
 * @file Speed_Sensor.cpp
 * @author Abdelrahman Abdelhalem (abdohalem305@gmail.com)
 * @brief This is a cpp file for Speed_Sensor class
 * @details This class provides the main functionality of a sensor that measure the car speed
 * @version 0.1
 * @date 2024-09-27
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "Speed_Sensor.hpp"

/**
 * @brief Construct a new Speed_Sensor::Speed_Sensor object and initializes the speed value with zero
 * @details Member Initialize Constructor
 */
Speed_Sensor::Speed_Sensor() : speed_(0) {}

/**
 * @brief Destroy the Speed_Sensor::Speed_Sensor object
 * @details Default Destructor
 * 
 */
Speed_Sensor::~Speed_Sensor() {}

/**
 * @brief Virtual function to get the speed value
 * 
 * @return unsigned int : The car speed
 */
unsigned int Speed_Sensor::getValue() const {
    return speed_;
}

/**
 * @brief Virtual function to update the speed in range 0 to 250 Km/h
 * 
 */
void Speed_Sensor::update() {
    speed_ = rand() % 251;
}

/**
 * @brief Function to control the speed value
 * 
 * @param speed : The new speed of the car
 */
void Speed_Sensor::controlSpeed(unsigned int speed) {
    speed_ = speed;
}