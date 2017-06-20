#!/bin/bash

echo -e "Please input a filename, I will check the filename's type and permission"
read -p "Input a filename: " filename
test -z $filename && echo "You must input a string" && exit 0

test ! -e $filenmae && echo "$filename not exists" && exit 0

test -f $filename && filetype="regular file"
test -d $filename && filetype="directory file"

test -r $filename && perm="readable"
test -w $filename && perm="writable"
test -x $filename && perm="executable"

echo "The filename $filename is $filetype"
echo "And the permission are : $perm"
