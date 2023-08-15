#shell program to find the sum on the first n numbers using a while loop.
#!/bin/bash
echo "Enter the number: "
read num
i=0
while((i<=num))
do
((sum=sum+i))
((i++))
done
echo "Sum of $num number is: $sum"

: '
OUTPUT
alwin@debian:~$ chmod u+x 2d_sumn.sh
alwin@debian:~$ ./2d_sumn.sh
Enter the number: 
5
Sum of 5 number is: 15
'
