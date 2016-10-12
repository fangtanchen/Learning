#!/bin/bash

echo "example"
for i in "$*";do
    echo $i
    echo 1
done

for i in "$@";do
    echo $i
    echo 1
done
