#shell program to find the factorial of a number using for loop
#!/bin/bash
echo "Enter the number: "
read num
fact=1
for((i=1;i<=num;i++))
do
((fact=fact*i))
done
echo "Factorial of $num is  $fact"

: '
OUTPUT
alwin@debian:~$ chmod u+x 2c_fact.sh
alwin@debian:~$ ./2c_fact.sh
Enter the number: 
5
Factorial of 5 is  120
'
