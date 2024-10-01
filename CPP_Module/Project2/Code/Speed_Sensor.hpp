#ifndef __SENSORS__H__
#define __SENSORS__H__

/**
 * @file Speed_Sensor.hpp
 * @author Abdelrahman Abdelhalem (abdohalem305@gmail.com)
 * @brief This is a header file for Speed_Sensor class
 * @details This class provides the main functionality of a sensor that measure the car speed
 * @version 0.1
 * @date 2024-09-27
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "Sensor.hpp"

/**
 * @brief Macro for speed threshold
 * 
 */
#define SAFE_SPEED 150

/**
 * @brief This class is for the car's speed sensor
 * 
 */
class Speed_Sensor : public Sensor {
private:
    unsigned int speed_;    // from 0 to 250 km/m
public:
    /* Member Initialize Constructor */
    Speed_Sensor();
    /* Default Destructor */
    ~Speed_Sensor();
    /* Setters and Getters */
    /* Get the speed value */
    unsigned int getValue() const override;
    /* Update the speed value */
    void update() override;
    /* Control the speed value */
    void controlSpeed(unsigned int speed) ;
};


#endif  //!__SENSORS__H__

