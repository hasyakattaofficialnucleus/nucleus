#include <stdio.h>
#include "syscalls.h"
#include "filesystem.h"

int main() {
    // Initialize the file system
    init_filesystem();

    // Create a new file
    create_file("my_file.txt");

    // Write data to the file
    const char* data_to_write = "Hello, this is my file!";
    write_file("my_file.txt", data_to_write, strlen(data_to_write));

    // Read data from the file
    char data_read[1024];
    int read_size = read_file("my_file.txt", data_read, sizeof(data_read));

    if (read_size > 0) {
        data_read[read_size] = '\0'; // Null-terminate for printing
        printf("Read from file: %s\n", data_read);
    } else {
        printf("Error reading file.\n");
    }

    return 0;
}
