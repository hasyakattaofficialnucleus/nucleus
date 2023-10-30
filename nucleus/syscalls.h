#ifndef SYSCALLS_H
#define SYSCALLS_H

#define SYS_GET_TIME 1

typedef struct {
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int second;
} TimeInfo;

int handle_syscall(int syscall_number, void* params);

#endif

