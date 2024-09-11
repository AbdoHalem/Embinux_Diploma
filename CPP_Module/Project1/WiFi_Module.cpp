#include "WiFi_Module.hpp"

/* =============== Helper Functions =============== */
static map<string, string> load_networks();
static void save_networks(const map<string, string>& networks);
static void add_network(const string& ssid, const string& password);

/* =============== APIs =============== */
/**
 * @brief: Displays the WIFI control options
 * 
 */
void wifi_menu(){
    int choice = 0;
    while(choice != 8){
        cout << "\nWiFi Control Program\n" << "------------------" << endl;
        cout << "1. Display WiFi Status\n2. Turn WiFi On\n3. Turn WiFi Off" << endl;
        cout << "4. Connect to a WiFI Network\n5. Remove a Saved Network\n6. Modify a Saved Network" << endl;
        cout << "7. Search for a Network\n8. Back to main menu" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        if(choice == 1){wifi_status();}
        else if(choice == 2){wifi_turn(WIFI_ENABLE);}
        else if(choice == 3){wifi_turn(WIFI_DISABLE);}
        else if(choice == 4){
            std::string network, password;
            cout << "\n1. Connect to a Saved Network\n2. Connect to a New network" << endl;
            cout << "Enter your choice: ";
            cin >> choice;
            if(choice == 1){
                cout << "\nEnter Network Name: ";
                cin >> network;
                wifi_connect_to_saved(network);
            }
            else if(choice == 2){
                cout << "\nEnter Network Name: ";
                cin >> network;
                cout << "Enter Network Password: ";
                cin >> password;
                wifi_connect_to_new(network, password);
            }
        }
        else if(choice == 5){
            std::string network;
            cout << "\nEnter Network Name: ";
            cin >> network;
            wifi_remove(network);
        }
        else if(choice == 6){
            std::string network;
            cout << "\nEnter Network Name: ";
            cin >> network;
            wifi_modify(network);
        }
        else if(choice == 7){
            std::string network;
            cout << "\nEnter Network Name: ";
            cin >> network;
            wifi_search(network);
        }
        
    }
    
}

/**
 * @brief: Displays the WIFI status enabled or disabled
 * 
 */
void wifi_status(){
    system("nmcli radio wifi");
    system("sleep 1.5");
}

/**
 * @brief: Enable and disable WIFI
 * 
 * @param status: To select enable or disable
 */
void wifi_turn(int status){
    if(status == WIFI_ENABLE){
        system("nmcli radio wifi on");
        cout << "WIFI is Enabled Successfully" << endl;
    }
    else if(status == WIFI_DISABLE){
        system("nmcli radio wifi off");
        cout << "WIFI is Disabled Successfully" << endl;

    }
    system("sleep 2");
}

/**
 * @brief: Connect to a saved WIFI network
 * 
 * @param network: Name of the WIFI network
 */
// Need dual boot to be implemented
void wifi_connect_to_saved(string network){
    map<string, string> saved_networks = load_networks();
    if(saved_networks.empty()) {
        cout << "No saved networks found. Please connect to a new network." << endl;
        system("sleep 1");
        return;
    }
    cout << "Available saved networks:" << endl;
    int index = 1;
    for (const auto &network : saved_networks) {
        cout << index++ << ". " << network.first << endl;
    }

    cout << "Select a network to connect: ";
    int choice;
    cin >> choice;
    if (choice < 1 || choice > saved_networks.size()) {
        cout << "\nInvalid selection!" << endl; system("sleep 1");
        return;
    }
    auto it = saved_networks.begin();
    advance(it, choice - 1);
    string selected_network = it->first;
    string password = it->second;

    string cmd = "nmcli dev wifi connect " + selected_network + " password " + password;
    int res = system(cmd.c_str());
    if(res == 0){
        cout << "\nSuccessfully connected to " << network << "!" << endl;
    }
    else{
        cout << "\nFailed to connect to " << network << ". Please check your credentials." << endl;
    }
    system("sleep 2");
}

