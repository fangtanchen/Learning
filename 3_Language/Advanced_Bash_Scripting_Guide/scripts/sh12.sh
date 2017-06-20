#!/bin/bash

read -p "input your choice: " choice

case $choice in
    "one")
        echo "$choice"
        ;;
    "two")
        echo "$choice"
        ;;
    "three")
        echo "$choice"
        ;;
    *)
        echo "Usage: $0 {one|two|three}"
        ;;
esac
