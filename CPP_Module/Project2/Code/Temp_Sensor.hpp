#ifndef __TEMP_SENSOR__H__
#define __TEMP_SENSOR__H__
/**
 * @file Temp_Sensor.hpp
 * @author Abdelrahman Abdelhalem (abdohalem305@gmail.com)
 * @brief This is a header file for Temp_Sensor class
 * @details This class provides the main functionality of a sensor that measure the car temperature
 * @version 0.1
 * @date 2024-09-27
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "Sensor.hpp"

/**
 * @brief Macros to the the threshold temperature values
 * 
 */
#define THRESHOLD_TEMPERATURE        (unsigned int)90
#define SAFE_TEMPERATURE             (unsigned int)70

/**
 * @brief This class is for the car's temperature sensor
 * 
 */
class Temp_Sensor : public Sensor {
private:
    unsigned int temperature_;      /*!< from 0 to 100 celesius*/ 
public:
    /* Member Initialize Constructor */
    Temp_Sensor();
    /* Default Destructor */
    ~Temp_Sensor();
    /* Setters and Getters */
    /* Get the temperature value */
    unsigned int getValue() const override;
    /* Update the temperature value */
    void update() override;
};

#endif  //!__TEMP_SENSOR__H__