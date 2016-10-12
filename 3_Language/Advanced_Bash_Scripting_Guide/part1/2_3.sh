#!/bin/bash
#Cleanup, version 3

#Warning:
#----
# This script use quite a number of features that will be explained
# later on.
# By the time you've finished the first half of the book,
# there would be nothing mysterious about it

LOG_DIR=/var/log
ROOT_UID=0	#only users with $UID 0 have root privileges
LINES=50	#Default number of lines saved.
E_XCD=86	#Can't change directory?
E_NOTROOT=87	#Non-root exit error

#Run as root, of course
if ["$UID" -ne "$ROOT_UID"]
then
	echo "Must be root to run this script."
	exit $E_NOTROOT
fi

if [-n "$1"]
# Test whether command-line argument is present(non-empty)
then
	lines=$1
else
	lines=$LIINES
fi

cd $LOG_DIR

if [`pwd`!="$LOG_DIR"]
then
	echo "Can't change to $LOG_DIR."
	exit $E_XCD
fi	#Doublecheck if in right directory before missing with log file

tail -n $lines message > mesg.temp	#save last section of message log file
mv mesg.temp messages
cat /dev/null > wtmp
echo "Log files cleaned up."
exit 0
