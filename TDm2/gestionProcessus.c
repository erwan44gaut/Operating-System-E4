#include "gestionProcessus.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void afficherPID(const char *str)
{
    printf("PID %d: %s\n", getpid(), str);
}

void afficherPPID(const char *str)
{
    printf("PPID %d: %s\n", getppid(), str);
}

void afficherPPIDEtPID(const char *str)
{
    printf("PID %d, PPID %d: %s\n", getpid(), getppid(), str);
}

char * litLigne(int fd)
{
	int i;
	int nbr;
	char buf[TAILLEBUF];
	char * s;

	for(nbr = 0 ; nbr < TAILLEBUF ; nbr++){
		if( read(fd, buf+nbr,1) <= 0  ){
			return NULL;
		}
		if(buf[nbr]=='\n')break;
	} 

	s=(char*)malloc(nbr+1);
	if(s==NULL)return NULL;

	for(i=0;i<nbr;i++)
		s[i]=buf[i];

	s[i] = '\0';
	return s;
}
