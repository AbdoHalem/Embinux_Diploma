# CPU_Policy not completed yet

# Function to Change CPU policy is not supported on virtualbox
CPU_Policy(){
    if [[ -d "/sys/devices/system/cpu/cpu0/cpufreq" ]]; then
        read -p "Enter CPU policy (performance/powersave): " policy
        echo $policy | sudo tee /sys/devices/system/cpu/cpu*/cpufreq/scaling_governor
        log "Changed CPU policy to $policy"
    else
        echo -e "\nCPU frequency scaling is not supported on this machine.\n"
        log "Change CPU policy failed !"
    fi
}

# Function to Set battery threshold (ex. 60%) is not supported on virtualbox
# So, the function is changed to display the full battery energy and the current energy
Battery_Info(){
    # read -p "Enter battery threshold (e.g., 60): " threshold
    # echo $threshold | tee /sys/class/power_supply/BAT0/charge_control_end_threshold
    printf "Battery full energy: "
    cat /sys/class/power_supply/BAT0/energy_full
    printf "\nBattery cuurent energy: "
    cat /sys/class/power_supply/BAT0/energy_now
    printf "\n"
    log "Display battery full and current energy"
}

# Function to Control PC LEDs (ex. CAPS-LOCK LED)
Control_LEDs(){
    read -p "Enter LED state (1/0): " state
    echo $state | tee /sys/class/leds/input*/brightness
    printf "\n"
    log "Set PC LEDs to $state"
}

# Function to serve Devices services
Devices_fun(){
    echo -e "\nSelect your option:"
    echo "1- Change CPU policy"
    echo "2- Display full and cuurent battery energy"
    echo "3- Control PC LEDs (ex. CAPS-LOCK LED)"
    read -n 1 -p "Enter your choice: " option
    printf "\n"

    if [[ $option -eq 1 ]]
        then
            CPU_Policy
    elif [[ $option -eq 2 ]]
        then
            Battery_Info
    elif [[ $option -eq 3 ]]
        then
            Control_LEDs
    fi
}