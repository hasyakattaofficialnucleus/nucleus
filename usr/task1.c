// usr/task1.c
#include <stdio.h>

void task1() {
    while (1) {
        printf("Task 1 is running!\n");
        // Add some delay to simulate work.
    }
}

int main() {
    init_scheduler();
    create_task(task1);
    switch_task();  // Start the task scheduler.
    return 0;
}
