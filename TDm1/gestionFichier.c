#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>

char* litDixCaracteres(int fd)
{
    int nbr;
    char* buf = malloc(11 * sizeof(char));

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

    /* Fin de ligne */
    buf[nbr] = '\0';

    return buf;
}

char* litLigne(int fd)
{
    int nbr;
    int TAILLEBUF = 2000;
    char* buf = malloc(TAILLEBUF * sizeof(char));
    char c;

    if (buf == NULL)
    {
        perror("allocation de la chaine");
        exit(1);
    }

    for (nbr = 0; nbr < TAILLEBUF - 1; nbr++)
    {
        int rv = read(fd, &c, 1);
        /* rv = 0 indicates end of file */
        if (rv == 0)
        {
            /* Aucun caractère lu, retourner NULL */
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

char* litFichier(int fd)
{
    int TAILLEBUF = 100;
    char* buf = malloc(TAILLEBUF * sizeof(char));
    char c;
    int size = 0;

    if (buf == NULL)
    {
        perror("allocation de la chaine");
        exit(1);
    }

    while (1)
    {
        int rv = read(fd, &c, 1);

        if (rv == 0 || c == '\n')
        {
            if (size == TAILLEBUF - 1)
            {
                TAILLEBUF *= 2;
                buf = realloc(buf, TAILLEBUF * sizeof(char));
            }

            buf[size++] = '\n';
            buf[size] = '\0';

            if (rv == 0) break;
        }
        else
        {
            if (size == TAILLEBUF - 1)
            {
                TAILLEBUF *= 2;
                buf = realloc(buf, TAILLEBUF * sizeof(char));
            }

            buf[size++] = c;
        }
    }

    return buf;
}

int compteNombreLignes(int fd)
{
    int nbLignes = 0;
    char* ligne = NULL;

    while ((ligne = litLigne(fd)) != NULL)
    {
        nbLignes++;
        free(ligne);
    }

    return nbLignes;
}

int copieFichier(const char *src, const char *dest) {
    int fd_src, fd_dest;
    int BUFFER_SIZE = 50;
    char buffer[BUFFER_SIZE];
    long int nread;

    fd_src = open(fd_src, O_RDONLY);
    if (fd_src < 0) {
        perror("Error opening source file");
        exit(1);
    }

    fd_dest = open(fd_dest, O_WRONLY | O_CREAT | O_TRUNC, 0700);
    if (fd_dest < 0) {
        perror("Error opening destination file");
        exit(1);
    }

    /* conserver les mêmes droit lors de la copie, sinon OK */
    while ((nread = read(fd_src, buffer, BUFFER_SIZE)) > 0)
    {
        if(write(fd_dest, buffer, nread) != nread){
            perror("writing problem ");
            exit(3);
        }
    }

    close(fd_src);
    close(fd_dest);

    return 0;
}
