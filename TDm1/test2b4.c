#include "gestionFichier.h"
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main()
{
    int s;
    
    int fd = open("fichierTest.txt", O_RDONLY);

    if (fd < 0)
    {
        perror("allocation de la chaine");
        exit(1);
    }

    s = compteNombreLignes(fd);

    printf("Nombre de lignes : %d\n", s);

    return 0;
}