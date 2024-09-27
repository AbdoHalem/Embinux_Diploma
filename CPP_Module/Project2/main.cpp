#include "Vehicle.hpp"
#include <chrono>
#include <ctime>    /*!< For time() */

int main()
{
    /*!< Seed the random number generator */
    srand(static_cast<unsigned int>(time(0)));
    Vehicle vehicle;

    while (true) {
        vehicle.updateSensors();    /*!< Update sensor data */
        vehicle.displayDashboard(); /*!< Display vehicle status */
        vehicle.runDiagnostics();   /*!< Run diagnostics */
        vehicle.controlVehicle();   /*!< Control vehicle behavior */
        /* Sleep for 2 second to simulate real-time operation */ 
        system("sleep 2");
    }
    return 0;
}