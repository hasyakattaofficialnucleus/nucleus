// nucleus/interrupts.c
#include <stdint.h>
#include "scheduler.h"
#include "timer.h"
#include "io.h"

// Define the PIC (Programmable Interrupt Controller) base addresses
#define PIC1 0x20  // Master PIC
#define PIC2 0xA0  // Slave PIC

// Define the PIC initialization command words
#define ICW1 0x11
#define ICW4 0x01

// Define the interrupt request numbers (IRQs)
#define TIMER_IRQ 0  // Example: IRQ 0 for the timer interrupt

// Interrupt Service Routine (ISR) for the timer interrupt
void timer_isr() {
    // Handle timer interrupt here.
    // For example, update system time, switch tasks, etc.
}

// Initialize the PIC (Programmable Interrupt Controller)
void init_pic() {
    // Initialize the master PIC
    outb(PIC1, ICW1);
    outb(PIC1 + 1, 0x20);  // Set the interrupt vector offset
    outb(PIC1 + 1, 1 << TIMER_IRQ);  // Configure which IRQ lines are connected

    // Initialize the slave PIC
    outb(PIC2, ICW1);
    outb(PIC2 + 1, 0x28);  // Set the interrupt vector offset for the slave
    outb(PIC2 + 1, TIMER_IRQ + 8);  // Configure which IRQ line the slave is connected to

    // Set up cascade
    outb(PIC1 + 1, 4);  // Inform the master about the slave
    outb(PIC2 + 1, 2);  // Inform the slave about cascade identity

    // Initialize the master and slave PICs in 8086/88 mode
    outb(PIC1 + 1, ICW4);
    outb(PIC2 + 1, ICW4);

    // Mask all IRQs by default (unmask specific IRQs when needed)
    outb(PIC1 + 1, 0xFF);
    outb(PIC2 + 1, 0xFF);
}

// Set up the Interrupt Descriptor Table (IDT)
void init_idt() {
    // Define and load IDT entries for each interrupt or exception (e.g., timer ISR).
    // This depends on your architecture and the specifics of your IDT setup.
}

// Function to enable interrupts
void enable_interrupts() {
    asm("sti");  // Set the interrupt flag
}

// Function to disable interrupts
void disable_interrupts() {
    asm("cli");  // Clear the interrupt flag
}


void isr_handler(uint32_t interrupt_number) {
    // Handle ISRs for various hardware or software interrupts.
    // Invoke the appropriate ISR function based on the interrupt number.
    // Example: Handle timer interrupt.
    if (interrupt_number == TIMER_INTERRUPT) {
        timer_isr();
    }
}

#define KEYBOARD_INTERRUPT 33 // Example interrupt number for the keyboard

void isr_handler(uint32_t interrupt_number) {
    // Handle various hardware and software interrupts.
    switch (interrupt_number) {
        case TIMER_INTERRUPT:
            timer_isr();
            break;
        case KEYBOARD_INTERRUPT:
            char key = getc();
            // Handle keyboard input (e.g., process key presses).
            break;
        // Handle other interrupts as needed.
    }