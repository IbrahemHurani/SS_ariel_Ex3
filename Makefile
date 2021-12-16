.PHONY = all clean
FLAGS = -Wall -Werror -g
CC = gcc
all: stringProg
stringProg: Hw3.c
	$(CC) $(FLAGS) Hw3.c -o stringProg
clean:
	rm -f *.o *.a stringProg
