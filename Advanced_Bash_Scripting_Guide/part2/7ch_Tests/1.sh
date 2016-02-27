#!/bin/bash

(( 0&&1 ))
echo $?

let "num=(( 0&&1 ))"
echo $num

let "num=(( 0&&1 ))"
echo $?

(( 200||11 ))
echo $?

let "num=(( 200||11 ))"
echo $?

let "num=((200||11))"
echo $num

