// nucleus/syscall_table.c
#include "syscalls.h"

extern int custom_print(const char *message);

void* sys_call_table[] = {
    [0] = custom_print,
};
