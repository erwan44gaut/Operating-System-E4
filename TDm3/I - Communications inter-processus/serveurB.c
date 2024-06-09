#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

#define FIFO_FILE "/tmp/fifo_file"

int main()
{
    char response[2048];
    int fd;

    fd = open(FIFO_FILE, O_RDONLY);
    if (fd == -1)
    {
        perror("open");
        return 1;
    }

    while (1)
    {
        if (read(fd, response, sizeof(response)) > 0)
        {
            printf("%s\n", response);
        }
    }

    close(fd);

    return 0;
}
