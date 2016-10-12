#!/bin/bash
#Proper header for a Bash script

LOG_DIR=/var/log
#Variables are better than hard-coded values
cd $LOG_DIR

cat /dev/null>messages
cat /home/fangtanchen/1.txt>wtmp

echo "Logs cleaned up."
exit
