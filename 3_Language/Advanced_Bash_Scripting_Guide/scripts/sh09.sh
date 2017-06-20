#!/bin/bash

if [ "$1" == "hello" ];then
    echo "Hello,how are you?"
elif [ "$1" == "" ];then
    echo "please input a parameter"
else
    echo "please input hello"
fi
