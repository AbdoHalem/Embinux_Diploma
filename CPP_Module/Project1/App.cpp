#include <iostream>
#include "WiFi_Module.hpp"
#include "Bluetooth_Module.hpp"

using namespace std;

int menu();

int main(){
    int choice = menu();
    while(choice != 3){
        if(choice == 1){wifi_menu();}
        else if(choice == 2){bluetooth_menu();}
        else{cout << "\nInvalid Choice! Try again.";}
        choice = menu();
    }
    return 0;
}

int menu(){
    cout << "\nControl Program\n" << "------------------" << endl;
    cout << "1. WiFi Control\n2. Bluetooth Control\n3. Exit" << endl;
    cout << "Enter your choice: ";
    int choice = 0;
    cin >> choice;
    return choice;
}