/**
 * @brief: Connect to a new WIFI network
 * 
 * @param network: Name of the WIFI network
 * @param password: WIFI password
 */
// Need dual boot to be implemented
void wifi_connect_to_new(string network, string password){
    std::string cmd = "nmcli device wifi connect " + network + " password " + password;
    int res = system(cmd.c_str());
    if(res == 0){
        cout << "\nSuccessfully connected to " << network << "!" << endl;
        add_network(network, password);
    }
    else{   // This condition will be executed as it needs dual boot
        cout << "\nFailed to connect to " << network << ". Please check your credentials." << endl;
    }
    system("sleep 2");
}

/**
 * @brief: Remove a saved WIFI network
 * 
 * @param network: Name of the network
 */
void wifi_remove(string network){
    map<string, string> saved_networks = load_networks();
    if(saved_networks.empty()) {
        cout << "No saved networks found !" << endl;
        system("sleep 2");
        return;
    }
    cout << "Available saved networks:" << endl;
    int index = 1;
    for (const auto &network : saved_networks) {
        cout << index++ << ". " << network.first << endl;
    }
    cout << "Select a network to connect: ";
    int choice;
    cin >> choice;
    if (choice < 1 || choice > saved_networks.size()) {
        cout << "\nInvalid selection!" << endl; system("sleep 1");
        return;
    }
    auto it = saved_networks.begin();
    advance(it, choice - 1);
    string selected_network = it->first;
    string password = it->second;

    saved_networks.erase(selected_network);
    save_networks(saved_networks);
    system("sleep 2");
}

/**
 * @brief: Modify name or password of a saved wifi network
 * 
 * @param network 
 */
void wifi_modify(string network){
    map<string, string> saved_networks = load_networks();
    if(saved_networks.empty()) {
        cout << "No saved networks found !" << endl;
        system("sleep 2");
        return;
    }
    cout << "Available saved networks:" << endl;
    int index = 1;
    for (const auto &network : saved_networks) {
        cout << index++ << ". " << network.first << endl;
    }

    cout << "Select a network to modify: ";
    int choice;
    cin >> choice;
    if (choice < 1 || choice > saved_networks.size()) {
        cout << "\nInvalid selection!" << endl; system("sleep 1");
        return;
    }
    auto it = saved_networks.begin();
    advance(it, choice - 1);
    string selected_network = it->first;
    string password = it->second;

    string new_password;
    cout << "Enter new password: "; cin >> new_password;
    // Update the saved network with the new password
    saved_networks[selected_network] = new_password;

    // Save the updated networks to the file
    save_networks(saved_networks);
    cout << "Network " << selected_network << " password is updated successfully to: " << new_password << endl;
    system("sleep 2");
}

/**
 * @brief: Search for a saved network
 * 
 * @param network: Name of the network
 */
void wifi_search(string network){
    map<string, string> saved_networks = load_networks();
    if (saved_networks.empty()) {
        cout << "No saved networks to search !" << endl;
        system("sleep 2");
        return;
    }

    auto it = saved_networks.find(network);
    if(it != saved_networks.end()) {
        cout << "Network is found Name: " << it->first << ", Password: " << it->second << endl;
    }
    else{
        cout << "Network with Name " << network << " is not found." << endl;
    }
    system("sleep 2");
}

/* =============== Helper Functions =============== */
static map<string, string> load_networks() {
    map<string, string> networks;
    ifstream infile("saved_networks.txt");
    string name, password;

    while (infile >> name >> password) {
        networks[name] = password;
    }
    return networks;
}

static void save_networks(const map<string, string>& networks) {
    ofstream outfile("saved_networks.txt");
    for (const auto& network : networks) {
        outfile << network.first << " " << network.second << endl;
    }
}

static void add_network(const string& name, const string& password) {
    ofstream outfile("saved_networks.txt", ios::app);
    outfile << name << " " << password << endl;
}