

decimal=15
octal=017
hex=0x0f

if [ "$decimal" -eq "$octal" ]
then
	echo "eq"
else
	echo "nq"
fi

if [[ "$decimal" -eq "$octal" ]]
then
	echo "eq"
else 
	echo "nq"
fi

