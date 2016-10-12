#!/bin/bash

if cmp a b &> /dev/null
then
	echo "Files a and b are identical."
else
	echo "Files a and b differs."
fi

if grep -q Bash a
then echo "File contains."
fi

word=Linux
letter=inu
if echo "$word" | grep -q "$letter"
then
	echo "found the letter"
else
	echo "not found"
fi

if DJDFKLJDSL
then 
	echo "no command"
else
	echo "yes"
fi
