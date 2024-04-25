#include "gestionFichier.h"
#include <stdio.h>

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        perror("argument erreur");
        exit(1);
    }
    
    copieFichier(argv[1], argv[2]);

    return 0;
}