read -p "Please input your demobilization date (YYYYMMDD):" date2
date_d=$(echo $date2|grep '[0-9]\{8\}')
if [ "date_d" == "" ];then
    echo "wrong date"
    exit 1
fi

declare -i date_dem=`date --date="$date2" +%s`
declare -i date_now=`date +%s`
declare -i date_total_s=$(($date_dem-$date_now))
declare -i date_d=$(($date_total_s/60/60/24))

if [ "$date_total_s" -lt "0" ];then
    echo "Your had been demobilization before"
else 
    declare -i date_h=$(($(($date_total_s-$date_d*60*24*60))/60/60))
    echo "$date_d days and $date_h hours"
fi
