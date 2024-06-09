#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

#define FIFO_FILE "/tmp/fifo_file"

int main()
{
    char response[2048];
    int fd;

    if (mkfifo(FIFO_FILE, 0666) == -1)
    {
        perror("mkfifo creation");
        exit(1);
    }

    while(1)
    {
        printf("Code scret de votre coffre fort :\n");
        scanf("%s", response);

        fd = open(FIFO_FILE, O_WRONLY);
        if (fd == -1)
        {
            perror("open fifo_file server A");
            continue;
        }

        if (write(fd, response, strlen(response) + 1) == -1)
        {
            perror("write");
        }

        close(fd);
    }

    unlink(FIFO_FILE);

    return 0;
}
