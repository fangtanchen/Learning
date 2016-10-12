#!/bin/bash

for file in $(ls /etc); do
    echo $file
done

for file in `ls .`; do
    echo $file
done
