// fylsys/filesystem.c
#include <stdio.h>
#include <string.h>

#define MAX_FILES 100
#define MAX_FILENAME_LENGTH 50

struct File {
    char filename[MAX_FILENAME_LENGTH];
    char data[1024];  // A small buffer for file data
};

struct Directory {
    char name[MAX_FILENAME_LENGTH];
    struct File files[MAX_FILES];
    int file_count;
};

struct Directory root;

void init_filesystem() {
    strcpy(root.name, "root");
    root.file_count = 0;
}

void create_file(const char *filename) {
    if (root.file_count >= MAX_FILES) {
        printf("Error: Maximum number of files reached.\n");
        return;
    }

    struct File *new_file = &root.files[root.file_count];
    strcpy(new_file->filename, filename);
    root.file_count++;
}

void delete_file(const char *filename) {
    for (int i = 0; i < root.file_count; i++) {
        if (strcmp(root.files[i].filename, filename) == 0) {
            for (int j = i; j < root.file_count - 1; j++) {
                root.files[j] = root.files[j + 1];
            }
            root.file_count--;
            printf("File '%s' deleted.\n", filename);
            return;
        }
    }
    printf("Error: File not found.\n");
}

void list_directory() {
    printf("Contents of directory '%s':\n", root.name);
    for (int i = 0; i < root.file_count; i++) {
        printf("%s\n", root.files[i].filename);
    }
}
