var1=20
var2=22

[ "$var1" -ne "$var2" ] && echo "$var1 is neq to $var2"

home=/home/fangtanche1n
[ -d "$home" ] || echo "not exits"
