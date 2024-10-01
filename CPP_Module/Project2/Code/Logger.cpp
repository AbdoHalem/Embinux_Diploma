/**
 * @file Logger.cpp
 * @author Abdelrahman Abdelhalem (abdohalem305@gmail.com)
 * @brief This is a cpp file for Logger class
 * @details This class is for logging all warning and events in a log file
 * @version 0.1
 * @date 2024-09-27
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "Logger.hpp"

/**
 * @brief Initialize static member of the class
 * 
 */
Logger* Logger::instance_ = nullptr;

/**
 * @brief Construct a new Logger:: Logger object
 * @details Private constructor to open the log file
 */
Logger::Logger() {
    // Open log file in append mode
    logFile_.open("vehicle_system.log", std::ios::app);
    if (logFile_.is_open()) {
        logFile_ << "Logger initialized...\n";
    }
}

/**
 * @brief Destroy the Logger:: Logger object
 * @details Destructor
 * 
 */
Logger::~Logger() {
    delete instance_;
}

/**
 * @brief Static function to get the singleton object
 * @details Public method
 * 
 * @return Logger* : pointer to the static object of Logger class
 */
Logger* Logger::getInstance() {
    if (instance_ == nullptr) {
        instance_ = new Logger();
    }
    return instance_;
}

/**
 * @brief Function to log messages in the log file only or in console too
 * @details Public method 
 * @param message: String of the message content
 * @param level: Level of the log message
 * @param dest: Destination to log the message
 */
void Logger::log(const std::string& message, LogLevel level, OutputDestination dest) {
    if (logFile_.is_open()) {
        /*!> Get current time and write it in the log file */
        auto now = std::chrono::system_clock::now();
        std::time_t now_c = std::chrono::system_clock::to_time_t(now);
        logFile_ << std::put_time(std::localtime(&now_c), "%Y-%m-%d %X %p ");
        
        /*!> Add log level */
        switch (level) {
            case DEBUG: logFile_ << "[DEBUG]: "; break;
            case INFO: logFile_ << "[INFO] "; break;
            case WARNING: logFile_ << "[WARNING] "; break;
            case ERROR: logFile_ << "[ERROR] "; break;
            case CRITICAL: logFile_ << "[CRITICAL] "; break;
            default : break;
        }
        /*!> Add the log message */
        if(dest == CONSOLE_ONLY || BOTH){
            std::cout << message << std::endl;
        }
        logFile_ << message << std::endl;

    }
    else {
        std::cerr << "Logger error: " << message << std::endl;
    }
}