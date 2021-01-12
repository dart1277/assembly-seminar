NAME=ex6
CC=gcc
CFLAGS=-g -O2 -masm=intel
LIBS=-lm 
OBJ = xmm2f.o

%.o: %.c 
	$(CC) -c -o $@ $< $(CFLAGS)

output: $(OBJ)
	$(CC) -o $(NAME) $(LIBS) $^

all: output

run:
	./$(NAME)

.PHONY: clean

clean:
	rm *.o; rm $(NAME);

