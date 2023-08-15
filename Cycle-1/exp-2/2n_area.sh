#Write a shell script to perform the following task according to the user choice menu.                             
#i. Area of Circle
#ii. Circumference of Circle
#iii. Area of Rectangle
#iv. Area of Square

#!/bin/bash
echo "Please select an option:"
echo "1. Area of Circle"
echo "2. Circumference of Circle"
echo "3. Area of Rectangle"
echo "4. Area of Square"
read choice

case $choice in
    1)
        echo "Enter the radius of the circle:"
        read radius
        ((area=(22/7)*radius*radius))
        echo "The area of the circle is: $area"
        ;;
    2)
        echo "Enter the radius of the circle:"
        read radius
        ((circumference=2 * (22/7) * radius))
        echo "The circumference of the circle is: $circumference"
        ;;
    3)
        echo "Enter the length and width of the rectangle:"
        read length
	read  width
        ((area=length * width))
        echo "The area of the rectangle is: $area"
        ;;
    4)
        echo "Enter the length of the square:"
        read length
        ((area=length * length))
        echo "The area of the square is: $area"
        ;;
    *)
        echo "Invalid choice. Please select an option from the menu."
        ;;
esac

: '
OUTPUT
alwin@debian:~$ chmod u+x 2n_area.sh
alwin@debian:~$ ./2n_area.sh
Please select an option:
1. Area of Circle
2. Circumference of Circle
3. Area of Rectangle
4. Area of Square
1
Enter the radius of the circle:
6
The area of the circle is: 108
'
