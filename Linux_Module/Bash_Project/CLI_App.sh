#!/bin/bash
# Apllication module
# source the modules
source ./System_Module.sh
source ./Devices_Module.sh
source ./DiectorySync_Module.sh
source ./Network_Module.sh
source ./Reboot_Module.sh
source ./Kernel_Module.sh

# Log file to save the logs of the commands
log_file="/home/abdo_halem/Desktop/Embinux_Diploma/Linux_Module/Tasks/Bash_Project/CLI_App.log"
log() {
    echo "$(date +'%Y-%m-%d %H:%M:%S') - $1" >> $log_file
}

###################################################
# Function to run the application for admin
Admin_Menu(){
    while true;
    do
        echo -e "Select option:\n1- System\n2- Devices\n3- Directory Sync over network"
        echo -e "4- Network\n5- Reboot\n6- Kernel logs\n7- Close the application"
        read -n 1 -p "Enter your choice: " option
        printf "\n"
        case $option in
            1) 
                System_fun ;;   # from System_Module.sh
            2) 
                Devices_fun ;;  # from Devices_Module.sh
            3) 
                Directory_Sync_fun ;; # from Directory_Module.sh
            4) 
                Network_fun ;;  # from Network_Module.sh
            5) 
                Reboot_fun ;;   # from Reboot_Module.sh
            6) 
                Kernel_logs_fun ;; # from Kernel_Module.sh
            7)
                log "Exiting CLI Application" 
                break ;;
            *) 
                echo -e "\nInvalid option! Please try again.\n" ;;
        esac
    done
}

# Function to run the application for user
user_Menu(){
    while true;
    do
            echo -e "Select option:\n1- System\n2- Directory Sync over network"
        echo -e "3- Network\n4- Close the application"
        read -n 1 -p "Enter your choice: " option
        printf "\n"
        
        case $option in
            1) 
                System_fun ;;   # from System_Module.sh 
            2) 
                Directory_Sync_fun ;; # from Directory_Module.sh
            3) 
                Network_fun ;;  # from Network_Module.sh
            4)
                log "Exiting CLI Application"
                break ;;
            *) 
                echo -e "\nInvalid option! Please try again.\n" ;;
        esac
    done
}

###################################################
# Function to run the application
app(){
    # Check for admin or user mode
    if [[ $EUID -eq 0 ]]; then
        Admin_Menu
    else
        user_Menu
    fi
}

# Call the application function
app

