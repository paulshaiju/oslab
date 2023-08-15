/*IMPLEMENTATION OF OPENDIR AND READDIR SYSTEM CALLS
AIM:
To write a program for implementing Directory management using the following system calls of
UNIX operating system: opendir, readdir.
ALGORITHM:
STEP 1: Start the program.
STEP 2: Create struct dirent.
STEP 3: declare the variable buff and pointer dptr.
STEP 4: Get the directory name.
STEP 5: Open the directory.
STEP 6: Read the contents in directory and print it.
STEP 7: Close the directory.
*System Calls used :
DIR *opendir(const char *name) - open a directory
struct dirent *readdir(DIR *dirp) - read a directory
struct dirent {
ino_t d_ino; ///inode number
off_t d_off; //offset to the next dirent
unsigned short d_reclen; //length of this record
unsigned char d_type; // type of file; not supported by all file system types
char d_name[256]; // filename
}

*/
#include<sys/types.h>
#include<dirent.h>
#include<stdio.h>
int main(int c, char* arg[])
{
	DIR *d;
	struct dirent *r;
	int i=0;
	d=opendir(arg[1]);
	printf("\n\t NAME OF ITEM \n");
	while((r=readdir(d)) != NULL)
	{
		printf("\t %s \n",r->d_name);
		i=i+1;
	}
	closedir(d);
	printf("\n TOTAL NUMBER OF ITEM IN THE DIRECTORY IS %d \n",i);
	return 0;
}
/* Compilation and Execution Step:
gcc dirlist.c -o dirlist
./dirlist /home/shaiju
NAME OF ITEM
.viminfo
thread2
.bashrc
linux-brprinter-installer-2.2.3-1.gz
...
...
TOTAL NUMBER OF ITEM IN THE DIRECTORY IS 177
*/
