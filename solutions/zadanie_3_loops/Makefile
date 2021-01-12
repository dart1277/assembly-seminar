NAME=ex3
CC=gcc
CFLAGS=-g -O0 
OBJ = loops.o

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

