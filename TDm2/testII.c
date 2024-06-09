#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    pid_t pid;
    pid = fork();

    if (pid < 0)
    {
        perror("fork");
        exit(1);
    }
    else if (pid == 0)
    {
        execlp("ls", NULL);
        perror("Échec de l'exécution du programme fils\n");
        exit(1);
    }
    else
    {
        printf("Je suis le père\n");
        wait(NULL);
    }

    return 0;
}
