#!/bin/bash
LOG_DIR=~/

time > test1.log
date >> test1.log
who >>  test1.log
uptime >>  test1.log
echo "Save the system times"
cat test1.log
