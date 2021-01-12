NAME=ex5
CC=gcc
CFLAGS=-g -O3
OBJ = restrict.o fun.o

%.o: %.cpp 
	$(CC) -c -o $@ $< $(CFLAGS)

output: $(OBJ)
	$(CC) -o $(NAME) $^

all: output

run:
	./$(NAME)
	gnuplot plot.plt

.PHONY: clean

clean:
	rm *.o; rm $(NAME); rm *.dat; rm *.png;

