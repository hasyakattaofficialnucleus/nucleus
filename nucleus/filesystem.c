#include "filesystem.h"

#define MAX_FILES 100
#define MAX_FILENAME_LENGTH 32
#define MAX_FILE_SIZE 1024

// File structure
typedef struct {
    char filename[MAX_FILENAME_LENGTH];
    char data[MAX_FILE_SIZE];
    int size;
} File;

// File system structure
typedef struct {
    File files[MAX_FILES];
    int file_count;
} FileSystem;

// Global file system instance
static FileSystem file_system;

// Initialize the file system
void init_filesystem() {
    file_system.file_count = 0;
}

// Create a new file
int create_file(const char* filename) {
    if (file_system.file_count < MAX_FILES) {
        File* new_file = &file_system.files[file_system.file_count];
        strncpy(new_file->filename, filename, MAX_FILENAME_LENGTH);
        new_file->size = 0;
        file_system.file_count++;
        return 0; // File created successfully
    }
    return -1; // File system full
}

// Write data to a file
int write_file(const char* filename, const char* data, int size) {
    for (int i = 0; i < file_system.file_count; i++) {
        File* file = &file_system.files[i];
        if (strcmp(file->filename, filename) == 0) {
            if (size <= MAX_FILE_SIZE) {
                strncpy(file->data, data, size);
                file->size = size;
                return 0; // Data written successfully
            } else {
                return -1; // Data too large for the file
            }
        }
    }
    return -2; // File not found
}

// Read data from a file
int read_file(const char* filename, char* data, int max_size) {
    for (int i = 0; i < file_system.file_count; i++) {
        File* file = &file_system.files[i];
        if (strcmp(file->filename, filename) == 0) {
            if (file->size <= max_size) {
                strncpy(data, file->data, file->size);
                return file->size; // Data read successfully
            } else {
                return -1; // Buffer too small for the data
            }
        }
    }
    return -2; // File not found
}
