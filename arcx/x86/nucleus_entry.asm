[BITS 32]
global nucleus_entry

nucleus_entry:
    ; Initialize the stack pointer for the nucleus
    mov esp, stack_top

    ; Call a function to initialize the nucleus
    call nucleus_init

    ; Enter the main nucleus loop
    call main_loop

    ; Should never reach here; halt the CPU
    hlt

main_loop:
    ; Implement your main nucleus loop logic here
    ; You can handle interrupts, schedule tasks, etc.

    ; Example: Infinite loop
.loop:
    jmp .loop

stack_top:
    ; Define the top of the stack for the nucleus
