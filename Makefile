FLAGS = -Wall -Werror -g
CC = gcc
all:stringProg
stringProg: Hw3.c
	$(CC) $(FLAGS) Hw3.c -o stringProg
 .PHONY:clean	all
clean:
	rm	-f	*.o	stringProg