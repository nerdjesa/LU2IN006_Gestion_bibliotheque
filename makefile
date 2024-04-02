CFLAGS= -Wall -Werror 
CC=gcc

all: main

main: entreeSortieLC.o biblioLC.o biblioH.o main.o
	$(CC) $(CFLAGS) -ggdb -o main entreeSortieLC.o biblioLC.o biblioH.o main.o -lm

entreeSortieLC.o: entreeSortieLC.c entreeSortieLC.h biblioLC.h biblioH.h
	$(CC) $(CFLAGS) -c entreeSortieLC.c 

biblioLC.o: biblioLC.c biblioLC.h
	$(CC) $(CFLAGS) -c biblioLC.c

biblioH.o: biblioH.c biblioH.h
	$(CC) $(CFLAGS) -c biblioH.c

main.o: main.c entreeSortieLC.h biblioLC.h biblioH.h
	$(CC) $(CFLAGS) -c main.c

clean:
	rm -f *.o main