#include <stdio.h>
#include "syscalls.h"

int main() {
    TimeInfo time_info;

    // Request the current time and date from the system
    int result = syscall(SYS_GET_TIME, &time_info);

    if (result == 0) {
        printf("Current Time: %02d:%02d:%02d\n", time_info.hour, time_info.minute, time_info.second);
        printf("Current Date: %04d-%02d-%02d\n", time_info.year, time_info.month, time_info.day);
    } else {
        printf("Error getting time from the system.\n");
    }

    return 0;
}
