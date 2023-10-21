BITS 64
section .text
global _start

_start:
    ; Bootloader code here

    ; Load nucleus from disk into memory
    mov ah, 0x02       ; BIOS read sector function
    mov al, 1          ; Number of sectors to read
    mov ch, 0x00       ; Cylinder 0
    mov dh, 0x00       ; Head 0
    mov dl, 0x80       ; Drive 0 (usually the boot drive)
    mov rsi, 0x1000    ; Load into memory address 0x1000
    int 0x13           ; Call BIOS interrupt

    ; Jump to the loaded nucleus
    jmp 0x1000

times 510 - ($ - $$) db 0
dw 0xaa55
