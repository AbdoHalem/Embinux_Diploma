#ifndef __BATTERY_SENSOR__H__
#define __BATTERY_SENSOR__H__

/**
 * @file Battery_Sensor.hpp
 * @author Abdelrahman Abdelhalem (abdohalem305@gmail.com)
 * @brief This is a header file for Battery_Sensor class
 * @details This class provides the main functionality of the car battery
 * @version 0.1
 * @date 2024-09-27
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "Sensor.hpp"

/**
 * @brief Macro for the battery threshold level
 * 
 */
#define THRESHOLD_LEVEL 20

/**
 * @brief This class is for the car battery
 * 
 */
class Battery_Sensor : public Sensor {
private:
    unsigned int temperature_;      // from 0 to 50 celesius
    unsigned int charge_;           // from 0% to 100%
public:
    /*!< Default Constructor */
    Battery_Sensor() : temperature_(0), charge_(0) {}
    /*!< Default Destructor */
    ~Battery_Sensor() {}
    /*!< Setters and Getters */
    /*!< Get the temperature value */
    unsigned int getValue() const override;
    /*!< Update the temperature value */
    void update() override;
    /*!< Get the charge value */
    unsigned int getBatteryTemp() const ;
};

#endif  //!__BATTERY_SENSOR__H__