# Function to synchronize two directories of two machines over network 
Directory_Sync_fun(){
    read -p "Enter target IP: " ip
    read -p "Enter source folder: " src
    read -p "Enter target folder: " tgt
    rsync -avz $src $ip:$tgt
    log "Synced $src to $ip:$tgt"
}