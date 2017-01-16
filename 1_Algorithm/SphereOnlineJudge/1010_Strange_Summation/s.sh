i=1;
max=110
while [ $i -le $max ]
do
    cat in.txt
    ./g
    cat in.txt |./p
    ./a.out
    i=$(($i+1))
    sleep 1
done
