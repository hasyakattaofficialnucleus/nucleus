section .boot
    global _start

_start:
    mov esp, stack_top       ; Set up the stack pointer

    ; Load the nucleus from disk to memory
    mov ah, 0x02             ; BIOS read sector function
    mov al, 1                ; Number of sectors to read
    mov ch, 0x00             ; Cylinder
    mov dh, 0x00             ; Head
    mov cl, 0x02             ; Sector (1-based)
    mov bx, nucleus_buffer    ; Buffer address
    int 0x13                 ; BIOS interrupt for disk I/O

    ; Jump to the loaded nucleus
    mov rsp, nucleus_buffer   ; Set stack pointer
    call nucleus_entry        ; Call the nucleus's entry point

    ; Infinite loop
.loop:
    hlt
    jmp .loop

section .bss
    resb 510 - ($ - $$)       ; Fill the boot sector to 510 bytes
    dw 0xAA55                 ; Boot signature

section .data
stack_top equ 0x7C00        ; Stack top address
nucleus_buffer equ 0x8000    ; Address to load the nucleus
nucleus_entry equ 0x8000     ; Entry point of the nucleus
