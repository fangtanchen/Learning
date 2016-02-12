#!/bin/bash
#Proper header for a Bash script.
#Cleanup, version 2

LOG_DIR=/var/log
#Variables are better than hard-coded values
cd $LOG_DIR

cat /dev/null > messages
cat /dev/null > wtmp
echo "Logs cleaned up."
exit

