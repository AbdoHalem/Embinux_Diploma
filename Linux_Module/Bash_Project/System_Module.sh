#!/bin/bash
# System module to show following system information using Procfs
# 1- CPU info (usage, temperature, frequency)
# 2- RAM (usage percentage, used in GB)
# 3- DISK (used percentage, free space)


CPU_Info(){
    printf "\n"
    # Display CPU usage
    echo "CPU Usage:"
    top -bn1 | grep "Cpu(s)" | awk '{print "Usage: " $2 + $4 "%\n"}'
    # Display CPU temperature is not supported at virtualbox
    # so it is replaced by display CPU caches
    echo "CPU Usagcache memory:"
    lscpu | grep 'cache'
    # sensors | grep 'Package id 0:' | awk '{print $4} "\n"'
    # Display CPU frequency
    echo -e "\nCPU Frequency:"
    cat /proc/cpuinfo | grep 'MHz' | \
    awk 'BEGIN {i=0} {print "Processor " i " Frequency: " $4 " MHz"; i++}'
    printf "\n"
    log "Display the CPU info"
}


RAM_Info(){
    printf "\n"
    echo "RAM Usage:"
    free -h
    printf "\n"
    log "Display the RAM info"
}

DISK_Info(){
    printf "\n"
    echo "Disk Usage:"
    df -h
    printf "\n"
    log "Display the Disk info"
}

System_fun(){
    echo -e "\nSelect your option:"
    echo "1- CPU info (usage, temperature, frequency)"
    echo "2- RAM (usage percentage, used in GB)"
    echo "3- DISK (used percentage, free space)"
    read -n 1 -p "Enter your choice: " option
    printf "\n"

    if [[ $option -eq 1 ]]
        then
            CPU_Info
    elif [[ $option -eq 2 ]]
        then
            RAM_Info
    elif [[ $option -eq 3 ]]
        then
            DISK_Info
    fi
}
