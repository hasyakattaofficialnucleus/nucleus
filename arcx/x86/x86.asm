BITS 16                  ; 16-bit real mode
ORG 0x7C00               ; Boot sector origin

start:
    xor ax, ax           ; Clear AX register
    mov ds, ax           ; Set DS to 0
    mov ss, ax           ; Set SS to 0
    mov es, ax           ; Set ES to 0
    mov sp, 0x7C00       ; Set SP to the stack address
    cld                  ; Clear the direction flag

    ; Load the nucleus from disk to memory
    mov ah, 0x02         ; BIOS read sector function
    mov al, 1            ; Number of sectors to read
    mov ch, 0x00         ; Cylinder
    mov dh, 0x00         ; Head
    mov cl, 0x02         ; Sector (1-based)
    mov bx, 0x0100       ; Buffer address
    int 0x13             ; BIOS interrupt for disk I/O

    ; Jump to the loaded nucleus
    mov ax, 0x0100       ; Segment:Offset of the loaded nucleus
    mov ds, ax
    mov es, ax
    mov fs, ax
    mov gs, ax
    mov esp, 0x7C00      ; Set stack pointer
    call 0x0100:0x0000   ; Call the nucleus's entry point

    ; Infinite loop
    cli
.loop:
    hlt
    jmp .loop

times 510 - ($ - $$) db 0   ; Fill the boot sector to 510 bytes
dw 0xAA55                   ; Boot signature
