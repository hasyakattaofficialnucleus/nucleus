.global nucleus_entry

nucleus_entry:
    # Initialize the stack pointer for the nucleus
    la sp, stack_top

    # Call a function to initialize the nucleus
    jal nucleus_init

    # Enter the main nucleus loop
    jal main_loop

    # Should never reach here; halt the CPU
    j .
