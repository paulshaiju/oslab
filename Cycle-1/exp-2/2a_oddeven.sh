#shell program to find odd or even number
#!/bin/bash
echo "Enter the number: "
read n
if(($n%2 == 0))
then
echo "$n is even"
else
echo "$n is odd"
fi

#OUTPUT
#alwin@debian:~$ chmod u+x 2a_oddeven.sh
#alwin@debian:~$ ./2a_oddeven.sh
#Enter the number: 
#5
#5 is odd

