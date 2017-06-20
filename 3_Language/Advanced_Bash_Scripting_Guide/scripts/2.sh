#!/bin/bash
read -p "Please input your birthday: " bir
now=`date +%m%d`
if [ "$bir" == "$now" ];then
    echo "Happy birthday to you!!!"
elif [ "$bir" -gt "$now"  ];then
    year=`date +%Y`
    total_d=$(($((`date --date="$year$bir" +%s`-`date +%s`))/3600/24))
    echo "You birthday will be $total_d later"
else
    year=$((`date +%Y`+1))
    total_d=$(($((`date --date="$year$bir" +%s`-`date +%s`))/60/60/24))
    echo "Your birthday will be $total_d later"
fi
