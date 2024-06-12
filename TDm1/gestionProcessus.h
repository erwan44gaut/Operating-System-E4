#ifndef _GESTION_PROCESSUS_H
#define _GESTION_PROCESSUS_H

#define TAILLEBUF 8191

void afficherPID(const char*);
void afficherPPID(const char*);
void afficherPPIDEtPID(const char*);
char * litLigne(int fd);

#endif