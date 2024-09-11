#ifndef __BLUETOOTH_MODULE__H__
#define __BLUETOOTH_MODULE__H__

#include <iostream>
#include <string>
using namespace std;

// Macros
#define  BLUETOOTH_ENABLE true 
#define  BLUETOOTH_DISABLE false

/**
 * @brief: Show bluetooth control options
 * 
 */
void bluetooth_menu();

/**
 * @brief: Display bluetooth status
 * 
 */
void bluetooth_status();

/**
 * @brief: Turn bluetooth on or off according to status 
 * 
 * @param status: Boolean to decide to turn on or off
 */
void bluetooth_turn(bool status);

/**
 * @brief: Connect to a bluetooth device
 * 
 */
// Needs dual boot to be executed
void bluetooth_connect();



#endif  //!__BLUETOOTH_MODULE__H__