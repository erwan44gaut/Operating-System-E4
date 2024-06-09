#include "gestionProcessus.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
    pid_t rv;
    int fd;
    char *s;
    
    rv = fork();

    if (rv == -1)
    {
        perror("fork");
        exit(1);
    }

    fd = open("fichierTest.txt", O_RDONLY);

    if (fd == -1)
    {
        perror("allocation de la chaine");
        exit(1);
    }

    s = litLigne(fd);
    printf("Première ligne : %s\n", s);

    close(fd);

    return 0;
}