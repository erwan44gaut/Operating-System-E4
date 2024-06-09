#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <string.h>

char* litDixCaracteres(int fd)
{
    int nbr;
    char *buf = malloc(11 * sizeof(char));

    if (buf == NULL)
    {
        perror("allocation de la chaine");
        exit(1);
    }

    for (nbr = 0; nbr < 10;)
    {
        int rv = read(fd, buf + nbr, 1);
        if (rv == 0) break;
        nbr += rv;
    }

    /* Fin de la chaine de caractère */
    buf[nbr] = '\0';

    return buf;
}

char* litLigne(int fd)
{
    int TAILLEBUF = 1024;
    char* buf = malloc(TAILLEBUF * sizeof(char));
    int nbr = 0;
    char c;
    ssize_t rv;

    if (buf == NULL)
    {
        perror("allocation de la chaine");
        exit(1);
    }

    for (nbr = 0; nbr < TAILLEBUF - 1; nbr++)
    {
        rv = read(fd, &c, 1);
        /* rv = 0 indique la fin du fichier */
        if (rv == 0)
        {
            /* Si aucun caractère lu */
            if (nbr == 0)
            {
                free(buf);
                return NULL;
            }
            break;
        }
        
        if (c == '\n') break;
        buf[nbr] = c;
    }

    buf[nbr] = '\0';

    return buf;
}

void ecrireChaine(int fd, char *phrase)
{
    if (write(fd, phrase, strlen(phrase)) == -1) {
        perror("Erreur lors de l'écriture dans le fichier");
        exit(1);
    }
}