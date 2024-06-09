#include "gestionFichier.h"

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX 1024

char buffer[MAX];

void* thread_1()
{
    int fd_src = open("input.txt", O_RDONLY);
    char *ligne;

    if (fd_src == -1)
    {
        perror("input.txt");
        exit(1);
    }

    while ((ligne = litLigne(fd_src)) != NULL)
    {
        strncpy(buffer, ligne, MAX - 1);
        buffer[MAX - 1] = '\0';
        free(ligne);
    }

    close(fd_src);
}

void* thread_2()
{
    int fd_dest = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);

    if (fd_dest == -1)
    {
        perror("output.txt");
        pthread_exit(NULL);
    }

    ecrireChaine(fd_dest, buffer);

    close(fd_dest);
}

int main()
{
    pthread_t t1, t2;

    if (pthread_create(&t1, NULL, thread_1, NULL) != 0)
    {
        perror("Erreur de création du thread 1");
        return EXIT_FAILURE;
    }

    if (pthread_create(&t2, NULL, thread_2, NULL) != 0)
    {
        perror("Erreur de création du thread 2");
        return EXIT_FAILURE;
    }

    return 0;
}
