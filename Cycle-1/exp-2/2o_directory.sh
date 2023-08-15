#Write a shell script to do the following in order:
#i. Check whether a directory by the name “bash” exist
#ii. If not create one.
#iii. List all the directories.

#!/bin/bash
if [ -d "bash" ]; then
    echo "Directory 'bash' exists."
else
    mkdir "bash"
    echo "Directory 'bash' created."
fi

echo "Listing all directories:"
ls -d */

: '
OUTPUT
alwin@debian:~$ chmod u+x 2o_directory.sh
alwin@debian:~$ ./2o_directory.sh
Directory 'bash' created.
Listing all directories:
bash/	  Documents/  Music/	 Public/     Videos/
Desktop/  Downloads/  Pictures/  Templates/
'
