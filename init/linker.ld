OUTPUT_FORMAT("elf32-i386")
ENTRY(_start)

SECTIONS
{
    . = 0x100000;  /* Nucleus starts at 1MB in memory */
    .text : {
        *(.text)
    }
    .rodata : {
        *(.rodata)
    }
    .data : {
        *(.data)
    }
    .bss : {
        *(.bss)
    }
}
