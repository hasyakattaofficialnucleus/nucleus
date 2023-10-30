// usr/filesystem_program.c
#include <stdio.h>
#include <string.h>
#include "syscalls.h"
#include "io.h"

void user_task() {
    // File system operations
    syscall(SYS_OPEN, "user_file.txt");
    syscall(SYS_LIST);

    // I/O operations
    putc('H');
    putc('e');
    putc('l');
    putc('l');
    putc('o');
    putc('\n');

    // Input a character from the keyboard
    char input = getc();
    putc(input);
}

int main() {
    init_filesystem();
    init_timer();

    // Set a timer interrupt handler
    set_timer_interrupt_handler(timer_handler);

    // Switch to user mode
    syscall(SYS_SET_PRIVILEGE_LEVEL, USER_MODE);

    // Create a user-mode process that combines file system and I/O operations
    uint32_t user_pid = syscall(SYS_CREATE_PROCESS, user_task);

    // Switch back to nucleus mode
    syscall(SYS_SET_PRIVILEGE_LEVEL, NUCLEUS_MODE);

    // Continue running in nucleus mode

    return 0;
}
