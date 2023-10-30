// usr/simple_shell.c
#include <stdio.h>
#include <string.h>

int main() {
    char command[100];
    while (1) {
        printf("Shell> ");
        fgets(command, sizeof(command), stdin);
        command[strlen(command) - 1] = '\0';  // Remove the newline character.

        if (strcmp(command, "exit") == 0) {
            printf("Shell is exiting.\n");
            break;
        }

        // Add code to parse and execute commands here.
        // Example: if (strcmp(command, "hello") == 0) { printf("Hello, World!\n"); }
    }

    return 0;
}
