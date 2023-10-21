// usr/process1.c
#include <stdio.h>

int main() {
    init_pipe();
    const char *message = "Hello from Process 1!";
    write_to_pipe(message);
    return 0;
}

// usr/process2.c
#include <stdio.h>

int main() {
    const char *received_message = read_from_pipe();
    printf("Received message: %s\n", received_message);
    return 0;
}
