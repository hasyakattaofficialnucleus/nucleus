// nucleus/io.c
#include <stdint.h>
#include "common.h"


// Output a character to the screen
void putc(char c) {
    // Implement character output to the screen.
}

// Input a character from the keyboard
char getc() {
    // Implement character input from the keyboard.
    // This may involve reading keyboard hardware registers.
    char key = 'A'; // Placeholder, actual implementation required.
    return key;
}

// Functions to read and write from/to I/O ports
uint8_t inb(uint16_t port) {
    uint8_t data;
    asm volatile ("inb %1, %0" : "=a" (data) : "dN" (port));
    return data;
}

void outb(uint16_t port, uint8_t data) {
    asm volatile ("outb %0, %1" :: "a" (data), "dN" (port));
}