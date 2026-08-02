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

void _exit(int code)
{
	// No implementation
	while(1) ;
}

int _lseek(int fd, _off_t pos, int whence)
{
	// No filesystem implementation
	return 0;
}

int _read(int fd, void *buf, size_t cnt)
{
	// No filesystem implementation
	return 0;
}

int _write(int fd, const void *buf, size_t cnt)
{
	// No filesystem implementation
	return 0;
}

// Used for memory allocation. Implementation from document above
int _sbrk(ptrdiff_t incr)
{
  extern char _end;		/* Defined by the linker */
  static char *heap_end;
  char *prev_heap_end;
 
  if (heap_end == 0) {
    heap_end = &_end;
  }
  prev_heap_end = heap_end;
  
  // Not sure where stack_ptr is meant to be defined. 
  // Commenting out for now. But this is meant to be a guard.
  //if (heap_end + incr > stack_ptr) {
  //  abort ();
  //}

  heap_end += incr;
  return (int)prev_heap_end;
}
