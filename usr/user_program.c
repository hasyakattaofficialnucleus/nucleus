#include <stdio.h>
#include "syscalls.h"

// User process entry point
void user_process() {
    printf("User process is running!\n");
    // Implement some work here
}

int main() {
    // Create multiple user processes
    int pid1 = syscall(SYS_CREATE_PROCESS, user_process);
    int pid2 = syscall(SYS_CREATE_PROCESS, user_process);

    if (pid1 < 0 || pid2 < 0) {
        printf("Process creation failed\n");
        return -1;
    }

    // Run the multitasking scheduler
    syscall(SYS_SET_PRIVILEGE_LEVEL, KERNEL_MODE);
    multitasking_scheduler();

    return 0;
}
