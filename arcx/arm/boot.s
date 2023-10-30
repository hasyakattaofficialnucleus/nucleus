.global _start

.section .text
_start:
    ; Bootloader code here

    ; Load nucleus from disk into memory
    mov r0, #1
    mov r1, #0x1000
    ldr r2, =nucleus
    bl read_sectors

    ; Jump to the loaded nucleus
    ldr lr, =nucleus
    bx lr

read_sectors:
    ; Disk read code here

.section .data
nucleus:
