all: trout.o util.o


trout.o:  trout.h util.h trout.c   util.c main.c
	gcc -g -Wall -c   util.c main.c

util.o: util.h util.c
	gcc -g -Wall -c util.c
