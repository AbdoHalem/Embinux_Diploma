/**
 * @file Diagnostics.cpp
 * @author Abdelrahman Abdelhalem (abdohalem305@gmail.com)
 * @brief This is a cpp file for Diagnostics class
 * @details This class is for running and checking all the car diagnostics
 * @version 0.1
 * @date 2024-09-27
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include "Diagnostics.hpp"

/**
 * @brief Construct a new Diagnostics:: Diagnostics object and initializes the members values with the given arguments
 * @details Parameterized Constructor
 * 
 * @param speed: Pointer to the Speed_Sensor object
 * @param radar: Pointer to the Radar_Sensor object
 * @param temp: Pointer to the Temp_Sensor object
 * @param batt: Pointer to the Battery_Sensor object
 */
Diagnostics::Diagnostics(Speed_Sensor* speed, Radar_Sensor* radar, Temp_Sensor* temp, Battery_Sensor* batt) 
    : speedSensor(speed), radarSensor(radar), tempSensor(temp), battery(batt) {
    logger = Logger::getInstance();     /*!< Singleton logger */
}

/**
 * @brief Destroy the Diagnostics:: Diagnostics object
 * @details Default Destructor
 * 
 */
Diagnostics::~Diagnostics() {}

/**
 * @brief Function to run all car diagnostics
 * @details It checks the values of all car sensors
 *  and give alert to the driver if upnormal event happened
 * 
 */
void Diagnostics::runDiagnostics() {
    bool speedCheck = checkSpeed();
    bool distanceCheck = checkDistance();
    bool tempCheck = checkTemperature();
    bool batteryCheck = checkBattery();

    if (!speedCheck || !distanceCheck || !tempCheck || !batteryCheck) {
        logger->log("Diagnostics: Warning or error detected.", WARNING);
    }
}

/**
 * @brief Function to check speed
 * @details It gives alert to the driver if the speed is higher than SAFE_SPEED
 * 
 * @return true: If the speed is in the safe range
 * @return false: If the speed exceeds the SAFE_SPEED
 */
bool Diagnostics::checkSpeed() {
    if (speedSensor->getValue() > SAFE_SPEED) { // Example threshold
        logger->log("Diagnostics: Speed is very high!", WARNING, BOTH);
        return false;
    }
    return true;
}

/**
 * @brief Function to check the distance between the car and front objects
 * @details It gives alert to the driver if the distance is lower than SAFE_DISTANCE
 * 
 * @return true: If the distance is in the safe range
 * @return false: If the distance lower than the SAFE_DISTANCE
 */
bool Diagnostics::checkDistance() {
    if (radarSensor->getValue() <= SAFE_DISTANCE) {
        logger->log("Diagnostics: Object is too close!", CRITICAL, BOTH);
        return false;
    }
    return true;
}

/**
 * @brief Function to check the car temperature
 * @details It gives alert to the driver if the temperature is higher than SAFE_TEMPERATURE
 * 
 * @return true: If the car temperature is in the safe range
 * @return false: If the car temperature is higher than SAFE_TEMPERATURE
 */
bool Diagnostics::checkTemperature() {
    if (tempSensor->getValue() > SAFE_TEMPERATURE) { // Example threshold
        logger->log("Diagnostics: Engine's temperature is high!", WARNING, BOTH);
        return false;
    }
    return true;
}

/**
 * @brief Function to check battery-charge level
 * @details It gives alert to the driver if the battery level is higher than THRESHOLD_LEVEL
 * 
 * @return true 
 * @return false 
 */
bool Diagnostics::checkBattery() {
    if (battery->getValue() <= THRESHOLD_LEVEL) { 
        logger->log("Diagnostics: Battery level is low!", WARNING, BOTH);
        return false;
    }
    return true;
}

