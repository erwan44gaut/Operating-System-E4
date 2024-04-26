#include "gestionFichier.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    int fd = open(argv[1], O_RDONLY);
    int nombreDeLignes = 0;
    char *ligne;

    if (fd == -1)
    {
        perror("allocation de la chaine");
        exit(1);
    }


    while ((ligne = litLigne(fd)) != NULL)
    {
        free(ligne);
        nombreDeLignes++;
    }

    printf("Nombre de lignes : %d\n", nombreDeLignes);

    close(fd);

    return 0;
}
