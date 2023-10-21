# Makefile in the nucleus/ directory
NUCLEUS_BINARY = nucleus.bin
C_SOURCES = nucleus.c memory.c syscalls.c
ASM_SOURCES = boot.asm

# Build and link the nucleus
$(NUCLEUS_BINARY): $(ASM_SOURCES) $(C_SOURCES)
    nasm -f elf32 boot.asm -o boot.o
    gcc -m32 -c $(C_SOURCES)
    ld -m elf_i386 -T linker.ld -o $(NUCLEUS_BINARY) boot.o $(C_SOURCES:.c=.o)


CFLAGS = -std=c99 -Wall

all: nucleus

nucleus: nucleus_main.o process.o syscalls.o memory.o filesystem.o context_switch.o timers.o scheduler.o io.o
    gcc $(CFLAGS) -o nucleus nucleus_main.o process.o syscalls.o memory.o filesystem.o context_switch.o timers.o scheduler.o io.o


nucleus_main.o: init/nucleus_main.c
    gcc $(CFLAGS) -c init/nucleus_main.c -o nucleus_main.o

process.o: process.c
    gcc $(CFLAGS) -c process.c -o process.o

syscalls.o: syscalls.c
    gcc $(CFLAGS) -c syscalls.c -o syscalls.o

memory.o: nucleus/memory.c
    gcc $(CFLAGS) -c nucleus/memory.c -o memory.o

filesystem.o: fylsys/filesystem.c
    gcc $(CFLAGS) -c fylsys/filesystem.c -o filesystem.o

io.o: io.c
    gcc $(CFLAGS) -c io.c -o io.o

context_switch.o: context_switch.c
    gcc $(CFLAGS) -c context_switch.c -o context_switch.o

timers.o: timers.c
    gcc $(CFLAGS) -c timers.c -o timers.o

scheduler.o: scheduler.c
    gcc $(CFLAGS) -c scheduler.c -o scheduler.o

clean:
    rm -f nucleus nucleus_main.o process.o syscalls.o memory.o filesystem.o
