#include "syscall.h"
#include "filesystem.h"

// Handle system calls
int handle_syscall(int syscall_num, int param1, int param2, int param3) {
    int result = 0;

    switch (syscall_num) {
        case SYS_OPEN:
            result = open_file((char*)param1);
            break;

        case SYS_READ:
            result = read_file(param1, (char*)param2, param3);
            break;

        case SYS_WRITE:
            result = write_file(param1, (char*)param2, param3);
            break;

        case SYS_CLOSE:
            result = close_file(param1);
            break;

        // Add more system calls as needed

        default:
            result = -1;  // Unknown system call
    }

    return result;
}
