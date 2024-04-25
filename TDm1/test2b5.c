#include "gestionFichier.h"
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main()
{
    printf("Entrez une ligne (Ctrl+D pour finir) : \n");
    char* ligne = litLigne(0);
    if (ligne != NULL)
    {
        printf("Ligne lue : %s\n", ligne);
        free(ligne);
    }
    else
    {
        printf("Aucune ligne lue ou fin de fichier atteinte.\n");
    }

    return 0;
}