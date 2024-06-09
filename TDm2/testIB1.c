#include "gestionProcessus.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
    afficherPID("bonjour");
    afficherPPID("bonjour");
    afficherPPIDEtPID("bonjour");
    
    return 0;
}