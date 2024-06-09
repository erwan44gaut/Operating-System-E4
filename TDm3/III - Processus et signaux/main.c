#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

#define SECRET_CODE "1234"
#define TIMEOUT 10

pid_t child_pid;

void foo(int signal) {
    printf("\nTrop tard : coffre-fort fermé\n");
    exit(1);
}

int main() {
    signal(SIGUSR1, foo);

    child_pid = fork();

    if (child_pid == -1)
    {
        perror("fork error");
        exit(1);
    }

    if (child_pid == 0)
    {
        sleep(TIMEOUT);
        kill(getppid(), SIGUSR1);
        exit(0);
    } 
    else
    {
        char input[100];

        printf("Veuillez entrer le code secret : ");
        scanf("%s", input);

        if (strcmp(input, SECRET_CODE) == 0)
        {
            printf("Bravo : coffre-fort ouvert\n");
        }
        else
        {
            printf("Code faux : coffre-fort fermé\n");
        }

        kill(child_pid, SIGKILL);
        wait(NULL);
    }

    return 0;
}
