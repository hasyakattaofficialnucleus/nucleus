#ifndef SYSCALLS_H
#define SYSCALLS_H

#define SYSCALL_COUNT 64

typedef int (*syscall_handler_t)(void*, void*, void*);

// Define system call numbers
#define SYS_OPEN 0
#define SYS_READ 1
#define SYS_WRITE 2
#define SYS_CLOSE 3

// Add more system call numbers as needed

#endif
