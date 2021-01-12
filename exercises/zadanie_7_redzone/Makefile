NAME=ex7
CFLAGS=-g -O0
all: 1

1:
	gcc red.c $(CFLAGS) -o $(NAME)

2:
	gcc red.c -mno-red-zone $(CFLAGS) -o $(NAME)

3:
	gcc red.c -D N $(CFLAGS) -o $(NAME)

.PHONY: clean

clean:
	rm *.o; rm $(NAME);


