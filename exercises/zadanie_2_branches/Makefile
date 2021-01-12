NAME=ex2
CC=gcc
CFLAGS=-g -O1
OBJ = branches.o

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

