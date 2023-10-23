#include "syscalls.h"
#include "timer.h"

// Implement the get_time system call
int get_time(TimeInfo* time_info) {
    // Get the current time and date from the timer module
    if (get_current_time(time_info) == 0) {
        return 0; // Success
    }
    return -1; // Error getting time
}
