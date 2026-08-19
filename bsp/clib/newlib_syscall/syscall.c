// Documentation location: https://sourceware.org/newlib/libc.html#Introduction
// This is running on baremetal and Newlib requires these system calls to be implemented for the library
// Using default implementations since there isn't any being used. An error code is a graceful failure
#include <errno.h>
#include <stdint.h>
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
	// Can be used to read from UART, but it's not implemented
	return 0;
}

int _write(int fd, const void *buf, size_t cnt)
{
	// No filesystem implementation
	// Can be used to write to UART, but it's not implemented
	return 0;
}

extern uint32_t _stack_start;
extern uint32_t _heap_start;

// Used for memory allocation. Implementation from document above
int _sbrk(ptrdiff_t incr)
{
  static uint32_t *heap_end;
  uint32_t *prev_heap_end;
  uint32_t stack_ptr;
 
  // Nullptr
  if (heap_end == 0) 
  {
	// At init heap is empty. Start of heap is end of heap.
	// Initialize it  
	heap_end = &_heap_start;
  }
  prev_heap_end = heap_end;
  
  // Use inline assembly to find the current top of stack
  __asm volatile ("mrs %0, msp" : "=r"(stack_ptr));
  
  if (heap_end + incr > stack_ptr) 
  {
    // Heap collided into stack. Do not allocate memory. Return
    return -1;
  }

  heap_end += incr;
  
  // Return the old end of heap
  return (int)prev_heap_end;
}
