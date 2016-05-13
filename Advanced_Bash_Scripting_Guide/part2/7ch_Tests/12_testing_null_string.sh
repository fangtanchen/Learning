#!/bin/bash

if [ -n $string1 ]
then
	echo "not null"
else
	echo "null"
fi

echo


if [ -n "$string1" ]
then
	echo "not null"
else 
	echo "null"
fi

if [ $string1 ]
then
	echo "not null"
else
	echo "null"
fi

echo

string1=initialized

if [ $string1 ]
then
	echo "not null"
else
	echo "null"
fi

string1="a=b"
if [ $string1 ]
then
	echo "not null"
else
	echo "null"
fi
