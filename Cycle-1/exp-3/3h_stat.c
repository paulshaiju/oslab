/*
Write a C Program to extract File information using stat() system call.
*/
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include <stdio.h>

#include <stdlib.h>
int main(int argc, char *argv[])
{
	struct stat sb;
	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s <pathname>\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	if (stat(argv[1], &sb) == -1)
	{
		perror("stat");
		exit(EXIT_FAILURE);
	}
	printf("File type: ");
	switch (sb.st_mode & S_IFMT)
	{
		case S_IFBLK: printf("block device\n"); break;
		case S_IFCHR: printf("character device\n"); break;
		case S_IFDIR: printf("directory\n"); break;
		case S_IFIFO: printf("FIFO/pipe\n"); break;
		case S_IFLNK: printf("symlink\n"); break;
		case S_IFREG: printf("regular file\n"); break;
		case S_IFSOCK: printf("socket\n"); break;
		default: printf("unknown?\n"); break;
	}
	printf("I-node number: %ld\n", (long) sb.st_ino);
	printf("Mode: %lo (octal)\n",
	(unsigned long) sb.st_mode);

	printf("Link count: %ld\n", (long) sb.st_nlink);
	printf("Ownership: UID=%ld GID=%ld\n",
	(long) sb.st_uid, (long) sb.st_gid);
	printf("Preferred I/O block size: %ld bytes\n",

	(long) sb.st_blksize);
	printf("File size: %lld bytes\n",
	(long long) sb.st_size);
	printf("Blocks allocated: %lld\n",
	(long long) sb.st_blocks);

	printf("Last status change: %s", ctime(&sb.st_ctime));
	printf("Last file access: %s", ctime(&sb.st_atime));
	printf("Last file modification: %s", ctime(&sb.st_mtime));
	exit(EXIT_SUCCESS);
}
/*
* shaiju@Ubuntu:~$ ./a.out threadnum.c
File type: regular file
I-node number: 4748721
Mode: 100664 (octal)
Link count: 1
Ownership: UID=1000 GID=1000
Preferred I/O block size: 4096 bytes
File size: 1223 bytes
Blocks allocated: 8
Last status change: Sat Mar 18 07:45:00 2023
Last file access: Sat Mar 18 07:45:00 2023
Last file modification: Sat Mar 18 07:45:00 2023
*
* shaiju@Ubuntu:~$ ./a.out dir
File type: directory
I-node number: 4719395
Mode: 40775 (octal)
Link count: 2
Ownership: UID=1000 GID=1000
Preferred I/O block size: 4096 bytes
File size: 4096 bytes
Blocks allocated: 8
Last status change: Sun May 8 10:46:52 2022
Last file access: Sat Mar 18 06:47:31 2023
Last file modification: Sun May 8 10:46:52 2022
*/
