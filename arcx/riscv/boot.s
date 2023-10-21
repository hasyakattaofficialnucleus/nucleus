.global _start

_start:
    ; Bootloader code here

    ; Load nucleus from disk into memory
    li t0, 1
    li t1, 0x1000
    la t2, nucleus
    call read_sectors

    ; Jump to the loaded nucleus
    la t3, nucleus
    jr t3

read_sectors:
    ; Disk read code here

.section .data
nucleus:
