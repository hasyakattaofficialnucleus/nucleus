// nucleus/scheduler.c
#include <stdint.h>
#include "common.h"
#include "process.h"

struct TaskControlBlock {
    uint32_t tid;   // Task ID
    void (*entry_point)();  // Task entry point function
    // Add more task-related data here.
};

struct TaskControlBlock* current_task = NULL;
struct TaskControlBlock* task_list = NULL;

void init_scheduler() {
    // Initialize the task scheduler and create an idle task.
    // Add other tasks to the task list.
}

void create_task(void (*entry_point)()) {
    // Create a new task, allocate a TCB, and initialize its data.
    // Add the task to the task list.
}

void switch_task() {
    // Implement task switching logic.
    // Choose the next task to run and switch to it.
}


int current_process = -1;

void schedule() {
    current_process = (current_process + 1) % process_count;
    // Switch to the next process using context_switch
    context_switch(&processes[current_process]);
}