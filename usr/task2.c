// usr/task2.c
#include <stdio.h>

void task2() {
    while (1) {
        printf("Task 2 is running!\n");
        // Add some delay to simulate work.
    }
}

int main() {
    create_task(task2);
    // No need to call switch_task here, as it's already running from task1's main.
    return 0;
}
