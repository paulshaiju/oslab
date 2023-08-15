#shell program to implement a basic calculator.
#!/bin/bash
echo "Enter the two number: "
read a
read b
echo "Enter choice: "
echo "1.ADD"
echo "2.SUBSTRACT"
echo "3.MULTIPLY"
echo "4.DIVIDE"
read ch
case $ch in
1)((res=a+b))
echo "SUM: $res";;
2)((res=a-b))
echo "DIFFERENCE: $res";;
3)((res=a*b))
echo "MULTIPLY: $res";;
4)((res=a/b))
echo "DIVISION: $res";;
*)
echo "INVALID CHOICE";;
esac

: '
OUTPUT
alwin@debian:~$ chmod u+x 2e_cal.sh
alwin@debian:~$ ./2e_cal.sh
Enter the two number: 
5
2
Enter choice: 
1.ADD
2.SUBSTRACT
3.MULTIPLY
4.DIVIDE
3
MULTIPLY: 10
'
