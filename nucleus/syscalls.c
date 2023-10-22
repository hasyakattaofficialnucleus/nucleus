#include "syscalls.h"
#include "process.h"
#include "memory.h"
#include "file_system.h" // You can include a file system module

// Function pointer array for system call handlers
static syscall_handler_t syscall_table[SYSCALL_COUNT];

// Register a system call handler
void register_syscall(int syscall_number, syscall_handler_t handler) {
    if (syscall_number >= 0 && syscall_number < SYSCALL_COUNT) {
        syscall_table[syscall_number] = handler;
    }
}

// Nucleus entry point for system calls
int syscall_handler(int syscall_number, void* arg1, void* arg2, void* arg3) {
    if (syscall_number >= 0 && syscall_number < SYSCALL_COUNT) {
        syscall_handler_t handler = syscall_table[syscall_number];
        if (handler) {
            return handler(arg1, arg2, arg3);
        }
    }
    // Invalid or unsupported system call
    return -1;
}

// Example system call handler for opening a file
int sys_open(void* arg1, void* arg2, void* arg3) {
    const char* filename = (const char*)arg1;
    // Implement file opening logic here, returning a file descriptor
    // You can include the file system module to handle this
    int file_descriptor = file_open(filename);
    return file_descriptor;
}

// Add more system call handlers for read, write, close, and other operations
