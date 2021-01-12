NAME=ex4
CC=gcc
CFLAGS=-g -O0 -masm=intel
OBJ = clobber.o

%.o: %.c 
	$(CC) -c -o $@ $< $(CFLAGS)

output: $(OBJ)
	$(CC) -o $(NAME) $^

all: output

run:
	./$(NAME)

.PHONY: clean

clean:
	rm *.o; rm $(NAME);

