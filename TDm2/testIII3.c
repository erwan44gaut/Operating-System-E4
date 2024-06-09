#include "gestionProcessus.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    pid_t rv;
    int fd;
    char *s;

    fd = open(argv[1], O_RDONLY);

    if (fd == -1)
    {
        perror("allocation de la chaine");
        exit(1);
    }

    rv = fork();

    if (rv == -1)
    {
        perror("fork");
        exit(1);
    }

    if (rv == 0) {
        s = litLigne(fd);
        printf("Fils : %s\n", s);
    } else {
        s = litLigne(fd);
        printf("Père : %s\n", s);
    }

    close(fd);

    return 0;
}