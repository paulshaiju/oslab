#shell program to swap two numbers
#!/bin/bash
echo "Enter the first number: "
read n1
echo "Enter the second number: "
read n2
swap=$n1
n1=$n2
n2=$swap
echo "After n1 = $n1 and n2 = $n2"

: '
OUTPUT
alwin@debian:~$ chmod u+x 2b_swap.sh
alwin@debian:~$ ./2b_swap.sh
Enter the first number: 
5
Enter the second number: 
8
After n1 = 8 and n2 = 5 
'
