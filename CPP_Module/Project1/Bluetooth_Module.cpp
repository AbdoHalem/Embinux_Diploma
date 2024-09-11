#include <iostream>
#include "Bluetooth_Module.hpp"

/**
 * @brief: Show bluetooth control options
 * 
 */
void bluetooth_menu(){
    int choice = 0;
    while(choice != 5){
        cout << "\nBluetooth Control Program\n" << "------------------" << endl;
        cout << "1. Display Bluetooth Status\n2. Turn Bluetooth On\n3. Turn Bluetooth Off" << endl;
        cout << "4. Connect to a Bluetooth Device.\n5. Back to main menu." << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        if(choice == 1){bluetooth_status();}
        else if(choice == 2){bluetooth_turn(BLUETOOTH_ENABLE);}
        else if(choice == 3){bluetooth_turn(BLUETOOTH_DISABLE);}
        else if(choice == 4){bluetooth_connect();}
    }
    
}

/**
 * @brief: Display bluetooth status
 * 
 */
void bluetooth_status() {
    int status = system("sudo systemctl status bluetooth | grep -i 'disabled' > /dev/null");
    if (status == 0) {
        cout << "\nBluetooth is currently OFF." << endl;
    } else {
        cout << "\nBluetooth is currently ON." << endl;
    }
    system("sleep 2");
}

/**
 * @brief: Turn bluetooth on or off according to status 
 * 
 * @param status: Boolean to decide to turn on or off
 */
void bluetooth_turn(bool status) {
    if (status == BLUETOOTH_ENABLE) {
        system("rfkill unblock bluetooth");
        system("sudo systemctl enable bluetooth");
        cout << "\nBluetooth has been turned ON." << endl;
    } else {
        system("rfkill block bluetooth");
        system("sudo systemctl disable bluetooth");
        cout << "\nBluetooth has been turned OFF." << endl;
    }
    system("sleep 2");
}

/**
 * @brief: Connect to a bluetooth device
 * 
 */
// Needs dual boot to be executed
void bluetooth_connect() {
    // Scan for available Bluetooth devices
    cout << "\nScanning for available Bluetooth devices..." << endl;
    system("sleep 1");
    system("bluetoothctl scan on & sleep 3 && bluetoothctl scan off ; bluetoothctl devices");  // No availabe controller
    // system("bluetoothctl scan on");
    string device_ID;
    cout << "Enter the ID of the Bluetooth device you want to connect to: ";
    cin >> device_ID;

    string cmd = "bluetoothctl connect " + device_ID;
    int result = system(cmd.c_str());

    if (result == 0) {
        cout << "\nSuccessfully connected to device: " << device_ID << endl;
    } else {
        cout << "\nFailed to connect to device: " << device_ID << endl;
    }
    system("sleep 1");
}