#!/bin/bash

echo "program name $0"
echo "parameter number $#"

[ "$#" -lt 2 ] && echo "parameter is not enough, Stop" && exit 0
echo "$@"
echo "$1"
echo "$2"
