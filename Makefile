CC = gcc
AS = nasm
CFLAGS = -m32 -std=gnu99 -ffreestanding -O2 -Wall -Wextra
ASFLAGS = -f elf32

NUCLEUS = nucleus.bin

all: $(NUCLEUS)

$(NUCLEUS): boot/boot.o init/nucleus.o
    ld -m elf_i386 -T linker.ld -o $@ $^

boot/boot.o: /boot/boot.asm
    $(AS) $(ASFLAGS) $< -o $@

init/nucleus.o: /init/nucleus.c
    $(CC) $(CFLAGS) -c $< -o $@

clean:
    rm -f $(NUCLEUS) init/*.o
