#!/bin/bash
# Simple system information script

# Hostname information
echo "***** HOSTNAME INFORMATION *****"
hostnamectl
echo ""

# File system disk space usage
echo "***** FILE SYSTEM DISK SPACE USAGE *****"
df -h
echo ""

# Free and used memory
echo "***** FREE AND USED MEMORY *****"
free -h
echo ""

# System uptime and load
echo "***** SYSTEM UPTIME AND LOAD *****"
uptime
echo ""

# Currently logged-in users
echo "***** CURRENTLY LOGGED-IN USERS *****"
who
echo ""

# Top 5 memory-consuming processes
echo "***** TOP 5 MEMORY-CONSUMING PROCESSES *****"
ps -eo %mem,%cpu,comm --sort=-%mem | head -n 6
echo ""

echo "Done."
