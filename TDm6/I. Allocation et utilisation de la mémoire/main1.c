#include "somme.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main()
{
    int **tab;
    int N = 2048;
    int M = 2048;
    int i;
    
    tab = (int**) malloc(sizeof(int*) * N);

    if (tab == NULL)
    {
        exit(1);
    }

    for (i = 0; i < N; i++)
    {
        tab[i] = (int*) malloc(sizeof(int) * M);
        if (tab[i] == NULL)
        {
            exit(1);
        }
    }

    somme1(tab, 2048, 2048);
    return 0;
}