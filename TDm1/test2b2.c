#include "gestionFichier.h"
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
    char *s;
    
    int fd = open(argv[1], O_RDONLY);

    if (fd < 0)
    {
        perror("allocation de la chaine");
        exit(1);
    }

    s = litLigne(fd);

    printf("Première ligne : %s\n", s);

    free(s);

    return 0;
}