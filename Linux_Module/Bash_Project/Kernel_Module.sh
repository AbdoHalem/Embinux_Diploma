# Function to display the kernel logs in real time
Kernel_logs_fun(){
    echo -e "Displaying kernel logs in real-time (press Ctrl+C to stop):\n"
    log "Displaying kernel logs in real-time"
    # Trap the SIGINT signal and call handle_interrupt
    trap handle_interrupt SIGINT
    # Start tailing the kernel logs
    tail -f /var/log/kern.log
    # Remove the trap after tailing
    trap - SIGINT
    printf "\n" 
}

# Function to handle the SIGINT signal (Ctrl+C)
handle_interrupt() {
    echo -e "\nExiting kernel logs view..."
    log "Exited kernel logs view"
    return 0
}