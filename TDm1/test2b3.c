#include "gestionFichier.h"

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int fd = open(argv[1], O_RDONLY);
    char *ligne;

    if (fd == -1)
    {
        perror("allocation de la chaine");
        exit(1);
    }

    while ((ligne = litLigne(fd)) != NULL)
    {
        printf("%s\n", ligne);
        free(ligne);
    }
    
    return 0;
}
