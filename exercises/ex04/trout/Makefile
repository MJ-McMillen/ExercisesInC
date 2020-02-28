all: main.o util.o
	gcc -g -Wall main.o util.o -o trout

trout.o:  trout.h util.h trout.c   util.c main.c
	gcc -g -Wall -c   util.c main.c

util.o: util.h util.c
	gcc -g -Wall -c util.c
