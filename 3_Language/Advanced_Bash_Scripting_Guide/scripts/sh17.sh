#!/bin/bash

network="192.168.1"

for sitenu in $(seq 1 10)
do
    echo "$network.$sitenu"
    ping -c 1 -w 1 $network.$sitenu &> /dev/null && result=0 || result=1

    if [ "$result" == "0" ];then
        echo "Server $network.$sitenu is UP"
    elif [ "$result" == "1" ];then
        echo "Server $network.$sitenu is Down"
    fi
done
