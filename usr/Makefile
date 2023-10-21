# Makefile in the usr/ directory
CFLAGS = -std=c99 -Wall

all: my_program simple_shell task1 task2 filesystem_program

my_program: my_program.c
    gcc $(CFLAGS) my_program.c -o my_program

simple_shell: simple_shell.c
    gcc $(CFLAGS) simple_shell.c -o simple_shell

task1: task1.c scheduler.c
    gcc $(CFLAGS) task1.c scheduler.c -o task1

task2: task2.c
    gcc $(CFLAGS) task2.c -o task2

filesystem_program: filesystem_program.c syscalls.c filesystem.c memory_protection.c process.c timer.c interrupts.c
    gcc $(CFLAGS) filesystem_program.c syscalls.c filesystem.c memory_protection.c process.c timer.c interrupts.c -o filesystem_program
	
clean:
    rm -f my_program simple_shell task1 task2 filesystem_program
