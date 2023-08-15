#shell script to print the given three strings in dictionary order.
#!/bin/bash
echo "Enter three strings:"
read str1
read str2
read str3
if [[ "$str1" > "$str2" ]]; then
    temp="$str1"
    str1="$str2"
    str2="$temp"
fi

if [[ "$str1" > "$str3" ]]; then
    temp="$str1"
    str1="$str3"
    str3="$temp"
fi

if [[ "$str2" > "$str3" ]]; then
    temp="$str2"
    str2="$str3"
    str3="$temp"
fi

echo "The strings in dictionary order are: $str1 $str2 $str3"

: '
OUTPUT
alwin@debian:~$ chmod u+x 2m_stringsort.sh
alwin@debian:~$ ./2m_stringsort.sh
Enter three strings:
cat  
apple
bat
The strings in dictionary order are: apple bat cat
'
