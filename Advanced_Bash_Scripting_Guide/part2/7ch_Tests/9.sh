function show()
{
	[ -p /dev/fd/0 ] && echo PIPE || echo STDIN
}

show "Input"
echo "Input" | show
