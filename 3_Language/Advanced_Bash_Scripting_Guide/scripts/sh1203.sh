#!/bin/bash

function printit(){
    echo -n "You choice is $1"
}

echo "Print your selection"

case $1 in
    "one")
        printit 1;echo $1 | tr 'a-z'  'A-Z'
        ;;
    "two")
        printit 2;echo $1 | tr 'a-z' 'A-Z'
        ;;
    "three")
        printit 3; echo $1 | tr 'a-z' 'A-Z'
        ;;
    *)
        echo "Usage: $0 {one|two|three}"
        ;;
esac
