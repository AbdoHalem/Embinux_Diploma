# Function to reboot or shutdown the system
Reboot_fun(){
    echo -e "\n1- Reboot"
    echo "2- Shutdown"
    read -p "Enter your option: " choice
    case $choice in
        1) reboot && log "System Rebooted" ;;
        2) shutdown now && log "System Shutdown" ;;
        *) echo "Invalid option" ;;
    esac
}