#include "gestionProcessus.h"
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
    pid_t rv;
    
    rv = fork();

    if (rv == -1)
    {
        perror("fork");
        exit(1);
    }

    if (rv == 0)
    {
        afficherPID("fils");
    }
    else
    {
        wait(NULL);
        afficherPPIDEtPID("père");
    }

    return 0;
}
