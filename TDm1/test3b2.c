#include "gestionFichier.h"
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    int src, dest;
    int BUFFER_SIZE = 50;
    char buffer[BUFFER_SIZE];
    long int nread;

    src = open("fichierTest.txt", O_RDONLY);
    if (src < 0) {
        perror("Error opening source file");
        exit(1);
    }

    dest = open("copieFichierTest.txt", O_WRONLY | O_CREAT | O_TRUNC, 0700);
    if (dest < 0) {
        perror("Error opening destination file");
        exit(1);
    }

    /* conserver les mêmes droit lors de la copie, sinon OK */
    while ((nread = read(src, buffer, 1)) > 0)
    {
        if(write(dest, buffer, 1) != nread){
            perror("writing problem ");
            exit(3);
        }
    }

    close(src);
    close(dest);

    return 0;
}