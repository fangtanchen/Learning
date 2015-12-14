#!/bin/sh

for i in 1 2 3 4 5 6 7 8 9 10
do
	echo -n "$i "
done & # Run this loop in background,
	# Will sometimes execute after second loop

echo

for i in 11 12 13 14 15 16 17 18 19 20 # Second loop.
do
	echo -n "$i "
done
echo

exit 0


