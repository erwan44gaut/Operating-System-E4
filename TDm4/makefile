##### main #####
main : gestionFichier.o main.o
	gcc -o main main.o gestionFichier.o

main.o : main.c gestionFichier.h
	gcc -c -Wall -ansi -pedantic main.c

gestionFichier.o : gestionFichier.c gestionFichier.h
	gcc -c -Wall -ansi -pedantic gestionFichier.c