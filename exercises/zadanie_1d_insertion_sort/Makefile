NAME=ex1
CC=gcc
CFLAGS=-g -O2
ASM=../yasm/yasm
ASMFLAGS= -f elf64 -g dwarf2
OBJ = insertion_sort3.o ins.o
DEF = D -D IL

%.o: %.asm 
	$(ASM) -o $@ $< $(ASMFLAGS)

%.o: %.c 
	$(CC) -D $(DEF) -c -o $@ $< $(CFLAGS)

output: $(OBJ)
	$(CC) -o $(NAME) $^

all: output

run:
	./$(NAME)
gdb: 
	gdb -command=gdbinit ex1

.PHONY: clean

clean:
	rm *.o; rm $(NAME);

