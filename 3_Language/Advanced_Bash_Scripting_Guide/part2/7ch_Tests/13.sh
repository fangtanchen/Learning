#!/bin/bash

E_NOARGS=85
E_NOTFOUND=86
E_NOTGZIP=87

if [ $# -eq 0 ]
then
	echo "Usage: `basename $0` filename " >&2
	exit $E_NOARGS
fi

filename=$1

if [ ! -f "$filename" ]
then
	echo "File $filename not found!" >&2
	exit $E_NOTFOUND
fi

if [ ${filename##*.} != "gz" ]
then
	echo "fda"
fi


