#ifndef __LOGGER__H__
#define __LOGGER__H__

/**
 * @file Logger.hpp
 * @author Abdelrahman Abdelhalem (abdohalem305@gmail.com)
 * @brief This is a header file for Logger class
 * @details This class is for logging all warning and events in a log file
 * @version 0.1
 * @date 2024-09-27
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <iostream>
#include <string>
#include <fstream>  /* std::ofstream */ 
#include <chrono>   /* std::chrono::system_clock */  
#include <ctime>    /* time() */ 
#include <iomanip>  /* std::put_time */ 

/**
 * @brief Enum to determine the type of log message 
 * 
 */
enum LogLevel { DEBUG, INFO, WARNING, ERROR, CRITICAL };

/**
 * @brief Enum to select at which destination the messages will be logged
 * 
 */
enum OutputDestination { FILE_ONLY, CONSOLE_ONLY, BOTH };

/**
 * @brief This class is for logging messages
 * @details This class is designed as singleton Pattern
 * 
 */
class Logger
{
private:
    /**
     * @brief Static instance for Singleton pattern
     * @details Private member pointer
     * 
     */
    static Logger *instance_;
    /**
     * @brief Output file stream for logging
     * @details Private member
     * 
     */
    std::ofstream logFile_;          /*!< Output file stream for logging */ 
    
    /* Private constructor to prevent direct instantiation */
    Logger() ;
    /* Prevent copy constructor and assignment operator to be used */
    Logger(const Logger&) = delete;
    Logger& operator=(const Logger&) = delete;
public:
    /* Static method to get the singleton instance */ 
    static Logger* getInstance();
    /* Public method to log messages */
    void log(const std::string& message, LogLevel level, OutputDestination dest = FILE_ONLY);
    /* Destructor */
    ~Logger();
};

#endif  //!__LOGGER__H__