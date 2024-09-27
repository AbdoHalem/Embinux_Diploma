#ifndef __RADAR_SENSOR__H__
#define __RADAR_SENSOR__H__

/**
 * @file Radar_Sensor.hpp
 * @author Abdelrahman Abdelhalem (abdohalem305@gmail.com)
 * @brief This is a header file for Radar_Sensor class
 * @details This class provides the main functionality of a sensor 
 * that measure the distance between the car and front object
 * @version 0.1
 * @date 2024-09-27
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "Sensor.hpp"

/**
 * @brief Macro for the distance threshold
 * 
 */
#define SAFE_DISTANCE           (unsigned int)5

/**
 * @brief This class is for the radar sensor
 * 
 */
class Radar_Sensor : public Sensor {
private:
    /*! Distance between car and front objects in meters */
    unsigned int distance_;
public:
    /* Member Intialize Constructor */
    Radar_Sensor();
    /* Default Destructor */
    ~Radar_Sensor();
    /* Setters and Getters */
    /* Get the distance value */
    unsigned int getValue() const override;
    /* Update the distance value */
    void update() override;
};


#endif  //!__RADAR_SENSOR__H__