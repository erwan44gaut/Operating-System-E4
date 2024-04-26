#include "gestionFichier.h"
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>

int main()
{
    char *s;
    int fd = open("fichierTest.txt", O_RDONLY);

    if (fd == -1)
    {
        perror("allocation de la chaine");
        exit(1);
    }

    s = litLigne(fd);
    printf("Première ligne : %s\n", s);
    free(s);

    return 0;
}