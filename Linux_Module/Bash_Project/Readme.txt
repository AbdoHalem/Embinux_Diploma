Bash project

Create an interactive CLI application. With the following requirements

 The application shall have two modes, admin mode and user mode.
Admin mode is active when application is opened with sudo command

The application shall have the following options
System : show following system information using Procfs
	1-CPU info (usage, temperature, frequency)
	2-RAM (usage percentage, used in GB)
	3-DISK (used percentage, free space)
Active for Both modes
 
Devices : show the device in the system with their information and topology from using Sysfs
   	i.Change CPU policy (Optional)
  	ii.Set battery threshold (ex. 60%) (Optional)
 	iii.Control PC LEDs (ex. CAPS-LOCK LED)
Active for Admin mode only
 
(Optional if not VM) Directory Sync over network: user shall specify the target ip and source and target folder to sync the two folders.
Active for both modes

Network : shall log the following information about the system (IP , DNS , download/upload rate)
Active For Both modes

Reboot, shutdown: shall control the system state
Active for Admin mode only

Kernel logs: shall put the kernel log in real time

The application should have an always on log file which saves the logs of the executed buttons and commands. The log file shall reflect the log live and correct

