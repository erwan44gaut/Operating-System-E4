CC=gcc
CFLAGS=-g -Wall -ansi -pedantic

all: main1 main2

# Executables
main1: main1.o somme.o
	$(CC) $(CFLAGS) -o main1 main1.o somme.o

main2: main2.o somme.o
	$(CC) $(CFLAGS) -o main2 main2.o somme.o

# Objects
main1.o: main1.c somme.h
	$(CC) $(CFLAGS) -c main1.c

main2.o: main2.c somme.h
	$(CC) $(CFLAGS) -c main2.c

somme.o: somme.c somme.h
	$(CC) $(CFLAGS) -c somme.c

clean:
	rm -f main1 main2 *.o
