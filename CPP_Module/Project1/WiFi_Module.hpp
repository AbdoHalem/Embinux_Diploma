#ifndef __WIFI_MODULE__H__
#define __WIFI_MODULE__H__

// Includes Section
#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <fstream>

using namespace std;

// Macros
#define  WIFI_ENABLE 1 
#define  WIFI_DISABLE 0

// APIs Declarations
/**
 * @brief: Displays the WIFI control options
 * 
 */
void wifi_menu();

/**
 * @brief: Displays the WIFI status enabled or disabled
 * 
 */
void wifi_status();

/**
 * @brief: Enable and disable WIFI
 * 
 * @param status: To select enable or disable
 */
void wifi_turn(int status);

/**
 * @brief: Connect to a saved WIFI network
 * 
 * @param network: Name of the WIFI network
 */
void wifi_connect_to_saved(string network);

/**
 * @brief: Connect to a new WIFI network
 * 
 * @param network: Name of the WIFI network
 * @param password: WIFI password
 */
void wifi_connect_to_new(string network, string password);

/**
 * @brief: Remove a saved WIFI network
 * 
 * @param network: Name of the network
 */
void wifi_remove(string network);

/**
 * @brief: Modify name or password of a saved wifi network
 * 
 * @param network 
 */
void wifi_modify(string network);

/**
 * @brief: Search for a saved network
 * 
 * @param network: Name of the network
 */
void wifi_search(string network);


#endif  //!__WIFI_MODULE__H__




