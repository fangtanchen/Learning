#!/bin/bash

function printit(){
    echo -n "You choice is"
}

echo "Print your selection"

case $1 in
    "one")
        printit;echo $1 | tr 'a-z'  'A-Z'
        ;;
    "two")
        printit;echo $2 | tr 'a-z' 'A-Z'
        ;;
    "three")
        printit; echo $3 | tr 'a-z' 'A-Z'
        ;;
    *)
        echo "Usage: $0 {one|two|three}"
        ;;
esac
