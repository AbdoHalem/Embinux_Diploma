# Vehicle Telemetry and Diagnostic System Simulation Project

## Project Description:
A customer has a car and wants to measure its telemetries and control its system.
This vehicle is equipped with state-of-the-art sensors and systems designed to ensure safe and efficient operation under various driving conditions.

## Sensors:
SpeedSensor: Simulates the vehicle's speed.
RadarSensor: Tracks Radar distance for obstacle detection.
TemperatureSensor: Monitors the engine's temperature.
Battery: Display the battery's charge level and temperature.

## ECUs:
AdaptiveCruiseControl: changes speed or break when temperature or obstacale detection happens.

## Diagnostics:
Regularly check all monitored parameters, identify any potential 
issues (such as low fuel, excessive speed, overheating, low battery 
charge, or unsafe proximity to another vehicle)

## Logger:
Single instance logger to be used among all the classes for logging

### Project Structure:
- **Sensor Interface**: A base interface class, with sensor types like `TemperatureSensor`, `SpeedSensor`, `RadarSensor`, and `Battery` inheriting from it.
- **Adaptive Cruise Control (ACC)**: This class includes all sensor data and manages vehicle speed adjustments and braking based on sensor inputs.
- **Diagnostics Class**: Responsible for checking and diagnosing all sensors, as well as the ACC system, to ensure everything operates within safe parameters.
- **Vehicle Class**: A high-level class used in the main function, encapsulating all other classes (sensors, ACC, diagnostics) to simulate the vehicle system.
- **Logger Class**: Implemented using the **Singleton pattern**, ensuring a single logging instance across all classes for centralized logging.

