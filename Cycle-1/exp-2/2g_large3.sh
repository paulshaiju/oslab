#shell script to find the largest among the three numbers inputted
#!/bin/bash
echo "a: "
read a
echo "b: "
read b
echo "c: "
read c
echo "Largest: "
if((a>b && a>c))
then
echo $a
elif((b>c && b>a))
then
echo $b
else
echo $c
fi

: '
OUTPUT
alwin@debian:~$ chmod u+x 2f_large3.sh
alwin@debian:~$ ./2f_large3.sh
a: 
5
b: 
6
c: 
1
Largest: 
6
'
