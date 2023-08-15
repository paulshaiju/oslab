#shell program to convert celcius to fahrenheit heat
#!/bin/bash
echo "Enter the temperature in celcius heat: "
read celcius
((farenh = celcius*(9/5)+32))
echo "Fahrenheit: $farenh"

: '
OUTPUT
alwin@debian:~$ chmod u+x 2e_fahren.sh
alwin@debian:~$ ./2e_fahren.sh
Enter the temperature in celcius heat: 
50
Fahrenheit: 82

'
