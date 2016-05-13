command_test(){ type "$1" &>/dev/null; }

cmd=rmdir
command_test $cmd; echo $?

cmd=bogus_command
command_test $cmd; echo $?
