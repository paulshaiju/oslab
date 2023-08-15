#shell script to generate the Fibonacci series up to n
#!/bin/bash
echo "Enter the limit: "
read n
n1=0
n2=1
echo "Fibonacci series: "
echo $n1
echo $n2
for((i=1;i<n;i++))
do
((n3=$n1+$n2))
((n1=$n2))
((n2=$n3))
echo $n3
done

: '
OUTPUT
alwin@debian:~$ chmod u+x 2i_fibo.sh
alwin@debian:~$ ./2i_fibo.sh
Enter the limit: 
5
Fibonacci series: 
0
1
1
2
3
5
'
