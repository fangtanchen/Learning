#!/bin/bash

your_name="qinjx"
echo $your_name
echo ${your_name}

for skill in Ada Coffe Action Java; do
    echo "I am good at ${skill}Script"
done

string="abcd"
echo ${#string}

string="runoob is a great site"
echo ${string:1:4}
