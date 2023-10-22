#include "process.h"
#include "memory.h"

#define MAX_PROCESSES 10
#define STACK_SIZE 1024 // Adjust stack size as needed

// Process control block structure
typedef struct {
    void* entry_point;
    int pid; // Process ID
    uint8_t stack[STACK_SIZE];
    // Add more process-related data here as needed
} ProcessControlBlock;

// Array to store process control blocks
static ProcessControlBlock pcb[MAX_PROCESSES];

// Number of currently active processes
static int process_count = 0;

// Currently running process
static int current_process = -1;

// Function to create a new process
int create_process(void* entry_point) {
    if (process_count < MAX_PROCESSES) {
        ProcessControlBlock* new_process = &pcb[process_count];
        new_process->entry_point = entry_point;
        new_process->pid = process_count;
        // Initialize other process-related data as needed

        process_count++;

        return new_process->pid;
    }
    // Process creation failed
    return -1;
}

// Function to switch to a different process
void context_switch(int new_pid) {
    if (new_pid < process_count) {
        if (current_process != new_pid) {
            // Save the context of the current process
            if (current_process >= 0) {
                // Implement context saving logic here
                // Save registers, stack pointer, etc.
            }

            // Switch to the new process
            // Implement context restoring logic here
            // Restore registers, stack pointer, etc.
            
            current_process = new_pid;
        }
    }
}

// Multitasking scheduler
void multitasking_scheduler() {
    while (1) {
        // Implement a simple round-robin scheduling algorithm
        for (int i = 0; i < process_count; i++) {
            int next_process = (current_process + 1) % process_count;
            context_switch(next_process);
        }
    }
}
