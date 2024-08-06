Network_fun(){
    printf "\nIP Address: "
    hostname -I
    dns_servers=$(grep 'nameserver' /etc/resolv.conf | awk '{print $2}')
    echo "DNS Servers: $dns_servers"
    echo "Network Usage: "
    ifstat -i enp0s3 1 1
    # Replace 'eth0' with the appropriate network interface name
    printf "\n"
    log "Display network IP, DNS and download/upload rate"
}

