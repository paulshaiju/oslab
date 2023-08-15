#shell script to find the gcd of two numbers
#!/bin/bash
echo "Enter the two number: "
read a
read b
for((i=1;i<=a&&i<=b;++i))
do
if((a%i==0&&b%i==0))
then
gcd=$i
fi
done
echo "GCD: $gcd"

: '
OUTPUT
alwin@debian:~$ chmod u+x 2h_gcd.sh
alwin@debian:~$ ./2h_gcd.sh
Enter the two number: 
5
10
GCD: 5
'
