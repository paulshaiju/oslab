#shell script to find the average of n numbers.
#!/bin/bash
echo "Enter the limit: "
read n
for((i=1;i<=n;i++))
do
((sum=sum+i))
done
((avg=sum/n))
echo "Average: $avg"

: '
OUTPUT
alwin@debian:~$ chmod u+x  2k_avg.sh
alwin@debian:~$ ./2k_avg.sh
Enter the limit: 
5
Average: 3
'
