// Documentation location: https://sourceware.org/newlib/libc.html#Introduction
// This is running on baremetal and Newlib requires these system calls to be implemented for the library
// Using default implementations since there isn't any being used. An error code is a graceful failure
#include <errno.h>
#undef errno
extern int errno;

int _close(int fd)
{
	// No filesystem implementation
	return -1;
}

void _exit()
{
	// No implementation
	while(1) ;
}

int _lskeek(int file, int ptr, int dir)
{
	// No filesystem implementation
	return 0;
}

int read(int file, char *ptr, int len)
{
	// No filesystem implementation
	return 0;
}

int write(int file, char *ptr, int len)
{
	// No filesystem implementation
	return 0;
}

int sbrk(
