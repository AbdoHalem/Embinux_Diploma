/**
 * @file Vehicle.cpp
 * @author Abdelrahman Abdelhalem (abdohalem305@gmail.com)
 * @brief This is a header file for Vehicle class
 * @details This class is used in the application to update the sensors values,
 * run diagnostics, control the car, and display the dashboard
 * @version 0.1
 * @date 2024-09-27
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include "Vehicle.hpp"

/**
 * @brief Construct a new Vehicle:: Vehicle object
 * @details It calls all object constructors and initialize the logger object.
 * Delegation Constructor.
 * 
 */
Vehicle::Vehicle()
    : speed_sensor(), radar_sensor(), temp_sensor(), battery(),
      cruise_control(&speed_sensor, &radar_sensor, &temp_sensor),
      diagnostics(&speed_sensor, &radar_sensor, &temp_sensor, &battery) {
    
    logger = Logger::getInstance(); // Initialize logger
    logger->log("Vehicle has been initialized...", INFO);
}

/**
 * @brief Destroy the Vehicle:: Vehicle object
 * @details Default Destructor
 * 
 */
Vehicle::~Vehicle(){}

/**
 * @brief Function to update readings of all the sensors
 * @details It logs all readings in the log file
 * 
 */
void Vehicle::updateSensors() {
    speed_sensor.update();
    radar_sensor.update();
    temp_sensor.update();
    battery.update();
    // Log updated sensor values
    logger->log("Vehicle sensors updated: Speed = " + std::to_string(speed_sensor.getValue()) + 
                ", Distance = " + std::to_string(radar_sensor.getValue()) +
                ", Temperature = " + std::to_string(temp_sensor.getValue()) +
                ", Battery Level = " + std::to_string(battery.getValue()), INFO);
}

/**
 * @brief Function to display the vehicle's status on the dashboard
 * 
 */
void Vehicle::displayDashboard() {
    std::cout << "======= Vehicle Dashboard =======" << std::endl;
    std::cout << "Speed: " << speed_sensor.getValue() << " km/h" << std::endl;
    std::cout << "Distance to Obstacle: " << radar_sensor.getValue() << " meters" << std::endl;
    std::cout << "Engine Temperature: " << temp_sensor.getValue() << " C" << std::endl;
    std::cout << "Battery Level: " << battery.getValue() << " %" << std::endl;
    std::cout << "=================================" << std::endl;
    /*!< Log dashboard display */
    logger->log("Dashboard displayed...", INFO);
}

/**
 * @brief Function to run diagnostics to check vehicle status
 * @details It calls runDiagnostics() method in Diagnostics class
 * 
 */
void Vehicle::runDiagnostics() {
    diagnostics.runDiagnostics();
}

/**
 * @brief Function to control the vehicle behavior (e.g., Adaptive Cruise Control)
 * @details It calls cruiseControl() method in Adaptive_Cruise_Control class
 * 
 */
void Vehicle::controlVehicle() {
    cruise_control.cruiseControl();
    logger->log("Vehicle control executed...", INFO, BOTH);
}
