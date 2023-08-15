#shell script to print given three alphabets in alphabetical order. (Input should be taken from the command line.)
#!/bin/bash
alpha1='E'
alpha2='A'
alpha3='G'
if [[ $alpha1 > $alpha2 ]]; then
    temp=$alpha1
    alpha1=$alpha2
    alpha2=$temp
fi

if [[ $alpha1 > $alpha3 ]]; then
    temp=$alpha1
    alpha1=$alpha3
    alpha3=$temp
fi

if [[ $alpha2 > $alpha3 ]]; then
    temp=$alpha2
    alpha2=$alpha3
    alpha3=$temp
fi
echo "The alphabets in alphabetical order are: $alpha1 $alpha2 $alpha3"

: '
OUTPUT
alwin@debian:~$ chmod u+x 2l_alphagr.sh
alwin@debian:~$ ./2l_alphagr.sh
The alphabets in alphabetical order are: A E G
'
