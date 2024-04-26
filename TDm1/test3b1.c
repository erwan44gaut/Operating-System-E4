#include "gestionFichier.h"
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    /*
    * argv[1] = source
    * argv[2] = destination
    */
    int fd_src = open(argv[1], O_RDONLY);
    int fd_dest = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0644);
    char *ligne;

    if (fd_src == -1)
    {
        perror("allocation de la chaine");
        exit(1);
    }

    if (fd_dest == -1)
    {
        perror("allocation de la chaine");
        exit(1);
    }

    while ((ligne = litLigne(fd_src)) != NULL) {
        ecrireChaine(fd_dest, ligne);
        write(fd_dest, "\n", 1); 
        free(ligne);
    }

    return 0;
}