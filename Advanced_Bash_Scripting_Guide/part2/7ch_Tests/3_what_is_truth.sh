#!/bin/sh

echo

echo "Testing \"0\""
if [ 0 ]
then
	echo "0 is true"
else
	echo "o is false"
fi

echo "Testing \"1\""
if [ 1 ]
then
	echo "1 is true"
else
	echo "1 is false"
fi

echo

echo "Testing \"-1\""
if [ -1 ]
then
	echo "-1 is true"
else
	echo "-1 is false"
fi

echo

echo "Testing \"NULL\""
if [ ]
then 
	echo "null is true"
else
	echo "null is false"
fi
echo

echo "Testing \"xyz\""
if [ xyz ]
then
	echo "xyz is true"
else
	echo "xya is false"
fi

echo

echo "Testing \"$xyz\""
if [ $xyz ]
then
	echo "uninitialized variable is true."
else
	echo "uninitialized vairiable is false"
fi

echo

exit 0



