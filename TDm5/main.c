#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h> 
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <semaphore.h>
#include <getopt.h>
#include <time.h>

#define SIZE_TAB 42
#define NB_PROD 100
#define MAX_RAND 50

void reset()
{
    printf("reset\n");
    /* TODO 
    *   shm_unlink();
    *   sem_unlink();
    *   sem_unlink();
    */
    shm_unlink("/toto");
    sem_unlink("nonVide");
    sem_unlink("nonPlein");
}

int* init_sem_mem(sem_t ** nonVide, sem_t **nonPlein)
{
    int fd;
    int *tab;
    /* TODO
     * shm_open()
     * ftruncate()
     * mmap()
     * sem_open()
     * sem_open()
     */
    fd = shm_open("/toto", O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);
    if (fd == -1)
    {
        perror("shm_open");
        exit(1);
    }
    if (ftruncate(fd, SIZE_TAB*sizeof(int)) == -1)
    {
        perror("ftruncate");
        exit(1);
    }
    tab = (int*) mmap(NULL, SIZE_TAB*sizeof(int), PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    if (tab == MAP_FAILED)
    {
        perror("mmap");
        exit(1);
    }
    *nonVide = sem_open("nonVide", O_RDWR | O_CREAT, S_IRUSR | S_IWUSR, 0);
    if (*nonVide == SEM_FAILED)
    {
        perror("sem_open");
        exit(1);
    }
    *nonPlein = sem_open("nonPlein", O_RDWR | O_CREAT, S_IRUSR | S_IWUSR, SIZE_TAB);
    if (*nonPlein == SEM_FAILED)
    {
        perror("sem_open");
        exit(1);
    }

    return tab;
}

void producteur()
{
    int *tab;
    sem_t *nonVide;
    sem_t *nonPlein;
    int i;
    int offset = 0;
    /* TODO
     * int * tab;
     * sem_t * nonVide;
     * sem_t * nonPlein;
     * init_sem_mem(); => initialise tab, nonVide et nonPlein
     * boucle production
     * munmap()
     */
    srand(time(NULL));
    tab = init_sem_mem(&nonVide, &nonPlein);
    for (i = 0; i < NB_PROD; i++)
    {
        int value = (int) ((rand() / (double)RAND_MAX) * MAX_RAND) + 1;
        sem_wait(nonPlein);
        tab[offset] = value;
        sem_post(nonVide);
        fprintf(stderr, "Produit %d\n", value);
        offset = (offset + 1) % SIZE_TAB;
    }
    if (munmap(tab, SIZE_TAB*sizeof(int)) == -1)
    {
        perror("munmap");
        exit(1);
    }
}

void consommateur()
{
    int *tab;
    sem_t *nonVide;
    sem_t *nonPlein;
    int i;
    int offset = 0;
    /* TODO
     * int * tab;
     * sem_t * nonVide;
     * sem_t * nonPlein;
     * init_sem_mem(); => initialise tab, nonVide et nonPlein
     * boucle consommation
     * munmap()
     */
    tab = init_sem_mem(&nonVide, &nonPlein);
    for (i = 0; i < NB_PROD; i++)
    {
        int value;
        sem_wait(nonVide);
        value = tab[offset];
        sem_post(nonPlein);
        fprintf(stderr, "Consomme %d\n", value);
        offset = (offset + 1) % SIZE_TAB;
    }
    if (munmap(tab, SIZE_TAB*sizeof(int)) == -1)
    {
        perror("munmap");
        exit(1);
    }
}

void usage()
{
    printf("must be run with either one of these option : -reset or -r, -producer or -d, -consumer or -c\n");
}

int main(int argc , char * argv[])
{
    static struct option long_options[] =
    {
        {"reset",     no_argument, 0, 'r'},
        {"producer",  no_argument, 0, 'p'},
        {"consumer",  no_argument, 0, 'c'},
        {0, 0, 0, 0}
    };
    /* getopt_long stores the option index here. */
    int option_index = 0;
    int c = getopt_long (argc, argv, "rpc",
            long_options, &option_index);

    /* Detect the end of the options. */
    if (c == -1)
        usage();
    else
        switch (c)
        {
            case 'r':
                reset();
                break;

            case 'p':
                producteur();
                break;

            case 'c':
                consommateur();
                break;

            default: break;
        }
    if (optind < argc)
    {
        usage();
        while (optind < argc)
            printf ("%s ", argv[optind++]);
        putchar ('\n');
    }

    return 0;
}