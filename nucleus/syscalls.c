#include "syscall.h"
#include "process.h"

// Handle system calls
int handle_syscall(int syscall_num, int param1, int param2, int param3) {
    int result = 0;

    switch (syscall_num) {
        case SYS_OPEN:
            // Handle open file system call
            break;

        case SYS_CREATE_PROCESS:
            // Handle process creation system call
            // For simplicity, we'll assume 'param1' is a function pointer
            result = create_process((void (*)())param1);
            break;

        // Add more system calls as needed

        default:
            result = -1;  // Unknown system call
    }

    return result;
}
