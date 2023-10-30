// usr/my_program.c
#include <stdio.h>
#include <syscall.h>
#include <string.h>

int main() {
    // System call to print a message
    char message[] = "Hello from user-space!\n";
    syscall(0, message);

    // File system operations
    char filename[] = "my_file.txt";
    char data[] = "This is some data.\n";

    // Create a file
    create_file(filename);

    // Write data to the file
    write_to_file(filename, data);

    return 0;
}
