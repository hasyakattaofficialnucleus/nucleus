#include "ipc.h"
#include "process.h"

#define MAX_MESSAGES 100
#define MAX_MESSAGE_SIZE 64

// Message structure
typedef struct {
    int sender_pid;
    int receiver_pid;
    char data[MAX_MESSAGE_SIZE];
} Message;

// Message queue
static Message message_queue[MAX_MESSAGES];
static int message_count = 0;

// Send a message from one process to another
int send_message(int sender_pid, int receiver_pid, const char* data) {
    if (message_count < MAX_MESSAGES) {
        Message* message = &message_queue[message_count];
        message->sender_pid = sender_pid;
        message->receiver_pid = receiver_pid;
        strncpy(message->data, data, MAX_MESSAGE_SIZE);

        message_count++;
        return 0; // Message sent successfully
    }
    return -1; // Message queue full
}

// Receive a message for the current process
int receive_message(int receiver_pid, char* data, int max_length) {
    for (int i = 0; i < message_count; i++) {
        Message* message = &message_queue[i];
        if (message->receiver_pid == receiver_pid) {
            // Copy the message data to the user buffer
            strncpy(data, message->data, max_length);
            // Remove the received message from the queue
            for (int j = i; j < message_count - 1; j++) {
                message_queue[j] = message_queue[j + 1];
            }
            message_count--;
            return 0; // Message received successfully
        }
    }
    return -1; // No message for the receiver
}
