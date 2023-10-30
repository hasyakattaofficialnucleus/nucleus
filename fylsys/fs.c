// fylsys/fs.c
#include <stdio.h>
#include <string.h>

void create_file(const char *filename) {
    // Create a new file with the given filename.
    FILE *file = fopen(filename, "w");
    if (file) {
        fclose(file);
    } else {
        printf("Failed to create the file.\n");
    }
}

void write_to_file(const char *filename, const char *data) {
    // Write data to the specified file.
    FILE *file = fopen(filename, "a");
    if (file) {
        fprintf(file, "%s", data);
        fclose(file);
    } else {
        printf("Failed to write to the file.\n");
    }
}

void read_file(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file) {
        char buffer[256];  // Adjust buffer size as needed.
        while (fgets(buffer, sizeof(buffer), file) != NULL) {
            printf("%s", buffer);
        }
        fclose(file);
    } else {
        printf("Failed to read the file.\n");
    }
}