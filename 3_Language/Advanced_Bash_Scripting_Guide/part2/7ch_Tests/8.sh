device0="/dev/sda2"
if [ -b "$device0" ]
then
	echo "block device"
fi

device1="/dev/ttyS1"
if [ -c $device1 ]
then
	echo "character device."
fi
