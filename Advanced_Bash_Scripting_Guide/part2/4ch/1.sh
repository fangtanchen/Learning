#!/bin/bash

a=375
hello=$a

echo hello

echo $hello

echo ${hello}

echo "$hello"

echo "${hello}"

echo

hello="A B C  D"
echo $hello
echo "$hello"
echo

echo '$hello'
hello=
echo "\$hello (null value) = $hello"

var1=21 var2=22 var3=23
echo
echo "var1=$var1 var2=$var2 var3=$var3"

echo; echo

number="one two three"
other_numbers="1 2 3"
echo "numbers=$number"
echo "other_numbers=$other_numbers"

mixed_bag=2\ --- \ Whatever
echo "$mixed_bag"
echo; echo

echo "uninit=$uninit"
uninit=

echo "uninit=$uninit"
if [ -z "$uninit" ]
then
	echo "\$uninit is NULL"
fi
