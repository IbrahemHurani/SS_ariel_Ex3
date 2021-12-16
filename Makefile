.PHONY = all clean
FLAGS = -Wall -Werror -g
CC = gcc
all: stringProg
stringProg: Ex3.c
	$(CC) $(FLAGS) Ex3.c -o stringProg
clean:
	rm -f *.o *.a stringProg
