#include "gestionFichier.h"
#include <stdlib.h>
#include <stdio.h>

int main()
{
    char *ligne = NULL;
    printf("Entrez une ligne ou Ctrl+D pour quitter : \n");
    ligne = litLigne(0);

    if (ligne != NULL)
    {
        ecrireChaine(1, "Ligne lue : ");
        ecrireChaine(1, ligne);
        ecrireChaine(1, "\n");
        free(ligne);
    }
    else
    {
        printf("Aucune ligne lue.\n");
    }

    return 0;
}