#shell script to check whether a given number is prime or not
#!/bin/bash
echo "Enter the number: "
read num
flag=1
for((i=2;i<num/2;i++))
do
if((num%i==0))
then
flag=0
fi
done
if((flag==0))
then
echo "Not prime"
else
echo "Prime"
fi

: '
OUTPUT
alwin@debian:~$ chmod u+x 2j_prime.sh
alwin@debian:~$ ./2j_prime.sh
Enter the number: 
5
Prime
'
