#!/bin/bash

users=$(cut -d ':' -f1 /etc/passwd)
i=1
for us in $users
do
    echo "The $i account is \" $us \""
    i=$(($i+1))
done
