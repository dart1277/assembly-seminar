NAME=ex4
CC=gcc
CFLAGS=-g -O3 -masm=intel
OBJ = label.o

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

