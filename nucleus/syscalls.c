// nucleus/syscalls.c
#include <stdio.h>
#include <string.h>
#include "process.h"
#include "memory.h"
#include "filesystem.h"

// Define system call numbers
#define SYS_OPEN 1
#define SYS_DELETE 2
#define SYS_LIST 3
#define SYS_SET_PRIVILEGE_LEVEL 4
#define SYS_CREATE_PROCESS 5
#define SYS_TERMINATE_PROCESS 6
#define SYS_ALLOCATE_MEMORY 7
#define SYS_DEALLOCATE_MEMORY 8

int syscall(int syscall_number, char *arg) {
    switch (syscall_number) {
        case SYS_OPEN:
            create_file(arg);
            return 0;  // Success
        case SYS_DELETE:
            delete_file(arg);
            return 0;  // Success
        case SYS_LIST:
            list_directory();
            return 0;  // Success
        case SYS_SET_PRIVILEGE_LEVEL:
            set_privilege_level(*arg);  // arg should contain the privilege level
            return 0;  // Success
        case SYS_CREATE_PROCESS:
            return create_process(USER_MODE, *arg);  // arg should contain the process entry point
        case SYS_TERMINATE_PROCESS:
            terminate_process(*arg);  // arg should contain the process ID
            return 0;  // Success
        case SYS_ALLOCATE_MEMORY:
            return (int)allocate_memory(*arg);  // arg should contain the size
        case SYS_DEALLOCATE_MEMORY:
            deallocate_memory((void*)*arg);  // arg should contain the address
            return 0;  // Success
        case SYS_CREATE_PROCESS:
            return create_process(arg);  // arg should contain the process entry point
        case SYS_TERMINATE_PROCESS:
            terminate_process(*arg);  // arg should contain the process ID
            return 0;  // Success
        default:
            return -1;  // Error: Invalid system call number
    }
}
