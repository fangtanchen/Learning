#!/bin/bash

a=4
b=5

echo

if [ "$a" -ne "$b" ]
then
	echo "$a is not equal to $b"
	echo "(arithmetic comparison)"
fi

if [ "$a" != "$b" ]
then
	echo "$a is not equal to $b."
	echo "(string comparison)"
fi

echo
exit 0
