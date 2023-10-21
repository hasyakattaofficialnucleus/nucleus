// nucleus/process.c
#include <stdint.h>
#include "memory_protection.h"

#define MAX_PROCESSES 10

struct Process {
    uint32_t pid;  // Process ID
    int privilege_level;  // Privilege level (nucleus or user)
    void (*entry_point)();  // Process entry point function
};

struct Process process_table[MAX_PROCESSES];
uint32_t next_pid = 1;  // Start at 1 to reserve 0 for the nucleus.

void init_process_manager() {
    // Initialize the process manager.
    // Create the first process (nucleus process) and add it to the table.
    create_process(NUCLEUS_MODE, nucleus_main);
}

uint32_t create_process(int privilege_level, void (*entry_point)()) {
    if (next_pid >= MAX_PROCESSES) {
        return 0;  // Error: Maximum number of processes reached.
    }

    struct Process *new_process = &process_table[next_pid];
    new_process->pid = next_pid;
    new_process->privilege_level = privilege_level;
    new_process->entry_point = entry_point;
    
    next_pid++;
    return new_process->pid;
}

void switch_process(uint32_t pid) {
    // Implement task switching logic.
    // Choose the next process to run and switch to it.
}
