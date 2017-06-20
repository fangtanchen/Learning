#!/bin/bash

declare -i sum=0
declare -i va=0
while [ "$va" -lt "101" ]
do
    sum=$(($sum+$va))
    va=$(($va+1))
done
echo $sum
