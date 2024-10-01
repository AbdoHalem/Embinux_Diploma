#ifndef __SENSOR__H__
#define __SENSOR__H__
/**
 * @file Sensor.hpp
 * @author Abdelrahman Abdelhalem (abdohalem305@gmail.com)
 * @brief This is a header file for Sensor class
 * @details This class provides main methods to be inherited in all sensors
 * @version 0.1
 * @date 2024-09-27
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <iostream>
#include <cstdlib>  // For rand() and srand()
using namespace std;

/* Interface Class for Inheritance */
/**
 * @brief This is an interface Class provides the main methods inherited in all sensors
 * 
 */
class Sensor
{
public:
    /*!< Default Constructor */
    Sensor() {}
    /*!< Default Destructor */
    ~Sensor() {}
    /*!< Virtual functions */
    virtual unsigned int getValue() const = 0;
    virtual void update() = 0;
};

#endif  //!__SENSOR__H__

