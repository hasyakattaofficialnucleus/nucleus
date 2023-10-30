.global nucleus_entry

nucleus_entry:
    @ Initialize the stack pointer for the nucleus
    ldr sp, =stack_top

    @ Call a function to initialize the nucleus
    bl nucleus_init

    @ Enter the main nucleus loop
    bl main_loop

    @ Should never reach here; halt the CPU
    b .
