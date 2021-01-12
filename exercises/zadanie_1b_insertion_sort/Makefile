NAME=ex1
CC=gcc
CFLAGS=-g -O2
ASM=../yasm/yasm
ASMFLAGS= -f elf64 -g dwarf2
OBJ = inner_loop0.o ins.o
DEF = B

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

