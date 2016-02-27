#!/bin/sh
echo

if test -z "$1"
then
	echo "no command "
else
	echo "$1."
fi

echo

if /usr/bin/test -z "$1"
then
	echo "no"
else
	echo "yes"
fi

echo

if [ -z "$1" ]
then
	echo "yes"
else
	echo "no"
fi

if /usr/bin/[ -z "$1"]
then
	echo "yes"
else
	echo "no"
fi

echo

exit 0

